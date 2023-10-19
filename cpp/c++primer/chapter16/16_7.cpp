#include <iostream>

using namespace std;

template<typename T,unsigned int N>
constexpr int arr_size(const T (&r)[N])
{

        return N;
}
int main(void)
{
    int arr[5] = {1,2,3,4,5};
	string str[4] = {"hello","world","good","morning"};

    cout<<arr_size(arr)<<endl;
    cout<<arr_size(str)<<endl;

    return 0;
}