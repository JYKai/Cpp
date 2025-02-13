#include <iostream>
#include <vector>
#include <algorithm>

struct Person
{
    std::string name;
    int age;
    float height;
    float weight;
};

void print_person_all(std::vector<Person>& vec)
{
    for (std::vector<Person>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << "이름: " << it->name << "\t > " << "나이: " << it->age << ", "
        << "키: " << it->height << ", " << "몸무게: " << it->weight << std::endl;
    }
}

int main()
{
    Person p[5] = {
        {"Brain", 24, 180, 70},
        {"Jessica", 22, 165, 55},
        {"James", 30, 170, 65},
        {"Tom", 12, 155, 46},
        {"Mary", 18, 172, 62}
    };

    std::vector<Person> from_vector;
    from_vector.push_back(p[0]);
    from_vector.push_back(p[1]);
    from_vector.push_back(p[2]);
    from_vector.push_back(p[3]);
    from_vector.push_back(p[4]);

    std::cout << "-----from_vector-----" << std::endl;
    print_person_all(from_vector);
    std::cout << std::endl;

    std::vector<Person> to_vector;
    std::copy(from_vector.begin(), from_vector.end(), std::back_insert_iterator(to_vector));
    
    std::cout << "-----to_vector-----" << std::endl;
    print_person_all(to_vector);
    std::cout << std::endl;

    from_vector[0].name = "Chris";
    from_vector[0].age = 5;
    from_vector[0].height = 110;
    from_vector[0].weight = 20;

    std::cout << "-----from_vector-----" << std::endl;
    print_person_all(from_vector);
    std::cout << std::endl;

    std::cout << "-----to_vector-----" << std::endl;
    print_person_all(to_vector);
    std::cout << std::endl;

    return 0;
}