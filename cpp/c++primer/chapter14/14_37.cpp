#include <iostream>
#include <vector>
#include <algorithm> //replace_if
using namespace std;

class Comp
{
	private:
		int a;
	public:
		Comp(int n=0):a(n){}
		bool operator()(int ivec_n ){return a ==ivec_n;}

};


int main(void)
{
	vector<int> ivec = {1,2,3,4,5,4,3,2,1};
	replace_if(ivec.begin(), ivec.end(), Comp(2),222);
	
	for(const auto &r :ivec)//范围for循环
		cout << r << " ";
	cout << endl;
	return 0;


}

