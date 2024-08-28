#include <iostream>

using namespace std;

int main(void)
{
    
    int num_list[5];
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << "번째 정수 입력: ";
        cin >> num_list[i];
    }

    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += num_list[i];
    }

    cout << "합계: " << sum << endl;

    return 0;
}