#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>
using namespace std;

class StrBlobPtr;
class StrBlob
{
	friend class StrBlobPtr;
	private:
		shared_ptr< vector<string> > data;
		void check(vector<string>::size_type i, const string &msg) const;

	public:
		StrBlob();
		StrBlob(initializer_list<string> il);
		StrBlob(const StrBlob &s);
		StrBlob &operator=(const StrBlob &rhs);
		vector<string>::size_type size() const{return data->size();}
		bool empty() const{return data->empty();}
		void push_back(const string &str){data->push_back(str);}
		void pop_back();
		string &front();
		string &back();
		const string &front() const;
		const string &back() const;
		StrBlobPtr begin();
		StrBlobPtr end();

};

StrBlob::StrBlob() : data(make_shared<vector<string>>()){}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)){}


StrBlob::StrBlob(const StrBlob &s) : data(make_shared< vector<string> >(*s.data)){}//智能指针不能用new 要用make_shared
StrBlob &StrBlob::operator = (const StrBlob &rhs)
{
	data = make_shared<vector<string>>(*rhs.data);
	return *this;
}
void StrBlob::check(vector<string>::size_type i,const string &msg) const
{
	if(i>= data->size())
		throw out_of_range{msg};
}

void StrBlob::pop_back()
{
	check(0,"pop_back on empty StrBlob");
	data->pop_back();
}

int main()
{
	return 0;
}

