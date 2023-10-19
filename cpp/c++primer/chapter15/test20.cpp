#include <iostream>

using namespace std;


class B{


};




class D: protected B{

friend void f1();
void f2(){B *b = new D;}
};

class E : private D{
friend void ff1();
void ff2(){B *b = new D;}

};


void ff2(){

B *b = new D;

}
void f1(){

   B *b = new D;
}
int main(void){


    return 0;
}