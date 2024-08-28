# Problem Analysis

## P2
```c++
#include <iostream>
#include <cstring>

int main()
{
    std::string name;
    std::string number;

    std::cout << "이름을 입력하세요: ";
    std::getline(std::cin, name);

    std::cout << "전화번호를 입력하세요: ";
    std::getline(std::cin, number);

    std::cout << "이름: " << name << std::endl;
    std::cout << "전화번호: " << number << std::endl;

    return 0;
}
```

**문자 배열(char array) 대신 `std::string` 사용**  
- C++에서는 char 배열을 사용하여 문자열을 저장할 수 있지만, 이는 안전하지 않고 유연성이 부족합니다. 
- C++에서는 문자열을 다룰 때 `std::string` 클래스를 사용하는 것이 더 안전하고 편리합니다.
- char 배열은 크기가 고정되어 있으며, 배열의 크기를 초과하는 문자열 입력 시 버퍼 오버플로우가 발생할 수 있습니다.
- `std::string`은 크기가 가변적이며, 문자열 조작에 유용한 다양한 기능을 제공합니다.

</br>

**`std::cin` 사용 시 문자열 입력 제한**  
- 기존 코드에서는 `std::cin`을 사용해 문자열을 입력받을 때, 공백이 포함된 문자열은 제대로 입력받지 못합니다. 예를 들어, 이름을 "John Doe"로 입력하려고 하면 John만 입력됩니다. 이 문제를 해결하기 위해 `std::getline`을 사용할 수 있습니다.