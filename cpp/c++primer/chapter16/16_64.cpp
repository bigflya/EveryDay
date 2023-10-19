#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

template <typename T>
int occur(vector<T> &vec, const T &val){
    int cnt =0;
    for(auto r:vec)
    {
        if(r==val)
            cnt++;

    }
    return cnt;

}


template <>
int occur(vector<const char *> &vec,const char * const &val)
{
    int cnt = 0;
    for(auto r:vec)
    {
        if(!strcmp(r,val))//相等返回0
            cnt++;
    }
    cout <<"i love you ,rick!"<<endl;

    return cnt;

}
int main(void){

    vector<int> ivec = {1,2,3,4,5,2,3,4,5,7,8,9};
    cout<<occur(ivec,2)<<endl;

    vector<string> svec ={"hello","bigfly","good","evening","hello","bigfly"};
    string str("good");
    cout<<occur(svec,str)<<endl;


    vector<const char *> strvec ={"hello","bigfly","good","evening","hello","bigfly"};
    const char *pt("hello");
    cout<<occur(strvec,pt);

    return 0;
}