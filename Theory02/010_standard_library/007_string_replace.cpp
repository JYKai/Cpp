#include <iostream>
#include <string>

int main()
{
    std::string str1("Hello World!");
    std::cout << "Original String = " << str1 << std::endl;

    str1.replace(6, 5, "C++");
    std::cout << "Replaced String = " << str1 << std::endl;

    return 0;
}