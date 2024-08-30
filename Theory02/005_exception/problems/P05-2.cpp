#include <iostream>

void process(int value)
{
    try
    {
        if (value < 0)
        {
            throw std::runtime_error("음수 값을 처리할 수 없습니다!");
        }
        std::cout << "value = " << value << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "예외 발생!" << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "처리에 실패했습니다..." << std::endl;
    }
}

int main()
{
    process(10);
    process(-5);
    return 0;
}