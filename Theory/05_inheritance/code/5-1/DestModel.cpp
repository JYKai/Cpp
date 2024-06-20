#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    int age;
    char * name;

public:
    Person(int myage, char *myname) : age(myage)
    {
        name = new char[strlen(myname) + 1];
        strcpy(name, myname);
    }
    void WhatYourName(void) const { cout << "My name is " << name << endl; }
    void HowOldAreYou(void) const { cout << "I'm " << age << " years old" << endl; }

    ~Person()
    {
        delete []name;
    }
};


class UnivStudent : public Person
{
private:
    char * major;

public:
    UnivStudent(char *myname, int myage, char *mymajor)
        : Person(myage, myname)
    {
        major = new char[strlen(mymajor) + 1];
        strcpy(major, mymajor);
    }
    void WhoAreYou(void) const
    {
        WhatYourName();
        HowOldAreYou();
        cout << "My major is " << major << endl << endl;
    }
    ~UnivStudent()
    {
        delete []major;
    }
};


int main(void)
{
    UnivStudent ustd1("Lee", 22, "Computer eng.");
    ustd1.WhoAreYou();

    UnivStudent ustd2("Kim", 24, "Environment eng.");
    ustd2.WhoAreYou();

    return 0;
}