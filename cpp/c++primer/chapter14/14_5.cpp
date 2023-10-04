
class Tree
{
	friend bool operator==(const Tree &t1,const Tree &t2);
	private:
		string name;
		double height;
		unsigned int age;
	public:
		Tree() = default;
		Tree(const string &nm, double h,unsigned int a ) : name(nm),height(h), age(a){}


};


bool operator==(const Tree &t1,const Tree &t2)
{
	if(t1.name ==t2.name &&t1.height ==t2.height &&t1.age==t2.age)
		return true;
	return false;


}
