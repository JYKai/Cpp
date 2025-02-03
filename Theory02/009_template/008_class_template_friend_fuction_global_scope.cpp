#include <iostream>


template <typename T = int>
class data_package
{
public:
    data_package(T first) : first(first) {}
    template <typename C>
    friend void printout_friend_element(C &data_object);
private:
    T first;
};

template <typename C>
void printout_friend_element(C &data_object)
{
    std::cout << "(friend 클래스 템플릿 호출) 템플릿 매개변수 값 : "
        << data_object.first << std::endl;
}


int main()
{
    data_package<> template_inst1(5);
    data_package<std::string> template_inst2("클래스 템플릿 기본값이 아닌 string형");

    printout_friend_element(template_inst1);
    printout_friend_element(template_inst2);

    return 0;
}