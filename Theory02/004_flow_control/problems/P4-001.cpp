#include <iostream>

int main()
{
    int num;
    std::cout << "수를 입력하세요: ";
    std::cin >> num;

    if (num > 0)
        std::cout << "양수" << std::endl;
    else
        std::cout << "음수" << std::endl;
    
    return 0;
}