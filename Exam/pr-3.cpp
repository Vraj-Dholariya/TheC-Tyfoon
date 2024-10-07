#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    string name;
    string sound;

    void displayDetails() const
     {
        cout << "Animal Name: " << name << endl;
        cout << "Animal Sound: " << sound << endl;
    }
};

class Dog : public Animal {
public:
    Dog(const string &dogName)
     {
        name = dogName;
        sound = "Bark";
    }
};

class Cat : public Animal {
public:
    Cat(const string &catName)
     {
        name = catName;
        sound = "Meow";
    }
};

int main() {
    string dogName, catName;

    cout << "Enter the name of the dog: ";
    cin >> dogName;
    Dog dog(dogName);

    cout << "Enter the name of the cat: ";
    cin >> catName;
    Cat cat(catName);

    cout << "\nDog Details:" << endl;
    dog.displayDetails();

    cout << "\nCat Details:" << endl;
    cat.displayDetails();

    return 0;
}
