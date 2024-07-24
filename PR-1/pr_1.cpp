#include <iostream>
using namespace std;

class Distance
{
public:
  int feet;
  int inches;
};

int main()
{
    Distance d1, d2, d3;

    cout << "Enter first distance: " << endl<<endl;
    cout<< "Enter feet: ";
    cin >> d1.feet;
    cout << "Enter inches: ";
    cin >> d1.inches;
    cout << endl << endl;

    cout << "Enter second distance: " << endl<<endl;
    cout<< "Enter feet: ";
    cin >> d2.feet;
    cout << "Enter inches: ";
    cin >> d2.inches;

    d3.feet = d1.feet + d2.feet;
    d3.inches = d1.inches + d2.inches;

    if (d3.inches>=12)
    {
        d3.feet += d3.inches/12;
        d3.inches = d3.inches % 12;
    }
    cout << endl;
    cout << d3.feet <<" feet "<<d3.inches <<" inches"<<endl;
}
