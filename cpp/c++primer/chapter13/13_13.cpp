# include <iostream>
# include <vector>
using namespace std;

class Point
{
	public:
		Point()//默认构造函数
		{
			cout<< "class create"<< endl;
		}
		Point(const Point&point)//拷贝构造函数
		{
			cout<<"class copy"<<endl;
		}
		Point &operator=(const Point &point)//赋值运算符重载函数
		{
			cout<<"overrided operator"<<endl;
			
			return *this;//this 是指针不能直接返回指针，要对其进行解引用
		}
		~Point()
		{
			cout<<"destruct function"<<endl;	
		}
};

void f1(Point p)
{
	cout<<"f1 without ref Point"<<endl;
}

void f2(Point &p)
{
	cout <<"f2 with ref Point"<<endl;
}


int main(void)
{
	Point x;//调用一次构造函数和一次析构函数
	//f1(x);
	f2(x);//引用的方式不创建析构函数销毁的时候也不调用析构函数

//	Point *pt= new Point(x);// 此时，开辟动态内存并初始化，会执行 拷贝构造函数
//	Point *pt1 = new  Point;//开辟了动态空间但是没有给初始值,此时不会执行拷贝构造函数，会执行默认构造函数
	vector<Point> vp;
	vp.push_back(x);//相当于用x初始化vp_0此时会调用拷贝构造函数， 当容器被销毁的时候其里面的元素也被销毁掉，执行相应的析构函数
//	delete  pt;//手动释放new 分配的动态内存空间
	return 0;
}


