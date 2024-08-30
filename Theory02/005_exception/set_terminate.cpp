#include <iostream>
#include <cstdlib>

void myterminate()
{
    std::cout << "myterminate called" << std::endl;
    exit(-1);       // 프로그램을 비정상으로 종료, <cstdlib>
}

int main(void)
{
    std::set_terminate(myterminate);    // 종료 처리 함수 지정
    throw 1;    // 예외 발생

    return 0;   // throw로 예외를 던졌으므로 실행되지 않음.

}