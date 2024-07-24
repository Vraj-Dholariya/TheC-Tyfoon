#include <iostream>
using namespace std;

class Time{
public:
    int hour;
    int min;
    int second;   
};

int main()
{
    Time t;
    int totalSecond;

    cout << "Enter seconds: ";
    cin >> totalSecond;

    t.hour = totalSecond/3600;
    t.min = (totalSecond%3600)/60;
    t.second = totalSecond%60;

    cout << endl;
    cout << t.hour << ":" << t.min << ":" << t.second << endl;
    
    return 0;
}