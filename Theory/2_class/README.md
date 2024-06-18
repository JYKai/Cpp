# 클래스의 기본

## C++에서의 구조체
구조체는 연관 있는 데이터를 묶을 수 있는 문법적 장치로 데이터의 표현에 큰 도움을 준다.

### C++에서의 구조체 변수의 선언
C++에서는 별도의 typedef 선언 없이도 아래와 같이 변수를 선언할 수 있다.
- ```Car basicCar```
- ```Car simpleCar```
```c++
#include <iostream>
using namespace std;

#define ID_LEN      20
#define MAX_SPD     200
#define FUEL_STEP   2
#define ACC_STEP    10
#define BRK_STEP    10


struct Car
{
    char gamerID[ID_LEN];
    int fuelGauge;
    int curSpeed;
};

void ShowCarState(const Car &car)   // 단순 정보 출력이므로 const 참조자를 매개변수로 선언
{
    cout << "소유자 ID: " << car.gamerID << endl;
    cout << "연료량: " << car.fuelGauge << "%" << endl;
    cout << "현재속도: " << car.curSpeed << "km/s" << endl << endl;;
}

void Accel(Car &car)
{
    if (car.fuelGauge <= 0) { return; }
    else { car.fuelGauge -= FUEL_STEP; }

    if (car.curSpeed + ACC_STEP >= MAX_SPD)
    {
        car.curSpeed = MAX_SPD;
        return;
    }

    car.curSpeed += ACC_STEP;
}

void Break(Car &car)
{
    if (car.curSpeed < BRK_STEP)
    {
        car.curSpeed = 0;
        return;
    }

    car.curSpeed -= BRK_STEP;
}

int main(void)
{
    Car run99 = {"run99", 100, 0};
    Accel(run99);
    Accel(run99);
    ShowCarState(run99);                
    
    Break(run99);
    ShowCarState(run99);

    Car sped77 = {"sped77", 100, 0};
    Accel(sped77);
    Break(sped77);
    ShowCarState(sped77);

    return 0;
}
```
- 위 세개의 함수는 구조체 Car와 함께 부류를 형성하여, Car와 관련된 데이터의 처리를 담당하는 함수들이다.
    - 종속적인 함수들이지만 엉뚱하게도 다른 영역에서 이 함수를 호출하는 실수를 범할 수도 있는 상황이다.


### 구조체 안에 함수 삽입하기
C++에서는 구조체 안에 함수를 삽입하는 것을 허용한다.
```c++
#include <iostream>
using namespace std;

#define ID_LEN      20
#define MAX_SPD     200
#define FUEL_STEP   2
#define ACC_STEP    10
#define BRK_STEP    10


struct Car
{
    char gamerID[ID_LEN];
    int fuelGauge;
    int curSpeed;

    void ShowCarState()
    {
        cout << "소유자 ID: " << gamerID << endl;
        cout << "연료량: " << fuelGauge << "%" << endl;
        cout << "현재속도: " << curSpeed << "km/s" << endl << endl;;
    }

    void Accel()
    {
        if (fuelGauge <= 0) { return; }
        else { fuelGauge -= FUEL_STEP; }

        if (curSpeed + ACC_STEP >= MAX_SPD)
        {
            curSpeed = MAX_SPD;
            return;
        }

        curSpeed += ACC_STEP;
    }

    void Break()
    {
        if (curSpeed < BRK_STEP)
        {
            curSpeed = 0;
            return;
        }

        curSpeed -= BRK_STEP;
    }
};

int main(void)
{
    Car run99 = {"run99", 100, 0};
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();                
    
    run99.Break();
    run99.ShowCarState();

    Car sped77 = {"sped77", 100, 0};
    sped77.Accel();
    sped77.Break();
    sped77.ShowCarState();

    return 0;
}
```


### 구조체 안에 enum 상수의 선언
enum 역시 구조체 안에 선언할 수 있다. 하지만, enum의 선언을 구조체 내부에 삽입하는 것이 부담스럽다면, 이름공간을 이용해서 상수가 사용되는 영역을 명시하는 것도 또 다른 방법이 될 수 있다.
```c++
#include <iostream>
using namespace std;

namespace CAR_CONST
{
    enum
    {
        ID_LEN      = 20,
        MAX_SPD     = 200,
        FUEL_STEP   = 2,
        ACC_STEP    = 10,
        BRK_STEP    = 10
    };
}


struct Car
{
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

    void ShowCarState()
    {
        cout << "소유자 ID: " << gamerID << endl;
        cout << "연료량: " << fuelGauge << "%" << endl;
        cout << "현재속도: " << curSpeed << "km/s" << endl << endl;;
    }

    void Accel()
    {
        if (fuelGauge <= 0) { return; }
        else { fuelGauge -= CAR_CONST::FUEL_STEP; }

        if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
        {
            curSpeed = CAR_CONST::MAX_SPD;
            return;
        }

        curSpeed += CAR_CONST::ACC_STEP;
    }

    void Break()
    {
        if (curSpeed < CAR_CONST::BRK_STEP)
        {
            curSpeed = 0;
            return;
        }

        curSpeed -= CAR_CONST::BRK_STEP;
    }
};

int main(void)
{
    Car run99 = {"run99", 100, 0};
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();                
    
    run99.Break();
    run99.ShowCarState();

    Car sped77 = {"sped77", 100, 0};
    sped77.Accel();
    sped77.Break();
    sped77.ShowCarState();

    return 0;
}
```
- 상수의 접근을 위해서 이름공간 CAR_CONST를 지정하고 있다. 이를 통해, 해당 상수가 어느 영역에서 선언되는 상수인지 알 수 있으므로 가독성이 좋아졌다.


### 함수는 외부로 뺄 수 있다.
프로그램을 분석할 때, 흐름 및 골격 위주로 분석하는 경우가 많다. 즉, 함수의 기능을 파악하지 세부구현까지는 신경쓰지 않는다.
- 구조체를 선언할 때, 정의되어 있는 함수의 종류와 기능이 한눈에 들어오게끔 코드를 작성하는 것이 좋다.
```c++
#include <iostream>
using namespace std;

namespace CAR_CONST
{
    enum
    {
        ID_LEN      = 20,
        MAX_SPD     = 200,
        FUEL_STEP   = 2,
        ACC_STEP    = 10,
        BRK_STEP    = 10
    };
}


struct Car
{
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

    void ShowCarState();    // 상태정보 출력
    void Accel();           // 엑셀, 속도증가
    void Break();           // 브레이크, 속도감소
};

int main(void)
{
    Car run99 = {"run99", 100, 0};
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();                
    
    run99.Break();
    run99.ShowCarState();

    Car sped77 = {"sped77", 100, 0};
    sped77.Accel();
    sped77.Break();
    sped77.ShowCarState();

    return 0;
}

void Car::ShowCarState()
{
    cout << "소유자 ID: " << gamerID << endl;
    cout << "연료량: " << fuelGauge << "%" << endl;
    cout << "현재속도: " << curSpeed << "km/s" << endl << endl;;
}

void Car::Accel()
{
    if (fuelGauge <= 0) { return; }
    else { fuelGauge -= CAR_CONST::FUEL_STEP; }

    if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
    {
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }

    curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
    if (curSpeed < CAR_CONST::BRK_STEP)
    {
        curSpeed = 0;
        return;
    }

    curSpeed -= CAR_CONST::BRK_STEP;
}
```

</br>

## 클래스(Class)와 객체(Object)

### 클래스와 구조체의 유일한 차이점
키워드 struct를 대신해서 class를 사용하면, 구조체가 아닌 클래스가 된다.
- 클래스가 된다면 ```Car run99 = {"run99", 100, 0};```의 방식으로 변수를 선언할 수 없다.
- 클래스는 기본적으로 클래스 내에 선안된 변수는 클래스 내에 선언된 함수에서만 접근 가능하다.
    - ```Car run99;``` (O)
- 클래스는 정의를 하는 과정에서 각각의 변수 및 함수의 접근 허용범위를 별도로 선언해야 한다. = 유일한 차이점

### 접근제어 지시자(접근제어 레이블)
- public : 어디서든 접근허용
- protected : 상속관계에 놓여있을 때, 유도 클래스에서의 접근허용
- private : 클래스 내(클래스 내에 정의된 함수)에서만 접근허용
```c++
#include <iostream>
#include <cstring>
using namespace std;

namespace CAR_CONST
{
    enum
    {
        ID_LEN      = 20,
        MAX_SPD     = 200,
        FUEL_STEP   = 2,
        ACC_STEP    = 10,
        BRK_STEP    = 10
    };
}


class Car
{
private:
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

public:
    void InitMembers(char *ID, int fule);
    void ShowCarState();
    void Accel();
    void Break();
};

void Car::InitMembers(char *ID, int fule)
{
    strcpy(gamerID, ID);
    fuelGauge = fule;
    curSpeed = 0;
}

void Car::ShowCarState()
{
    cout << "소유자 ID: " << gamerID << endl;
    cout << "연료량: " << fuelGauge << "%" << endl;
    cout << "현재속도: " << curSpeed << "km/s" << endl << endl;;
}

void Car::Accel()
{
    if (fuelGauge <= 0) { return; }
    else { fuelGauge -= CAR_CONST::FUEL_STEP; }

    if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
    {
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }

    curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
    if (curSpeed < CAR_CONST::BRK_STEP)
    {
        curSpeed = 0;
        return;
    }

    curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void)
{
    Car run99;
    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();

    run99.Break();
    run99.ShowCarState();

    return 0;
}
```
- ```void InitMembers(char *ID, int fule);``` : 클래스 안에 선언된 변수의 초기화를 목적으로 정의된 함수
    - 변수가 모두 private으로 선언되어서 main 함수에서 접근이 불가능하지만, 해당 함수는 동일 클래스 내에 정의된 함수이므로 접근이 가능하다.
    - public으로 선언되어서 main 함수에서 호출이 가능하다.
- 키워드 struct를 이용해서 정의한 구조체(클래스)에 선언된 변수와 함수의 별도의 접근제어 지시자를 선언하지 않으면, 모든 변수와 함수는 **public**으로 선언된다.
- 키워드 class를 이용해서 정의한 클래스에 선언된 변수와 함수의 별도의 접근제어 지시자를 선언하지 않으면, 모든 변수와 함수는 **private**으로 선언된다.


**레이블**  
접근제어 지시자의 뒤에 세미콜론이 아닌 콜론이 붙는다.
- 접근제어 지시자가 특정 위치정보를 알리는 '레이블(라벨)'이기 때문이다.
- switch문에 사용되는 case도 레이블이기 때문에 콜론이 붙는다.


### 용어정리: 객체(Object), 맴버변수, 멤버함수
- 구조체와 클래스는 변수의 성격만 지니는 것이 아니기 때문에 변수라는 표현을 대신해서 '객체(Object)'라는 표현을 사용한다.
- 멤버변수: 클래스를 구성하는 변수
- 멤버함수: 클래스를 구성하는 함수


### C++에서의 파일분할
C++은 클래스 별로 헤더파일과 소스파일을 생성해서 클래스의 선언과 정의를 분리하는 경우가 많다.
- Car.h : 클래스의 선언을 담는다.
- Car.cpp : 클래스의 정의(멤버함수의 정의)를 담는다.

**Car.h**  
```c++
#ifndef __CAR_H__
#define __CAR_H__

namespace CAR_CONST
{
    enum
    {
        ID_LEN      = 20,
        MAX_SPD     = 200,
        FUEL_STEP   = 2,
        ACC_STEP    = 10,
        BRK_STEP    = 10
    };
}


class Car
{
private:
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

public:
    void InitMembers(char *ID, int fule);
    void ShowCarState();
    void Accel();
    void Break();
};

#endif
```

**Car.cpp**  
```c
#include <iostream>
#include <cstring>
#include "Car.h"
using namespace std;

void Car::InitMembers(char *ID, int fule)
{
    strcpy(gamerID, ID);
    fuelGauge = fule;
    curSpeed = 0;
}

void Car::ShowCarState()
{
    cout << "소유자 ID: " << gamerID << endl;
    cout << "연료량: " << fuelGauge << "%" << endl;
    cout << "현재속도: " << curSpeed << "km/s" << endl << endl;;
}

void Car::Accel()
{
    if (fuelGauge <= 0) { return; }
    else { fuelGauge -= CAR_CONST::FUEL_STEP; }

    if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
    {
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }

    curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
    if (curSpeed < CAR_CONST::BRK_STEP)
    {
        curSpeed = 0;
        return;
    }

    curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void)
{
    Car run99;
    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();

    run99.Break();
    run99.ShowCarState();

    return 0;
}
```
- ```#include "Car.h"```
    - 멤버함수에서 접근하는 변수의 존재유무를 확인하기 위해 멤버함수의 정의부분을 컴파일 하는데도 클래스의 선언 정보가 필요하다.
    - CAR_CONST에 선언된 상수의 사용을 위해서도 이 헤더파일은 포함되어야 한다.

**실행파일**  
```c++
#include "Car.h"
#include "Car.cpp" // mac 환경에서 vscode로 코드를 실행할 때는 자동 링크를 지원하지 않는다.

int main(void)
{
    Car run99;
    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();

    run99.Break();
    run99.ShowCarState();

    return 0;
}
```


### 인라인 함수는 헤더파일에 함께 넣어야 한다.
컴파일 과정에서 함수의 호출 문이 있는 곳에 함수의 몸체 부분이 삽입되어야 한다.
- 인라인 함수의 호출문장은 컴파일러에 의해서 함수 몸체로 대체되어야 한다.
- 인라인 함수는 클래스의 선언과 동일한 파일에 저장되어서 컴파일러가 동시에 참조할 수 있게 해야 한다.


</br>


## 객체지향 프로그래밍 이해

### 객체지향 프로그래밍의 이해
객체지향 프로그래밍은 현실에 존재하는 사물과 대상, 그리고 그에 따른 행동을 있는 그대로 실체화시키는 형태의 프로그래밍이다.

### 객체를 이루는 것은 데이터와 기능이다.
객체는 하나 이상의 상태 정보(데이터)와 하나 이상의 행동(기능)으로 구성이 되며, 상태 정보는 변수를 통해서 표현이 되고, 행동은 함수를 통해서 표현이 된다.

### 클래스 기반의 두 가지 객체생성 방법
- ```ClassName objName;                     // 일반적인 변수의 선언방식```
- ```ClassName *prtObj = new ClassName      // 동적 할당방식(힙 할당방식)```

### 사과장수 시뮬레이션
```c++
#include <iostream>
using namespace std;

class FruitSeller
{
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    void InitMembers(int price, int num, int money)
    {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }
    int SaleApples(int money)
    {
        int num = money / APPLE_PRICE;
        numOfApples -= num;
        myMoney += money;
        return num;
    }
    void ShowSalesResult(void)
    {
        cout << "남은 사과: " << numOfApples << endl;
        cout << "판매 수익: " << myMoney << endl << endl;
    }
};


class FruitBuyer
{
private:
    int myMoney;
    int numOfApples;

public:
    void InitMembers(int money)
    {
        myMoney = money;
        numOfApples = 0;
    }
    void BuyApples(FruitSeller &seller, int money)
    {
        numOfApples += seller.SaleApples(money);
        myMoney -= money;
    }
    void ShowBuyResult(void)
    {
        cout << "현재 잔액: " << myMoney << endl;
        cout << "사과 개수: " << numOfApples << endl << endl;
    }
};


int main(void)
{
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);

    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000);

    cout << "과일 판매자의 현황" << endl;
    seller.ShowSalesResult();

    cout << "과일 구매자의 현황" << endl;
    buyer.ShowBuyResult();

    return 0;
}
```
- 하나의 객체가 다른 하나의 객체에게 메세지를 전달하는 방법은 함수호출을 기반으로 한다. = Message Passing

</br>

# 클래스의 완성

## 정보은닉(Information Hiding)
- 클래스 멤버변수가 public으로 선언되면, 구조체 변수를 초기화하듯이 초기화가 가능하다.
- 제한된 방법으로의 접근만 허용을 해서 잘못된 값이 저장되지 않도록 도와야 하고, 또 실수 했을 때, 실수가 쉽게 발견되도록 해야 한다.

**Point.h**  
```c++
#ifndef __POINT_H_
#define __POINT_H_

class Point
{
private:
    int x;
    int y;

public:
    bool InitMebers(int xpos, int ypos);
    int GetX() const;
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
};

#endif
```

**Point.cpp**  
```c++
#include <iostream>
#include "Point.h"
using namespace std;

bool Point::InitMebers(int xpos, int ypos)
{
    if (xpos < 0 || ypos < 0)
    {
        cout << "벗어난 범위의 값 전달" << endl;
        return false;
    }

    x = xpos;
    y = ypos;
    return true;
}

int Point::GetX() const { return x; }

int Point::GetY() const { return y; }

bool Point::SetX(int xpos)
{
    if (0 > xpos || xpos > 100)
    {
        cout << "벗어난 범위의 값 전달." << endl;
        return false;
    }
    x = xpos;
    return true;
}

bool Point::SetY(int ypos)
{
    if (0 > ypos || ypos > 100)
    {
        cout << "벗어난 범위의 값 전달." << endl;
        return false;
    }
    y = ypos;
    return true;
}
```
- 멤버변수를 private으로 선언하고, 해당 변수에 접근하는 함수를 별도로 정의해서, 안전한 형태로 멤버 변수의 접근을 유도하는 것이 바로 '정보은닉'이며, 이는 좋은 클래스가 되기 위한 기본조건이 된다.
- ```int GetX() const;```, ```bool SetX(int xpos);```
    - 엑세스 함수(access function) : 멤버변수를 private으로 선언하면서 클래스 외부에서의 멤버변수 접근을 목적으로 정의되는 함수


### const 함수
(ex) ```int GetX() const;```
- 이 함수 내에서는 멤버변수에 저장된 값을 변경하지 않겠다!
    - 매개변수도 아니고, 지역변수도 아닌, 멤버변수에 저장된 값을 변경하지 않게다는 선언이다.
    - 실수로 자신의 의도와 다르게 멤버변수의 값을 변경했을 때, 컴파일 에러를 통해서 이를 확인할 수 있다.
- const 함수 내에서는 const가 아닌 함수의 호출이 제한된다.
    - const로 선언되지 않은 함수는 아무리 멤버변수에 저장된 값을 변경하지 않더라도, 변경할 수 있는 능력을 지닌 함수이다.

(ex)```void InitNum(const EasyClass &easy);```
- C++에서는 const 참조자를 대상으로 값의 변경 능력을 가진 함수의 호출을 허용하지 않는다. 따라서, const 참조자를 이용해서는 const 함수만 호출이 가능하다.

</br>

## 캡슐화(Encapsulation)
```c++
#include <iostream>
using namespace std;

class SinivelCap
{
public:
    void Take(void) const { cout << "콧물이 싹 ~ 납니다." << endl;}
};

class SneezeCap
{
public:
    void Take(void) const { cout << "재채기가 멎습니다." << endl;}
};

class SnuffleCap
{
public:
    void Take(void) const { cout << "코가 뻥 뚫립니다." << endl;}
};

class CONTAC600
{
private:
    SinivelCap sin;
    SneezeCap sne;
    SnuffleCap snu;

public:
    void Take(void) const
    {
        sin.Take();
        sne.Take();
        snu.Take();
    }
};

class ColdPatient
{
public:
    void TakeCONTAC600(const CONTAC600 &cap) const { cap.Take(); }
};

int main(void)
{
    CONTAC600 cap;
    ColdPatient sufferer;
    sufferer.TakeCONTAC600(cap);

    return 0;
}
```
- 캡슐화의 범위를 결정하는 일은 쉽지 않은 일이기 때문에 캡슐화는 어려운 개념이다.

</br>

## 생성자(Constructor)와 소멸자(Destructor)
**생성자**  
- 클래스의 이름과 함수의 이름이 동일하다.
- 반환형이 선언되어 있지 않으며, 실제로 반환하지 않는다.
- 객체 생성시 딱 한번 호출된다.
- 생성자도 함수의 일종이니 오버로딩이 가능하다.
- 생성자도 함수의 일종이니 매개변수에 '디폴트 값'을 설정할 수 있다.
```c++
#include <iostream>
using namespace std;

class SimpleClass
{
private:
    int num1;
    int num2;

public:
    SimpleClass()
    {
        num1 = 0;
        num2 = 0;
    }
    SimpleClass(int n)
    {
        num1 = n;
        num2 = 0;
    }
    SimpleClass(int n1, int n2)
    {
        num1 = n1;
        num2 = n2;
    }

    void ShowData() const { cout << num1 << ' ' << num2 << endl; }
};

int main(void)
{
    SimpleClass sc1;
    sc1.ShowData();         // 0 0

    SimpleClass sc2(100);
    sc2.ShowData();         // 100 0

    SimpleClass sc3(100, 200);
    sc3.ShowData();         // 100 200

    return 0;
}
```
- ```SimpleClass sc1();``` -> (X)
    - 위와 같은 형식은 함수의 원형을 선언하는 것과 같다. 즉, 객체생성문인지 함수의 원형선언인지를 구분할 수 없게 된다.
    - 함수의 원형선언에만 사용하기로 약속했다.
- ```SimpleClass sc1;```   -> (O)
- ```SimpleClass *ptr1 = new SimpleClass;```   -> (O)
- ```SimpleClass *ptr1 = new SimpleClass();``` -> (O)


### '멤버 이니셜라이저(Member Initializer)'를 이용한 멤버 초기화
**Rectangle.h**  
```c++
#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "Point.h"

class Rectangle
{
private:
    Point upLeft;
    Point lowRight;

public:
    Rectangle(const int &x1, const int &y1, const int &x2, const int &y2);
    void ShowRecInfo() const;
};

#endif
```

**Rectangle.cpp**  
```c++
#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2)
            :upLeft(x1, y1), lowRight(x2, y2)
{
    // empty
}

void Rectangle::ShowRecInfo() const
{
    cout << "좌 상단: " << '[' << upLeft.GetX() << ", ";
    cout << upLeft.GetY() << ']' << endl;

    cout << "우 하단: " << '[' << lowRight.GetX() << ", ";
    cout << lowRight.GetY() << ']' << endl << endl;
}
```
- ```upLeft(x1, y1), lowRight(x2, y2)```
    - 객체 upLeft의 생성과정에서 x1, y1를 인자로 전달받는 생성자를 호출하라.
    - 객체 lowRight의 생성과정에서 x2, y2를 인자로 전달받는 생성자를 호출하라.
- 위와 같이 멤버 이니셜라이저는 멤버변수로 선언된 객체의 생성자 호출에 활용된다.
- 멤버 이니셜라이저를 사용하다 보면, 생성자의 몸체 부분이 그냥 비는 일이 종종 발생한다.


### '멤버 이니셜라이저(Member Initializer)'를 이용한 변수 및 const 상수(변수) 초기화
'멤버 이니셜라이저'는 객체가 아닌 멤버의 초기화에도 사용할 수 있다.
- 일반적으로 멤버변수의 초기화에 있어서는 이니셜라이저를 선호하는 편이다.
    - 초기화의 대상을 명확히 인식할 수 있다.
    - 성능에 약간의 이점이 있다.
- 이니셜라이저를 통해서 초기화되는 멤버는 선언과 동시에 초기화가 이뤄지는 것과 같은 유형의 바이너리 코드를 구성한다.
- const 변수는 선언과 동시에 초기화해야 하는 특징이 있다.
    - const 멤버변수도 이니셜라이저를 이용하면 초기화가 가능하다!

**const 변수와 const 상수**  
- const는 변수를 상수화시키는 키워드이다. 따라서 const 선언에 의해서 상수화 된 변수를 가리켜 'const 변수'라고도 하고, 'const 상수'라고도 한다.


### 이니셜라이저의 이러한 특징은 멤버변수로 참조자를 선언할 수 있게 한다.
const 변수와 마찬가지로 '참조자'도 선언과 동시에 초기화가 이뤄져야 한다.
```c++
#include <iostream>
using namespace std;

class AAA
{
public:
    AAA() { cout << "empty object" << endl; }
    void ShowYourName(void) { cout << "I'm class AAA" << endl; }
};

class BBB
{
private:
    AAA &ref;
    const int &num;

public:
    BBB(AAA &r, const int &n)
        : ref(r), num(n)
    { }
    void ShowYourName(void)
    {
        ref.ShowYourName();
        cout << "and" << endl;
        cout << "I'm ref num " << num << endl;
    }
};

int main(void)
{
    AAA obj1;
    BBB obj2(obj1, 20);
    obj2.ShowYourName();

    return 0;
}
```
- ```AAA &ref;``` -> 참조자가 멤버변수로 선언되었다. 따라서 이니셜라이저를 통해서 초기화를 해야 한다.
- 참조자를 멤버변수로 선언하는 경우가 흔한 것은 아니다. 하지만 의미를 이해할 수 있도록 하자.


### 디폴트 생성자(Default Constructor)
객체가 되기 위해서는 반드시 하나의 생성자가 호출되어야 한다. 디폴트 생성자는 인자를 받지 않으며, 내부적으로 아무런 일도 하지 않는 생성자이다.
- ```malloc``` 함수호출 시, 실제로는 클래스의 크기정보만 바이트 단위로 전달되기 때문에 생성자가 호출될 리 없다. 따라서 객체를 동적으로 할당하려는 경우에는 반드시 ```new``` 연산자를 이용해야 한다.
- 생성자 코드가 작성되어 있는 상태라면 디폴트 생성자가 삽입되지 않는다.


### private 생성자
클래스 내부에서 객체를 생성한다면, 생성자가 private로 선언된다.
```c++
#include <iostream>
using namespace std;

class AAA
{
private:
    int num;
public:
    AAA() : num(0) { }
    AAA& CreateInitObj(int n) const
    {
        AAA * ptr = new AAA(n);
        return *ptr;
    }
    void ShowNum(void) const { cout << num << endl; }
private:
    AAA(int n) : num(n) { }
};

int main(void)
{
    AAA base;
    base.ShowNum();

    AAA &obj1 = base.CreateInitObj(3);
    obj1.ShowNum();

    AAA &obj2 = base.CreateInitObj(12);
    obj2.ShowNum();

    delete &obj1;
    delete &obj2;
    return 0;
}
```
- 힙에 할당된 메모리 공간은 변수로 간주하여, 참조자를 통한 참조가 가능하다.
- 위 예시는 private로 선언도니 생성자를 통해서도 객체의 생성이 가능함을 보여주는 예제이다.


### 소멸자의 이해와 활용
객체소멸시 반드시 호출되는 것은 소멸자이다.
- 클래스의 이름 앞에 '~'가 붙은 형태의 이름을 갖는다.
- 반환형이 선언되어 있지 않으며, 실제로 반환하지 않는다.
- 매개변수는 void형으로 선언되어야 하기 때문에 오버로딩도, 디폴트 값 설정도 불가능하다.
- 생성자에서 할당한 리소스의 소멸에 사용된다.
```c++
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char *name;
    int age;
public:
    Person(char *myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    void ShowPersonInfo(void) const
    {
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
    }
    ~Person()
    {
        delete []name;
        cout << "called destructor!" << endl;
    }
};


int main(void)
{
    Person man1("Lee dong woo", 29);
    Person man2("Kim ji yun", 30);

    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}
```

</br>

## 클래스 배열 그리고 this 포인터

### 객체 배열
```SoSimple arr[10];```
- 배열을 선언하는 경우에도 생성자는 호출이 된다. 단, 배열의 선언과정에서는 호출할 생성자를 별도로 명시하지 못한다.
- 배열선언 이후에 각각의 요소를 원하는 값으로 초기화시키길 원하다면, 일일이 초기화의 과정을 별도로 거쳐야 한다.
```c++
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char *name;
    int age;
public:
    Person(char *myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    Person()
    {
        name = NULL;
        age = 0;
        cout << "called Person()" << endl;
    }
    void SetPersonInfo(char *myname, int myage)
    {
        name = myname;
        age = myage;
    }
    void ShowPersonInfo(void) const
    {
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
    }
    ~Person()
    {
        delete []name;
        cout << "called destructor!" << endl;
    }
};


int main(void)
{
    Person parr[3];
    char namestr[100];
    char *strptr;
    int age;
    int len;

    for (int i = 0; i < 3; i++)
    {
        cout << "이름: "; cin >> namestr;
        cout << "나이: "; cin >> age;

        len = strlen(namestr) + 1;
        strptr = new char[len];
        strcpy(strptr, namestr);

        parr[i].SetPersonInfo(strptr, age);
    }
    parr[0].ShowPersonInfo();
    parr[1].ShowPersonInfo();
    parr[2].ShowPersonInfo();

    return 0;
}
```
- 객체 배열을 생성시 void형 생성자가 호출됨을 확인할 수 있다.


### 객체 포인터 배열
객체 배열이 객체로 이뤄진 배열이라면, 객체 포인터 배열은 객체의 주소 값 저장이 가능한 포인터 변수로 이뤄진 배열이다.
```c++
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char *name;
    int age;
public:
    Person(char *myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    Person()
    {
        name = NULL;
        age = 0;
        cout << "called Person()" << endl;
    }
    void SetPersonInfo(char *myname, int myage)
    {
        name = myname;
        age = myage;
    }
    void ShowPersonInfo(void) const
    {
        cout << "이름 : " << name << endl;
        cout << "나이 : " << age << endl;
    }
    ~Person()
    {
        delete []name;
        cout << "called destructor!" << endl;
    }
};


int main(void)
{
    Person *parr[3];
    char namestr[100];
    int age;

    for (int i = 0; i < 3; i++)
    {
        cout << "이름: "; cin >> namestr;
        cout << "나이: "; cin >> age;
        parr[i] = new Person(namestr, age);
    }

    parr[0] -> ShowPersonInfo();
    parr[1] -> ShowPersonInfo();
    parr[2] -> ShowPersonInfo();

    delete parr[0];
    delete parr[1];
    delete parr[2];

    return 0;
}
```
- 객체를 저장할 때에는 위의 예제에서 보인 두 가지 방법 중 하나를 택해야 한다.


### this 포인터의 이해
멤버함수 내에서는 this라는 이름의 포인터를 사용할 수 있는데, 이는 객체 자신을 가리키는 용도로 사용되는 포인터이다.
```c++
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
```
- ```return this;```
    - this를 반환하고 있다. 이는 이 문장을 실행하는 객체의 포인터를 반환하라는 의미이다.


### this 포인터의 활용
```c++
#include <iostream>
using namespace std;

class TwoNumber
{
private:
    int num1;
    int num2;

public:
    TwoNumber(int num1, int num2)
    {
        this->num1 = num1;
        this->num2 = num2;
    }
    /*
    TwoNumber(int num1, int num2)
        : num1(num1), num2(num2)
    { }
    */

    void ShowTwoNumber(void)
    {
        cout << this->num1 << endl;
        cout << this->num2 << endl;
    }
};

int main(void)
{
    TwoNumber two(2, 4);
    two.ShowTwoNumber();

    return 0;
}
```
- 멤버 이니셜라이저에서는 this 포인터를 사용할 수 없다.
- 멤버변수와 매개변수의 이름을 동일하게 짓고, this 포인터르 이용해서 이 둘을 구분하는 것을 좋아하는 프로그래머들도 있다.


### Self-Reference의 반환
Self-Reference란 객체 자신을 참조할 수 있는 참조자를 의미한다.
- this 포인터를 이용해서, 객체가 자신의 참조에 사용할 수 있는 참조자의 반환문을 구성할 수 있다.
```c++
#include <iostream>
using namespace std;

class SelfRef
{
private:
    int num;

public:
    SelfRef(int n) : num(n) { cout << "객체생성" <<endl; }
    SelfRef& Adder(int n)
    {
        num += n;
        return *this;
    }
    SelfRef& ShowTwoNumber(void)
    {
        cout << num << endl;
        return *this;
    }
};

int main(void)
{
    SelfRef obj(3);
    SelfRef &ref = obj.Adder(2);
    
    obj.ShowTwoNumber();
    ref.ShowTwoNumber();

    ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
    
    return 0;
}
```
- ```SelfRef& Adder(int n)```
    - 반환 내용은 *this인데, 이는 이 문장을 실행하는 객체 자신의 포인터가 아닌, 객체 자신을 반환하겠다는 의미가 된다.
    - 반환형이 SelfRef&으로 선언되었으므로, 객체 자신을 참조할 수 있는 '참조 값'이 반환된다.