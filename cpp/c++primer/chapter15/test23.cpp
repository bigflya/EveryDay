#include <iostream>
//继承的构造函数
using namespace std;

class Base{
public:
    Base(){cout<<"Base()"<<endl;}
    Base(const Base &r){cout<<"Base &r"<<endl;}
    explicit Base(int i):n(i){cout<<"explicit Base(int)"<<endl;}//禁止隐式转换

private:
    int n;
};

class Derived:public Base{
public:
/*  方法一
    Derived():Base(){}
    Derived(const Derived &r):Base(r){}
    explicit Derived(int i):Base(i){} */


    /*方法二*/
    using Base::Base;
};

int main(void){

    Derived d1;
    Derived d2(5);
    Derived d3(d2);
    return 0;
}