class Tree
{
    private:
        string name;
        double height;
        unsigned int age;
    public:
        Tree() = default;
        Tree(const string &nm, double h, unsigned int a):name(nm),height(h),age(a){}
	
	explicit operator bool() const
	{

		return (name !="") &&(height>0)&& (age>=0);
	}


};
