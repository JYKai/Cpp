#include <iostream>
#include <random>
#include <chrono>

int main()
{
    auto curTime = std::chrono::system_clock::now();
    auto duration = curTime.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

    std::mt19937_64 mt_rand(millis);

    for (int i = 0; i < 10; i++)
        std::cout << mt_rand() << std::endl;
    
    return 0;
}