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
    catch (float b)
    {
        std::cout << "catch " << b << std::endl;
    }
    catch (char c)
    {
        std::cout << "catch " << c << std::endl;
    }

    return 0;
}