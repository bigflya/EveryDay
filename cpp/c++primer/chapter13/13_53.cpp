
HasPtr &HasPtr::operator=(HasPtr &&rhs)	noexcept
{
	if(this != &rhs)
	{
		delete ps;
		ps =rhs.ps;
		i = rhs.i;
		rhs.ps = nullptr;
		rhs.i = 0;

	}
	return *this;
}
