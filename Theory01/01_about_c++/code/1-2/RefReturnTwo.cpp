#include <iostream>
using namespace std;

int& RefRetFuncTwo(int &ref);

int main(void)
{
    int num1 = 1;
    int num2 = RefRetFuncTwo(num1);

    num1++;
    num2 += 100;

    cout << "num1: " << num1 << endl;   // num1: 3
    cout << "num2: " << num2 << endl;   // num2: 102

    return 0;
}

int& RefRetFuncTwo(int &ref)
{
    ref++;
    return ref;
}