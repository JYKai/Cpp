#include <iostream>

int main(void)
{
    int val1, val2 = 0;
    std::cout << "두 개의 숫자 입력: "; // 두 개의 숫자 입력: 1 3
    std::cin >> val1 >> val2;

    int result = val1 + val2;
    std::cout << "덧셈결과: " << result << std::endl; // 덧셈결과: 4
    
    return 0;
}