#include <iostream>
using namespace std;

class TimeConverter
{
    int hours, minutes, seconds , totalSeconds;

public:
    void secondsToTime()
    {
        cout << "Enter total seconds: ";
        cin >> totalSeconds;

        hours = totalSeconds / 3600;
        totalSeconds = totalSeconds % 3600;

        minutes = totalSeconds / 60;
        seconds = totalSeconds % 60;

        cout << "HH:MM:SS => " << hours << " : " << minutes << " : " << seconds << endl;
    }

    void timeToSeconds()
    {
        cout << "Enter hours: ";
        cin >> hours;

        cout << "Enter minutes: ";
        cin >> minutes;

        cout << "Enter seconds: ";
        cin >> seconds;

        totalSeconds = (hours * 3600) + (minutes * 60) + seconds;

        cout << "Total seconds: " << totalSeconds << endl;
    }
};

int main()
{
    TimeConverter t;
    int choice;

    cout << "===== TIME CONVERTER =====" << endl;
    cout << "1. Seconds to HH:MM:SS" << endl;
    cout << "2. HH:MM:SS to Seconds" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        t.secondsToTime();
    }
    else if (choice == 2)
    {
        t.timeToSeconds();
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}