#include <iostream>

class character
{
public:
    character() {
        std::cout << "character class!" << std::endl;
    };
};

int main()
{
    character player;
    return 0;
}