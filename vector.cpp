#include <iostream>
#include <vector>
#include <map>
#include <unistd.h>
#include <memory.h>
using namespace std;

class Node {
public:
    vector<float> f_v;
};
void TestVector() {
  cout<<"begin vector"<<endl;
  size_t size = 2000000000;
  vector<int> test_vec;
  vector<int>().swap(test_vec);
  vector<float> f_vec;
  vector<float>().swap(f_vec);
  Node *n = new Node;
  vector<float>().swap(n->f_v);
  memset(n, 0, sizeof(class Node));
  vector<float>().swap(n->f_v);
  cout<<"end vector"<<endl;
}

int main() {
    TestVector();
}
