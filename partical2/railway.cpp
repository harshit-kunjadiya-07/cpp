#include <iostream>

using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[20];

    static int trainCount;

public:
    // Default Constructor
    Train()
    {
        trainNumber = 0;

        trainName[0] = '\0';
        source[0] = '\0';
        destination[0] = '\0';
        trainTime[0] = '\0';

        trainCount++;
    }

    // Parameterized Constructor
    Train(int number, const char name[], const char src[],
            const char dest[], const char time[])
    {
        trainNumber = number;

        int i = 0;

        while (name[i] != '\0')
        {
            trainName[i] = name[i];
            i++;
        }
        trainName[i] = '\0';

        i = 0;

        while (src[i] != '\0')
        {
            source[i] = src[i];
            i++;
        }
        source[i] = '\0';

        i = 0;

        while (dest[i] != '\0')
        {
            destination[i] = dest[i];
            i++;
        }
        destination[i] = '\0';

        i = 0;

        while (time[i] != '\0')
        {
            trainTime[i] = time[i];
            i++;
        }
        trainTime[i] = '\0';

        trainCount++;
    }

    // Destructor
    ~Train()
    {
        trainCount--;
    }

    // Setters
    void setTrainNumber(int number)
    {
        trainNumber = number;
    }

    void setTrainName(const char name[])
    {
        int i = 0;

        while (name[i] != '\0')
        {
            trainName[i] = name[i];
            i++;
        }

        trainName[i] = '\0';
    }

    void setSource(const char src[])
    {
        int i = 0;

        while (src[i] != '\0')
        {
            source[i] = src[i];
            i++;
        }

        source[i] = '\0';
    }

    void setDestination(const char dest[])
    {
        int i = 0;

        while (dest[i] != '\0')
        {
            destination[i] = dest[i];
            i++;
        }

        destination[i] = '\0';
    }

    void setTrainTime(const char time[])
    {
        int i = 0;

        while (time[i] != '\0')
        {
            trainTime[i] = time[i];
            i++;
        }

        trainTime[i] = '\0';
    }

    // Getters
    int getTrainNumber()
    {
        return trainNumber;
    }

    char *getTrainName()
    {
        return trainName;
    }

    char *getSource()
    {
        return source;
    }

    char *getDestination()
    {
        return destination;
    }

    char *getTrainTime()
    {
        return trainTime;
    }

    // Input Train Details
    void inputTrainDetails()
    {
        cout << "\nEnter Train Number: ";
        cin >> trainNumber;

        cout << "Enter Train Name: ";
        cin >> ws;
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 20);
    }

    // Display Train Details
    void displayTrainDetails()
    {
        cout << "\nTrain Number : " << trainNumber;
        cout << "\nTrain Name   : " << trainName;
        cout << "\nSource       : " << source;
        cout << "\nDestination  : " << destination;
        cout << "\nTrain Time   : " << trainTime;
        cout << "\n";
    }

    // Static Function
    static int getTrainCount()
    {
        return trainCount;
    }
};

// Initialize Static Member
int Train::trainCount = 0;

// RailwaySystem Class
class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:
    // Constructor
    RailwaySystem()
    {
        totalTrains = 0;
    }

    // Add Train
    void addTrain()
    {
        if (totalTrains < 100)
        {
            cout << "\n========== Add New Train ==========\n";

            trains[totalTrains].inputTrainDetails();

            totalTrains++;

            cout << "\nTrain record added successfully!";
        }
    }

    // Display All Trains
    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "\nNo train records available!";
        }
        else
        {
            cout << "\n========== All Train Records ==========\n";

            for (int i = 0; i < totalTrains; i++)
            {
                cout << "\nTrain " << i + 1 << " Details:";

                trains[i].displayTrainDetails();
            }
        }
    }

    // Search Train By Number
    void searchTrainByNumber(int number)
    {
        int found = 0;

        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "\n========== Train Found ==========\n";

                trains[i].displayTrainDetails();

                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            cout << "\nTrain with number "
                    << number << " not found!";
        }
    }
};

int main()
{
    RailwaySystem railway;

    int choice;
    int number;

    do
    {
        cout << "\n\n==========================================";
        cout << "\n       RAILWAY RESERVATION SYSTEM";
        cout << "\n==========================================";
        cout << "\n1. Add New Train Record";
        cout << "\n2. Display All Train Records";
        cout << "\n3. Search Train by Number";
        cout << "\n4. Exit";
        cout << "\n==========================================";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            railway.addTrain();

            break;

        case 2:

            railway.displayAllTrains();

            break;

        case 3:

            cout << "\nEnter Train Number to search: ";
            cin >> number;

            railway.searchTrainByNumber(number);

            break;

        case 4:

            cout << "\nExiting the system. Goodbye!";

            break;

        default:

            cout << "\nInvalid choice!";
        }

    } while (choice != 4);

    return 0;
}