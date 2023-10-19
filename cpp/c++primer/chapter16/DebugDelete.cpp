#include <iostream>
#include "DebugDelete.h"
#include <memory>

using namespace std;
int main(void){

    double* p = new double;
    DebugDelete d;
    d(p);  //方法1 调用对象d进行删除
    int* ip = new int;

    //方法2 在一个临时的DebugDelete对象上调用DebugDelete()(int*)
    DebugDelete()(ip);//这里可以充分理解 operator()就相当于 DebugDelete()  就是一个函数

    //方法3 调用DebugDelete作用 unique_ptr的删除器
    unique_ptr<int, DebugDelete> pp(new int,DebugDelete());


// void DebugDelete::operator()(int *p) const{delete p;}

    return 0;
}

