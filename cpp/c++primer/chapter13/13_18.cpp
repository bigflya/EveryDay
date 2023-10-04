

class Employee
{
	private:
		static int id;
		string name;
		int mysn;
	public:
		Employee(){mysn = id++;}
		Employee(const string &s){name = s; mysn =id++;}


};
