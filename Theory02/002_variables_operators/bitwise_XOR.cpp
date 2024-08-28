// 비트 AND 연산하기
// std::bitset<8> = 정수를 8비트 이진수로 변환하여 출력

#include <iostream>
#include <bitset>

int main()
{
    int a = 13;
    int b = 27;
    int c = a ^ b;

    std::cout << "a = " << std::bitset<8>(a) << " : " << a << std::endl;
    std::cout << "b = " << std::bitset<8>(b) << " : " << b << std::endl;
    std::cout << "c = " << std::bitset<8>(c) << " : " << c << std::endl;

    return 0;
}