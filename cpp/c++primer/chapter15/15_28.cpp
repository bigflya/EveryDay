#include <iostream>
#include <vector>
#include "Quote.h"


using namespace std;

int main(void){
    vector<Quote> qVec;
    double sum = 0.0;
    qVec.push_back(Quote("c++ primer",128));
    qVec.push_back(Bulk_quote("c pp",100,10,0.1));//0.1表示打9折

    for(auto iter = qVec.begin();iter!=qVec.end();iter++)
        sum +=(*iter).net_price(20);//这句中net_price调用的是基类中的成员还是派生类中的成员呢？
        //因为 vector<Quote>容器里面存放的是Quote，且存放的是对象而不是指针，所以不会发生动态类型和静态类型分离的情况，那么也就是说即使里面放的是Bulk_quote派生类类型，实际也会转换为基类的类型
        //最终的sum应该是  128x20+100x20=4560
    cout<<sum<<endl;
    return 0;
}