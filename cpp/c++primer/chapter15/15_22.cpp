class Figure{
public:
    Figure(double px, double py);
    virtual double area();

private:
    double x;
    double y;

};


class Rectangle: public Figure{

public:
    Rectangle(double x,double y);
    virtual double area();

private:
    double length;
    double width;



};