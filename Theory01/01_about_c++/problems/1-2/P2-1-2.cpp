#include <iostream>
using namespace std;

void SwapPtr(int *(&ref1), int *(&ref2));

int main(void)
{
    int num1 = 5, num2 = 10;
    int *ptr1 = &num1;
    int *ptr2 = &num2;

    SwapPtr(ptr1, ptr2);

    cout << "ptr1 = " << *ptr1 << endl;
    cout << "ptr2 = " << *ptr2 << endl;

    return 0;
}

void SwapPtr(int *(&ref1), int *(&ref2))
{
    int *temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}