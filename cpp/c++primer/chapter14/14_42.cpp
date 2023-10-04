a)

count_if(vec.begin(),vec.end(),bind(greater<int>(),_1,1024));// std::placeholders::_1


b)

find_if(vec.begin(),vec.end(),bind(not_equal_to<string>(),_1,"pooh"));//bind函数返回的是一个可调用对象，而我们要把vec中每个元素放到bind函数返回的那个可调用对象里



c)

transform(vec.begin(),vec.end(),vec.begin(),bind(multiplies<int>,_1,2));
