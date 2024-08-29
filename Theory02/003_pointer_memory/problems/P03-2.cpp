#include <iostream>

struct Monster
{
    std::string name;
    int hp;
    int attack;
    int defence;
    int speed;
};

void ShowInfo(Monster *_mon, int _count);

int main()
{
    Monster monsters[2] = 
    {
        {"zerg", 50, 5, 2, 5},
        {"protos", 100, 7, 3, 1},
    };

    int len = sizeof(monsters) / sizeof(Monster);

    ShowInfo(monsters, len);

    return 0;
}

void ShowInfo(Monster *_mon, int _count)
{
    for (int i = 0; i < _count; i++)
    {
        std::cout << "Name: " << _mon[i].name << std::endl;
        std::cout << "HP: " << _mon[i].hp << std::endl;
        std::cout << "Attack: " << _mon[i].attack << std::endl;
        std::cout << "Defence: " << _mon[i].defence << std::endl;
        std::cout << "Speed: " << _mon[i].speed << std::endl;
        std::cout << std::endl;
    }
}