# C언어 기반의 C++

## printf & scanf를 대신하는 입출력 방식

### 문자열 "Hello, World"의 출력
- 파일 이름을 지정할 때, 확장자를 .cpp로 해준다.
```C++
#include <iostream>

int main(void)
{
    std::cout << "Hello World!" << std::endl; // Hello World!
    std::cout << "Hello " << "World!" << std::endl; // Hello World!
    
    return 0;
}
```

1. 헤더파일 선언문 ```#include <iostream>```
- std, cout, endl을 사용하기 위해 사용한다.
- C 언어와 달리 헤더파일을 생략한다.

2. ```std::cout```과 ```<<``` 연산를 이용한 출력
```C++
std::cout << '출력대상';
```
- '출력대상' 위치에는 무엇이든 올 수 있다.
- C 언어와 달리 서식문자를 이용해서 별도의 출력포맷을 지정하지 않아도 출력이 이루어진다.

3. ```<<``` 연산자를 이용한 출력대상의 연이은 표현과 개행
```C++
std::cout << '출력대상1' << '출력대상2' << '출력대상3';
```

### scanf를 대신하는 데이터의 입력

```C++
#include <iostream>

int main(void)
{
    int val1, val2 = 0;
    std::cout << "두 개의 숫자 입력: "; // 두 개의 숫자 입력: 1 3
    std::cin >> val1 >> val2;

    int result = val1 + val2;
    std::cout << "덧셈결과: " << result << std::endl; // 덧셈결과: 4
    
    return 0;
}
```

1. 데이터의 입력에 사용되는 ```std::cin```과 ```>>``` 연산자
```C++
std::cin >> '변수'
```
- 정수를 하나 입력받아 '변수'에 저장한다.
- C++에서는 데이터의 입력 또한 별도의 포맷 지정이 필요 없다.

2. C++의 지역변수 선언
- C 언어의 경우 함수를 정의함에 있어 지역변수의 선언이 항상 먼저 등장해야한다. 반면, C++는 함수 내 어디든 지역변수를 선언할 수 있다.

두 개의 정수를 입력받아서 두 정수 사이의 정수들의 합 구하기
```c++
#include <iostream>

int main(void)
{
    int val1, val2;
    int result = 0;
    std::cout << "두 개의 숫자입력: ";
    std::cin >> val1 >> val2;

    if (val1 < val2)
    {
        for (int i = val1 + 1; i < val2; i++)
        {
            result += i;
        }
    }
    else
    {
        for (int i = val2 + 2; i < val1; i++)
        {
            result += i;
        }
    }

    std::cout << "두 수 사이의 정수의 합: " << result << std::endl;

    return 0;
}
```
- for문의 초기화 문장 내에서 변수 선언이 가능함을 알 수 있다.

### 배열 기반의 문자열 입출력
```c++
#include <iostream>

int main(void)
{
    char name[100];
    char lang[200];

    std::cout << "이름을 입력하시오. ";
    std::cin >> name;

    std::cout << "좋아하는 프로그래밍 언어를 입력하시오. ";
    std::cin >> lang;

    std::cout << "이름: " << name << std::endl;
    std::cout << "좋아하는 프로그래밍 언어: " << lang << std::endl;

    return 0;
}

// 이름: 김지윤
// 좋아하는 프로그래밍 언어: C++
```

</br>

## 함수 오버로딩(Function Overloading)
- C 언어에서는 동일한 이름의 함수가 정의되는 것을 허용하지 않는다.
- C++ 에서는 함수호출 시 전달되는 인자를 통해서 호출하고자 하는 함수의 구분이 가능하다.
- 즉, 함수 오버로딩을 위해 매개변수의 자료형 또는 개수가 다르면 같은 이름의 함수를 정의할 수 있다.
- 반환형은 함수호출 시, 호출되는 함수를 구분하는 기준이 될 수 없다.
```c++
#include <iostream>

void Func(void)
{
    std::cout << "Func(void) called!" << std::endl;
}

void Func(char c)
{
    std::cout << "Func(char c) called!" << std::endl;
}

void Func(int a, int b)
{
    std::cout << "Func(int a, int b) called!" << std::endl;
}

int main(void)
{
    Func();
    Func('A');
    Func(12, 13);

    return 0;
}

// Func(void) called!
// Func(char c) called!
// Func(int a, int b) called!
```

</br>

## 매개변수의 디폴트 값

```c++
#include <iostream>

int Adder(int num1=1, int num2=2)
{
    return num1 + num2;
}

int main(void)
{
    std::cout << Adder() << std::endl; // 3
    std::cout << Adder(5) << std::endl; // 7
    std::cout << Adder(1, 5) << std::endl; // 6

    return 0;
}
```
- 매개변수에 디폴트 값이 설정되어 있으면, 선언된 매개변수의 수보다 적은 수의 인자전달이 가능하다. 전달되는 인자는 왼쪽부터 입력되고, 부족한 부분은 디폴트 값으로 채워진다.

```c++
#include <iostream>

int Adder(int num1=1, int num2=2);

int main(void)
{
    std::cout << Adder() << std::endl; // 3
    std::cout << Adder(5) << std::endl; // 7
    std::cout << Adder(1, 5) << std::endl; // 6

    return 0;
}

int Adder(int num1, int num2)
{
    return num1 + num2;
}
```
- 함수의 선언이 별도로 필요한 경우 디폴트 값은 함수의 선언 부분에만 위치시켜야 한다.
    - 함수의 선언부분에 위치하지 않는다면 ```Adder(), Adder(5)``` 가 컴파일 될 수 없다.

- 함수의 전달되는 인자가 왼쪽부터 채워지기 때문에 부분적으로 디폴트 값을 설정하려면 반드시 오른쪽 매개변수의 디폴트 값부터 채우는 형태가 되어야 한다.

</br>

## 인라인(inline) 함수
인라인 함수란 '프로그램 코드라인 안으로 들어가 버린 함수'라는 뜻이다.

### 매크로 함수
**장점**  
'일반적인 함수에 비해서 실행속도의 이점이 있다.'

**단점**  
'정의하기가 어렵다. 복잡한 함수를 매크로의 형태로 정의하는데 한계가 있다.'
```c++
#include <iostream>
#define SQUARE(x) ((x) * (x))

int main(void)
{
    std::cout << SQUARE(5) << endl;
    return 0;
}
```
- 함수의 몸체부분이 함수호출 문장을 완전히 대체했을 때 '함수가 인라인화 되었다'라고 표현한다.


### C++ 기반의 인라인 함수 정의
```c++
#include <iostream>

inline int SQUARE(int x) { return x*x; }

int main(void)
{
    std::cout << SQUARE(5) << std::endl;  // 25
    std::cout << SQUARE(12) << std::endl; // 144

    return 0;
}
```
- ```inline int SQUARE(int x) { return x*x; }```
    - 키워드 inline의 선언을 통해서 함수 SQUARE는 인라인 함수가 된다.

**참고**  
- 매크로를 이용한 함수의 인라인화는 전처리기에 의해서 처리되지만, 키워드 inline을 이용한 함수의 인라인화는 컴파일러에 의해서 처리가 된다.
- 컴파일러는 함수의 인라인화가 오히려 성능에 해가 된다고 판단할 경우, 이 키워드를 무시해버리기도 한다.
- 컴파일러는 필요한 경우 일부 함수를 임의로 인라인 처리하기도 한다.


### 매크로 함수에는 있지만, 인라인 함수에는 없는 장점
```#define SQUARE(x) ((x) * (x))```
- 자료형에 의존적이지 않다. x에 정수가 들어가거나 실수가 들어가도 상관없다.
```inline int SQUARE(int x) { return x*x; }```
- int형 기반으로 정의된 함수이기 때문에 데이터 손실이 발생할 수 있다.
    - ```template```를 활용하면 해결할 수 있다.

</br>

## 이름공간(namespace)
말 그대로 특정 영역에 이름을 붙여주기 위한 문법적 요소이다.

```c++
#include <iostream>

namespace BestComImpl
{
    void SimpleFunc(void)
    {
        std::cout << "BestCom이 정의한 함수" << std::endl;
    }
}

namespace ProgComImpl
{
    void SimpleFunc(void)
    {
        std::cout << "ProgCom이 정의한 함수" << std::endl;
    }
}

int main(void)
{
    BestComImpl::SimpleFunc(); // BestCom이 정의한 함수
    ProgComImpl::SimpleFunc(); // ProgCom이 정의한 함수

    return 0;
}
```
- ```::``` : 범위지정 연산자(scope resolution operator)로 이름공간을 지정할 때 사용하는 연산자이다.

### 이름공간 기반의 함수 선언과 정의 구분
```c++
#include <iostream>

namespace BestComImpl
{
    void SimpleFunc(void);
}

namespace BestComImpl
{
    void PrettyFunc(void);
}

namespace ProgComImpl
{
    void SimpleFunc(void);
}

int main(void)
{
    BestComImpl::SimpleFunc();
    return 0;
}

void BestComImpl::SimpleFunc(void)
{
    std::cout << "BestCom이 정의한 함수" << std::endl;
    PrettyFunc(); // 동일한 이름 공간
    ProgComImpl::SimpleFunc(); // 다른 이름 공간
}
```
- 동일한 이름공간에 정의된 함수를 호출할 때에는 이름공간을 명시할 필요가 없다.
- 이름공간은 둘 이상의 영역으로 나뉘어서 선언할 수도 있다. 동일공간으로 간주된다.


### 이름공간의 중첩
이름공간은 다른 이름공간 안에 삽입될 수 있다.


### using을 이용한 이름공간의 명시
```c++
#include <iostream>

namespace Hybrid
{
    void HybFunc(void)
    {
        std::cout << "So simple function!" << std::endl;
        std::cout << "In namespace Hybrid!" << std::endl;
    }
}

int main(void)
{
    using Hybrid::HybFunc;
    HybFunc();
    return 0;
}
```
- ```using Hybrid::HybFunc;```
    - 키워드 using을 사용해서 '이름공간 Hybrid에 정의된 HybFunc를 호출할 때에는, 이름공간을 지정하지 않고 호출하겠다'라는 것을 명시하고 있다.

```c++
#include <iostream>
using namespace std;

int main(void)
{
    int num = 20;
    cout << "Hello World!" << endl;
    cout << "num = " << num << endl;

    return 0;
}
```
- 이름공간 std에 선언된 모든 것에 대해 이름공간 지정의 생략 = ```using namespace std```
    - 이름충돌이 발생할 확률은 상대적으로 높아진다.

### 이름공간의 별칭 지정
```c++
#include <iostream>
using namespace std;

namespace AAA
{
    namespace BBB
    {
        namespace CCC
        {
            int num1;
            int num2;
        }
    }
}

int main(void)
{
    AAA::BBB::CCC::num1 = 20;
    AAA::BBB::CCC::num2 = 30;

    namespace ABC=AAA::BBB::CCC;
    cout << ABC::num1 << endl;
    cout << ABC::num2 << endl;

    return 0;
}
```
- ```namespace ABC=AAA::BBB::CCC;``` : 별칭을 붙여주고 있다.

### 범위지정 연산자의 또 다른 기능
지역변수의 이름이 전역변수의 이름과 같을 경우, 전역변수는 지역변수에 의해 가려진다. 이를 범위지정 연산자를 사용해서 가려지지 않도록 할 수 있다.
```c++
int val = 100;

int SimpleFunc(void)
{
    int val = 20;   // 지역변수
    val += 3;       // 지역변수 val의 값 3 증가
    ::val += 7;     // 전역변수 val의 값 7 증가
}
```

</br>

## 새로운 자료형 bool

### '참'을 의미하는 true와 '거짓'을 의미하는 false
C++에서는 참과 거짓의 표현을 위한 키워드 true와 false를 정의하고 있기 때문에, 굳이 매크로 상수를 이용해서 참과 거짓을 표현할 필요가 없다.
```c++
#include <iostream>
using namespace std;

int main(void)
{
    int num = 10;
    int i = 0;

    cout << "true = " << true << endl;
    cout << "false = " << false << endl;

    while (true)
    {
        cout << i++ << " ";
        if (i > num) { break; }
        cout << endl;
    }

    cout << "sizeof 1: " << sizeof(1) << endl;
    cout << "sizeof 0: " << sizeof(0) << endl;
    cout << "sizeof true: " << sizeof(true) << endl;
    cout << "sizeof false: " << sizeof(false) << endl;

    return 0;
}
```
- true는 1이 아니며, false 역시 0이 아니다. 이 둘은 '참'과 '거짓'을 표현하기 위한 1바이트 크기의 데이터일 뿐이다.
- true와 false를 굳이 숫자에 연결시켜서 이해하지 말자.

### 자료형 bool
```c++
#include <iostream>
using namespace std;

bool IsPositive(int num)
{
    if (num < 0) { return false; }
    else { return true; }
}

int main(void)
{
    bool isPos;
    int num;
    cout << "Input number: "; cin >> num;

    isPos = IsPositive(num);
    if (isPos) { cout << "Positive number." << endl; }
    else {cout << "Negative number." << endl; }

    return 0;
}
```
- true와 false를 가리켜 bool 데이터라 하며, 기본자료형의 하나 이기 때문에 bool형 변수를 선언하는 것이 가능하다.

</br>

## 참조자(Reference)

### 참조자의 이해
& 연산자는 변수의 주소 값을 반환하는 연산자이지만, 새로 선언되는 변수의 이름 앞에 사용하면 참조자의 선언을 뜻하게 된다.
- ``` int &num2 = num1; ```
- 참조자는 자신이 참조하는 변수를 대신할 수 있는 또 하나의 이름이다.
```c++
#include <iostream>
using namespace std;

int main(void)
{
    int num1 = 1020;
    int &num2 = num1;

    num2 = 3048;

    cout << "VAL: " << num1 << endl;        // VAL: 3048
    cout << "REF: " << num2 << endl;        // REF: 3048

    cout << "VAL: " << &num1 << endl;       // VAL: 0x16ef6b0f8
    cout << "REF: " << &num2 << endl;       // REF: 0x16ef6b0f8

    return 0;
}
```
- num2는 num1과 동일한 메모리 공간을 참조하게 된다. 따라서, 값의 변화가 같이 이루어지며 결과적으로 주소 또한 같음을 확인할 수 있다.
- 참조자 수에는 제한이 없으며, 참조자를 대상으로도 참조자를 선언할 수 있다.


### 참조자의 선언 가능 범위
참조자는 변수에 대해서만 선언이 가능하고, 선언됨과 동시에 누군가를 참조해야한다.
- 상수를 대상으로 참조자를 선언할 수는 없다.
- 미리 참조자를 선언했다가, 후에 누군가를 참조하는 것을 불가능하다.
```c++
#include <iostream>
using namespace std;

int main(void)
{
    int arr[3] = {1, 3, 5};
    int &ref1 = arr[0];
    int &ref2 = arr[1];
    int &ref3 = arr[2];

    cout << ref1 << endl;   // 1
    cout << ref2 << endl;   // 3
    cout << ref3 << endl;   // 5

    return 0;
}
```
- 배열요소는(배열이 아닌, 배열요소) 변수로 간주되어 참조자의 선언이 가능하다.
- 포인터 변수도 변수이기 때문에 참조자의 선언이 가능하다.
```c++
#include <iostream>
using namespace std;

int main(void)
{
    int num = 12;
    int *ptr = &num;
    int **dptr = &ptr;

    int &ref = num;
    int *(&pref) = ptr;
    int **(&dpref) = dptr;

    cout << ref << endl;        // 12
    cout << *pref << endl;      // 12
    cout << **dpref << endl;    // 12

    return 0;
}
```
- 포인터 변수의 참조자 선언도 & 연산자를 하나 더 추가하는 형태로 진행된다.

</br>

## 참조자(Reference)와 함수
함수에 사용되는 매개변수에 참조자를 사용할 수 있다.
- 매개변수는 함수가 호출되어야 초기화가 진행되는 변수들이기 때문에 매개변수 선언은 초기화가 이뤄지지 않은 것이 아니라, 함수호출 시 전달되는 인자로 초기화를 하겠다는 의미의 선언일 뿐이다.
```c++
#include <iostream>
using namespace std;

void SwapByRef2(int &ref1, int &ref2);

int main(void)
{
    int val1 = 10;
    int val2 = 20;

    SwapByRef2(val1, val2);
    
    cout << "val1 = " << val1 << endl;  // val1 = 20
    cout << "val2 = " << val2 << endl;  // val2 = 10

    return 0;
}

void SwapByRef2(int &ref1, int &ref2)
{
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}
```
- 위와 같이 C++에서는 Call-by-reference의 구현 방법에 참조자를 이용하는 방법과 주소 값을 이용하는 방법, 이렇게 두 가지가 존재한다.


### 참조자를 이용한 Call-by-reference의 황당함과 const 참조자
참조자를 사용하는 경우, 함수의 원형을 확인해야 하고, 확인결과 참조자가 매개변수의 선언에 와있다면, 함수의 몸체까지 문장 단위로 확인을 해서 참조자를 통한 값의 변경이 일어나는지를 확인해야 한다.
- C언어에서는 함수의 호출문장만 보고도 값이 변경되지 않음을 알 수 있지만, C++에서는 불가능하다.
- const 키워드를 이용하면 위의 단점을 어느 정도 보완할 수 있다.
    - ```void HappyFunc(const int &ref) { ... }```
        - 함수 HappyFunc 내에서 참조라 ref를 이용한 값의 변경은 하지 않겠다!
    - 함수 내에서, 참조자를 통한 값의 변경을 진행하지 않을 경우, 참조자를 const로 선언해서, 함수의 원형만 봐도 값의 변경이 이뤄지지 않음을 알 수 있게 한다. => 중요한 원칙과 습관


### 반환형이 참조형인 경우
```c++
#include <iostream>
using namespace std;

int& RefRetFuncOne(int &ref);

int main(void)
{
    int num1 = 1;
    int &num2 = RefRetFuncOne(num1);

    num1++;
    num2++;

    cout << "num1: " << num1 << endl;   // num1: 4
    cout << "num2: " << num2 << endl;   // num2: 4

    return 0;
}

int& RefRetFuncOne(int &ref)
{
    ref++;
    return ref;
}
```
- 과정
    - ```int num1 = 1 -> int &ref = num1 -> int &num2 = ref```
- 매개변수로 선언된 참조자 ref는 지역변수와 동일한 성격을 갖으므로, 함수가 반환이 되면 참조자 ref는 소멸이 된다.
- ```int &num2 = RefRetFuncOne(num1);``` 에서 ```int num2 = ... ``` 형식으로 바뀌게 되면?
    ```c++
    #include <iostream>
    using namespace std;

    int& RefRetFuncTwo(int &ref);

    int main(void)
    {
        int num1 = 1;
        int num2 = RefRetFuncTwo(num1);

        num1++;
        num2 += 100;

        cout << "num1: " << num1 << endl;   // num1: 3
        cout << "num2: " << num2 << endl;   // num2: 102

        return 0;
    }

    int& RefRetFuncTwo(int &ref)
    {
        ref++;
        return ref;
    }
    ```
    - 참조형으로 반환이 되지만, 참조자가 아닌 일반변수를 선언해서 반환 값을 저장했기 때문에 num1과 num2는 완전히 별개의 변수가 된다.
- 참조자를 반환하되, 반환형은 기본자료형인 경우 참조자가 참조하는 변수의 값이 반환된다.
- 지역변수를 참조형으로 반환하게 되면 함수가 종료될 때 이미 지역변수는 사라지기 때문에 지역변수를 참조형으로 반환하는 일은 없어야한다.


### const 참조자의 또 다른 특징 
```c++
const int num = 20;
const int &ref = num;
```
- 상수화된 변수 num과 같이 참조자 선언 또한 const를 붙여준다.

### 참조자가 상수를 참조한다..?
```c++
const int &ref = 50;
```
- const 참조자를 이용해서 상수를 참조할 때 '임시변수'라는 것을 만들어, 상수를 저장하고 참조자가 이를 참조하게끔 한다.

**왜 굳이..?**  
```c++
int Adder(const int &num1, const int &num2)
{
    return num1 + num2;
}
```
- 위와 같이 정의된 함수에 인자 전달을 목적으로 변수를 선언한다는 것은 매우 번거로운 일이 아닐 수 없다.
    - 임시변수의 생성을 통한 const 참조자의 상수참조를 허용함으로써, 위의 함수는 간단히 호출할 수 있게 된다.

</br>


## malloc & free를 대신하는 new & delete

### new & delete
```c++
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

char *MakeStrAdr(int len);

int main(void)
{
    char *str = MakeStrAdr(20);
    strcpy(str, "I am so happy~");
    
    cout << str << endl;    // I am so happy~
    free(str);
    return 0;
}

char *MakeStrAdr(int len)
{
    char *str = (char *)malloc(sizeof(char) * len);
    return str;
}
```
- ```char *str = (char *)malloc(sizeof(char) * len);```
    - 할당된 대상의 정보를 무조건 바이트 크기단위로 전달해야 한다.
    - 반환형이 void형 포인터이기 때문에 적절한 형 변환을 거쳐야 한다.

```c++
#include <iostream>
#include <string.h>
using namespace std;

char *MakeStrAdr(int len);

int main(void)
{
    char *str = MakeStrAdr(20);
    strcpy(str, "I am so happy~");

    cout << str << endl;
    delete []str;
    return 0;
}

char *MakeStrAdr(int len)
{
    char *str = new char[len];
    return str;
}
```


### 힙에 할당된 변수? 이제 포인터를 사용하지 않아도 접근할 수 있다.
new 연산자를 이용해서 할당된 메모리 공간에도 참조자의 선언이 가능할까?
- 변수의 자격을 갖추기 위해서는 메모리 공간이 할당되고, 그 공간을 의미하는 이름이 존재해야 하지만, C++에서는 new 연산자를 이용해서 할당된 메모리 공간도 변수로 간주한다. 따라서, 참조자로 선언할 수 있다.
```c++
int *ptr = new int;
int &ref = *ptr;    // 힙 영역에 할당된 변수에 대한 참조자 선언
ref = 20;
cout << *ptr << endl;   // 출력결과는 20!
```

</br>

## C++에서 C언어의 표준함수 호출하기

### c를 더하고 .h를 빼라.
- ```#include <stdio.h> -> #include <cstdio>```
- ```#include <string.h> -> #include <cstring>```