#include <iostream>
#include <string>


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
	swap(*this,rhs);
	return *this;


};

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
	HasPtr hp1("hello world",1);
	HasPtr hp2("good morning",2);
	swap(hp1,hp2);

	hp1.show();
	hp2.show();
	return 0;
}
