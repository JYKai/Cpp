#include <iostream>
#include <cassert>

void print_number(int *_pt_int)
{
    assert(_pt_int != NULL);    // 디버그 모드에서 _pt_int가 널인지 검사
    std::cout << *_pt_int << std::endl;
}

int main()
{
    int a = 100;
    int *b = NULL;
    int *c = NULL;

    b = &a;
    print_number(b);
    print_number(c);

    return 0;
}