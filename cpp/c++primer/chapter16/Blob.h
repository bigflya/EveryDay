#ifndef BLOB_H
#define BLOB_H

#include <iterator>
#include <string>
#include <vector>
#include <initializer_list>//包含initializer_list模板类，它是一个访问const T类型对象数组的轻量代理对象,，可以接受可变个参数而设计的。vector 就不可以接收可变参数
#include <cstddef>//定义了一些特殊类型（如size_t），以及有用的宏函数（offsetof）等
#include <stdexcept>
#include <utility>//包含了许多与通用工具相关的函数和类模板，其中最常见的是std::pair、std::make_pair、std::swap
#include <memory>
#include <algorithm>
#include <iostream>
#include <cstdlib>


// forward declarations needed for friend declarations in Blob
template <typename> class BlobPtr;   
template <typename> class Blob; // needed for parameters in operator==
template <typename T> 
    bool operator==(const Blob<T>&, const Blob<T>&);//判断两个类型是否一样

template <typename T> class Blob 
{
	// each instantiation of Blob grants access to the version of
	// BlobPtr and the equality operator instantiated with the same type
	friend class BlobPtr<T>;
	friend bool operator==<T>
	       (const Blob<T>&, const Blob<T>&);

public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	// constructors
	Blob(); 
	Blob(std::initializer_list<T> il);
	template <typename It> Blob(It b, It e); 
	Blob(T*, std::size_t);

	// return BlobPtr to the first and one past the last elements
	BlobPtr<T> begin() { return BlobPtr<T>(*this); }
	BlobPtr<T> end() 
	    { auto ret = BlobPtr<T>(*this, data->size()); 
	      return ret; }

	// number of elements in the Blob
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	// add and remove elements
	void push_back(const T &t) {data->push_back(t);}
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();

	// element access
	T& front();
	T& back();
	T& at(size_type);
	const T& back() const;
	const T& front() const;
	const T& at(size_type) const;
	T& operator[](size_type i); 
	const T& operator[](size_type i) const;

	void swap(Blob &b) { data.swap(b.data); }
private:
	std::shared_ptr<std::vector<T>> data; 

	// throws msg if data[i] isn't valid
	void check(size_type i, const std::string &msg) const;
};

// constructors
template <typename T>
Blob<T>::Blob(T *p, std::size_t n): 
              data(std::make_shared<std::vector<T>>(p, p + n)) { }

template <typename T>
Blob<T>::Blob():
	          data(std::make_shared<std::vector<T>>()) { }

template <typename T>     // type parameter for the class
template <typename It>    // type parameter for the constructor
    Blob<T>::Blob(It b, It e):
              data(std::make_shared<std::vector<T>>(b, e)) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il): 
              data(std::make_shared<std::vector<T>>(il)) { }

// check member
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

// element access members
template <typename T>
T& Blob<T>::front()
{
	// if the vector is empty, check will throw
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
T& Blob<T>::back() 
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T> void Blob<T>::pop_back() 
{
	check(0, "pop_back on empty Blob"); 
	data->pop_back(); 
}

template <typename T>
const T& Blob<T>::front() const 
{
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
const T& Blob<T>::back() const 
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::at(size_type i) 
{
	// if i is too big, check will throw, preventing access to a nonexistent element
	check(i, "subscript out of range");
	return (*data)[i];  // (*data) is the vector to which this object points
}

template <typename T>
const T&
Blob<T>::at(size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
	// if i is too big, check will throw, preventing access to a nonexistent element
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
const T& 
Blob<T>::operator[](size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

// operators
template <typename T>
std::ostream&
operator<<(std::ostream &os, const Blob<T> a)
{
	os << "< ";
	for (size_t i = 0; i < a.size(); ++i) 
		os << a[i] << " ";
	os << " >";
	return os;
}

template <typename T>
bool
operator==(const Blob<T> lhs, const Blob<T> rhs)
{
	if (rhs.size() != lhs.size())
		return false;
	for (size_t i = 0; i < lhs.size(); ++i) {
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;
}

// BlobPtr throws an exception on attempts to access a nonexistent element 
template <typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> class BlobPtr : public std::iterator<std::bidirectional_iterator_tag,T> {
	friend bool 
	operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
    BlobPtr(): curr(0) { }
    BlobPtr(Blob<T> &a, size_t sz = 0): 
	        wptr(a.data), curr(sz) { }

	T &operator[](std::size_t i)
	{ auto p = check(i, "subscript out of range"); 
	  return (*p)[i];  // (*p) is the vector to which this object points
	}

	const T &operator[](std::size_t i) const
	{ auto p = check(i, "subscript out of range"); 
	  return (*p)[i];  // (*p) is the vector to which this object points
	}//非const版本可以修改所指向的数据，而const版本只能读取不能修改所指向的数据。当你不需要修改数据的时候，使用const版本会更安全，因为它避免了可能的错误。
    
    T& operator*() const
	{ auto p = check(curr, "dereference past end"); 
	  return (*p)[curr];  // (*p) is the vector to which this object points
	}
    T* operator->() const
	{ // delegate the real work to the dereference operator
	 return & this->operator*(); 
	}

    // increment and decrement
    BlobPtr& operator++();       // prefix operators
    BlobPtr& operator--();

    BlobPtr operator++(int);     // postfix operators
    BlobPtr operator--(int);
    
private:
	// check returns a shared_ptr to the vector if the check succeeds
	std::shared_ptr<std::vector<T>> 
		check(std::size_t, const std::string&) const;

	// store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<T>> wptr;  
    std::size_t curr;      // current position within the array
};

// equality operators
template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return lhs.wptr.lock().get() == rhs.wptr.lock().get() && 
	       lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return !(lhs == rhs);
}

// check member
template <typename T>
std::shared_ptr<std::vector<T>> 
BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();   // is the vector still around?//返回其所指对象的 shared_ptr 智能指针（对象销毁时返回"空"shared_ptr）。
	if (!ret)
		throw std::runtime_error("unbound BlobPtr");
	if (i >= ret->size()) //i=-1 表示没有一个引用，如果超过智能指针中size的计数就返回超出范围
		throw std::out_of_range(msg);
	return ret; // otherwise, return a shared_ptr to the vector
}

// member operators
// postfix: increment/decrement the object but return the unchanged value
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    // no check needed here; the call to prefix increment will do the check
    BlobPtr ret = *this;   // save the current value
    ++*this;     // advance one element; prefix ++ checks the increment
    return ret;  // return the saved state
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)//后置递增运算符++(int)是一个双目运算符，它需要一个操作数，但是需要一个int参数作为其右操作数。这个运算符会将其左操作数递增1，并将结果返回。
{
    // no check needed here; the call to prefix decrement will do the check
    BlobPtr ret = *this;  // save the current value
	--*this;     // move backward one element; prefix -- checks the decrement
    return ret;  // return the saved state
}

// prefix: return a reference to the incremented/decremented object
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	// if curr already points past the end of the container, can't increment it
	check(curr, "increment past end of BlobPtr");
    ++curr;       // advance the current state
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	// if curr is zero, decrementing it will yield an invalid subscript
    --curr;       // move the current state back one element
    check(-1, "decrement past begin of BlobPtr");
    return *this;
}




#endif