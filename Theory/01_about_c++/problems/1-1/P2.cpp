#include <iostream>
using namespace std;

int main(void)
{
    char name[20];
    char number[20];

    cout << "이름을 입력하세요: ";
    cin >> name;
    cout << "전화번호를 입력하세요: ";
    cin >> number;

    cout << "이름은 " << name << "입니다." << endl;
    cout << "전화번호는 " << number << "입니다." << endl;

    return 0;
}