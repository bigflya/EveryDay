#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class  Foo
{
	public:
		Foo sorted() &&;
		Foo sorted() const &;
	private:
		vector<int> data;

};


Foo Foo::sorted() &&
{
	cout <<"&&"<<endl;
	sort(data.begin(),data.end());
	return *this;

}



Foo Foo::sorted() const &
{
	cout << "&"<<endl;
	//Foo ret(*this);
	//return ret.sorted();//无限递归

	return Foo(*this).sorted();//此处是右值
}

int main(void)
{

	Foo f;
	f.sorted();

	return 0;
}
