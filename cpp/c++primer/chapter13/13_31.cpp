#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class HasPtr
{
	friend void swap(HasPtr &lhs, HasPtr &rhs);
	private:
		string *ps;
		int i;
	public:
		HasPtr(const string &s=string(),int n = 0) : ps(new string(s)),i(n){}//默认构造函数赋初值 ，和成员初始化列表的方式进行初始化
		HasPtr(const HasPtr &hp);
		HasPtr &operator = (HasPtr rhs);
		bool operator<(const HasPtr &rhs);//
		~HasPtr();
		void show() const{cout <<"*ps="<<*ps<<",i="<<i<<endl;}
};


HasPtr::HasPtr(const HasPtr &hp)
{
	ps = new string(*hp.ps);
	i = hp.i;
};

HasPtr &HasPtr::operator = (HasPtr rhs)
{
	cout<<"="<<endl;
	swap(*this,rhs);
	return *this;


};

bool HasPtr::operator<(const HasPtr &rhs)//小于号运算符的重载函数
{
	cout<<"<"<<endl;
	return *ps < *rhs.ps;
}
HasPtr::~HasPtr()
{
	delete ps;

};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	cout<< "swap class object"<< endl;
	swap(lhs.ps,rhs.ps);
	swap(lhs.i,rhs.i);

};
int main(void)
{
	vector<HasPtr> vhp= {{"3"},{"8"},{"1"},{"6"}};//{{"hello world"},{"good morning"},{"i love you"},{"bigfly"}};//其中i的值采用默认构造函数的初始值 即i=0
	
	for(const auto &tmp : vhp)
	{
		tmp.show();

	}
	
	cout<<"-----------"<<endl;
	
	sort(vhp.begin(),vhp.end());

	for(const auto &tmp :vhp)
		tmp.show();

	return 0;
}
