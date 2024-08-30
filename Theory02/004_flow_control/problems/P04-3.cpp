#include <iostream>

int main()
{
    int num = 1;

    while (num <= 10)
    {
        if (num % 2 == 0)
        {
            std::cout << num << std::endl;
        }
        num++;
        
    }
    
    return 0;
}