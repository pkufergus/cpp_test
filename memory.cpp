#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unistd.h>
using namespace std;
void TestVector() {
 
  cout<<"begin vector"<<endl;
  size_t size = 2000000000;
  vector<int> test_vec;
  for (size_t i = 0; i < size; ++i) {
        test_vec.push_back(i);
  }
  cout<<"create vector ok"<<endl;
  sleep(30);
  cout<<"clear vector"<<endl;
  // 你觉得clear 它会降低内存吗？
  test_vec.clear();
  sleep(30);
  cout<<"swap vector"<<endl;
  {
        vector<int> tmp_vec;
        // 你觉得swap它会降低内存吗？
        test_vec.swap(tmp_vec);
  }
  sleep(30);
  cout<<"end test vector"<<endl;
}

void TestMap() {
  cout<<"begin map"<<endl;
  size_t size = 100000000;
  unordered_map<int, int> test_map;
  for (size_t i = 0; i < size; ++i) {
        test_map[i] = i;
  }
  cout<<"create map ok"<<endl;
  sleep(10);
  cout<<"clear map"<<endl;
  // 你觉得clear 它会降低内存吗？
  test_map.clear();
  cout<<"clear map end"<<endl;
  sleep(10);
  cout<<"swap map"<<endl;
  {
         // 你觉得swap它会降低内存吗？
        unordered_map<int,int> tmp_map;
        tmp_map.swap(test_map);
  }
  cout<<"swap map end"<<endl;
  sleep(10);
  cout<<"end test map"<<endl;
}

const int N = 128;
class Node {
    public:
        char a[N];
};
void TestPtrMap() {
  cout<<"begin map"<<endl;
  size_t size = 10000000;
  string val = "1234567890123456789012345678901";
  unsigned long long vid = (unsigned long long)15219601032230891217;
  unordered_map<uint64_t, Node> *ptest_map = new unordered_map<uint64_t, Node>();
  for (size_t i = 0; i < size; ++i) {
      uint64_t key = vid + i;
      for (int j = 0; j < N; j++ ) {
          (*ptest_map)[key].a[j] = i;
      }
  }
  cout<<"create map ok"<<endl;
  sleep(10);
  cout<<"clear map"<<endl;
  // 你觉得clear 它会降低内存吗？
  ptest_map->clear();
  cout<<"clear map end"<<endl;
  sleep(10);
  cout<<"swap map end"<<endl;
  sleep(10);
  delete ptest_map;
  cout<<"delete map end"<<endl;
  for (;;) {}
  cout<<"end test map"<<endl;
}

int main() {
    //TestVector();
    char buf[687091];
    TestPtrMap();
    return 0;
}
