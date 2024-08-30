#include <iostream>

int main()
{
    int number;
    std::cout << "정수를 입력하세요: "; std::cin >> number;

    if (number >= 0){
        std::cout << "입력된 정수 " << number << "는 양수입니다." << std::endl;
    }
    else {
        std::cout << "입력된 정수 " << number << "는 음수입니다." << std::endl;
    }
    
    return 0;
}