class ReadString
{
	private:
		istream &is;

	public:
		ReadString(istream &i =cin): is(i){}
		string operator()()
		{	
			string str;
			if(!getline(is,str))
				str ="";
			return str;
		}//不带参数的运算符重载函数


};
