#include <iostream>
#include <string>

using namespace std;

const int MAX_ENTRIES = 100;

class Item
{
protected:
    string itemTitle;
    string itemAuthor;
    string itemDueDate;

public:
    Item(string t, string a) : itemTitle(t), itemAuthor(a), itemDueDate("") {}

    virtual void borrowItem() = 0;
    virtual void returnItem() = 0;
    virtual void showDetails() const = 0;

    string getItemTitle() const { return itemTitle; }
    string getItemAuthor() const { return itemAuthor; }
    string getItemDueDate() const { return itemDueDate; }

    void setItemTitle(string newTitle) { itemTitle = newTitle; }
    void setItemAuthor(string newAuthor) { itemAuthor = newAuthor; }
    void setItemDueDate(string newDueDate) { itemDueDate = newDueDate; }

    virtual ~Item() {}
};

class Novel : public Item
{
private:
    string bookISBN;

public:
    Novel(string t, string a, string i) : Item(t, a), bookISBN(i) {}

    void borrowItem() override
    {
        itemDueDate = "2024-10-01";
        cout << "Checked out Book: " << itemTitle << endl;
    }

    void returnItem() override
    {
        itemDueDate = "";
        cout << "Returned Book: " << itemTitle << endl;
    }

    void showDetails() const override
    {
        cout << "Book - Title: " << itemTitle << ", Author: " << itemAuthor
             << ", ISBN: " << bookISBN << ", Due Date: " << itemDueDate << endl;
    }
};

class MovieDisc : public Item
{
private:
    int playDuration;

public:
    MovieDisc(string t, string a, int d) : Item(t, a), playDuration(d) {}

    void borrowItem() override
    {
        itemDueDate = "2024-10-01";
        cout << "Checked out DVD: " << itemTitle << endl;
    }

    void returnItem() override
    {
        itemDueDate = "";
        cout << "Returned DVD: " << itemTitle << endl;
    }

    void showDetails() const override
    {
        cout << "DVD - Title: " << itemTitle << ", Author: " << itemAuthor
             << ", Duration: " << playDuration << " mins, Due Date: " << itemDueDate << endl;
    }
};

class Periodical : public Item
{
private:
    int issueNum;

public:
    Periodical(string t, string a, int i) : Item(t, a), issueNum(i) {}

    void borrowItem() override
    {
        itemDueDate = "2024-10-01";
        cout << "Checked out Magazine: " << itemTitle << endl;
    }

    void returnItem() override
    {
        itemDueDate = "";
        cout << "Returned Magazine: " << itemTitle << endl;
    }

    void showDetails() const override
    {
        cout << "Magazine - Title: " << itemTitle << ", Author: " << itemAuthor
             << ", Issue Number: " << issueNum << ", Due Date: " << itemDueDate << endl;
    }
};

class LibrarySystem
{
private:
    Item *itemCollection[MAX_ENTRIES];
    int totalItems;

public:
    LibrarySystem() : totalItems(0) {}

    void addItem(Item *newItem)
    {
        if (totalItems < MAX_ENTRIES)
        {
            itemCollection[totalItems++] = newItem;
        }
        else
        {
            cout << "Library is full, cannot add more items!" << endl;
        }
    }

    void borrowLibraryItem(const string &title)
    {
        for (int i = 0; i < totalItems; ++i)
        {
            if (itemCollection[i]->getItemTitle() == title)
            {
                itemCollection[i]->borrowItem();
                return;
            }
        }
        cout << "Item not found!" << endl;
    }

    void returnLibraryItem(const string &title)
    {
        for (int i = 0; i < totalItems; ++i)
        {
            if (itemCollection[i]->getItemTitle() == title)
            {
                itemCollection[i]->returnItem();
                return;
            }
        }
        cout << "Item not found!" << endl;
    }

    void showAllItems() const
    {
        for (int i = 0; i < totalItems; ++i)
        {
            itemCollection[i]->showDetails();
        }
    }

    ~LibrarySystem()
    {
        for (int i = 0; i < totalItems; ++i)
        {
            delete itemCollection[i];
        }
    }
};

void displayMenu()
{
    cout << "Library Management System Menu:" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Add DVD" << endl;
    cout << "3. Add Magazine" << endl;
    cout << "4. Check Out Item" << endl;
    cout << "5. Return Item" << endl;
    cout << "6. Display All Items" << endl;
    cout << "7. Exit" << endl;
}

int main()
{
    LibrarySystem librarySys;
    int option;

    while (true)
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> option;

        if (option == 1)
        {
            string title, author, isbn;
            cout << "Enter Book Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            cout << " << Book Added >> " << endl
                 << endl;
            librarySys.addItem(new Novel(title, author, isbn));
        }
        else if (option == 2)
        {
            string title, author;
            int duration;
            cout << "Enter DVD Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter Duration (in minutes): ";
            cin >> duration;
            cout << " << DVD Added >> " << endl
                 << endl;
            if (duration < 0)
            {
                cout << "Duration cannot be negative." << endl
                     << endl;
            }
            else
            {
                librarySys.addItem(new MovieDisc(title, author, duration));
            }
        }
        else if (option == 3)
        {
            string title, author;
            int issueNumber;
            cout << "Enter Magazine Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter Issue Number: ";
            cin >> issueNumber;
            cout << " << Magazine Added >> " << endl
                 << endl;
            if (issueNumber < 0)
            {
                cout << "Issue number cannot be negative." << endl
                     << endl;
            }
            else
            {
                librarySys.addItem(new Periodical(title, author, issueNumber));
            }
        }
        else if (option == 4)
        {
            string title;
            cout << "Enter the title of the item to check out: ";
            cin.ignore();
            getline(cin, title);
            librarySys.borrowLibraryItem(title);
        }
        else if (option == 5)
        {
            string title;
            cout << "Enter the title of the item to return: ";
            cin.ignore();
            getline(cin, title);
            librarySys.returnLibraryItem(title);
        }
        else if (option == 6)
        {
            librarySys.showAllItems();
        }
        else if (option == 7)
        {
            break;
        }
        else
        {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
