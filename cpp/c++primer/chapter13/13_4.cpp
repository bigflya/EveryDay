# include <iostream>

using namespace std;

class Point
{
	public:
		Point()
		{
			cout<< "class create"<< endl;
		}
		Point(const Point&point)
		{
			cout<<"class copy"<<endl;
		}


};
//拷贝构造函数调用的场景之一：将一个对象作为实参传递给一个非引用类型的形参，会调用拷贝构造函数
Point func(Point arg)// 在将实参传递给 arg时候，调用一次拷贝构造函数。(函数按值传递对象，使用拷贝构造函数)
{
	Point local = arg;//调用拷贝构造函数 ，总结：当函数按值传递或者函数返回对象时都会调用拷贝构造函数。
	Point *heap = new Point(arg);//调用拷贝构造函数，用类创建一个指向此类的指针，也会调用拷贝构造函数
	*heap =local;// 给heap赋值，不会调用拷贝构造函数。这里调用赋值运算符重载。
	Point pa[4] = {local, *heap};//前两个元素调用拷贝构造函数，后两个元素没有指定，调用默认构造函数
	return *heap;//调用拷贝构造函数
}


int main(void)
{
	Point x;//默认构造函数
	func(x);
	return 0;
}
