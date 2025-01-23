#include <iostream>

void process(int value)
{
    try
    {
        if (value < 0)
            throw value;
        std::cout << value << std::endl;
    }
    catch(int except)
    {
        std::cerr << "예외 발생!" << std::endl;
    }
}

int main()
{
    process(10);
    process(-5);

    return 0;
}