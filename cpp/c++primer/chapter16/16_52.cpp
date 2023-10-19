#include <iostream>

using namespace std;

template <typename T,typename...Args>
void foo(const T &t,const Args...args)
{
    cout<<sizeof...(Args)<<endl;
    cout<<sizeof...(args)<<endl;
}
int main(void){
    int i =0;
    double d =3.14;
    string s="good evening bigfly";
    foo(i,s,42,d);
    foo("hi");
    return 0;
}