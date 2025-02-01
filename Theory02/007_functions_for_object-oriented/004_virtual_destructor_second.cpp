#include <iostream>


class monster
{
private:
    int *dummy;

public:
    monster();
    virtual ~monster();
};

monster::monster()
{
    std::cout << "monster() 생성자 호출" << std::endl;
    dummy = new int;
}

monster::~monster()
{
    std::cout << "~monster() 소멸자 호출" << std::endl;
    delete dummy;
}


class monster_a : public monster
{
private:
    int *dummy_a;

public:
    monster_a();
    virtual ~monster_a() override;
};

monster_a::monster_a()
{
    std::cout << "monster_a() 생성자 호출" << std::endl;
    dummy_a = new int;
}

monster_a::~monster_a()
{
    std::cout << "~monster_a() 소멸자 호출" << std::endl;
    delete dummy_a;
}


int main()
{
    monster_a *mon = new monster_a;

    delete mon;
    return 0;
}