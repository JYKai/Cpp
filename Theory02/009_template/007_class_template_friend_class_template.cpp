#include <iostream>


template <typename U>
class caller
{
public:
    caller() : object(nullptr) {};
    void set_object(U *obj_pointer) { object = obj_pointer; }
    void printout_friend_object()
    {
        std::cout << "(friend 클래스 템플릿 호출) 템플릿 매개변수 값 : "
        << object->first << std::endl;
    }
private:
    U *object;
};


template <typename T = int>
class data_package
{
public:
    data_package(T first) : first(first) {}
    friend caller<data_package>;
private:
    T first;
};


int main()
{
    caller<data_package<>> caller_int_obj;
    caller<data_package<std::string>> caller_string_obj;

    data_package<> template_inst1(5);
    data_package<std::string> template_inst2("클래스 템플릿 기본값이 아닌 string형");

    caller_int_obj.set_object(&template_inst1);
    caller_string_obj.set_object(&template_inst2);

    caller_int_obj.printout_friend_object();
    caller_string_obj.printout_friend_object();

    return 0;
}