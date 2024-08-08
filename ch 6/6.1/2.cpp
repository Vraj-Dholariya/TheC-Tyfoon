#include <iostream>
using namespace std;

class P
{
 public:
    float cel;
    //setter
    void setData()
    {
        cout << "Enter tempreture in celsius: ";
        cin >> cel ;
    }
    //getter
    void getData()
    {
        cout << "celsius: " << cel << endl;
    }
};

class Q : public P
{
    public:
            float fehren;
            void toFehrenheit()
            {
                fehren = (9.0/5.0)*(cel) + 32;
            }
            void printFehrenheit()
            {
                 cout << "Fehrenheit: " << fehren << endl;
            }

};
class R : public Q
{
public:
            float kel;
            void toKelvin()
               {
                    toFehrenheit();
                     kel = (fehren-32)*5/9 + 273.15;
               }     
            void printKelvin()
            {
                  cout << "Kelvin: " << kel << endl;
            }
};

int main()
{
    R k;

    k.setData();
    k.getData();
    k.toFehrenheit();
    k.printFehrenheit();
    k.toKelvin();
    k.printKelvin();

   return 0; 
}