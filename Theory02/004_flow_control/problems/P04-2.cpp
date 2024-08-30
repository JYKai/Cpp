#include <iostream>

int main()
{
    int number;
    std::cout << "1 ~ 7 사이의 수를 입력하세요: "; std::cin >> number;

    switch (number)
    {
    case 1:
        std::cout << "월요일" << std::endl;
        break;
    case 2:
        std::cout << "화요일" << std::endl;
        break;
    case 3:
        std::cout << "수요일" << std::endl;
        break;
    case 4:
        std::cout << "목요일" << std::endl;
        break;
    case 5:
        std::cout << "금요일" << std::endl;
        break;
    case 6:
        std::cout << "토요일" << std::endl;
        break;
    case 7:
        std::cout << "일요일" << std::endl;
        break;
    default:
        std::cout << "1 ~ 7 사이의 정수를 입력하세요." << std::endl;
        break;
    }

    return 0;
}