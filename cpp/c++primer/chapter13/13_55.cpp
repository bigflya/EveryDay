void StrBlob::push_back(string &&str)
{
	data->push_back(move(str));

}
