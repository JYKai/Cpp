#include <iostream>
using namespace std;

int main(void)
{
    const double RATE = 0.12;
    const int DEFAULT = 50;

    while (true)
    {
        int sell;
        cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
        cin >> sell;

        if (sell == -1) { break; }
        else if (sell != -1)
        {
            cout << "이번 달 급여: " << sell * RATE + DEFAULT << "만원" << endl;
        }
    }

    cout << "프로그램을 종료합니다." << endl;
    return 0;
}