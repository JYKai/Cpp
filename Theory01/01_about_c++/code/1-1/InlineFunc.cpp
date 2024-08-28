#include <iostream>

inline int SQUARE(int x) { return x*x; }

int main(void)
{
    std::cout << SQUARE(5) << std::endl;  // 25
    std::cout << SQUARE(12) << std::endl; // 144

    return 0;
}