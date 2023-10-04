#include "13_43.h"
#include <typeinfo>

//using namespace std;

StrVec::StrVec(const StrVec &rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	elements = newdata.first;
	first_free = cap = newdata.second;


}

StrVec::StrVec(initializer_list<string> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;


}

StrVec &StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;	
	return *this;
}

StrVec::~StrVec()
{
	free();
}
pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e-b);
	return {data, uninitialized_copy(b, e, data)};


}

void StrVec::free()
{
	if(elements)
	{
		//for(auto p = first_free; p !=elements;)
		//	alloc.destroy(--p);//为什么是--p呢？  因为first_free指向的是 未构造的第一个元素，也就是想要释放第一个元素之后的位置。
		for_each(elements, first_free, [&](string &s){alloc.destroy(&s);});
		alloc.deallocate(elements, cap - elements);

	}

}
void StrVec::reallocate()
{
	size_t i;
	auto newcapacity = size() ? 2*size() :1;//申请内存空间的规则，这里是2倍原来的空间
	auto newdata = alloc.allocate(newcapacity);//申请空间,返回值newdata指向 内存空间首地址的前一个位置
	
	auto dest =newdata;//为了保留 newdata、elements的起始位置 ，拷贝新的变量用来进行迁移数据操作, 这里是初始化而不是赋值！
	auto elem =elements;
	for(i = 0; i != size(); ++i)//++i是没执行一次循环后执行的，记得之前看到过书中写道++i前置递增的效率是比 i++要高的，唯一的区别是i++后置递增保存临时变量，可以使用
		alloc.construct(dest++,std::move(*elem++));//将原来空间中的数据，移动到新的内存空间
	free();
	elements = newdata;//赋值  应该是浅拷贝吧 
	first_free =dest;
	cap =elements + newcapacity; //这里面由强制类型转换 是将newcapacity转化为 cap对应的格式, 因为newcapacoty是size_t（long unsigned int）类型，而cap  是string * 类型。 要对其进行转换  ，指针的类型和其所指对象的 类型没有必然联系。所指对象的类型是由对象的实际类型决定的

}

void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++,s);

}

void StrVec::reserve(size_t n)
{
	size_t i;
	if(n <=capacity())
		return ;
	
	
	auto newdata = alloc.allocate(n);
	
	auto dest =newdata;
	auto elem =elements;
	for(i = 0; i != size(); ++i)
		alloc.construct(dest++,std::move(*elem++));
	free();
	elements = newdata;
	first_free =dest;
	cap =elements + n; 



}

void StrVec::resize(size_t n)
{
	if(n >size())
	{
		while(size() <n)
			push_back("");

	}
	else if(n<size())
	{
		while(size() >n)
			alloc.destroy(--first_free);
	}

}
int main(void)
{
	string s1 ="hello world i am bigfly";
	string s2 ="hello world i am bigfly";
	auto a= StrVec();
	a.push_back(s1);
	cout << a.begin()<<endl<<a.end()<<endl<<a.size()<<endl;
	a.push_back(s1);
	cout<<a.size()<<endl;
	//StrVec::reserve(2);
}
