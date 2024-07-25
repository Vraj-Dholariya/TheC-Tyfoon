#include <iostream>
using namespace std;

int main()
{
    char input[100];
    cout << "Enter the string: ";
    cin >> input;

    for (int i = 0; input[i] != '\0'; ++i)
{
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            input[i] = input[i] - 'a' + 'A';
        }
        else if (input[i] >= 'A' && input[i] <= 'z')
        {
            input[i] = input[i] - 'A' + 'a';
        }
        
    }
    cout << "String: " <<input << endl;
    return 0;
}
 