#include <iostream>
#include <string>


using namespace std;

class HasPtr
{
	private:
		string *ps;
		int i;
		size_t *use;

	public:
		HasPtr(const string &s = string()) : ps(new string(s)),i(0), use(new size_t(1)){};
		HasPtr(const HasPtr &p) : ps(p.ps),i(p.i),use(p.use){++*use;};
		HasPtr &operator = (const HasPtr &rhs);//拷贝复制运算符重载函数，函数体比较大所以写在外部
		~HasPtr();



};//类的后面要加上分号

HasPtr &HasPtr::operator = (const HasPtr &rhs)
{
	++*rhs.use;
	if(--*use==0)
	{
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i =rhs.i;
	use = rhs.use;

	return *this;

}

HasPtr::~HasPtr()
{
	if(--*use==0)
	{
		delete ps;
		delete use;
	}

}

int main()
{

	return 0;
}
