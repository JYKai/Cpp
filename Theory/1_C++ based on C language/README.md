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