StrBlobPtr &StrBlobPtr::operator+=(size_t n)
{ 
        StrBlobPtr curr -=n;
	check(curr,"increment pastend of StrBlobPtr");
	return *this;
	

}


StrBlobPtr &StrBlobPtr::operator-=(size_t n)
{ 
        StrBlobPtr curr +=n;
        check(curr,"increment pastend of StrBlobPtr");
        return *this;
        

}





StrBlobPtr StrBlobPtr::operator+(size_t n)
{
	StrBlobPtr ret =*this;
	ret +=n;
	return ret;

}

StrBlobPtr StrBlobPtr::operator-(size_t n)
{ 
        StrBlobPtr ret =*this;
        ret -=n;
        return ret;

}
