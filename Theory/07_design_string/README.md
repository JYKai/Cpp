# String 클래스의 디자인

## C++의 표준과 표준 string 클래스

### 표준 string 클래스
```c++
#include <iostream>
#include <string>
using namespace std;


int main(void)
{
    string str1 = "I like ";
    string str2 = "string class";
    string str3 = str1 + str2;

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    str1 += str2;
    if (str1 == str3) { cout << "동일 문자열!" << endl; }
    else { cout << "동일하지 않은 문자열!" << endl; }

    string str4;
    cout << "문자열 입력 : "; cin >> str4;
    cout << "입력한 문자열 : " << str4 << endl;

    return 0;
}
```
- ```string str3 = str1 + str2;```
    - string 객체간 덧셈연산이 가능하다. -> opeartor+ 연산자의 오버로딩이 되어있다는 것을 확인할 수 있다.
- <<, >>, += 등에도 오버로딩이 되어있다는 것을 알 수 있다.

</br>

## 문자열 처리 클래스의 정의

### 표준 string 클래스의 분석

**string 클래스를 대체하는 새로운 String 클래스의 정의를 위해서 필요한 것**  
1. 문자열을 인자로 전달받는 생성자의 정의
2. 생성자, 소멸자, 복사 생성자 그리고 대입 연산자의 정의
    - 문자열의 저장을 위한 메모리 공간을 생성자 내에서 동적 할당해야한다.
3. 결합된 문자열로 초기화된 객체를 반환하는 + 연산자의 오버로딩
4. 문자열을 덧붙이는 += 연산자의 오버로딩
5. 내용비교를 진행하는 == 연산자의 오버로딩
6. 콘솔입출력이 가능하도록 <<, >> 연산자의 오버로딩


**String 클래스의 선언 부분**
```c++
#include <iostream>
#include <cstring>
using namespace std;


class String
{
private:
    int len;
    char * str;

public:
    String();
    String(const char * s);
    String(const String& s);
    ~String();
    String& operator= (const String& s);
    String& operator+= (const String& s);
    bool operator== (const String& s);
    String operator+ (const String& s);

    friend ostream& operator<< (ostream& os, const String& s);
    friend istream& operator>> (istream& is, String& s);
};
```

**String 클래스의 정의 부분**
```c++
String::String()
{
    len = 0;
    str = NULL;
}

String::String(const char * s)
{
    len = strlen(s) + 1;
    str = new char[len];
    strcpy(str, s);
}

String::String(const String& s)
{
    len = s.len;
    str = new char[len];
    strcpy(str, s.str);
}

String::~String()
{
    if (str != NULL) { delete []str; }
}

String& String::operator= (const String& s)
{
    if (str != NULL) { delete []str; }
    len = s.len;
    str = new char[len];
    strcpy(str, s.str);
}

String& String::operator+= (const String& s)
{
    len += (s.len - 1);
    char *tempstr = new char[len];
    strcpy(tempstr, str);
    strcpy(tempstr, s.str);

    if (str != NULL) { delete []str; }
    str = tempstr;
    return *this;
}

bool String::operator== (const String& s)
{
    return strcmp(str, s.str) ? false : true;
}

String String::operator+ (const String& s)
{
    char *tempstr = new char[len + s.len - 1];
    strcpy(tempstr, str);
    strcpy(tempstr, s.str);

    String temp(tempstr);
    delete []tempstr;
    return temp;
}

ostream& operator<< (ostream& os, const String& s)
{
    os << s.str;
    return os;
}

istream& operator>> (istream& is, String& s)
{
    char str[100];
    is >> str;
    s = String(str);
    return is;
}
```
- \+ 연산자는 원래 새로운 값을 만들어 내는 연산자이지, 피연산자의 값을 변경시키는 연산자가 아니다.
    - 메모리 공간을 계산하는데 있어 -1을 한 이유는 멤버변수 len에 저장된 문자열의 길이 정보에 문자열의 끝을 의미하는 NULL 문자도 포함되어 있기 때문이다. => NULL이 두 번 계산되었으니 하나를 빼는 것은 당연하다.

