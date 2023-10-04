#include <iostream>

HasPtr::HasPtr(const HasPtr &hp)
{
ps = hp.ps;  //浅拷贝
ps = new string(*hp.ps);/深拷贝


}


HasPtr &HasPtr::operator=(const HasPtr &hp)
{
	if(this ==&hp)
		return *this;

	delete ps;
	ps = new string(*hp.ps);
	i = hp.i;
	return *this;


}

HasPtr::~Hasptr()
{
	delete ps;// 直接析构的话ps指针不会释放  ，new出来的动态内存要自己动手释放。

}
