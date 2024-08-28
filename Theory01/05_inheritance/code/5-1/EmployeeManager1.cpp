#include <iostream>
#include <cstring>
using namespace std;


// PermanentWorker 클래스 정의
class PermanentWorker
{
private:
    char name[100];
    int salary;     // 매달 지불해야 하는 급여액

public:
    PermanentWorker(char *name, int money)
        : salary(money)
    {
        strcpy(this->name, name);
    }
    int GetPay(void) const { return salary; }
    void ShowSalaryInfo(void) const
    {
        cout << "name = " << name << endl;
        cout << "salary = " << salary << endl << endl;
    }
};


// EmployHandler 클래스 정의
class EmployHandler
{
private:
    PermanentWorker* empList[50];
    int empNum;

public:
    EmployHandler() : empNum(0) { }
    void AddEmployee(PermanentWorker* emp) { empList[empNum++] = emp; }
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

    // 직원 등록
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    handler.AddEmployee(new PermanentWorker("JUN", 2000));

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    // 이번 달에 지불해야 할 급여의 총합
    handler.ShowTotalSalary();

    return 0;
}