class Rev_quote : public Disc_quote()
{
    public:
        Rev_quote(){};
        Rev_quote(const string &bookNo, double p, size_t q, double disc):Disc_quote(bookNo,p,q,disc){};//用成员初始化列表的方式初始化直接基类
        double net_price(size_t) const override;

};

double Rev_quote::net_price(size_t cnt) const
{
    if(cnt <= quantity)
        return price*(1-discount)*cnt;
    else
        return price*(1-discount)*quantity + (cnt-quantity)*price;

}