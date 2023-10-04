#ifndef __13_39_H__
#define __13_39_H__

#include <string>
#include <iostream>
#include <memory>
using namespace std;

class StrVec
{
	private:
		string *elements;
		string *first_free;
		string *cap;
		allocator<string> alloc;
		
		pair<string *,string *> alloc_n_copy(const string *,const string *);
		void free();
		void reallocate();
		void chk_n_alloc(){if(size() == capacity()) reallocate();}//检查空间是否用完，如果用完则调用reallocate() 重新分配空间
	public:
		//各种构造函数
		StrVec() : elements(nullptr), first_free(nullptr),cap(nullptr){}
		StrVec(const StrVec &);//拷贝构造函数
		StrVec &operator=(const StrVec &);
		~StrVec();

		void push_back(const string &);
		//一些小函数方便调用
		size_t size() const{return first_free -elements;}
		size_t capacity() const{return cap -elements;}
		string *begin() const{return elements;}
		string *end() const{return first_free;}
		void reserve(size_t n);
		void resize(size_t n);
};

#endif
