#include <iostream>
using namespace std;

class First
{
public:
    void FirstFunc(void) { cout << "FirstFunc()" << endl; }
    virtual void SimpleFunc(void) { cout << "First's SimpleFunc()" << endl; }
};

class Second : public First
{
public:
    void SecondFunc(void) { cout << "SecondFunc()" << endl; }
    virtual void SimpleFunc(void) { cout << "Second's SimpleFunc()" << endl; }
};

class Third : public Second
{
public:
    void ThirdFunc(void) { cout << "ThirdFunc()" << endl; }
    virtual void SimpleFunc(void) { cout << "Third's SimpleFunc()" << endl; }
};

int main(void)
{
    Third obj;
    obj.FirstFunc();    // FirstFunc()
    obj.SecondFunc();   // SecondFunc()
    obj.ThirdFunc();    // ThirdFunc()
    obj.SimpleFunc();   // Third's SimpleFunc()

    Second &sref = obj;
    sref.FirstFunc();   // FirstFunc()
    sref.SecondFunc();  // SecondFunc()
    sref.SimpleFunc();  // Third's SimpleFunc()

    First &fref = obj;
    fref.FirstFunc();   // FirstFunc()
    fref.SimpleFunc();  // Third's SimpleFunc()

    return 0;
}