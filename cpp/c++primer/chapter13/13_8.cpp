#include <iostream>

HsaPtr::HasPtr(const HasPtr &hp)
{
ps = new string(*hp.ps);//深拷贝
i=hp.i;

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