# 복사 생성자(Copy Constructor)

## '복사 생성자'와의 첫 만남

### ClassName name2(name1) == ClassName name2 = name1
- ClassName형 객체를 생성하라
- 객체의 이름은 name2로 정한다.
- name1을 인자로 받을 수 있는 생성자의 호출을 통해서 객체생성을 완료한다.
```c++
ClassName(ClassName &copy)
{
    . . .
}
```
- ```ClassName name2 = name1``` 문장이 묵시적으로 ```ClassName name2(name1)```와 같이 변환된다.
```c++
#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num1;
    int num2;

public:
    SoSimple(int n1, int n2)
        : num1(n1), num2(n2)
    { }

    SoSimple(SoSimple &copy)
        : num1(copy.num1), num2(copy.num2)
    {
        cout << "Called SoSimple(SoSimple &copy)" << endl;
    }

    void ShowSimpleDate(void) const
    {
        cout << "num1 = " << num1 << endl;
        cout << "num2 = " << num2 << endl;
    }
};


int main(void)
{
    SoSimple sim1(15, 20);
    cout << "생성 및 초기화 직전" << endl;  // 생성 및 초기화 직전
    SoSimple sim2 = sim1;               // Called SoSimple(SoSimple &copy)
    cout << "생성 및 초기화 직후" << endl;  // 생성 및 초기화 직후
    sim2.ShowSimpleDate();              // num1 = 15
                                        // num2 = 20
    return 0;


}
```
- ```SoSimple(SoSimple &copy)``` -> 복사 생성자
    - 멤버 대 멤버의 복사에 사용되는 원본을 변형시키는 것은 복사의 개념을 무너뜨리는 행위가 되니, 키워드 const를 삽입해서 실수를 방지하는 것이 좋다. -> ```SoSimple(const SoSimple &copy)```


### 자동으로 삽입이 되는 디폴트 복사 생성자
복사 생성자를 정의하지 않으면, 멤버 대 멤버의 복사를 진행하는 **디폴트 복사 생성자**가 자동으로 삽입된다.

### 변환에 의한 초기화! 키워드 explicit으로 막을 수 있다.
```ClassName name2 = name1``` 문장이 묵시적으로 ```ClassName name2(name1)```와 같이 변환된다.
- 위와 같은 유형의 변환이 마음에 들지 않는다면, 복사 생성자의 묵시적 호출을 허용하지 않으면 된다. = ```explicit```
```c++
explicit SoSimple(const SoSimple &copy)
            : num1(copy.num1), num2(copy.num2)
{ }
```
- 위와 같이 설정하면, 묵시적 변환이 발생하지 않아서 대입 연산자를 이용한 객체의 생성 및 초기화는 불가능해진다.
    - 묵시적 변환이 많이 발생하는 코드일수록 코드의 결과를 예측하기가 어려워진다. 
    - ```explicit```은 코드의 명확함을 더하기 위해서 자주 자용되는 키워드 중 하나이다.
- 복사 생성사의 매개변수는 반드시 참조형이여야 한다.
    - & 선언이 없다면 복사 생성자의 호출은 무한루프에 빠져버린다. 다행히, C++ 컴파일러는 &선언을 하지 않으면 컴파일 에러를 발생시켜준다.

</br>

## '깊은 복사'와 '얕은 복사'

### 디폴트 복사 생성자의 문제점
디폴트 복사 생성자는 멤버 대 멤버를 단순 복사하는 '얕은 복사'를 진행하기 때문에 기존의 객체가 포인터를 통해 문자열을 참조하고 있으면, 그 포인터의 주소를 복사하여 결과적으로 하나의 문자열을 두 개의 객체가 동시에 참조하는 꼴을 만들어버린다.
- 객체의 소멸과정에서 문제가 발생한다.

### '깊은 복사'를 위한 복사 생성자의 정의
'깊은 복사' : 멤버뿐만 아니라, 포인터로 참조하는 대상까지 깊게 복사한다는 뜻
```c++
// 깊은 복사를 위한 복사 생성자 정의
Person(const Person& copy) : age(copy.age)
{
    name = new char(strlen(copy.name) + 1);
    strcpy(name, copy.name);
}
```
- 멤버변수 age의 멤버 대 멤버 복사
- 메모리 공간 할당후 문자열 복사, 그리고 할당된 메모리의 주소값을 멤버 name에 저장

</br>

## 복사 생성자의 호출시점

### 복사 생성자가 호출되는 시점은?
- case 1: 기존에 생성된 객체를 이용해서 새로운 객체를 초기화하는 경우
- case 2: Call-by-value 방식의 함수호출 과정에서 객체를 인자로 전달하는 경우
- case 3: 객체를 반환하되, 참조형으로 반환하지 않는 경우
복사 생성자의 호출횟수는 프로그램의 성능과도 관계가 있기 때문에, 호출의 시기를 이해하는 것은 매우 중요하다.

### 메모리 공간의 할당과 초기화가 동시에 일어나는 상황!
- ```int num1 = num2``` : num1이라는 이름의 메모리 공간을 할당과 동시에 num2에 저장된 값으로 초기화
- ```int SimpleFunc(int n); SimpleFunc(num)``` : 매개변수 n이 할당과 동시에 변수 num에 저장된 값으로 초기화
- ```return n;``` : 반환하는 순간 메모리 공간이 할당되면서 동시에 초기화
    - 반환되는 값을 별도의 변수에 저장하는 것과 별개로, 값을 반환하면 반환된 값은 별도의 메모리 공간이 할당되어서 저장이 된다.
    - 함수가 값을 반환하면, 별도의 메모리 공간이 할당되고, 이 공간에 반환 값이 저장된다.
    - 반환형이 참조형이 아니면 복사본이 만들어지면서 반환이 진행된다.
    - 객체를 반환하게 되면, **'임시객체'**라는 것이 생성되고, 이 객체의 복사 생성자가 호출되면서 return문에 명시된 객체가 인자로 전달된다. 즉, 최종적으로 변환되는 객체는 새롭게 생성되는 임시객체이다.
        - 임시객체가 생성된 위치에는 임시객체의 참조 값이 반환된다.
        - 임시객체는 다음 행으로 넘어가면 바로 소멸되어 버린다.
        - 참조자에 참조되는 임시객체는 바로 소멸되지 않는다.
위의 세 가지 상황은 객체를 대상으로 해도 달라지지 않는다.





### 할당 이후, 복사 생성자를 통한 초기화
초기화는 멤버 대 멤버가 복사되는 형태로 이뤄져야 한다.