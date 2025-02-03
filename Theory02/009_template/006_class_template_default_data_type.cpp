#include <iostream>


template <typename T = int>
class data_package
{
public:
    data_package(T first) : first(first) {}
    void print_out_element()
    {
        std::cout << "템플릿 매개변수 값: " << first << std::endl;
    }
private:
    T first;
};


int main()
{
    data_package<> template_inst1(5);
    data_package<std::string> template_inst2("클래스 템플릿 기본값이 아닌 string형");

    template_inst1.print_out_element();
    template_inst2.print_out_element();

    return 0;
}