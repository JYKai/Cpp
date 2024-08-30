#include <iostream>

void func_throw()
{
    std::cout << "func_throw()" << std::endl;
    std::cout << "throw -1" << std::endl;

    throw -1;

    std::cout << "after throw -1" << std::endl;
}

int main()
{
    try
    {
        func_throw();   // 예외 처리의 책임은 throw가 발생한 함수를 호출한 쪽으로 넘어간다.
    }
    catch(int exec)
    {
        std::cout << "catch " << exec << std::endl;
    }

    return 0;
}