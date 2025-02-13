#include <iostream>
#include <string>


int main()
{
    std::string str1("Hello");
    str1.append(" World!");
    std::cout << str1 << std::endl;

    std::string str2("Hello");
    str2.append(" World!", 6, 1);
    std::cout << str2 << std::endl;

    return 0;
}