#include "Quote.h"


using namespace std;


double Quote::net_price(std::size_t n) const{

    return n*price;
}

double print_total(std::ostream & os,const Quote & item, std::size_t n){
    double ret = item.net_price(n);
    os<<"ISBN: "<<item.isbn()<<"#sold: "<<n<<"total due: "<<ret<<std::endl;
    return ret;
}

double Bulk_quote::net_price(std::size_t cnt) const{
    if(cnt >=quantity)
        return cnt*(1-discount)*price;
    else
        return cnt*price;
}

std::ostream & Quote::debug(std::ostream & os) const{
    os<<bookNo<<" "<<price;
    return os;
}

std::ostream & Disc_quote::debug(std::ostream & os) const{
    Quote::debug(os)<<" "<<quantity<<" "<<discount;
    return os;
}