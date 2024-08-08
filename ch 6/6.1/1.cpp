#include <iostream>
using namespace std;
      //inheritance
class X
{
protected:
         int a,b,c,d;

 public:
        int cube(int a,int b,int c)
        {
            d=((a*a*a) + (b*b*b) + (c*c*c));
            return d;
        }        
};

class Y : public X
{
public:    
    //setter
    void setData()
    {
        cout << "Enter a: ";
        cin >> a;
        cout << "Enter b: ";
        cin >> b;
        cout << "Enter c: ";
        cin >> c;
    }

     //getter
    void getData()
    {
        cout << "A\t: " << a << endl;
        cout << "B\t: " << b << endl;
        cout << "C\t: " << c << endl;
        cout << "Sum of Cubes are: " << cube(a,b,c) << endl;
    }    
};
int main()
{
    Y y;

    y.setData();
    y.getData();
}