class Rev_quote : public Quote
{
    public:
        Rev_quote(){};
        Rev_quote(const string &, double, size_t, double);
        double net_price(size_t) const override;

    private:
        size_t min_qty = 0;
        double discount = 0.0;

};

double Rev_quote::net_price(size_t cnt) const
{
    if(cnt <= min_qty)
        return price*(1-discount)*cnt;
    else
        return price*(1-discount)*min_qty + (cnt-min_qty)*price;

}