#include <iostream>
using namespace std;

void func()
{
    int a = 10;
    static int b = 10;

    a++;
    b++;

    cout << "a = " << a <<  " b = " << b << endl;
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        func();
    }

    return 0;
}