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
    Train()
    {
        trainNumber = 0;
        trainName[0] = 0;
        source[0] = 0;
        destination[0] = 0;
        trainTime[0] = 0;
        trainCount++;
    }

    Train(int number, const char name[], const char src[],
          const char dest[], const char time[])
    {
        trainNumber = number;
        int i;
        for (i = 0; name[i] != 0 && i < 49; i++)
        {
            trainName[i] = name[i];
        }
        trainName[i] = 0;

        for (i = 0; src[i] != 0 && i < 49; i++)
        {
            source[i] = src[i];
        }
        source[i] = 0;

        for (i = 0; dest[i] != 0 && i < 49; i++)
        {
            destination[i] = dest[i];
        }
        destination[i] = 0;

        for (i = 0; time[i] != 0 && i < 19; i++)
        {
            trainTime[i] = time[i];
        }
        trainTime[i] = 0;
        trainCount++;
    }

    ~Train()
    {
        trainCount--;
    }

    void setTrainNumber(int number)
    {
        trainNumber = number;
    }

    void setTrainName(const char name[])
    {
        int i;

        for (i = 0; name[i] != 0 && i < 49; i++)
        {
            trainName[i] = name[i];
        }
        trainName[i] = 0;
    }

    void setSource(const char src[])
    {
        int i;
        for (i = 0; src[i] != 0 && i < 49; i++)
        {
            source[i] = src[i];
        }
        source[i] = 0;
    }

    void setDestination(const char dest[])
    {
        int i;
        for (i = 0; dest[i] != 0 && i < 49; i++)
        {
            destination[i] = dest[i];
        }
        destination[i] = 0;
    }

    void setTrainTime(const char time[])
    {
        int i;
        for (i = 0; time[i] != 0 && i < 19; i++)
        {
            trainTime[i] = time[i];
        }
        trainTime[i] = 0;
    }

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

    void displayTrainDetails()
    {
        cout << "\nTrain Number : " << trainNumber;
        cout << "\nTrain Name   : " << trainName;
        cout << "\nSource       : " << source;
        cout << "\nDestination  : " << destination;
        cout << "\nTrain Time   : " << trainTime;
        cout << "\n";
    }

    static int getTrainCount()
    {
        return trainCount;
    }
};

int Train::trainCount = 0;
class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem()
    {
        totalTrains = 0;
    }

    void addTrain()
    {
        if (totalTrains < 100)
        {
            cout << "\n==========================================";
            cout << "\n            ADD NEW TRAIN";
            cout << "\n==========================================";
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
            cout << "\nTrain record added successfully!";
        }
        else
        {
            cout << "\nTrain record limit reached!";
        }
    }

    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "\nNo train records available!";
        }
        else
        {
            cout << "\n==========================================";
            cout << "\n          ALL TRAIN RECORDS";
            cout << "\n==========================================";

            for (int i = 0; i < totalTrains; i++)
            {
                cout << "\nTrain " << i + 1 << " Details:";
                trains[i].displayTrainDetails();
            }
        }
    }

    void searchTrainByNumber(int number)
    {
        int found = 0;

        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "\n==========================================";
                cout << "\n             TRAIN FOUND";
                cout << "\n==========================================";
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

            cout << "\nInvalid choice! Please enter 1 to 4.";
        }

    } while (choice != 4);

    return 0;
}