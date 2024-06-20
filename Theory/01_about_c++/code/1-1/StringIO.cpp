#include <iostream>

int main(void)
{
    char name[100];
    char lang[200];

    std::cout << "이름을 입력하시오. ";
    std::cin >> name;

    std::cout << "좋아하는 프로그래밍 언어를 입력하시오. ";
    std::cin >> lang;

    std::cout << "이름: " << name << std::endl;
    std::cout << "좋아하는 프로그래밍 언어: " << lang << std::endl;

    return 0;
}