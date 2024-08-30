#include <iostream>

int main()
{
    try
    {
        int divisor;
        std::cout << "나눗셈을 위한 정수 입력: ";
        std::cin >> divisor;

        if (divisor == 0)
        {
            throw std::runtime_error("0으로 나눌 수 없습니다!");    // 런타임 오류를 나타내는 예외 클래스입니다.
        }

        int result = 10 / divisor;
        std::cout << "Result = " << result << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << "예외 발생: " << e.what() << std::endl;    // e.what(): 예외 메시지를 출력합니다.
    }
    return 0;
}