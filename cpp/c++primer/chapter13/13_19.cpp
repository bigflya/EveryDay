

class Employee
{
	private:
		static int id;
		string name;
		int mysn;
	public:
		Employee(){mysn = id++;}
		Employee(const string &s){name = s; mysn =id++;}
		Employee(Employee &e){name = e.name;mysn = id++;}//拷贝构造函数

		//可以改名 但是不能改id ，所以 return *this
		Employee &operator = (Employee &rhs){name = rhs.name;return *this; }//拷贝赋值运算符重载

};
