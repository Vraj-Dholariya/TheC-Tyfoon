#include <iostream>
#include "hotel.cpp"
using namespace std;

int main()
{
    int n;
    cout << "Enter number of Hotels: "; 
    cin >> n;

    Hotel h[n]; 

    for (int i = 0; i < n; i++)
    {
        h[i].setHotelData(); 
    }
    for (int i = 0; i < n; i++)
    {
        h[i].getHotelData();
    }
return 0; 
}