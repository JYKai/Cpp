#include <iostream>
#include <cstring>
using namespace std;

class Printer
{
private:
    char str[30];

public:
    void SetString(char *s);
    void ShowSting(void);
};

void Printer::SetString(char *s)
{
    strcpy(str, s);
}

void Printer::ShowSting(void)
{
    cout << str << endl;
}

int main(void)
{
    Printer pnt;
    pnt.SetString("Hello world!");
    pnt.ShowSting();

    pnt.SetString("I love C++");
    pnt.ShowSting();

    return 0;
}