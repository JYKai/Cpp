# 상속(Inheritance)의 이해

## 상속에 들어가기에 앞서
상속이 지니는 문법적 요소를 이해하는 것도 중요하지만, 상속이 가져다 주는 이점을 이해하는 것이 무엇보다 중요하다.

**이해를 위한 과정**  
1. 문제의 제시
2. 기본개념 소개
3. 문제의 해결

서두르지 말고 천천히, 생각을 많이 하면서 진행한다.

### 문제의 제시를 위한 시나리오 도입

**예시**  
OrangeMedia라는 회사가 운영하는 '급여관리 시스템'
- 회사 초기 직원의 근무 형태는 '정규직(Permaent)' 하나였다.
- 시스템 설계는 정규직 직원을 관리하기 위한 형태로 설계되어있다.

**PermanentWorker 클래스 in EmployeeManager1.cpp**  
```c++
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
```
- 데이터적 성격이 강한 클래스

**PermanentWorker 클래스 in EmployeeManager1.cpp**
```c++
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
```
- 기능적인 성격이 강한 클래스 = '컨트롤(control) 클래스' 또는 '핸들러(handler) 클래스'라 한다.
    - 컨트롤 클래스는 기능 제공의 핵심이 되기 때문에 모든 객체지향 프로그램에서 반드시 존재하는 클래스이다.

**소프트웨어의 설계에 있어서 중요시하는 것**  
- 요구사항의 변경에 대응하는 프로그램의 유연성
- 기능의 추가에 따른 프로그램의 확장성


### 문제의 제시
- 문제 : 직원의 고용형태가 다양해짐
    - 영업직(Sales) : 특화된 형태의 고용직으로, 인센티브 개념이 도입됨
    - 임시직(Temporary) : 아르바이트
- 급여 계산방식
    - 고용직 : 매달의 급여가 정해져 있음
    - 영업직 : 기본급여 + 인센티브
    - 임시직 : 시간당 급여 x 일한 시간
- 목표 : EmployeeHandler 클래스를 조금도 변경하지 않도록 코드를 확장시켜야 한다.

</br>

## 상속의 문법적인 이해

### 상속이란?
"A 클래스가 B 클래스를 상속한다"
- A 클래스가 B 클래스를 상속하게 되면, A 클래스는 B 클래스가 지니고 있는 모든 멤버를 물려 받는다.

### 상속받은 클래스의 생성자 정의
- B 클래스의 생성자는 A 클래스의 멤버까지 초기화해야 할 의무가 있다.
- B 클래스의 생성자는 A 클래스의 생성자를 호출해서 A 클래스의 멤버를 초기화하는 것이 좋다.
    - 이니셜라이저를 통해 초기화를 시켜준다.

### 상속관련 완전한 예제의 확인 및 실행
```c++
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    int age;
    char name[50];

public:
    Person(int myage, char *myname) : age(myage)
    {
        strcpy(name, myname);
    }
    void WhatYourName(void) const { cout << "My name is " << name << endl; }
    void HowOldAreYou(void) const { cout << "I'm " << age << " years old" << endl; }
};


class UnivStudent : public Person
{
private:
    char major[50];

public:
    UnivStudent(char *myname, int myage, char *mymajor)
        : Person(myage, myname)
    {
        strcpy(major, mymajor);
    }
    void WhoAreYou(void) const
    {
        WhatYourName();
        HowOldAreYou();
        cout << "My major is " << major << endl << endl;
    }
};


int main(void)
{
    UnivStudent ustd1("Lee", 22, "Computer eng.");
    ustd1.WhoAreYou();

    UnivStudent ustd2("Kim", 24, "Environment eng.");
    ustd2.WhoAreYou();

    return 0;
}
```
- Q. UnivStudent 클래스의 멤버함수(또는 생성자) 내에서는 Person 클래스에 private으로 선언된 멤버변수에 접근이 가능한가?
    - 접근 제한의 기준은 클래스이다. UnivStudent의 멤버함수 내에서는 Person의 멤버변수에 직접 접근이 불가능하다.
    - 상속은 이루어지나, Person 클래스에 정의된 public 함수를 통해서 간접적으로 접근을 해야 한다.
        - '정보의 은닉'은 하나의 객체 내에서도 진행이 된다.


### 유도 클래스의 객체 생성과정
- 유도 클래스의 객체생성 과정에서 기초 클래스의 생성자는 100% 호출된다.
- 유도 클래스의 생성자에서 기초 클래스의 생성자 호출을 명시하지 않으면, 기초 클래스의 void 생성자가 호출된다. 즉, 유도 클래스의 객체생성 과정에서는 생성자가 두 번 호출된다.
- 클래스의 멤버는 해당 클래스의 생성자를 통해서 초기화해햐 한다.

### 유도 클래스 객체의 소멸과정
- 유도 클래스의 객체가 소멸될 때에는, 유도 클래스의 소멸자가 실행되고 난 다음에 기초 클래스의 소멸자가 실행된다.
    - 스택에 생성된 객체의 소멸순서는 생성순서와 반대이다.
- 생성자에서 동적 할당한 메모리 공간은 소멸자에서 해제한다.
```c++
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    int age;
    char * name;

public:
    Person(int myage, char *myname) : age(myage)
    {
        name = new char[strlen(myname) + 1];
        strcpy(name, myname);
    }
    void WhatYourName(void) const { cout << "My name is " << name << endl; }
    void HowOldAreYou(void) const { cout << "I'm " << age << " years old" << endl; }

    ~Person()
    {
        delete []name;
    }
};


class UnivStudent : public Person
{
private:
    char * major;

public:
    UnivStudent(char *myname, int myage, char *mymajor)
        : Person(myage, myname)
    {
        major = new char[strlen(mymajor) + 1];
        strcpy(major, mymajor);
    }
    void WhoAreYou(void) const
    {
        WhatYourName();
        HowOldAreYou();
        cout << "My major is " << major << endl << endl;
    }
    ~UnivStudent()
    {
        delete []major;
    }
};


int main(void)
{
    UnivStudent ustd1("Lee", 22, "Computer eng.");
    ustd1.WhoAreYou();

    UnivStudent ustd2("Kim", 24, "Environment eng.");
    ustd2.WhoAreYou();

    return 0;
}
```
- 두 클래스 모두 자신의 생성자에서 할당한 메모리 공간에 대해 해제만을 책임지고 있다.


</br>


## protected 선언과 세 가지 형태의 상속

### protected로 선언된 멤버가 허용하는 접근의 범위
protected로 선언된 멤버변수는 private와 유사하지만, 다른 점은 이를 상속하는 유도 클래스에서 접근이 가능하다는 점이다.
- 유용하게 사용될 수 있지만, 기초 클래스와 이를 상속하는 유도 클래스 사이에서도 '정보은닉'은 지켜지는 것이 좋으므로 자주 사용되지는 않는다.

### protected 상속
protected보다 접근의 범위가 넓은 멤버는 protected로 변경시켜서 상속하겠다.
- 베이스 클래스를 protected로 상속하면 베이스 클래스의 public 멤버변수는 해당 유도 클래스에서 protected 멤버가 된다.
    - 외부에서의 접근이 불가능한 멤버가 된다.

### private 상속
priavte보다 접근의 범위가 넓은 멤버는 priavte로 변경시켜서 상속하겠다.
- priavte 상속이 이뤄진 클래스를 다시 상속할 경우, 멤버함수를 포함하여 모든 멤버가 '접근불가'가 되기 때문에 사실상 의미 없는 상속이 되고 만다.

### public 상속
public보다 접근의 범위가 넓은 멤버는 public로 변경시켜서 상속하겠다.
- private을 제외한 나머지는 그냥 그대로 상속한다.
- 사실상 C++의 상속은 public 상속만 있다고 생각을 하라

</br>

## 상속을 위한 조건

### 상속을 위한 기본 조건인 IS-A 관계의 성립
- 무선 전화기 is a 전화기
- 노트북 is a 컴퓨터

### HAS-A 관계도 상속의 조건은 되지만 복합 관계롤 이를 대신하는 것이 일반적이다.
- 경찰 has a 총
- 상속으로 묶인 두 개의 클래스는 강환 연관성을 띤다.
    - 총 클래스를 상속하는 경찰 클래스는 총을 소유하는 경찰만 표현 가능하다.
    - 하지만, 상속이 아닌 생성자에서 총 클래스를 생성해서 이를 직접 참조한다면, 멤버변수 총(pistol)을 NULL로 초기화하여 권총을 소지하지 않은 경찰을 표현할 수 있다.
    - 만약, 전기봉을 소유하는 경찰을 표현하고 싶다면 전기봉을 표현하는 객체를 참조하는 멤버변수 하나만 추가하면 된다. 상속을 하게 된다면 다중상속이 발생한다. 이러한 구현방식은 더 복잡한 문제로 이어질 수 있다.
- 결과적으로 상속은 IS-A 관계의 표현에 매우 적절하다. HAS-A 관계의 표현에도 사용될 수 있으나, 프로그램의 변경에 많은 제약을 가져다 줄 수 있다.

</br>

# 상속과 다형성(Polymorphism)

## 객체 포인터의 참조관계

### 객체 포인터 변수: 객체의 주소 값을 저장하는 포인터 변수
```c++
Person *ptr;
ptr = new Person();
```
- Person형 포인터는 Person 객체뿐만 아니라, Person을 상속하는 유도 클래스의 객체도 가리킬 수 있다.
```c++
class Student : public Person
{
    . . . 
};
```
- ```Person *ptr = new Student();```
- Student 클래스를 상속하는 유도 클래스가 존재할 경우 이 또한 Person형 포인터 변수로 가리킬 수 있다.

"C++에서, AAA형 포인터 변수는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 가리킬 수 있다(객체의 주소 값을 저장할 수 있다)."

### '오렌지미디어 급여관리 확장성 문제'의 1차적 해결과 함수 오버라이딩
- 정규직, 영업직, 임시직 모두 고용의 한 형태이다(고용인이다).
- 영업직은 정규직의 일종이다.

"EmloyeeHandler 클래스가 저장 및 관리하는 대상이 Employee 객체가 되게 하면, 이후에 Employee 클래스를 직접 혹은 간접적으로 상속하는 클래스가 추가되었을 때, EmployeeHandler 클래스에는 변화가 발생하지 않는다."ㄴ

```c++
#include <iostream>
#include <cstring>
using namespace std;

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
        // for (int i = 0; i < empNum; i++)
        // {
        //     empList[i]->ShowSalaryInfo();
        // }
    }
    void ShowTotalSalary(void) const
    {
        int sum = 0;
        // for (int i = 0; i < empNum; i++)
        // {
        //     sum +=  empList[i]->GetPay();
        // }
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

    // 정규직 등록
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));

    // 임시직 등록
    TemporaryWorker *alba = new TemporaryWorker("JUNG", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);

    // 영업직 등록
    SalesWorker * seller = new SalesWorker("HONG", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);
    

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    // 이번 달에 지불해야 할 급여의 총합
    handler.ShowTotalSalary();

    return 0;
}
```
- PermanetWorker 클래스에도 GetPay 함수와 ShowSalaryInfo 함수가 있는데, 유도 클래스인 SalesWorker 클래스에도 동일한 이름과 형태로 두 함수를 정의했다. = 함수 오버라이딩
    - 오버라이딩 된 기초 클래스의 함수는, 오버라이딩을 한 유도 클래스의 함수에 의해 가려진다.
- ```PermanentWorker::GetPay()```
    - 오버라이딩 된 기초 클래스의 GetPay 함수를 호출하는 구문이다. -> 클래스의 이름을 명시적으로 적어주면 된다.
- 배열을 구성하는 포인터 변수가 Employee형 포인터 변수이므로, Employee 클래스의 멤버가 아닌 GetPay 함수와 ShowSalaryInfo 함수의 호출부분에서 컴파일 에러가 발생해서 주석처리 되어 있다.
    - Employee형 포인터 변수를 대상으로 이 두 함수를 호출할 수 있도록 해야한다.
        - Employee 클래스에 GetPay 함수와 ShowSalaryInfo 함수를 추가로 선언하고, 이를 가상함수로 선언하면 된다.


Q. SalesWorker 클래스의 ShowSalaryInfo 함수는 PermanentWorker 클래스의 ShowSalaryInfo 함수와 완전히 동일한데 굳이 오버라이딩을 한 이유는 무엇일까?
- 상속을 하여 ShowSalaryInfo 함수를 사용할 수 있다고는 하나 PermamentWorker 클래스의 ShowSalaryInfo 함수 내에서 호출된는 GetPay 함수는 PermamentWorker 클래스에 정의된 GetPay 함수로 호출이 이어진다.
- SalesWorker 클래스의 GetPay 함수가 호출 될 수 있도록 별도의 ShowSalaryInfo 함수를 정의해야만 한다.


**함수 오버라이딩 vs. 함수 오버로딩**  
기초 클래스와 동일한 이름의 함수를 유도 클래스에서 정의한다고 해서 무조건 함수 오버라이딩이 되는 것은 아니다.
- 매개변수의 자료형 및 개수가 다르면, 함수 오버로딩이 되어 잔달되는 인자에 따라서 호출되는 함수가 결정된다.
- 함수 오버로딩은 상속의 관계에서도 구성이 될 수 있다.


</br>


## 가상함수(Virtual Function)

### 기초 클래스의 포인터로 객체를 참조하면,
C++ 컴파일러는 포인터 연산의 가능성 여부를 판단할 때, 포인터의 자료형을 기준으로 판단하지, 실제 가리키는 객체의 자료형을 기준으로 판단하지 않는다.
```c++
int main(void)
{
    Base *bptr = new Derived();     // 컴파일 OK!
    Derived *dptr = bptr;           // 컴파일 ERROR!
}
```
- Derived 클래스는 Base 클래스의 유도 클래스이니까 Base 클래스의 포인터 변수로 Derived 객체의 참조가 가능하다!
- bptr은 Base형 포인터이니까, bptr이 가리키는 대상은 Base 객체일 수도 있다! 따라서, ```Derived *dptr = bptr;```은 컴파일 에러가 발생한다.
    - 컴파일러는 bptr이 실제로 가리키는 객체가 Derived 객체라는 사실을 기억하지 않는다.


### 가상함수(Virtual Function)
"함수를 오버라이딩을 했다는 것은, 해당 객체에서 호출되어야 하는 함수를 바꾼다는 의미인데, 포인터 변수의 자료형에 따라서 호출되는 함수의 종류가 달라지는 것은 문제가 있어 보인다."
- 위와 같은 상황이 발생하지 않도록 '가상함수'를 제공하고 있으며, virtual 키워드의 선언을 통해 이뤄진다.
    - 이렇게 가상함수가 선언되고 나면, 이 함수를 오버라이딩 하는 함수도 가상함수가 된다.
```c++
#include <iostream>
using namespace std;

class First
{
public:
    virtual void MyFunc(void) { cout << "FirstFunc" << endl; }
};

class Second : public First
{
public:
    virtual void MyFunc(void) { cout << "SecondFunc" << endl; }
};

class Third : public Second
{
public:
    virtual void MyFunc(void) { cout << "ThirdFunc" << endl; }
};


int main(void)
{
    Third *tptr = new Third();
    Second *sptr = tptr;
    First *fptr = sptr;

    fptr->MyFunc(); // ThirdFunc
    sptr->MyFunc(); // ThirdFunc
    tptr->MyFunc(); // ThirdFunc
    delete tptr;

    return 0;
}
```
- MyFunc 함수가 virtual로 이미 선언되었으므로, 이후에는 굳이 virtual 선언을 추가하지 않아도 된다. 그러나 virtual 선언을 넣어서 함수가 가상함수임을 알리는 것이 좋다.
- 함수가 가상함수로 선언되면, 해당 함수호출 시, 포인터의 자료형을 기반으로 호출대상을 결정하지 않고, 포인터 변수가 실제로 가리키는 객체를 참조하여 호출의 대상을 결정한다.


```c++
#include <iostream>
#include <cstring>
using namespace std;

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
    virtual int GetPay(void) const { return 0; }
    virtual void ShowSalaryInfo(void) const { }
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

    // 정규직 등록
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));

    // 임시직 등록
    TemporaryWorker *alba = new TemporaryWorker("JUNG", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);

    // 영업직 등록
    SalesWorker * seller = new SalesWorker("HONG", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);
    

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    // 이번 달에 지불해야 할 급여의 총합
    handler.ShowTotalSalary();

    return 0;
}
```
- ShowSalaryInfo 함수와 GetPay 함수는 가상함수이므로 가장 마지막에 오버라이딩을 진행한 함수가 호출된다.


### 순수 가상함수(Pure Virtual Function)와 추상 클래스(Abstract Class)
클래스 중에서는 객체생성을 목적으로 정의되지 않는 클래스도 존재한다.
- 가상함수를 '순수 가상함수'로 선언하여 객체의 생성을 문법적으로 막는 것이 좋다.
- '순수 가상함수'란 '함수의 몸체가 정의되지 않은 함수'를 의미한다.
    - ```virtual int GetPay(void) const = 0;```
    - ```virtual void ShowSalaryInfo(void) const = 0;```
    - '0의 대입'을 표시한다. = 명시적으로 몸체를 정의하지 않았음을 컴파일러에게 알리는 것이다.
- 하나 이상의 멤버함수를 순수 가상함수로 선언한 클래스를 가리켜 '추상 클래스'라 한다.
    - 완전하지 않은, 객체생성이 불가능한 클래스라는 의미를 지닌다.

### 다형성(Polymorphism)
모습은 같은데 형태는 다르다. = 문장은 같은데 결과는 다르다.


</br>

## 가상 소멸자와 참조자의 참조 가능성
가상함수 말고도 virtual 키워드를 붙여줘야 할 대상이 하나 더 있다. 바로 소멸자이다. 즉, virtual 선언은 소멸자에도 올 수 있다.

### 가상 소멸자(Virtual Destructor)
```c++
#include <iostream>
#include <cstring>
using namespace std;

class First
{
private:
    char * strOne;

public:
    First(char *str)
    {
        strOne = new char[strlen(str) + 1];
    }
    ~First()
    {
        cout << "~First()" << endl;
        delete []strOne;
    }
};


class Second : public First
{
private:
    char * strTwo;

public:
    Second(char *str1, char *str2) : First(str1)
    {
        strTwo = new char[strlen(str2) + 1];
    }
    ~Second()
    {
        cout << "~Second()" << endl;
        delete []strTwo;
    }
};


int main(void)
{
    First *ptr = new Second("simple", "complex");       // ~First()
    delete ptr;
    return 0;
}
```
- 객체의 소멸을 First형 포인터로 명령하니, First 클래스의 소멸자만 호출되었다.
    - 메모리 누수가 발생한다.
    - 객체의 소멸과정에서는 delete 연산자에 사용된 포인터 변수의 자료형에 상관없이 모든 소멸자가 호출되어야 한다.
```c++
virtual ~First()
{
    cout << "~First()" << endl;
    delete []strOne;
}
```
- 가상함수와 마찬가지로 소멸자로 상속의 계층구조상 맨 위에 존재하는 기초 클래스의 소멸자만 virtual로 선언하면, 이를 상속하는 유도 크랠스의 소멸자들도 모두 '가상 소멸자'로 선언이 된다.
    - 가상 소멸자가 호출되면, 상속의 계층구조상 맨 아래에 존재하는 유도 클래스의 소멸자가 대신 호출되면서, 기초 클래스의 소멸자가 순차적으로 호출된다.


### 참조자의 참조 가능성
"C++에서, AAA형 포인터 변수는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 가리킬 수 있다."
- 위의 특성은 참조자에도 적용이 된다.
    - "C++에서, AAA형 참조자는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 참조할 수 있다."
```c++
#include <iostream>
using namespace std;

class First
{
public:
    void FirstFunc(void) { cout << "FirstFunc()" << endl; }
    virtual void SimpleFunc(void) { cout << "First's SimpleFunc()" << endl; }
};

class Second : public First
{
public:
    void SecondFunc(void) { cout << "SecondFunc()" << endl; }
    virtual void SimpleFunc(void) { cout << "Second's SimpleFunc()" << endl; }
};

class Third : public Second
{
public:
    void ThirdFunc(void) { cout << "ThirdFunc()" << endl; }
    virtual void SimpleFunc(void) { cout << "Third's SimpleFunc()" << endl; }
};

int main(void)
{
    Third obj;
    obj.FirstFunc();    // FirstFunc()
    obj.SecondFunc();   // SecondFunc()
    obj.ThirdFunc();    // ThirdFunc()
    obj.SimpleFunc();   // Third's SimpleFunc()

    Second &sref = obj;
    sref.FirstFunc();   // FirstFunc()
    sref.SecondFunc();  // SecondFunc()
    sref.SimpleFunc();  // Third's SimpleFunc()

    First &fref = obj;
    fref.FirstFunc();   // FirstFunc()
    fref.SimpleFunc();  // Third's SimpleFunc()

    return 0;
}
```
- ```Second &sref = obj;```
    - obj는 Second를 상속하는 Third 객체이므로, Second형 참조자로 참조가 가능하다.
- ```sref.FirstFunc();```
    - 컴파일러는 참조자의 자료형을 가지고 함수의 호출 가능성을 판단하기 때문에 First 클래스에 정의된 FirstFunc 함수와 Second 클래스의 SecondFunc 함수는 호출이 가능하지만, Third 클래스에 정의된 ThirdFunc 함수는 호출이 불가능하다.
- SimpleFunc 함수는 가상함수이므로, Third 클래스에 정의된 SimpleFunc 함수가 호출된다.