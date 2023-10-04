class StrBlob
{
	friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator<=(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator>(const StrBlob &lhs, const StrBlob &rhs);
	friend bool operator>=(const StrBlob &lhs, const StrBlob &rhs);


};



bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data < *rhs.data;

}


bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{ 
        return *lhs.data <= *rhs.data;

}

bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{ 
        return *lhs.data > *rhs.data;

}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{ 
        return *lhs.data >= *rhs.data;

}
