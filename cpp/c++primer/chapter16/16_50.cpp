#include <iostream>


using namespace std;


template <typename T>
void g(T)
{
    cout<<"call g(T)"<<endl;
}

template <typename T>
void g(T *)
{
    cout<<"call g(T *)"<<endl;
}

template <typename T>
void f(T )
{
    cout<<"call f(T)"<<endl;
}

template <typename T>
void f(const T *)
{
    cout<<"call f(T *)"<<endl;
}


int main(void){
    int i =42,*p= &i;
    const int ci = 0,*p2 =&ci;

    g(42);
    g(p);
    g(ci);
    g(p2);
    f(42);
    f(p);//调用的是T因为  要是const 的话会进行一次转换,f(T)-->int *   f(const T*)----> T:int
    f(ci);
    f(p2);
    return 0;
}