#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(const T &r)
{
    for(auto iter = r.begin();iter !=r.end();iter++)
        cout<<*iter<<" ";
    cout<<endl;

}

int main(void){
    vector<int> ivec={1,2,3,4,5};
    print(ivec);

    return 0;
}