#include <iostream>

class character
{
protected:
    int hp;
    int power;

public:
    character()
        : hp(100), power(100) {};
};


class player : public character
{
public:
    player() {};
};


class monster
{
public:
    monster() {};
    void get_damage(int _damage);
    void attack(player target_player);
    virtual void attack_special(player target_player);
};

void monster::attack_special(player target_player)
{
    std::cout << "기본 공격 : 데미지 - 10 hp" << std::endl;
}


class monster_a : public monster, character
{
public:
    virtual void attack_special(player target_player) override;
};

void monster_a::attack_special(player target_player)
{
    std::cout << "인텡글 공격 : 데미지 - 15 hp" << std::endl;
};


int main()
{
    player player_1;

    monster_a forest_monster;

    monster &mon = forest_monster;
    monster_a &mon_a = forest_monster;

    std::cout << std::endl << "부모 클래스로 업캐스팅 후 공격" << std::endl;
    mon.attack_special(player_1);

    std::cout << std::endl << "자식 클래스로 공격" << std::endl;
    mon_a.attack_special(player_1);

    std::cout << std::endl << "범위 연산자로 공격" << std::endl;
    mon_a.monster::attack_special(player_1);

    return 0;
}