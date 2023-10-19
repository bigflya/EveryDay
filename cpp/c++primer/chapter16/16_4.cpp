#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template<typename I,typename T>
I find(I b,I e,const T &r)
{
        auto iter=b;
    for(; iter !=e; iter++)
    {
        if(*iter ==r)
            break;

    }
    return iter;


}


int main(void){

    vector<int> ivec ={1,2,3,4,5};
    list<string> slist = {"hello", "world","good","morning"};
    
    auto iter = find(ivec.begin(),ivec.end(),3);
    if(iter ==ivec.end())
        cout<<"cannot find"<<endl;
    else
        cout<<"find it"<<endl;
    
    auto iter1 = find(slist.begin(),slist.end(),"world");
    if(iter1==slist.end())
        cout<<"cannot find"<<endl;
    else
        cout<<"find it"<<endl;

    return 0;
}