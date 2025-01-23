#include <iostream>
#include <cstdlib>
using namespace std;

void myterminate()
{
    cout << "myterminate called" << endl;
    exit(-1);   // 프로그램을 비정상으로 종료
}

int main()
{
    set_terminate(myterminate);

    throw 1;

    return 0;
}