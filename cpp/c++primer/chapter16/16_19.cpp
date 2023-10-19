#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(const T &r)
{
    for(typename T::size_type i=0;i<r.size();i++)//用T这个容器里面的类型， 把它当作一个类型而不是一个变量
        cout<<r[i]<<" ";
    cout<<endl;

}

int main(void){
    vector<int> ivec={1,2,3,4,5};
    print(ivec);

    return 0;
}