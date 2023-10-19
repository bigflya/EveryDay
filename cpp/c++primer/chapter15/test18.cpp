#include <iostream>


using namespace std;

class Base{


};


class D1 : public Base{


};


class D2 :protected Base{


};


class D3 :private Base{


};


int main(void){

    D1 d1;
    D2 d2;
    D3 d3;

    Base B1 =d1;
    //Base B2 =d2;//不允许受保护的派生类成员转换成相应的基类
    //Base B3 =d3;//同上，不允许私有的派生类成员转换成相应的基类
    return 0;
}