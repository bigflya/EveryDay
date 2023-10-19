#include <iostream>
#include <string>

using namespace std;

template<typename T,unsigned int N>
void print(const T (&r)[N])
{
		for(auto pt = begin(r);pt !=end(r); pt++)
			cout<<*pt<<" ";
		cout<<endl;
}
int main()
{
	
	int arr[5] = {1,2,3,4,5};
	string str[4] = {"hello","world","good","morning"};

	print(arr);
	print(str);

	return 0;
}
