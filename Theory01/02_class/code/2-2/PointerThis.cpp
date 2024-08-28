#include <iostream>
#include <cstring>
using namespace std;

class SoSimple
{
private:
    int num;

public:
    SoSimple(int n) : num(n)
    {
        cout << "num = " << num << ", ";
        cout << "address = " << this << endl;
    }
    void ShowSimpleData(void) { cout << num << endl; }
    SoSimple *GetThisPointer(void) { return this; }
};

int main(void)
{
    SoSimple sim1(100);
    SoSimple *ptr1 = sim1.GetThisPointer();

    cout << ptr1 << ", ";           // num = 100, address = 0x16d0df158
    ptr1 -> ShowSimpleData();       // 0x16d0df158, 100

    SoSimple sim2(200);
    SoSimple *ptr2 = sim2.GetThisPointer();

    cout << ptr2 << ", ";           // num = 200, address = 0x16d0df14c
    ptr2 -> ShowSimpleData();       // 0x16d0df14c, 200

    return 0;
}