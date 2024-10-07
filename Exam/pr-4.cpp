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

    void displayDetails() const
     {
        cout << "Dog Details:" << endl;
        Animal::displayDetails();
        cout << "This dog says: " << sound << endl;
    }
};

class Cat : public Animal {
public:
    Cat(const string &catName)
     {
        name = catName;
        sound = "Meow";
    }

    void displayDetails() const 
    {
        cout << "Cat Details:" << endl;
        Animal::displayDetails();
        cout << "This cat says: " << sound << endl;
    }
};

int main() {
    const int MAX_ANIMALS = 2;
    Dog dog("Buddy");
    Cat cat("Whiskers");

    Animal* animals[MAX_ANIMALS] = { &dog, &cat };

    cout << "\nAnimal Details:" << endl;
    for (int i = 0; i < MAX_ANIMALS; ++i)
     {
        animals[i]->displayDetails();
        cout << endl;
    }

    return 0;
}
