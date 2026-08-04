#include <iostream>

using namespace std;

int main()
{

    int sci, math, eng, phy, chem, percentage;

    cout << "Enter marks for Science: ";
    cin >> sci;
    cout << "Enter marks for Mathematics: ";
    cin >> math;
    cout << "Enter marks for English: ";
    cin >> eng;
    cout << "Enter marks for Physics: ";
    cin >> phy;
    cout << "Enter marks for Chemistry: ";
    cin >> chem;

    percentage = (sci + math + eng + phy + chem) / 5;
    cout << "================================" << endl;
    cout << "\nYour percentage is: " << percentage << "%" << endl;
    cout << "\n================================" << endl;


    if (percentage >= 95)
    {
        cout << "Grade: A" << endl;
    }
    else if (percentage >= 80 && percentage < 95)
    {
        cout << "Grade: B" << endl;
    }
    else if (percentage >= 65 && percentage < 80)
    {
        cout << "Grade: C" << endl;
    }
    else if (percentage >= 35 && percentage < 65)
    {
        cout << "Grade: D" << endl;
    }
    else
    {
        cout << "Grade: F" << endl;
    }

    return 0;
}