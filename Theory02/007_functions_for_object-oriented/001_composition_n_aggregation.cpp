#include <iostream>
using namespace std;


class character
{
protected:
    int hp;
    int power;

public:
    character() : hp(100), power(100) {};
    int get_hp() { return hp; }
    int get_power() { return power; }
};


// character 클래스를 상속 받은 player 클래스
class player
{
private:
    character main_body;
public:
    player() {};
};


class monster
{
public:
    monster() {};
    void get_damage(int _damage) {};
    virtual void attack(player target_player)
    {
        cout << "공격 : 데미지 - 10 hp" << endl;
    };
};


class monster_2nd_gen : public monster
{
public:
    virtual void attack(player target_plager) override
    {
        cout << "새로운 공격 : 데이지 - 30 hp" << endl;
    };
};


// 몬스터 A는 monster, character 클래스를 컴포지션으로 포함
class monster_a
{
private:
    character main_body;
    monster main_role;
public:
    void attack(player target_player)
    {
        main_role.attack(target_player);
    };
};


// 몬스터 B는 monster, character 클래스를 어그리게이션으로 포함
class monster_b
{
private:
    character& main_body;
    monster& main_role;
public:
    // 레퍼런스 멤버 변수는 초기화 리스트로 초기화 진행
    monster_b(character& ref_character, monster& ref_monster)
        : main_body(ref_character), main_role(ref_monster) {};
    void attack(player target_player)
    {
        main_role.attack(target_player);
    };
};


int main()
{
    // 어그리게이션에 포함할 객체 생성 - 몬스터 클래스의 생명 주기 다름
    character character_obj;
    monster monster_obj;
    monster_2nd_gen monster_new_obj;

    player player_1;

    // 컴포지션을 객체와 생명주기가 같아 객체에서 직접 생성
    monster_a forest_monster;

    // 어그리게이션을 위해서 외부의 객체의 참조를 전달
    monster_b tutorial_monster(character_obj, monster_obj);
    monster_b urban_monster(character_obj, monster_new_obj);

    cout << "몬스터 A 공격" << endl;
    tutorial_monster.attack(player_1);

    cout << endl << "몬스터 B 공격" << endl;
    forest_monster.attack(player_1);
    urban_monster.attack(player_1);

    return 0;
}