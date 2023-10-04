


bool divided_all(vector<int> &ivec, int div)
{
	return any_of(ivec.begin(), ivec.end(), bind(modulus<int>(),_1,div));



}
