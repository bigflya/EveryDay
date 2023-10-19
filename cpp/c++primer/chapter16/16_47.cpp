#include <iostream>

using namespace std;

void f(int v1,int &v2){


}

void g(int &&i,int &j)
{


}
template <typename F, typename T1,typename T2>
void flip2(F func, T1 &&t1, T2 &&t2)
{
    //func(t2,t1);
    func(std::forward<T2>(t2),std::forward<T1>(t1));
}

int main(void){

    int j=10;
    flip2(f,j,42);//正确:j和42在给f传递参数的时候，相当于把左值（这里实际看起来是右值引用的形参，但是函数参数与其他任何变量一样，都是左值表达式。）传递给左值和左值引用，所以是成立的
    flip2(g,j,42);//错误:j和42在给g传参的时候相当于把左值传递给g的右值引用形参，是错误的

    return 0;
}