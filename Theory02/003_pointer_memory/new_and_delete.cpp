#include <iostream>

int main()
{
    int *pt_int_value = new int;    // 동적 메모리 할당
    *pt_int_value = 100;

    std::cout << *pt_int_value << std::endl;

    delete pt_int_value;        // 동적 메모리 해제

    return 0;
}