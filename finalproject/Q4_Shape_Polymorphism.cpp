#include <iostream>
#include <string>
using namespace std;

class Shape
{
private:
    string color;
    double area;

public:
    Shape(string c)
    {
        color = c;
        area = 0;
    }

    void setArea(double a)
    {
        area = a;
    }

    string getColor()
    {
        return color;
    }

    double getArea()
    {
        return area;
    }

    virtual void displayDetails()
    {
        cout << "Shape Color : " << color << endl;
        cout << "Area        : " << area << endl;
    }

    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r, string c) : Shape(c)
    {
        radius = r;
        setArea(3.14159 * radius * radius);
    }

    void displayDetails() override
    {
        cout << "Circle" << endl;
        cout << "Color  : " << getColor() << endl;
        cout << "Radius : " << radius << endl;
        cout << "Area   : " << getArea() << endl;
    }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w, string c) : Shape(c)
    {
        length = l;
        width = w;
        setArea(length * width);
    }

    void displayDetails() override
    {
        cout << "Rectangle" << endl;
        cout << "Color  : " << getColor() << endl;
        cout << "Length : " << length << endl;
        cout << "Width  : " << width << endl;
        cout << "Area   : " << getArea() << endl;
    }
};

int main()
{
    Shape* shapes[2];

    Circle c(5, "Red");
    Rectangle r(10, 5, "Blue");

    shapes[0] = &c;
    shapes[1] = &r;

    cout << "Shape Details" << endl;
    cout << "-------------" << endl;

    for (int i = 0; i < 2; i++)
    {
        shapes[i]->displayDetails();
        cout << endl;
    }

    return 0;
}
