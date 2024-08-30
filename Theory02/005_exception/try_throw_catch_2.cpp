#include <iostream>

int main()
{
    try
    {
        int input;
        std::cout << "정수 중 하나를 입력하세요 : ";
        std::cin >> input;

        if (input > 0)
        {
            std::cout << "throw 1" << std::endl;
            throw 1;
            std::cout << "after throw 1" << std::endl;
        }

        if (input < 0)
        {
            std::cout << "throw -1.0f" << std::endl;
            throw -1.0f;
            std::cout << "after throw -1.0f" << std::endl;
        }

        if (input == 0)
        {
            std::cout << "throw Z" << std::endl;
            throw 'Z';
            std::cout << "after throw Z" << std::endl;
        }
    }
    catch (int a)
    {
        std::cout << "catch " << a << std::endl;
    }
    catch (...) // 처리되지 않은 나머지 예외 모두 받기
    {
        std::cout << "catch all" << std::endl;
    }

    return 0;
}