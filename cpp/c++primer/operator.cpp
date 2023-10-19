#include <string.h>
#include <iostream>
class String {
public:
    char* data;
public:
    String(const char* p) {
        data = new char[strlen(p) + 1];
        strcpy(data, p);
    }
    
    String& operator=(const String& source) {
        std::cout<<"source "<<source.data<<std::endl;
        std::cout<<"this "<<(*this).data<<std::endl;
        if (this != &source) {
           
            delete[] data;
            data = new char[strlen(source.data) + 1];
            strcpy(data, source.data);
        }
        return *this;
    }
    
    // ... other methods ...
};


int main(void){

    String b1("bigfly");
    String b2=" ";

    std::cout << "s1: " << b1.data << std::endl;
    std::cout << "s2: " << b2.data << std::endl;

    b2= b1;// =b1 调用的是  =operator(const String& source) ,将返回值赋值给b2

    std::cout << "s1: " << b1.data << std::endl;
    std::cout << "s2: " << b2.data << std::endl;

    
    return 0;
}