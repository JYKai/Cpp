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