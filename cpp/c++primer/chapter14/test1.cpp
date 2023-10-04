#include <iostream>

using namespace std;

class A
{
	public:
		A *operator->(){ return this;}//箭头返回类型必须是 指针
		void mem()
		{
			cout<< "mem in class A!"<< endl;
		}



};


int main(void)
{

	A point;//此时point 不是指针而是是类的对象，对象想调用成员的方法就是 使用运算符重载
	point->mem();
	point.operator->()->mem();//上面的等价写法  ，通过point  显式调用 operator->()函数
	return 0;
}
