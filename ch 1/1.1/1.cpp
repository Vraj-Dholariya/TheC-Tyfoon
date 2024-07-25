#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << "a["<<i<<"] = ";
        cin >> arr[i];

    }

    cout << "Even elements of the array: ";
    bool first = true; //to handle comma formatting
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0){
            if(!first){
                cout << arr[i];
            }
            cout << arr[i];
            first=false;
        }
    }
    cout<<endl;
return 0;
}
