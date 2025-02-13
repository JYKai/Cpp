#include <iostream>
#include <string>

int main()
{
    setlocale(LC_ALL, "");

    std::wstring korString = L"안녕하세요";
    std::wcout << korString << std::endl;
    
    return 0;
}