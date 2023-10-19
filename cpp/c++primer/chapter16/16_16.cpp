template <typename T>
class Vec{
public:
    
    Vec<T>::Vec():elements(nullptr),first_free(nullptr),cap(nullptr){}//Vec<T>::可以不用写
    Vec<T>::Vec(const Vec&);
    Vec<T> &operator=(const Vec&);
    ~Vec();
    void push_back(const T&);
    size_t size() const{return first_free -elements;}
    size_t capacity() const{return cap - elements;}
    T *begin() const{return elements;}
    T *end() const{return first_free;}

private:
    static allocator<T> alloc;
    void chk_n_alloc(){
        if(size()==capacity())
            reallocate();
    }

    pair<T *,T *> alloc_n_copy(T *,T *);
    void free();
    void reallocate();
    T *elements;
    T *first_free;
    T *cap;


};