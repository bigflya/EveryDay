#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ReadString
{
	private:
		istream &is;

	public:
		ReadString(istream &i =cin): is(i){}
		string operator()()
		{	
			string str;
			if(!getline(is,str))//从is中捕获内容存到str中
				str ="";
			return str;
		}//不带参数的运算符重载函数


};


int main(void)
{
	ReadString rs;//初始化一个对象
	
	vector<string> svec = {rs(),rs(), rs()};//这里会调用不需要参数的运算符重载函数

	for(const auto &r :svec)//范围for循环
		cout << r << " ";
	cout << endl;

	return 0;


};
