#include <iostream>

using namespace std;


class base{
public:
    virtual int fcn(){return 0;}
    virtual int fcn(int i){cout<<i+1<<endl; return i+1;}

};

class D1:public base{
public:
    using base::fcn;//覆盖掉部分的做法如下
    int fcn(){return 1;}
    

};

int main(void){

    D1 d1;
    d1.fcn(10);////此处会将base中带参数的版本覆盖,解决这个问题的方法是要么全部覆盖要么一个都别写

    

    return 0;
}