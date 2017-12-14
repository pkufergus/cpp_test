#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unistd.h>
#include <sys/time.h>
using namespace std;

int split_fast(
        const std::string& input_str,
        const std::string& delimiter,
        std::vector<std::string>& output_str_list) {
    //output_str_list.clear();
    if (input_str.empty()) {
        return 0;
    }
    size_t pre_pos = 0;
    size_t position = 0;
    std::string tmp_str;
    int t = 0;
    while ((position = input_str.find(delimiter, pre_pos)) != std::string::npos) {
        tmp_str.assign(input_str, pre_pos, position - pre_pos);
        // notice: empty string will also be counted
        // e.g.: when delimiter is ";", ";;" will also have an empty string
        //output_str_list.push_back(tmp_str);
        output_str_list[t++] = tmp_str;
        pre_pos = position + delimiter.length();
        //printf("tmp_str=%s\t", tmp_str.c_str());
    }
    tmp_str.assign(input_str, pre_pos, input_str.length() - pre_pos);
    //printf("size=%d\n ", output_str_list.size());
    //output_str_list.push_back(tmp_str);
    output_str_list[t++] = tmp_str;
    //printf("size=%d\n ", output_str_list.size());
    //printf("tmp_str=%s\t", tmp_str.c_str());
    return t;
}

int split_fast3(
        const std::string& input_str,
        const char& delimiter,
        std::vector<std::string>& output_str_list) {
    //output_str_list.clear();
    if (input_str.empty()) {
        return 0;
    }
    size_t pre_pos = 0;
    size_t position = 0;
    std::string tmp_str;
    int t = 0;
    while ((position = input_str.find(delimiter, pre_pos)) != std::string::npos) {
        //tmp_str.assign(input_str, pre_pos, position - pre_pos);
        // notice: empty string will also be counted
        // e.g.: when delimiter is ";", ";;" will also have an empty string
        //output_str_list.push_back(tmp_str);
        if (t >= output_str_list.size()) {
            output_str_list.resize(2 * t);
        }
        output_str_list[t++].assign(input_str, pre_pos, position - pre_pos);
        //output_str_list.push_back(tmp_str);
        pre_pos = position + 1;
        //printf("tmp_str=%s\t", tmp_str.c_str());
    }
    /* tmp_str.assign(input_str, pre_pos, input_str.length() - pre_pos); */
    //printf("size=%d\n ", output_str_list.size());
    //output_str_list.push_back(tmp_str);
    /* output_str_list[t++] = tmp_str; */
    output_str_list[t++].assign(input_str, pre_pos, position - pre_pos);
    //output_str_list.push_back(tmp_str);
    //printf("size=%d\n ", output_str_list.size());
    //printf("tmp_str=%s\t", tmp_str.c_str());
    return t;
}

int split_fast2(
        char *buf,
        const int max_buf_len,
        const char& delimiter,
        std::vector<std::string>& output_str_list) {
    output_str_list.clear();
    if (buf == NULL || buf[0] == 0) {
        return 0;
    }
    size_t pre_pos = 0;
    std::string tmp_str;
    int i = 0;
    for (i = 0; i < max_buf_len; i++) {
        if (buf[i] == '\n') {
            //printf("[yudao huanhang]");
            break;
        }
        if (buf[i] == 0) {
            break;
        }
        if (buf[i] == delimiter) {
            tmp_str.assign(buf, i - pre_pos);
            //printf("tmp_str=%s\t", tmp_str.c_str());
            output_str_list.push_back(tmp_str);
            pre_pos = i + 1;
        }
    }
    tmp_str.assign(buf, i - pre_pos);
    //printf("tmp_str=%s\n", tmp_str.c_str());
    output_str_list.push_back(tmp_str);
    return output_str_list.size();
}

void TestSplit() {
    string data_path = "index_1.txt";
    FILE *fp = fopen(data_path.c_str(), "r");
    char *buf = new char[102400];
    vector<string> items;
    items.resize(19);
    /* items.reserve(18); */
    printf("items size=%d\n", items.size());
    string line;
    int vsize = 0;
    while (1) {
        if (fgets(buf, 102400, fp) == NULL) {
            break;
        }
        if (buf[0] == 0) {
            continue;
        }
        //split_fast2(buf, 102400, '\t', items);
        line = buf;
        vsize = split_fast3(line, '\t', items);
        //printf("items size=%d\n", items.size());
        //printf("items ret=%d size=%d\n", vsize, items.size());
        //printf("items ret=%d size=%d\n", vsize, items.size());
        //printf("items size=%s\n", items[17].c_str());
        //break;
    }
    fclose(fp);
    delete buf;
}

int main() {
    struct timeval start_tv;
    struct timeval end_tv;
    gettimeofday(&start_tv, NULL);
    /* string s; */
    uint64_t i = 11689811695265249315l;
    string s(i);
    string tmp_s = to_string(i);
    printf("%s\n", s.c_str());
    printf("%s\n", tmp_s.c_str());
    gettimeofday(&end_tv, NULL);
    time_t cost_mget = (end_tv.tv_sec - start_tv.tv_sec) * 1000
        + (end_tv.tv_usec - start_tv.tv_usec) / 1000;
    printf("fread file COST:%dms\n", cost_mget);
    return 0;
}
