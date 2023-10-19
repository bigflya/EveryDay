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

class BB : public AA{
public:
    BB():AA(),c(30){}
    void show();

private:
    int c;


};

void BB::show(){
    print();//调用基类中受保护的成员函数
    cout<<"c="<<c<<endl;
}

int main(void){

     AA aa;
    BB bb;
    bb.show();
    // aa.print();

    return 0;
}
