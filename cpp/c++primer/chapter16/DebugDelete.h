#include <iostream>

class DebugDelete
{
private:
    /* data */
    std::ostream &os;
public:
    DebugDelete(std::ostream &s=std::cerr):os(s){}
    template <typename T> void operator()(T *p) const
    {os<<"deleting unique_ptr"<<std::endl; delete p;}

    
    ~DebugDelete();
};


DebugDelete::~DebugDelete()
{
}


