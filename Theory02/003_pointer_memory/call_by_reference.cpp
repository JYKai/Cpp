#include <iostream>

void swap(int &ref_a, int &ref_b);

int main(void)
{
    int a = 10, b = 20;

    std::cout << "[main] before swap, " << "a: " << a << " " << "b: " << b << std::endl;
    swap(a, b);
    std::cout << "[main] after swap, " << "a: " << a << " " << "b: " << b << std::endl;

    return 0;
}

void swap(int &ref_a, int &ref_b)
{
    std::cout << "[swap func] before swap, " << "ref_a: " << ref_a << " " << "ref_b: " << ref_b << std::endl;

    int temp = ref_a;
    ref_a = ref_b;
    ref_b = temp;

    std::cout << "[swap func] after swap, " << "ref_a: " << ref_a << " " << "ref_b: " << ref_b << std::endl;
}