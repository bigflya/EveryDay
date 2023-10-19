#include <iostream>


class B{



};

//class D:public B{
//class D:private B{
class D:protected B{

friend void f1();

void f2();
};


void D::f2(){

    B *b = new D;
}


void f1(){

   B *b = new D;
}
int main(void){


}