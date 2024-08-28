#include <iostream>
using namespace std;

class AAA
{
public:
    AAA() { cout << "empty object" << endl; }
    void ShowYourName(void) { cout << "I'm class AAA" << endl; }
};

class BBB
{
private:
    AAA &ref;
    const int &num;

public:
    BBB(AAA &r, const int &n)
        : ref(r), num(n)
    { }
    void ShowYourName(void)
    {
        ref.ShowYourName();
        cout << "and" << endl;
        cout << "I'm ref num " << num << endl;
    }
};

int main(void)
{
    AAA obj1;
    BBB obj2(obj1, 20);
    obj2.ShowYourName();

    return 0;
}