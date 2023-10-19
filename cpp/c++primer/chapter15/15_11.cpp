class Quote
{
    public:
        Quote() = default;
        Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price){}
        std::string isbn() const{return bookNo;}

        virtual double net_price(std::size_t n) const{return n*price;}
        virtual ~Quote() =default;
        virtual void debug() const{cout<<"bookNo = "<<bookNo<<", price = " <<price << endl;}
    private:
        std::string bookNo;

    protected:
        double price = 0.0;
        



};

class Bulk_quote : public Quote
{
    public:
        Bulk_quote() = default;
        Bulk_quote(const std::string & book, double p, std::size_t qty, double disc);
        double net_price(std::size_t ) const override;
        virtual void debug() const override{Quote::debug(); cout<<"min_qty = "<<min_qty<<", discount = "<<discount<<endl;}//在基类里面已经有了，所以在派生类中也可以不加virtual

    private:
        std::size_t min_qty = 0;
        double discount =0.0;


};
