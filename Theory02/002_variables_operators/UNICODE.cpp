#include <iostream>
#include <locale> // 로케일 설정에 필요
#include <unistd.h> // POSIX 시스템 호출
#include <fcntl.h>

using namespace std;

int main()
{
    // 로케일 설정: 모든 로케일에 대해 기본 로케일 사용
    setlocale(LC_ALL, ""); // POSIX 표준 방식
    wcout.imbue(locale("")); // C++ 방식
    
    wchar_t message_korean[] = L"반갑다 세계야!";

    cout << "Hello, World!" << endl;
    wcout << message_korean << endl;

    return 0;
}