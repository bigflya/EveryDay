

class  Sales_data
{
	friend istream &operator>>(istream &is,Sales_data &sa);
	friend ostream &operator<<(ostream &os,const Sales_data &sa);
	friend Sales_data operator+(const Sales_data &sa,const Sales_data &sb);

	public:
		Sales_data &operator+=(const Sales_data &sa);

};
