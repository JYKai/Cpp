#include <iostream>

int main()
{
    
    int num;
    while (true)
    {
        std::cout << "1 ~ 9사이의 정수를 입력하세요: ";
        std::cin >> num;
        if (num > 0 && num < 10)
            break;
    }

    std::cout << std::endl;

    for (int i = 1; i < 10; i++)
    {
        std::cout << num << " x " << i << " = " << num * i << std::endl;
    }

    return 0;
}