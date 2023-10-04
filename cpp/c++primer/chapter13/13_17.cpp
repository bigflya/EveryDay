#include <iostream>

using namespace std;

class numbered
{
	private:
	static int id;//全局属性
	public:
		int mysn;
		numbered(){mysn = id++;}
		numbered(const numbered &n){mysn = id++;}
		numbered &operator=(const numbered &n){mysn =id++;}//拷贝赋值运算符，返回一个引用

};
int numbered::id = 0;

//void f(numbered s)//会调用拷贝构造函数
void f(numbered &s)
{
	cout <<s.mysn <<endl;

}
int main(void)
{
	numbered a,b=a,c=b;
	f(a);
	f(b);
	f(c);
	return 0;
}
