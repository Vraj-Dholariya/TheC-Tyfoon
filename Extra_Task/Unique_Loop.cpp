#include <iostream>
using namespace std;
int main()
{
    int rowtemp = 0;

    int n;
    cout << "Enter number: ";
    cin >> n;

    for (int  i = 1; i <= n; i++)
    {
        rowtemp += i;

        int j=1;

        for (j;j<i;j++)
        {
            cout << "_" << " ";
        }
        int coltemp = rowtemp;

        for (j; j <= n; j++)
        {
            cout << coltemp << " ";
            coltemp += j;
        }

        j -= 2;

        for (j ; j>=i; j--)
        {
            cout << coltemp << " ";
            coltemp += j;
        }

        cout << endl;
               
    }
    return 0;
}
