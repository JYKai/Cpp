#include <iostream>
using namespace std;

class Calculator
{
private:
    int addCnt;
    int minCnt;
    int divCnt;
    int mulCnt;

public:
    void Init()
    {
        addCnt = 0;
        minCnt = 0;
        divCnt = 0;
        mulCnt = 0;
    }
    double Add(double num1, double num2);
    double Div(double num1, double num2);
    double Min(double num1, double num2);
    double Mul(double num1, double num2);
    void ShowOpCount(void);
};

double Calculator::Add(double num1, double num2)
{
    addCnt++;
    return (num1 + num2);
}

double Calculator::Min(double num1, double num2)
{
    minCnt++;
    return (num1 - num2);
}

double Calculator::Mul(double num1, double num2)
{
    mulCnt++;
    return (num1 * num2);
}

double Calculator::Div(double num1, double num2)
{
    if (num2 == 0)
    {
        cout << "영으로 나눌 수 없습니다." << endl;
        return -1;
    }
    divCnt++;
    return (num1 / num2);
}

void Calculator::ShowOpCount(void)
{
    cout << "덧셈: " << addCnt << " " << "뺄셈: " << minCnt << " " << "곱셈: " << mulCnt << " " << "나눗셈: " << divCnt << endl;
}


int main(void)
{
    Calculator cal;
    cal.Init();
    cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
    cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
    cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
    cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
    cal.ShowOpCount();

    return 0;
}