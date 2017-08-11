#include <iostream>
using namespace std;
class Base1
{
    public:
        virtual void func1() { cout << "Base1::func1()" << endl; }
        void func2() { cout << "Base1::func2()" << endl; }
};

class Base2 : public Base1
{
    void func1() { cout << "Base2::func1()" << endl; }
};

int main()
{
    cout << "virtual function testing:" << endl;
    Base2 b;
    Base1 *ptr = &b;
    ptr->func1();
    ptr->func2();
}
