#include <iostream>

using namespace std;


class AA{
public:
    AA(){a=10;b=20;}

protected:
    int a;
    void print(){cout<<"a="<<a<<"b="<<b<<endl;}
private:
    int b;

};


int main(void){

    AA aa;

    aa.print();

    return 0;

}