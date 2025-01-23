#include <iostream>

int main()
{
    int divisor = 0;
    try
    {
        if (divisor == 0)
            throw divisor;
        
        int result = 10 / divisor;
        std::cout << "결과: " << result << std::endl;
    }
    catch (int except)
    {
        std::cout << except << "로 숫자를 나눌 수 없습니다." << std::endl;
    }

    return 0;
}