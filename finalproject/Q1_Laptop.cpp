#include <iostream>
#include <string>
using namespace std;

class Laptop
{
private:
    string name;
    double price;
    string processor;

public:
    // Parameterized constructor
    Laptop(string n, double p, string pro)
    {
        name = n;
        price = p;
        processor = pro;
    }

    void display()
    {
        cout << "Laptop Name : " << name << endl;
        cout << "Price       : " << price << endl;
        cout << "Processor   : " << processor << endl;
    }
};

int main()
{
    Laptop l1("Dell", 55000, "Intel Core i5");
    Laptop l2("HP", 65000, "Intel Core i7");

    cout << "Laptop 1" << endl;
    l1.display();

    cout << "\nLaptop 2" << endl;
    l2.display();

    return 0;
}
