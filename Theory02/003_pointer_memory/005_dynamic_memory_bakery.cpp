#include <iostream>
#include <string>

using namespace std;

int main()
{
    int customer_num;
    cout << "오늘 방문한 손님: ";
    cin >> customer_num;

    string *breads = new string[customer_num];

    for (int i = 0; i < customer_num; i++)
    {
        breads[i] = "빵_" + to_string(i);
    }

    cout << endl << "---생산된 빵---" << endl;
    for (int i = 0; i < customer_num; i++)
    {
        cout << breads[i] << endl;
    }

    delete []breads;
    
    return 0;
}