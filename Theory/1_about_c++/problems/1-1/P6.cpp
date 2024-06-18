#include <iostream>
using namespace std;

int BoxVolume(int num1, int num2, int num3);
int BoxVolume(int num1, int num2);
int BoxVolume(int num1);

int main(void)
{
    cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << endl;
    cout << "[5, 5, D] : " << BoxVolume(5, 5) << endl;
    cout << "[7, D, D] : " << BoxVolume(7) << endl;

    return 0;
}

int BoxVolume(int num1, int num2, int num3)
{
    return num1 * num2 * num3;
}
int BoxVolume(int num1, int num2)
{
    return num1 * num2;
}
int BoxVolume(int num1)
{
    return num1;
}