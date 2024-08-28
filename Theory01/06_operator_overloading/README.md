# 연산자 오버로딩

## 연산자 오버로딩의 이해와 유형
함수가 오버로딩 되면 전달되는 인자에 따라서 호출되는 함수가 달라진다. 이처럼, 연산자가 오버로딩 되면, 피연산자의 종류에 따라서 연산의 방식이 달라지므로 연산자 오버로딩이라고 부른다.

### operator+ 라는 이름의 함수
```c++
#include <iostream>
using namespace std;


class Point
{
private:
    int xpos, ypos;

public:
    Point(int x, int y) : xpos(x), ypos(y)
    { }
    void ShowPosition(void) const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point operator+(const Point &ref)
    {
        Point pos(xpos + ref.xpos, ypos + ref.ypos);
        return pos;
    }
};

int main(void)
{
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1.operator+(pos2);  // == Point pos3 = pos1 + pos2

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    return 0;
}
```
- ```pos1.operator+(pos2)  = pos1 + pos2```
    - 객체간의 연산을 위한 C++의 약속
- 연산자 오버로딩을 위한 함수 또한 const로 선언하는 것이 좋다.
    - 연산이라는 것 자체가 원래의 연산 대상이 되는 피연산자의 값을 변경하는 것이 아니라 새로운 연산의 결과를 만드는 것이기 때문이다.

### 연산자를 오버로딩 하는 두 가지 방법
- 멤버함수에 의한 연산자 오버로딩
    - ```pos1.operator+(pos2)```
- 전역함수에 의한 연산자 오버로딩
    - ```operator+(pos1, pos2);```
- 멤버함수 기반으로 오버로딩 된 함수가 전역함수 기반으로 오버로딩 된 함수보다 우선시되어 호출된다.
```c++
#include <iostream>
using namespace std;


class Point
{
private:
    int xpos, ypos;

public:
    Point(int x, int y) : xpos(x), ypos(y)
    { }
    void ShowPosition(void) const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    friend Point operator+(const Point &pos1, const Point &pos2);
};

Point operator+(const Point &pos1, const Point &pos2)
{
    Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
    return pos;
}

int main(void)
{
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1 + pos2;

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    return 0;
}
```
- ```Point pos3 = pos1 + pos2;``` == ```operator+(pos1, pos2)```
- 특별한 경우가 아니면 멤버함수를 기반으로 연산자를 오버로딩 하는 게 낫다.


### 연산자를 오버로딩 하는데 있어서의 주의사항
- 본래의 의도를 벗어난 형태의 연산자 오버로딩은 좋지 않다.
- 연산자의 우선순위와 결합성을 바뀌지 않는다.
- 매개변수의 디폴트 값 설정이 불가능하다.
- 연산자의 순수 기능까지 빼앗을 수는 없다.

</br>

## 단항 연산자의 오버로딩

### 증가, 감소 연산자의 오버로딩
- ```pos.operator++()```
- ```operator++(pos)```
- 멤버함수로 단항 연산자를 오버로딩 했을 때, 매개변수가 필요없지만 전역함수의 경우 대상이 되는 매개변수가 하나 필요하게 된다.
```c++
Point& operator++()
{
    xpos += 1;
    ypos += 1;
    return *this;
}
```
- 함수의 호출결과로 객체 자신을 참조할 수 있는 '참조 값'이 반환된다.
- ```++(++pos)``` = ```++(pos.operator++())```
    - ```++(pos의 참조 값)``` = ```(pos의 참조 값).operator++()```

### 전위증가와 후위증가의 구분
- ```++pos``` -> ```pos.operator++()```
- ```pos++``` -> ```pos.operator++(int)```
- 키워드 int를 이용해서 후위연산에 대한 함수를 전위연산에 대한 함수와 구분하고 있다.
    - 사용된 int는 단지 후위연산을 구분하기 위한 목적으로 선택된 것일 뿐, int형 데이터를 인자로 전달하라는 뜻과는 거리가 멀다.

### 반환형에서의 const 선언과 const 객체
```c++
const Point operator++(int) // 후위증가
{
    const Point retobj(xpos, ypos);
    xpos += 1;
    ypos += 1;
    return retobj;
}
```
- 반환형으로 선언된 const는 어떠한 의미를 지닐까?
    - operator++ 함수의 반환으로 인해서 생성되는 임시객체를 const 객체로 생성하겠다!
    - 이는 해당 객체를 상수화해서 해당 객체에 저장된 값의 변경을 허용하지 않겠다는 뜻이다.
        - const 객체를 대상으로는 const로 선언된 함수만 호출이 가능하게 된다.
        - const 객체를 대상으로는 값의 변경능력을 지니는, const로 선언되지 않은 함수의 호출은 허용하지 않는다.
- 후위증가 및 후위감소 연사에 대해서 오버로딩 한 함수의 반환형을 const로 선언한 이유는 아래의 문장에서 컴파일 에러를 일으키기 위함이다.
    - ```(pos++)++``` = ```(Point형 const 임시객체).operator++();```
    - ```(pos--)--```

</br>

## 교환법칙 문제의 해결

### 자료형이 다른 두 피연산자를 대상으로 하는 연산
```c++
#include <iostream>
using namespace std;


class Point
{
private:
    int xpos, ypos;

public:
    Point(int x=0, int y=0) : xpos(x), ypos(y)
    { }
    void ShowPosition(void) const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point operator*(int times)
    {
        Point pos(xpos * times, ypos * times);
        return pos;
    }
    friend Point operator*(int times, Point& ref);
};

Point operator*(int times, Point& ref)
{
    return ref * times;
}

int main(void)
{
    Point pos1(1, 2);
    Point cpy;

    cpy = 3 * pos1;
    cpy.ShowPosition();

    cpy = 2 * pos1 * 3;
    cpy.ShowPosition();

    return 0;
}
```
- ```friend Point operator*(int times, Point& ref);```
    - ```3 * pos1;```의 연산이 가능할 수 있도록 전역 함수로 정의하였다.

</br>

## cout, cin 그리고 endl의 정체

### cout과 endl 이해하기
```c++
#include <iostream>
namespace mystd
{
    using namespace std;

    class ostream
    {
    public:
        void operator<< (char *str) { printf("%s", str); }
        void operator<< (char str) { printf("%c", str); }
        void operator<< (int num) { printf("%d", num); }
        void operator<< (double e) { printf("%g", e); }
        void operator<< (ostream& (*fp)(ostream &ostm)) { fp(*this); }
    };

    ostream& endl(ostream &ostm)
    {
        ostm<<'\n';
        fflush(stdout);
        return ostm;
    }

    ostream cout;
}

int main(void)
{
    using mystd::cout;
    using mystd::endl;

    cout << "Simple String";
    cout << endl;
    cout << 3.14;
    cout << endl;
    cout << 123;
    endl(cout);

    return 0;
}
```

</br>

## 반드시 해야 하는 대입 연산자의 오버로딩
대입 연산자의 오버로딩은 그 성격이 복사 생성자와 매우 유사하다.

### 객체간 대입연산의 비밀: 디폴트 대입 연산자
- 정의하지 않으면 디폴트 대입 연산자가 삽입된다.
- 디폴트 대입 연산자는 멤버 대 멤버의 복사(얕은 복사)를 진행한다.
- 연산자 내에서 동적 할당을 한다면, 그리고 깊은 복사가 필요하다면 직접 정의해야 한다.

**복사 생성자가 호출되는 대표적인 상황**  
```c++
int main(void)
{
    Point pos1(5, 7);
    Point pos2 = pos1;
}
```
- 새로 생성하는 객체 pos2의 초기화에 기존에 생성된 객체 pos1이 사용되었다는 점이다.

**대입 연산자가 호출되는 대표적인 상황**  
```c++
int main(void)
{
    Point pos1(5, 7);
    Point pos2(9, 10);
    pos2 = pos1;    // pos2.operator=(pos1);
}
```
- pos2도 pos1도 이미 생성 및 초기화가 진행된 객체라는 사실이다. 즉, 기존에 생성된 두 객체간의 대입연산 시에는 대입 연산자가 호출된다.
```c++
#include <iostream>
using namespace std;

class First
{
private:
    int num1, num2;

public:
    First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
    { }
    void ShowData(void) { cout << num1 << ", " << num2 << endl; }
};

class Second
{
private:
    int num3, num4;

public:
    Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
    { }
    void ShowData(void) { cout << num3 << ", " << num4 << endl; }

    Second& operator=(const Second& ref)
    {
        cout << "Second& operator=()" << endl;
        num3 = ref.num3;
        num4 = ref.num4;
        return *this;
    }
};


int main(void)
{
    First fsrc(111, 222);
    First fcpy;

    Second ssrc(333, 444);
    Second scpy;

    fcpy = fsrc;    // 디폴트 대입 연산자 호출
    scpy = ssrc;    // 정의된 대입 연산자 호출

    fcpy.ShowData();
    scpy.ShowData();

    First fob1, fob2;
    Second sob1, sob2;
    fob1 = fob2 = fsrc;
    sob1 = sob2 = ssrc;

    fob1.ShowData();
    fob2.ShowData();
    sob1.ShowData();
    sob2.ShowData();

    return 0;
}
```
- 대입 연산자는 오른쪽에서 왼쪽으로 진행된다(결합방향에 의해).
    - 이를 통해, 디폴트 대입 연산자의 반환형을 유추할 수 있다.

### 디폴트 대입 연산자의 문제점
디폴트 복사 생성자와 같은 문제로, 깊은 복사가 이루어지지 않으면 동적 할당된 객체에 대해서 소멸자의 호출과정에 문제가 발생한다.
- 메모리 누수가 발생하지 앟도록, 깊은 복사에 앞서 메모리 해제의 과정을 거친다.
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
    Person(char *myname, int myage) : age(myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
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

    Person& operator=(const Person& ref)
    {
        delete []name;  // 메모리 누수를 막기 위한 메모리 해제 연산
        int len = strlen(ref.name) + 1;
        name = new char[len];
        strcpy(name, ref.name);
        age = ref.age;
        return *this;
    }
};

int main(void)
{
    Person man1("Lee dong woo", 29);
    Person man2("Yoon ji yul", 22);
    man2 = man1;

    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}
```


### 상속 구조에서의 대입 연산자 호출
유도 클래스의 대입 연산자에는 아무런 명시를 하지 않으면, 기초 클래스의 대입 연산자가 호출되지 않는다.
- 유도 클래스의 대입 연산자 정의에서, 명시적으로 기초 클래스의 대입 연산자 호출문을 삽입하지 않으면, 기초 클래스의 대입 연산자는 호출되지 않아서, 기초 클래스의 멤버변수는 멤버 대 멤버의 복사 대상에서 제외된다.
- 유도 클래스의 대입 연산자를 정의해야 하는 상황에 놓이게 되면, 기초 클래스의 대입 연산자를 명시적으로 호출해야 한다.
```c++
Second& operator=(const Second& ref)
{
    cout << "Second& operator=()" << endl;
    First::operaotr=(ref);  // 기초 클래스의 대입 연산자 호출을 명령!
    num3 = ref.num3;
    num4 = ref.num4;
    return *this;
}
```

</br>

## 배열의 인덱스 연산자 오버로딩

### 배열보다 나은 배열 클래스
C, C++의 기본 배열은 '경게검사를 하지 않는다'는 단점이 있다.
```c++
#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
    int *arr;
    int arrlen;

public:
    BoundCheckIntArray(int len) : arrlen(len)
    {
        arr = new int[len];
    }
    int& operator[] (int idx)
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    ~BoundCheckIntArray()
    {
        delete []arr;
    }
};


int main(void)
{
    BoundCheckIntArray arr(5);
    for (int i = 0; i < 5; i++)
    {
        arr[i] = (i + 1) * 11;
    }
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
```
- ```int& operator[] (int idx)``` -> 반환이 참조형
    - 배열요소의 참조값이 반환되고, 이 값을 이용해서 배열요소에 저장 된 값의 참조뿐만 아니라 변경도 가능하다.
- 배열은 저장소의 일종이고, 저장소에 저장된 데이터는 '유일성'이 보장되어야 하기 때문에, 대부분의 경우 저장소의 복사는 불필요하거나 잘못된 일로 간주된다.
    - 깊은 복사가 진행되도록 클래스를 정의할 것이 아니라, 빈 상태로 정의된 복사 생성자와 대입 연산자를 private 멤버로 둠으로써 복사와 대입을 원천적으로 막는 것이 좋은 선택이 되기도 한다.

### const 함수를 이용한 오버로딩 활용
const의 선언유무도 함수 오버로딩의 조건에 해당합니다.
```c++
#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
    int *arr;
    int arrlen;
    BoundCheckIntArray(const BoundCheckIntArray& ref) { }
    BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }

public:
    BoundCheckIntArray(int len) : arrlen(len)
    {
        arr = new int[len];
    }
    int& operator[] (int idx)
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    int operator[] (int idx) const
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    int GetArrLen(void) const { return arrlen; }
    ~BoundCheckIntArray() { delete []arr; }
};

void ShowAllData(const BoundCheckIntArray& ref)
{
    int len = ref.GetArrLen();
    for (int idx = 0; idx < len; idx++) { cout << ref[idx] << endl;}
}

int main(void)
{
    BoundCheckIntArray arr(5);
    for (int i = 0; i < 5; i++)
    {
        arr[i] = (i + 1) * 11;
    }
    ShowAllData(arr);

    return 0;
}
```
- ```int operator[] (int idx) const```
    - 참조값이 아닌, 배열요소의 값을 단순히 반환하는 형태로 정의되었다.

### 객체의 저장을 위한 배열 클래스의 정의
다시 한 번 공부하기

</br>

## 그 이외의 연산자 오버로딩

### new & delete
new, delete도 연산자이기 때문에 오버로딩이 가능하다.
- new 연산자는 메모리 공간의 할당만 오버로딩 할 수 있다.
- operator new, operator delete 함수들은 static 함수이므로, 객체생성의 과정에서 호출이 가능했던 것이다.

### 포인터 연산자 오버로딩
- -> : 포인터가 가리키는 객체의 멤버에 접근
- \* : 포인터가 가리키는 객체에 접근
- 둘 다 피 연산자가 하나인 단항 연산자의 형태로 오버로딩 된다는 특징을 기억하자.

### 스마트 포인터
스마트 포인터는 포인터의 역할을 하는 객체를 뜻한다.
- 스마트 포인터를 개인적으로 구현해서 사용하는 경우는 드물며, 오랜 시간 다듬어서, 그래서 라이브러리의 일부로 포함되어 있는 스마트 포인터를 활용하는 경우가 대부분이다.

### ()연산자의 오버로딩과 펑터(Functor)
- ()연산자를 오버로딩 하면, 객체를 함수처럼 사용할 수 있게 된다.
- 함수처럼 동작하는 클래스를 가리켜 '펑터(Functor)'라 한다.
    - 펑터는 함수 또는 객체의 동작방식에 유연함을 제공할 때 주로 사용된다.

### 임시객체로의 자동 형 변환과 형 변환 연산자
객체와 정수간의 대입연산도 가능할까?
- A형 객체가 와야 할 위치에 B형 데이터(또는 객체)가 왔을 경우, B형 데이터를 인자로 전달받는 A형 클래스의 생성자 호출을 통해서 A형 임시객체를 생선한다.
- 형 변환 연산자의 오버로딩
    ```c++
    operator int ()
    {
        return num;
    }
    ```
    - 반환형이 없음에도 불구하고 반환을 하고 있다.
    - int형으로 형 변환해야 하는 상황에서 호출되는 함수이다.