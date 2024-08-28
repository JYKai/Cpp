#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;

public:
    SoSimple(int n) : num(n) { }
    SoSimple& AddNum(int n)
    {
        num += n;
        return *this;
    }

    void ShowData(void)
    {
        cout << "num: " << num << endl;
    }

    void ShowData(void) const
    {
        cout << "const num: " << num << endl;
    }
};

void YourFunc(const SoSimple &obj)
{
    obj.ShowData();
}

int main(void)
{
    SoSimple obj1(2);
    const SoSimple obj2(7);
    
    obj1.ShowData();  // num: 2
    obj2.ShowData();  // const num: 7

    YourFunc(obj1);   // const num: 2
    YourFunc(obj2);   // const num: 7

    return 0;
}