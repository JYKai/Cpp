#include <iostream>
#include <cstring>

int main()
{
    std::string name;
    std::string number;

    std::cout << "이름을 입력하세요: ";
    std::getline(std::cin, name);

    std::cout << "전화번호를 입력하세요: ";
    std::getline(std::cin, number);

    std::cout << "이름: " << name << std::endl;
    std::cout << "전화번호: " << number << std::endl;

    return 0;
}