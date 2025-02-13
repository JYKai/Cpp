#include <iostream>
#include <string>

void check_found(std::string::size_type n)
{
    if (n == std::string::npos)
        std::cout << "not found" << std::endl;
    else
        std::cout << "found index: " << n << std::endl;
};

int main()
{
    std::string::size_type n; // size_type : 문자열의 크기를 나타내는 형식(부호 없는 정수)
    std::string str = "This is an example of a standard string.";

    n = str.find("example");
    check_found(n);

    n = str.find("is");
    check_found(n);

    n = str.find("is", 4);
    check_found(n);

    n = str.find('h');
    check_found(n);

    n = str.find('k');
    check_found(n);

    return 0;
}