#include <iostream>
#include <cstring>
using namespace std;

namespace RISK_LEVEL
{
    enum {RISK_A=30, RISK_B=20, RISK_C=10};
}

class Employee
{
private:
    char name[100];

public:
    Employee(char *name)
    {
        strcpy(this->name, name);
    }
    void ShowYourName(void) const
    {
        cout << "name = " << name << endl;
    }
    virtual int GetPay(void) const = 0;
    virtual void ShowSalaryInfo(void) const = 0;
};


// PermanentWorker 클래스 정의
class PermanentWorker : public Employee
{
private:
    int salary;     // 매달 지불해야 하는 급여액

public:
    PermanentWorker(char *name, int money)
        : Employee(name), salary(money)
    { }
    int GetPay(void) const { return salary; }
    void ShowSalaryInfo(void) const
    {
        ShowYourName();
        cout << "salary = " << GetPay() << endl << endl;
    }
};


// SalesWorker 클래스 정의
class SalesWorker : public PermanentWorker
{
private:
    int salesResult;
    double bonusRatio;

public:
    SalesWorker(char *name, int money, double ratio)
        : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    { }
    void AddSalesResult(int value) { salesResult += value; }
    int GetPay(void) const
    {
        return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
    }
    void ShowSalaryInfo(void) const
    {
        ShowYourName();
        cout << "salary = " << GetPay() << endl << endl;
    }
};


// ForeignSaleWorker
class ForeignSaleWorker : public SalesWorker
{
private:
    int riskLevel;

public:
    ForeignSaleWorker(char *name, int money, double ratio, int level)
        : SalesWorker(name, money, ratio), riskLevel(level)
    { }
    void ShowSalaryInfo(void) const
    {
        ShowYourName();
        cout << "salary = " << SalesWorker::GetPay() << endl;
        cout << "risk pay = " << (int)(SalesWorker::GetPay() * ((double)riskLevel / 100)) << endl;
        cout << "sum = " << SalesWorker::GetPay() + \
        (int)(SalesWorker::GetPay() * ((double)riskLevel / 100)) << endl << endl;
    }
};


// TemporaryWorker 클래스 정의
class TemporaryWorker : public Employee
{
private:
    int workTime;
    int payPerHour;

public:
    TemporaryWorker(char *name, int pay)
        : Employee(name), workTime(0), payPerHour(pay)
    { }
    void AddWorkTime(int time) { workTime += time; }
    int GetPay(void) const { return workTime * payPerHour; }
    void ShowSalaryInfo(void) const
    {
        ShowYourName();
        cout << "salary = " << GetPay() << endl << endl;
    }
};



// EmployHandler 클래스 정의
class EmployHandler
{
private:
    Employee* empList[50];
    int empNum;

public:
    EmployHandler() : empNum(0){ }
    void AddEmployee(Employee* emp) { empList[empNum++] = emp; }
    void ShowAllSalaryInfo(void) const
    {
        for (int i = 0; i < empNum; i++)
        {
            empList[i]->ShowSalaryInfo();
        }
    }
    void ShowTotalSalary(void) const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
        {
            sum +=  empList[i]->GetPay();
        }
        cout << "salary sum = " << sum << endl;
    }
    ~EmployHandler()
    {
        for (int i = 0; i < empNum; i++)
        {
            delete empList[i];
        }
    }
};


int main(void)
{
    // 직원 관리를 목적으로 설계된 컨트롤 클래스의 객체생성
    EmployHandler handler;

    // 해외 영업직 등록
    ForeignSaleWorker *fseller1 = new ForeignSaleWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller1);

    ForeignSaleWorker *fseller2 = new ForeignSaleWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000);
    handler.AddEmployee(fseller2);

    ForeignSaleWorker *fseller3 = new ForeignSaleWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000);
    handler.AddEmployee(fseller3);
    

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();
    return 0;
}