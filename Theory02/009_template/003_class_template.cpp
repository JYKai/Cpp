#include <iostream>

template <typename Type1, typename Type2>
class data_package
{
public:
    data_package(Type1 first, Type2 second)
        : first(first), second(second) { }
    void print_out_element()
    {
        std::cout << "첫 번째 요소: " << first << ", 두 번째 요소: " << second << std::endl;
    }
private:
    Type1 first;
    Type2 second;
};


int main()
{
    data_package<int, double> template_inst1(5, 10.5);
    data_package<std::string, int> template_inst2("문자열", 10);

    template_inst1.print_out_element();
    template_inst2.print_out_element();

    return 0;
}