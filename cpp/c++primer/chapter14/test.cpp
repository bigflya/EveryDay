#include <iostream>

using namespace std;

class A
{
	public:
		void mem()
		{
			cout<< "mem in class A!"<< endl;
		}



};


int main(void)
{

	A *point  = new A;
	point->mem();//point是指向某一个类的对象的指针，通过对这个指针使用 箭头运算符 来实现成员函数的访问。
	(*point).mem();//上面的等价写法
	
	return 0;
}
