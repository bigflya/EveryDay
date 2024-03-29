#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>
class Quote
{
private:

    /* data */
    std::string bookNo;
public:
    Quote(/* args */)=default;
    Quote(const std::string &book, double sales_price):bookNo(book),price(sales_price){}
    std::string isbn() const {return bookNo;}
    virtual double net_price(std::size_t n) const;
    virtual ~Quote()= default;
    virtual std::ostream &debug(std::ostream & os) const;
    

protected:
    double price = 0.0;
};


class Disc_quote:public Quote{

private:

public:
    Disc_quote() = default;
    Disc_quote(const std::string & book, double price, std::size_t qty, double disc):Quote(book,price),quantity(qty),discount(disc){}
    std::ostream &debug(std::ostream &os)const override;
    double net_price(std::size_t) const = 0;

protected:
    std::size_t quantity = 0;
    double discount = 0.0;
    
};


class Bulk_quote:public Disc_quote
{
private:
    /* data */
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string & book, double price, std::size_t qty, double disc):Disc_quote(book,price,qty,disc){}
    double net_price(std::size_t) const override;
};

double print_total(std::ostream & os,const Quote & item, std::size_t cnt);


#endif