#include <iostream>
#include <string>
using namespace std;

class Shape
{
private:
    string color;
    double area;

public:
    void setColor(string c)
    {
        color = c;
    }

    string getColor()
    {
        return color;
    }

    void setArea(double a)
    {
        area = a;
    }

    double getArea()
    {
        return area;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r, string c)
    {
        radius = r;
        setColor(c);
    }

    void calculateArea()
    {
        double a = 3.14159 * radius * radius;
        setArea(a);
    }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w, string c)
    {
        length = l;
        width = w;
        setColor(c);
    }

    void calculateArea()
    {
        double a = length * width;
        setArea(a);
    }
};

int main()
{
    Circle c(5, "Red");
    Rectangle r(10, 5, "Blue");

    c.calculateArea();
    r.calculateArea();

    cout << "Circle" << endl;
    cout << "Color : " << c.getColor() << endl;
    cout << "Area  : " << c.getArea() << endl;

    cout << "\nRectangle" << endl;
    cout << "Color : " << r.getColor() << endl;
    cout << "Area  : " << r.getArea() << endl;

    return 0;
}
