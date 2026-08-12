
#include<iostream>
using namespace std;

class Animal
{
public:
    virtual void sound()
    {
        cout << "Animal Sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void sound() override
    {
        cout << "Dog Barks" << endl;
    }
};

class Cat : public Animal
{
public:
    void sound() override
    {
        cout << "Cat Meows" << endl;
    }
};

int main()
{
    Animal *ptr;

    Dog d;
    Cat c;

    ptr = &d;
    ptr->sound();

    ptr = &c;
    ptr->sound();

    return 0;
}

