#include <iostream>
#include <string>

void compare_result(int result)
{
    if (result == 0)
        std::cout << result << " = 두 문자열이 같음" << std::endl;
    else if (result > 0)
        std::cout << result << " = 대상 문자열이 더 길거나 일치하지 않는 첫 번째 문자가 더 큼" << std::endl;
    else if (result < 0)
        std::cout << result << " = 대상 문자열이 더 짧거나 일치하지 않는 첫 번째 문자가 더 작음" << std::endl;
}

int main()
{
    std::string s1 = "Hello";
    std::string s2 = "Hello";
    int result = s1.compare(s2);
    compare_result(result);

    s1 = "Hello";
    s2 = "Hello World!";
    result = s1.compare(s2);
    compare_result(result);

    s1 = "cat";
    s2 = "dog";
    result = s1.compare(s2);
    compare_result(result);

    s1 = "Hello World";
    s2 = "Hello";
    result = s1.compare(s2);
    compare_result(result);

    s1 = "cat";
    s2 = "apple";
    result = s1.compare(s2);
    compare_result(result);

    return 0;
}