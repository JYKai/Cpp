// string으로 문자열 사용하기

#include <iostream>
// #include <string> // iostream 헤더에 string도 포함됨

int main()
{
    std::string string_value("Hello");
    std::cout << string_value << std::endl;

    string_value = "World!";
    std::cout << string_value << std::endl;

    return 0;
}