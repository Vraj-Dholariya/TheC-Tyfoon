#include <iostream>
using namespace std;

int main()
{
    int startYear,endYear;
    cout <<"Enter the first number of year: ";
    cin >> startYear;
    cout << "Enter the last number of year: ";
    cin >> endYear;

    int maxLeapyear = (endYear - startYear)/4+1;
    int leapYear[maxLeapyear];
    int count = 0;

    for (int  year = startYear; year <= endYear; year++)
    {
        if ((year % 4 == 0 && year % 100 != 0)||(year % 400 == 0))
        {
            leapYear[count] = year;
            count++;
        }
    }
    cout << "The array is : ";
    for (int  i = 0; i < count; i++)
    {
        cout << leapYear[i] ;
        if (i != count-1)
        {
            cout << " , ";
        } 
    }
    cout << endl;
    return 0;
}   