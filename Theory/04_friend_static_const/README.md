# friend와 static 그리고 const

## const

### const 객체와 const 객체의 특성들
```const SoSimple sim(20)```
- 객체에 const 선언이 붙게 되면, 이 객체를 대상으로 const 멤버함수만 호출이 가능하다. = 객체의 데이터 변경을 허용하지 않겠다.
```c++
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
    void ShowData(void) const
    {
        cout << "num: " << num << endl;
    }
};


int main(void)
{
    const SoSimple obj(7);
    // obj.AddNum(20);          // 호출이 불가능
    obj.ShowData();

    return 0;
}
```
- 멤버변수에 저장된 값을 수정하지 않는 함수는 가급적 const로 선언해서, const 객체에서도 호출이 가능하도록 할 필요가 있다.


### const와 함수 오버로딩
const의 선언유무도 함수 오버로딩의 조건에 해당이 된다.
```c++
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
```

</br>

## 클래스와 함수에 대한 friend 선언

### 클래스의 friend 선언
- A 클래스가 B 클래스를 대상으로 friend 선언을 하면, B 클래스는 A 클래스의 private 멤버에 직접 접근이 가능하다.
- 단, A 클래스도 B 클래스의 private 멤버에 직접 접근이 가능 하려면, B 클래스가 A 클래스를 대상으로 friend 선언을 해줘야 한다.
- friend 선언은 클래스 내에 어디든 위치할 수 있다.
```c++
#include <iostream>
#include <cstring>
using namespace std;

class Girl;

class Boy
{
private:
    int height;
    friend class Girl;

public:
    Boy(int len) : height(len) { }
    void ShowYourFriendInfo(Girl &frn);
};

class Girl
{
private:
    char phNum[20];

public:
    Girl(char * num)
    {
        strcpy(phNum, num);
    }
    void ShowYourFriendInfo(Boy &frn);
    friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl &frn)
{
    cout << "Her phone number = " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy &frn)
{
    cout << "His height = " << frn.height << endl;
}

int main(void)
{
    Boy boy(170);
    Girl girl("010-1234-5678");
    boy.ShowYourFriendInfo(girl);
    girl.ShowYourFriendInfo(boy);

    return 0;
}
```

### friend 선언은 언제?
friend 선언은 지나치면 아주 위험할 수 있다. friend 선언은 필요한 상황에서 극히 소극적으로 사용해야 한다.
- 가급적 사용하지 않는 연습을 하자.

### 함수의 friend 선언
전역함수를 대상으로도, 클래스의 멤버함수를 대상으로도 friend 선언이 가능하다.

</br>

## C++에서의 static

### 전역변수가 필요한 상황
```c++
#include <iostream>
using namespace std;

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple
{
public:
    SoSimple()
    {
        simObjCnt++;
        cout << simObjCnt << "번째 SoSimple 객체" << endl;
    }
};

class SoComplex
{
public:
    SoComplex()
    {
        cmxObjCnt++;
        cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
    }
    SoComplex(SoComplex &copy)
    {
        cmxObjCnt++;
        cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
    }
};

int main(void)
{
    SoSimple sim1;
    SoSimple sim2;

    SoComplex com1;
    SoComplex com2 = com1;
    SoComplex();

    return 0;
}
```
- 위의 전역변수들은 어디서든 접근 가능하므로, 문제를 일으킬 소지가 매우 높다.
- 위의 각 전역변수들을 각 클래스의 static 멤버로 선언하면 이러한 문제의 소지를 없앨 수 있다.

### static 멤버변수(클래스 변수)
static 멤버변수는 클래스 변수라고도 한다. 일반적인 멤버변수와 달리 클래스당 하나씩만 생성되기 때문이다.
- 특정 클래스 안에 선언된 static 멤버변수는 해당 클래스의 모든 객체가 공유하는 구조이다.
- 객체 내에 존재하는 것이 아닌 객체 외부에 있으며, 객체에게 멤버변수처럼 접근할 수 있는 권한을 줬을 뿐이다.
- 생성 및 소멸의 시점도 전역변수와 동일하다.
```c++
#include <iostream>
using namespace std;

class SoSimple
{
private:
    static int simObjCnt;

public:
    SoSimple()
    {
        simObjCnt++;
        cout << simObjCnt << "번째 SoSimple 객체" << endl;
    }
};
int SoSimple::simObjCnt = 0;

class SoComplex
{
private:
    static int cmxObjCnt;
public:
    SoComplex()
    {
        cmxObjCnt++;
        cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
    }
    SoComplex(SoComplex &copy)
    {
        cmxObjCnt++;
        cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
    }
};
int SoComplex::cmxObjCnt = 0;

int main(void)
{
    SoSimple sim1;
    SoSimple sim2;

    SoComplex com1;
    SoComplex com2 = com1;
    SoComplex();

    return 0;
}
```
- ```int SoSimple::simObjCnt = 0;```
    - 클래스 외부에서 초기화를 해야한다.
        - 생성자에 ```simObjCnt = 0;```과 같이 선언을 해버리면 객체가 생성될 때마다 변수가 0으로 초기화된다.


### static 멤버변수의 또 다른 접근방법
static 멤버가 private으로 선언되면, 해당 클래스의 객체들만 접근이 가능하지만, public으로 선언되면, 클래스의 이름 또는 객체의 이름을 통해서 어디서든 접근이 가능하다.
- public static 멤버에 접근할 때는 클래스의 이름을 이용해서 접근하는 것이 좋다.


### static 멤버함수
- 선언된 클래스의 모든 객체가 공유한다.
- public으로 선언이 되면, 클래스의 이름을 이용해서 호출이 가능하다.
- 객체의 맴버로 존재하는 것이 아니다.
    - static 멤버함수 내에서는 static 멤버변수와 static 멤버함수만 호출이 가능하다.


### const static 멤버
```c++
#include <iostream>
using namespace std;

class CountryArea
{
public:
    const static int RUSSIA         = 1707540;
    const static int CANADA         = 998467;
    const static int CHINA          = 957290;
    const static int SOUTH_KOREA    = 9922;
};

int main(void)
{
    cout << "러시아 면적 = " << CountryArea::RUSSIA << "km" << endl;
    cout << "캐나다 면적 = " << CountryArea::CANADA << "km" << endl;
    cout << "중국 면적 = " << CountryArea::CHINA << "km" << endl;
    cout << "한국 면적 = " << CountryArea::SOUTH_KOREA << "km" << endl;

    return 0;
}
```
- const static 상수는 하나의 클래스에 둘 이상 모이는 것이 보통이다.
- 클래스의 이름을 통해서 접근할 수 있으므로 정의된 상수에 접근하기 위해 굳이 객체를 생성할 필요가 없다.


### 키워드 mutable
const 함수 내에서의 값의 변경을 예외적으로 허용한다.
- 가급적 사용의 빈도수를 낮춰야 하는 키워드이다.
```c++
#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num1;
    mutable int num2;   // const 함수에 대해 예외를 둔다!

public:
    SoSimple(int n1, int n2)
        : num1(n1), num2(n2)
    { }
    
    void ShowSimpleData() const
    {
        cout << num1 << ", " << num2 << endl;
    }

    void CopyToNum2() const
    {
        num2 = num1;
    }
};


int main(void)
{
    SoSimple sm(1, 2);
    sm.ShowSimpleData();    // 1, 2
    sm.CopyToNum2();
    sm.ShowSimpleData();    // 1, 1

    return 0;
}
```