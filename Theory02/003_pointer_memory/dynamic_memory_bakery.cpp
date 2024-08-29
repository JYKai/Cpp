#include <iostream>
#include <string>

int main()
{
    int customer_num = 0;

    std::cout << "오늘 방문 손님: "; std::cin >> customer_num;

    std::string *bread = new std::string[customer_num];
    
    for (int i = 0; i < customer_num; i++)
    {
        bread[i] = "빵_" + std::to_string(i);
    }

    std::cout << std::endl;
    std::cout << "--생산된 빵--" << std::endl;
    
    for (int i = 0; i < customer_num; i++)
    {
        std::cout << bread[i] << std::endl;
    }

    delete []bread;

    return 0;
}