#include <iostream>
#include <string>
using namespace std;

struct Monster
{
    string name;
    int attack;
    int health;
};

void MonsterInfo(Monster mon[], int _count)
{
    for (int i = 0; i < _count; i++)
    {
        cout << "Monster [" << mon[i].name << "]" << endl;
        cout << "--Health : " << mon[i].health << endl;
        cout << "--Attack : " << mon[i].attack << endl;
    }
}

int main()
{
    Monster mon[2] = 
    {
        {"Zeg", 50, 5},
        {"Proto", 100, 15}
    };

    MonsterInfo(mon, 2);

    return 0;
}