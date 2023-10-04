

class ShorterString
{
	public:
		bool operator()(const string &s1, const string &s2) const
		{
			return s1.size() < s2.size();
		}


}；

class SizeComp
{
	public:
		SizeComp(size_t n): sz(n) {} //该形参对应捕获的变量

		//该调用运算符的返回类型、形参和函数体都与lambda 一致
		bool operator()(const string &s) const{return s.size()>= sz;}

	private:
		size_t sz;//该数据成员对应通过值捕获的变量


};

class PrintString
{
	public:
		PrintString(ostream &o = cout, char c = ' '): os(o),sep(c){}
		void operator()(const string &s) const {os <<s <<sep;}
	
	private:
		ostream &os;  //用于写入目的的流
		char sep;  //用于将不同输出隔开的字符


}；

void biggies(vector<string> &words,
		vector<string>::size_type s)
{

	ShorterString ss;
	SizeComp sc;
	PrintString ps;
	stable_sort(words.begin(), words.end(),ss);

	auto wc = find_id(words.begin(),words.end(),sc);
	for_each(wc,word.end(),ps);

}
