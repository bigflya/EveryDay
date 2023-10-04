class Sales_data
{
	friend Sales_data operator-(const Sales_data &lhs,const Sales_data &rhs);
	

	public:
		Sales_data &operator-=(const Sales_data &rhs);//根据规则复合运算符通常定义为成员函数，而算数运算符定义为友元函数。


};


Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sub = lhs;
	sub -=rhs;
	return sub;

}


Sales_data &Sales_data::operator-=(const Sales_data &rhs)
{
	units_sold -= rhs.units_sold;
	revenue -=rhs.revenue;

	return *this;
}

