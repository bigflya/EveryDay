#include <iostream>
//此程序有段错误，原因在没有定义拷贝构造函数，
using namespace std;

class HasPtr
{
	private:
		string *ps;
		int i;
	public:
		HasPtr(const string &s = string()) :ps(new string(s)),i(0){}
		HasPtr(const HasPtr &hp);
		HasPtr &operator=(const HasPtr &hp);
		~HasPtr(){delete ps;}

};

HasPtr::HasPtr(const HasPtr &hp)//拷贝构造函数
{
	ps = new string(*hp.ps);
	i = hp.i;

}

HasPtr &HasPtr::operator=(const HasPtr &hp)//拷贝赋值运算符函数
{
	if(this ==&hp)
		return *this;

	delete ps;
	ps = new string(*hp.ps);
	i = hp.i;
	return *this;


}

int main(void)
{
	HasPtr p("hello world!");
	HasPtr hp = p;
// 此时hp指针所指的对象与p是同一个，这样当调用析构函数的时候，先析构p  释放掉ps 和i所指的动态内存空间，然后析构hp,此时hp中的对象所指的内存空间已经被释放掉了，二次释放会报错

	return 0;

}
