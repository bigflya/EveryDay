#include <iostream>
#include <vector>
#include <string>

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

int main(void){

    vector<int> ivec = {1,2,3,4,5,2,3,4,5,7,8,9};
    cout<<occur(ivec,2)<<endl;

    vector<string> svec ={"hello","bigfly","good","evening","hello","bigfly"};
    string str("good");
    cout<<occur(svec,str)<<endl;

    return 0;
}