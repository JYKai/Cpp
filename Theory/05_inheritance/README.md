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