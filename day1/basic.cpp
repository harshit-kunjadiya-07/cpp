#include <iostream>

using namespace std;

int main()
{
    int eng, math, sci, age;
    float avg;
    string name, last;

    cout << "Enter your name : ";
    cin >> name;

    cout << "Enter your last name : ";
    cin >> last;

    cout << "Enter your age : ";
    cin >> age;

    cout << "English mark : ";
    cin >> eng;

    cout << "Math mark : ";
    cin >> math;

    cout << "Science mark : ";
    cin >> sci;

    cout << "Your name is : " << name << " " << last << endl;
    cout << "Your age is : " << age << endl;

    avg = (eng + math + sci) / 3.0;
    cout << "Your average marks is : " << avg << endl;

    return 0;
}