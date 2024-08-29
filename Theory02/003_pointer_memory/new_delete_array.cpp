#include <iostream>

int main()
{
    int *pt_int_array_value = new int[5];

    for (int i = 0; i < 5; i++)
    {
        pt_int_array_value[i] = i;
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << pt_int_array_value[i] << std::endl;
    }

    delete[] pt_int_array_value;

    return 0;
}