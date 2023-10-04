class ConstStrBlobPtr
{
	public:
		const string &operator*() const
		{
			auto p = check(curr,"dereference past end");
		}
		const string *operator->() const
		{
			return  &(this->operator*());//此处的括号是没必要加上的但是为了方便理解返回值是一个地址在此处加上了。
		}
};
