#include <iostream>

using namespace std;

class Student
{
public:
    string fname, lname;
    int age;

}

int
main()
{
    Student s1;
    s1.fname = "John";
    s1.lname = "Doe";
    s1.age = 20;

    cout << "Student Name: " << s1.fname << " " << s1.lname << endl;
    cout << "Student Age: " << s1.age << endl;

    return 0;
}