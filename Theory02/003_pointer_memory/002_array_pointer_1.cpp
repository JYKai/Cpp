#include <iostream>

using namespace std;

int main()
{
    int int_array[3] = { 1, 2, 3 };

    cout << "int_array[0] Address: " << &int_array[0] << endl;
    cout << "int_array[1] Address: " << &int_array[1] << endl;
    cout << "int_array[2] Address: " << &int_array[2] << endl << endl;

    cout << "(int_array + 0) Address: " << int_array + 0 << endl;
    cout << "(int_array + 1) Address: " << int_array + 1 << endl;
    cout << "(int_array + 2) Address: " << int_array + 2 << endl << endl;

    return 0;
}