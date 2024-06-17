#include <iostream>
using namespace std;

void ImpNum(int &ref);
void ReverseNum(int &ref);

int main(void)
{
    int num = 5;
    ImpNum(num);
    cout << "num = " << num << endl;

    ReverseNum(num);
    cout << "num = " << num << endl;

    return 0;
}

void ImpNum(int &ref) { ref++; }
void ReverseNum(int &ref) { ref = ref * -1; }