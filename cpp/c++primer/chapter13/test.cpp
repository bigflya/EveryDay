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
		Point &operator=(const Point &point)
		{
			cout<<"overrided operator"<<endl;
			
			return *this;//this 是指针不能直接返回指针，要对其进行解引用
		}

};


int main(void)
{
	Point x;//默认构造函数
	Point y(x);//拷贝构造函数

	Point tmp;//默认构造函数
	tmp = y;//重载赋值运算符

	Point w =x;//拷贝构造函数	
	return 0;
}


