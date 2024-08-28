#include <iostream>

using namespace std;

int main(void)
{
    int num;
    cout << "숫자를 입력하세요: ";
    cin >> num;

    for (int i = 1; i < 10; i++)
    {
        cout << num << " x " << i << " = " << num * i << endl; 
    }

    return 0;
}