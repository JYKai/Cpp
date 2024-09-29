#include <iostream>

using namespace std;


// 캐릭터 클래스
class Character
{
protected:
    int hp;
    int power;

public:
    Character() : hp(100), power(100) { };
};

// 플레이어 클래스
class Player : public Character
{
public:
    Player() { };
};

// 기본 몬스터 클래스
class Monster
{
public:
    Monster(){};
    void get_damage(int _damage){};
    void attack(Player target_player){};
    void attack_special(Player target_player);
};

void Monster::attack_special(Player target_player)
{
    cout << "기본 공격 : 데미지 - 10 hp" << endl;
}

// 기본 몬스터 클래스 상속
class MonsterA : public Monster, Character
{
public:
    // 상속받은 함수 오버라이딩
    void attack_special(Player target_player);
};

void MonsterA::attack_special(Player target_player)
{
    cout << "인텡글 공격 : 데이지 - 15 hp" << endl;
}


class MonsterB : public Monster, Character
{
public:
    // 상속받은 함수 오버라이딩
    void attack_special(Player target_player);
};

void MonsterB::attack_special(Player target_player)
{
    cout << "가상 공격 : 데이지 - 0 hp" << endl;
}


class MonsterC : public Monster, Character
{
public:
    // 상속받은 함수 오버라이딩
    void attack_special(Player target_player);
};

void MonsterC::attack_special(Player target_player)
{
    cout << "강력 뇌전 공격 : 데이지 - 100 hp" << endl;
}


int main()
{
    Player player_1;

    MonsterA forest_monster;
    MonsterB tutorial_monster;
    MonsterC boss_monster;

    cout << "몬스터 총 공격" << endl;

    forest_monster.attack_special(player_1);
    tutorial_monster.attack_special(player_1);
    boss_monster.attack_special(player_1);

    return 0;
}