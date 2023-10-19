#include <iostream>

using namespace std;

template<typename T>
int compare(const T,const T){

    return 0;
}


int main(void){

 

    compare("hi","bigfly");//引用是不能编译通过的，除非两个字符串长度相等
    return 0;
}