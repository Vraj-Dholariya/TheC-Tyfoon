#include <iostream>
#include <string.h>
#include "pr_1.cpp"
using namespace std;

int main()
{   
    RailwaySystem system;
    int choice;
    int number;
     do
     {
        cout << "---Railway Resevation System---"<<endl 
        << "1.Add New Train" << endl
        << "2.Display All Train Records" <<endl
        << "3.Search Train By Train Number" << endl
        << "4.Exit" << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;     
        
        switch (choice)
        {
            case 1:
                system.addNewTrain();
                break;
            case 2:
                system.displayAllTrains();
                break;
            case 3:
                system.searchTrainByNumber(number);
                break;
            case 4:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }        
     }while ( choice != 4);
 return 0;    
}
