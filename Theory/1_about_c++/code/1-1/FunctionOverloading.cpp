#include <iostream>

void Func(void)
{
    std::cout << "Func(void) called!" << std::endl;
}

void Func(char c)
{
    std::cout << "Func(char c) called!" << std::endl;
}

void Func(int a, int b)
{
    std::cout << "Func(int a, int b) called!" << std::endl;
}

int main(void)
{
    Func();
    Func('A');
    Func(12, 13);

    return 0;
}