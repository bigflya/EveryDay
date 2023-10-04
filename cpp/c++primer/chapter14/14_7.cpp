
class String
{
	friend ostream &operator<<(ostream &os,const String &str);

	

};


ostream &operator<<(ostream &os, const String &str)
{
	os << str;

	return os;

}
