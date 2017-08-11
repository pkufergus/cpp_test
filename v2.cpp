#include <iostream>
using namespace std;
class Base
{
public:
    // 虚函数func1
    virtual void func1() { cout << "Base::func1()" << endl; }
    // 虚函数func2
    virtual void func2() { cout << "Base::func2()" << endl; }
    // 虚函数func3
    void func3() { cout << "Base::func3()" << endl; }
    // 虚函数func3
    virtual void func4() { cout << "Base::func4()" << endl; }
    void func5() { cout << "Base::func5()" << endl; }

    int a;
};
class Base2 : public Base
{
    void func1() { cout << "Base2::func1()" << endl; }
};

int main()
{
    typedef void(*pFunc)(void);

    cout << "virtual function testing:" << endl;
    Base b;
    b.a = 123;
    cout << "虚函数表地址：" << (int *)(&b) << endl;
    pFunc pfunc;
    pfunc = (pFunc)*((int *)(*((int *)(&b))));
    pfunc();
    cout << "虚函数表地址：func1:" << (int *)pfunc << endl;
    cout << "虚函数表地址：func1:" << (int *)(*((int *)(&b))) << endl;
    cout << "虚函数表地址：func1:" << (int *)*((int *)(*((int *)(&b)))) << endl;
    cout << "虚函数表地址：func2:" << (int *)*((int *)((int *)(&b)) + 1) << endl;
    int *p = (int *)*((int *)(*((int *)(&b))));
    cout << "虚函数表地址：func2:" << p << endl;
    cout << "虚函数表地址：func2:" << (int *)*p << endl;
    uint64_t *p2 = (uint64_t *)((int *)(&b));
    cout << "虚函数表地址：func2:" << p2<< endl;
    cout << "虚函数表地址：func2:" << p2 + 1<< endl;
    cout << "虚函数表地址：func2:" << (uint64_t *)*(p2 + 1)<< endl;
    
    //pfunc = (pFunc)*((int *)(*((int *)(&b))) + 1);
    //pfunc();
    pfunc = (pFunc)*((int *)(*((int *)(&b))) + 2);
    pfunc();
    pfunc = (pFunc)*((int *)(*((int *)(&b))) + 4);
    pfunc();
    cout << "虚函数表地址：f3:" << ((int *)(&b) + 1) << endl;
    cout << "虚函数表地址：f3:" << *((int *)(&b) + 1) << endl;
    cout << "虚函数表地址：f3:" << ((int *)(&b) + 2) << endl;
    cout << "虚函数表地址：f3:" << *((int *)(&b) + 2) << endl;
    pfunc = (pFunc)*((int *)(&b) + 2);
    cout << "虚函数表地址：f3:" << ((int *)(&b) + 3) << endl;
    cout << "虚函数表地址：f3:" << (int *)*((int *)(&b) + 3) << endl;
    cout << "虚函数表地址：f3:" << ((int *)(&b) + 4) << endl;
    cout << "虚函数表地址：f3:" << (int *)*((int *)(&b) + 4) << endl;
    cout << "虚函数表地址：f3:" << ((int *)(&b) + 6) << endl;
    cout << "虚函数表地址：f3:" << (int *)*((int *)(&b) + 6) << endl;
    pfunc = (pFunc)*((int *)(&b) + 4);
    void (Base:: *pf)() = &Base::func3;
    cout << "函数地址：pf:" << pf << endl;
    pf = &Base::func5;
    //cout << "函数地址：pf:" << (int *)pf << endl;
    (b.*pf)();
    Base c;
    cout << "虚函数表地址：c:" << (int *)(&c) << endl;
    pfunc = (pFunc)*((int *)(*((int *)(&c))));
    pfunc();
    cout << "虚函数表地址：func1:" << (int *)pfunc << endl;
}
