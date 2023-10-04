class StrBlob
{
	public:
		string &operator[](size_t n){return (*data)[n];}//下标运算符必须是成员函数, 访问指针data中的内容，对其解引用  ，然后用下标n来确定访问第几个元素。
		const string &operator[](size_t n)const {return (*data)[n];}

};

