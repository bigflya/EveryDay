#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;


map<string,function<int(int,int)>> binops = 
{
	{"+",plus<int>()},//plus<int> 是标准库中 的类型   ，plus<int>() 是其产生的匿名的对象
	{"-",minus<int>()},
	{"*",multiplies<int>()},
	{"/",divides<int>()}


};



int main(void)
{


	
	cout<<"this is a calculato," << endl << "example: you can input 3+2 and end with Enter Key,the terminal will out put 5"<<endl;
	string s;
	

	cin >> s;
	stringstream ss(s);
   	 int num1, num2;
  	  char op;
  	  ss >> num1 >> op >> num2;
	cout<< binops[string(1, op)](num1,num2)<<endl;

	return 0;


}
