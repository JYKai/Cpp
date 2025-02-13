#include <iostream>
#include <random>

int main()
{
    std::mt19937_64 mt_rand;

    for (int i = 0; i < 10; i++)
        std::cout << mt_rand() << std::endl;
    
    return 0;
}