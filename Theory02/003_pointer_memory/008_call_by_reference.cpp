#include <iostream>
using namespace std;


void swap(int &ref1, int &ref2)
{
    cout << "[swap func] before swap, ref_a: " << ref1 << " ref_b: " << ref2 << endl;
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
    cout << "[swap func] after swap, ref_a: " << ref1 << " ref_b: " << ref2 << endl;
}

int main()
{
    int a = 5;
    int b = 10;

    swap(a, b);

    return 0;
}