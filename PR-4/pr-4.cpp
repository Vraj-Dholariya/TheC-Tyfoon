#include <iostream>
#include <string>

using namespace std;

class UserAccount
{
private:
    string accNumber;
    string accType;
    float accBalance;

public:
    void setAccountInfo(string number, string type, float balance)
    {
        accNumber = number;
        accType = type;
        accBalance = balance;
    }

    void addFunds(float amount)
    {
        accBalance += amount;
    }

    void removeFunds(float amount)
    {
        if (accBalance >= amount)
        {
            accBalance -= amount;
        }
        else
        {
            cout << "Insufficient balance in your bank account: " << accNumber << endl;
        }
    }

    void showAccountInfo()
    {
        cout << "Account Number: " << accNumber << endl;
        cout << "Account Type: " << accType << endl;
        cout << "Balance: " << accBalance << endl;
    }

    string getAccountNumber()
    {
        return accNumber;
    }

    float getAccountBalance()
    {
        return accBalance;
    }
};

class SavingsAccount : public UserAccount
{
public:
    void calculateInterest(float rate)
    {
        float interest = getAccountBalance() * rate / 100;
        addFunds(interest);
    }
};

class CheckingAccount : public UserAccount
{
private:
    float limit;

public:
    void setLimit(float overdraftLimit)
    {
        limit = overdraftLimit;
    }

    void removeFunds(float amount)
    {
        if (getAccountBalance() + limit >= amount)
        {
            UserAccount::removeFunds(amount);
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }
};

class BankSystem
{
private:
    UserAccount *allAccounts[100];
    int totalAccounts;

public:
    BankSystem() : totalAccounts(0) {}

    void openAccount(string number, string type, float initialBalance)
    {
        if (type == "Savings")
        {
            SavingsAccount *savings = new SavingsAccount();
            savings->setAccountInfo(number, type, initialBalance);
            allAccounts[totalAccounts++] = savings;
        }
        else if (type == "Current")
        {
            CheckingAccount *current = new CheckingAccount();
            current->setAccountInfo(number, type, initialBalance);
            allAccounts[totalAccounts++] = current;
        }
    }

    void addFundsToAccount(string number, float amount)
    {
        for (int i = 0; i < totalAccounts; i++)
        {
            if (allAccounts[i]->getAccountNumber() == number)
            {
                allAccounts[i]->addFunds(amount);
                cout << "Amount deposited successfully." << endl;
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void removeFundsFromAccount(string number, float amount)
    {
        for (int i = 0; i < totalAccounts; i++)
        {
            if (allAccounts[i]->getAccountNumber() == number)
            {
                allAccounts[i]->removeFunds(amount);
                cout << "Amount withdrawn successfully." << endl;
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void showAccountInfo(string number)
    {
        for (int i = 0; i < totalAccounts; i++)
        {
            if (allAccounts[i]->getAccountNumber() == number)
            {
                allAccounts[i]->showAccountInfo();
                return;
            }
        }
        cout << "Account not found." << endl;
    }
};

int main()
{
    BankSystem bank;

    int option;
    string number, type;
    float initialBalance, amount;

    while (true)
    {
        cout << "\nBanking System" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display Account Details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter account number: ";
            cin >> number;
            cout << "Enter account type (Savings/Current): ";
            cin >> type;
            cout << "Enter initial balance: ";
            cin >> initialBalance;
            bank.openAccount(number, type, initialBalance);
            cout << "Account created successfully." << endl;
            break;
        case 2:
            cout << "Enter account number: ";
            cin >> number;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            bank.addFundsToAccount(number, amount);
            break;
        case 3:
            cout << "Enter account number: ";
            cin >> number;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            bank.removeFundsFromAccount(number, amount);
            break;
        case 4:
            cout << "Enter account number: ";
            cin >> number;
            bank.showAccountInfo(number);
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
