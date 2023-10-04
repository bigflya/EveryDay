#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>//count_if
using namespace std;


class StrLen
{
	private:
		int n;
	
	public:
		StrLen(int i= 0):n(i){}
		bool operator()(const string &str){return str.size() ==n;}


};

int main(void)
{

	ifstream ifs("1.txt");
	vector<string> svec;

	string str;

	while(ifs >>str)
	{
	svec.push_back(str);

	
	}

	for(int i = 1; i!=11; i++)
		cout <<count_if(svec.begin(),svec.end(),StrLen(i)) <<" ";
	cout << endl;
	
	return 0;



}
