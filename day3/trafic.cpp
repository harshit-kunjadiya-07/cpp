#include <iostream>

using namespace std;

int main()
{
    char signal;

    cout << "Enter the traffic signal color (R for Red, Y for Yellow, G for Green): ";
    cin >> signal;  

    switch (signal)
    {
        case 'R':
        case 'r':
            cout << "Stop" << endl;
            break;
        case 'Y':
        case 'y':
            cout << "Wait" << endl;
            break;
        case 'G':
        case 'g':
            cout << "Go" << endl;
            break;
        default:
            cout << "Invalid signal color!" << endl;
    }

    return 0;
}
