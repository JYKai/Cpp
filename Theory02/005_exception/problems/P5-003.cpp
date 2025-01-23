#include <iostream>
#include <cassert>

void divide(int a, int b)
{
    assert(b != 0);
    std::cout << a / b << std::endl;
}

int main()
{
    divide(10, 2);
    divide(5, 0);

    return 0;
}