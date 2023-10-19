#include <iostream>
#include <vector>
#include "Quote.h"
#include <memory>//想使用智能指针的话应该包括此头文件

using namespace std;

int main(void){
    vector<shared_ptr<Quote>> qVec;
    double sum = 0.0;
    qVec.push_back(make_shared<Quote>(Quote("c++ primer",128)));
    qVec.push_back(make_shared<Bulk_quote>(Bulk_quote("c pp",100,10,0.1)));//0.1表示打9折 ，静态类型和动态类型不一致，调用的时候会调用动态类型Bulk_quote这个派生类中的对象

    for(auto iter = qVec.begin();iter!=qVec.end();iter++)
        //sum +=(*iter)->net_price(20);//iter 迭代器   ，*iter 迭代器里面存放的内容（此时的内容是智能指针p） ，要想拿到指针p里面的成员需要先*P(解引用) 然后 .net_price(20),(*P).net_price(20)等价于P->net_price(20)
        sum +=(*(*iter)).net_price(20);//与上面等价， 因为存放的是指针，所以会发生动态类型和静态类型的分离
    cout<<sum<<endl;//20x128+100x(1-0.1)x20=4360
    cout<<qVec.size()<<endl;
    return 0;
}
