#include <iostream>
#include <string>


using namespace std;


template <unsigned H,unsigned W>
class Screen{
private:
    unsigned int cursor = 0;
    string contents;

public:
    Screen() :contents(H*W,' '){}
    Screen(char c):contents(H*W,c){}
    Screen<H,W> &set(char c);//因为在类里面所以 <H,W>可以不写，
    Screen &set(unsigned int row, unsigned int col, char c);//返回的是类的对象用引用会更好一点。
    Screen &move(unsigned int row,unsigned int col);
    Screen &display(){cout<<contents<<endl; return *this;}

};


template <unsigned H,unsigned W>
inline Screen<H,W> &Screen<H,W>::set(char c){
    contents[cursor] = c;
    return *this;

}

template <unsigned H,unsigned W>
inline Screen<H,W> &Screen<H,W>::set(unsigned int row, unsigned int col, char c){
    cursor[row*W +col] =c;
    return *this;
}


template <unsigned H,unsigned W>
inline Screen<H,W> &Screen<H,W>::move(unsigned int row ,unsigned int col){
    cursor = row*W+col;
    return *this;
}