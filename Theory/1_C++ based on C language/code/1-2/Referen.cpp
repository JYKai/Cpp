#include <iostream>
using namespace std;

int main(void)
{
    int num1 = 1020;
    int &num2 = num1;

    num2 = 3048;

    cout << "VAL: " << num1 << endl;        // VAL: 3048
    cout << "REF: " << num2 << endl;        // REF: 3048

    cout << "VAL: " << &num1 << endl;       // VAL: 0x16ef6b0f8
    cout << "REF: " << &num2 << endl;       // REF: 0x16ef6b0f8

    return 0;
}