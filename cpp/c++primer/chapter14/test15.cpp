#include <iostream>

using namespace std;


class A
{

	friend int operator+(A &a,int x); //用定义的普通函数实现的，但是为了访问到私有成员n ，需要将其定义为友元函数。

	private:
		int n;

	public:
		A():n(10){}
		operator int() const{return n;}//通过类型转换运算符，调用内置类型转换符
		int operator+(int x){return this->n +x;}//定义一个加法运算符重载运算符
};

int operator+(A &a,int x)
{
	return a.n +x;

}




int main(void)
{
	A a;

//	cout <<a + 20<<endl;  //如果三种方式同时生效此时会报错，编译器不知道该调用哪个 ,


	// 调用下面两句则不会发生重载冲突  。
	cout << a.operator+(20) <<endl;
	cout << operator+(a,20) <<endl;

	return 0;



};

