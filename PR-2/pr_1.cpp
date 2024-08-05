#include <iostream>
#include <string.h>
using namespace std;

class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];
    static int trainCount;

public:
    Train()   
    {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

    Train(int trainNumber, char trainName[], char source[], char destination[], char trainTime[]) 
   {
        this->trainNumber = trainNumber;
        strcpy(this->trainName, trainName);
        strcpy(this->source, source);
        strcpy(this->destination, destination);
        strcpy(this->trainTime, trainTime);
        trainCount++;
    }

    ~Train()
    {
        trainCount--;
    }

    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;

        cout << "Enter Train Name: ";
        cin >> trainName;

        cout << "Enter Source: ";
        cin >> source;

        cout << "Enter Destination: ";
        cin >> destination;

        cout << "Enter Train Time: ";
        cin >> trainTime;
    }

    void displayTrainDetails() const {
        cout << endl;
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
        cout << "---------------------------" << endl;
    }

    int getTrainNumber()const{
        return trainNumber;
    }

    static int getTrainCount() {
        return trainCount;
    }
};

int Train::trainCount = 0;

class RailwaySystem {
private:
    Train trains[100];
    int totalTrains = 0;

public:
    void addNewTrain() 
    {
        if (totalTrains < 100) {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
        }
        else
        {
            cout << "Maximum train limit reached!" << endl;
        }
    }

    void displayAllTrains() const {
        if (totalTrains == 0) {
            cout << "No trains to display!" << endl;
        } 
        else
        {
            for (int i = 0; i < totalTrains; i++) {
                cout << "Train " << i + 1 << " details:" << endl;
                trains[i].displayTrainDetails();
            }
        }
    }

    void searchTrainByNumber(int number) const {
        bool found = false;
        for (int i = 0; i < totalTrains; i++)
            {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "Train details:" << endl;
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Train with number " << number << " not found!" << endl;
        }
    }
};

