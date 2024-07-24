#include <iostream>
#include<string.h>
using namespace std;

class Vraj
{
    private:
           string name;
           int age;
    
    public:
            string ocupation;
            string college;
};
int main()
{
    Vraj v;

       v.ocupation = "This is public information";
       v.college = "Nirma intitute of technology";

       // v.name = "vraj"; // ERROR
       // v.age = 18; // ERROR

       cout << "public information: " << v.ocupation << endl;
       cout << "collage name: " << v.college << endl;

    return 0;     
}

