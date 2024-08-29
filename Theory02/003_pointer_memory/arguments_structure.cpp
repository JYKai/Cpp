#include <iostream>

struct Person
{
    std::string name;
    int age;
    float height;
    float weight;
};

void check_age(Person *_adult, int _count); // 포인터 변수 전달을 통해 메모리 낭비 방지

int main()
{
    Person adults[3] = 
    {
        {"Brain", 24, 180, 70}, // 중괄호 초기화
        {"Jessica", 22, 165, 55},
        {"James", 30, 170, 65},
    };

    int adults_len = sizeof(adults) / sizeof(Person);

    check_age(adults, adults_len);

    return 0;
}

void check_age(Person *_adult, int _count)
{
    for (int i = 0; i < _count; i++)
    {
        if (_adult[i].age >= 25)
        {
            std::cout << "Name: " << _adult[i].name << std::endl;
            std::cout << "Age: " << _adult[i].age << std::endl;
            std::cout << "Height: " << _adult[i].height << std::endl;
            std::cout << "Weight: " << _adult[i].weight << std::endl;
        }
    }
}