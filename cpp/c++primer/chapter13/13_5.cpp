#include <iostream>

HsaPtr::HasPtr(const HasPtr &hp)
{
ps = hp.ps;  //浅拷贝
ps = new string(*hp.ps);/深拷贝


}
