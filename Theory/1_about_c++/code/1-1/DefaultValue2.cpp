#include <iostream>

int Adder(int num1=1, int num2=2);

int main(void)
{
    std::cout << Adder() << std::endl; // 3
    std::cout << Adder(5) << std::endl; // 7
    std::cout << Adder(1, 5) << std::endl; // 6

    return 0;
}

int Adder(int num1, int num2)
{
    return num1 + num2;
}