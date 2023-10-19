#include <iostream>

using namespace std;

class AA{

public:
    virtual void print() const =0;//纯虚函数
};

class BB : public AA{
public:
    virtual void print() const override{cout<<"hello"<<endl;}//virtual在这里是可以不用写的

};


int main(void)
{
    AA aa;

    return 0;

}