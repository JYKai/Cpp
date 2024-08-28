# 함수 정리

<details>
<summary>setprecision(numeric_limits<T>::digits10 + 1)</summary>
<div markdown='1'>

---
코드에서 사용된 `setprecision(numeric_limits<long double>::digits10 + 1)`는 부동소수점 숫자를 출력할 때 유효 숫자 자릿수를 설정하는 역할을 합니다. 이 설정은 `setprecision`과 `numeric_limits`의 조합을 통해 이루어지며, 이를 통해 부동소수점 숫자를 출력할 때 가능한 최대한의 정밀도를 유지하려는 목적입니다.

### 1. **`setprecision`**

- **설명**: `setprecision`은 C++ 표준 라이브러리의 `<iomanip>` 헤더에 정의된 함수로, 출력할 때 숫자의 유효 자릿수를 설정하는 데 사용됩니다.
- **용법**: `cout << setprecision(n)`과 같이 사용하면, 이후에 출력되는 숫자는 총 `n`자리의 유효 숫자로 출력됩니다. 여기서 유효 숫자는 정수 부분과 소수점 이하 부분을 포함한 자릿수를 의미합니다.

### 2. **`numeric_limits<T>::digits10`**

- **설명**: `numeric_limits`는 C++ 표준 라이브러리 `<limits>` 헤더에 정의된 템플릿 클래스입니다. 이 클래스는 특정 데이터 타입(`T`)의 특성을 제공하는데, 여기서 `digits10`은 해당 타입이 표현할 수 있는 정확한 십진수 자릿수를 나타냅니다.
- **`digits10`**: 예를 들어, `numeric_limits<float>::digits10`은 `float` 타입이 일반적으로 정확하게 표현할 수 있는 십진수 자릿수(유효 숫자)를 나타냅니다. 
  - `float`의 경우, 보통 `6` 자릿수입니다.
  - `double`의 경우, 보통 `15` 자릿수입니다.
  - `long double`의 경우, 보통 `18` 자릿수 이상입니다(시스템과 컴파일러에 따라 다름).

### 3. **`digits10 + 1`의 의미**

- **추가적인 +1**: `digits10`에 `+ 1`을 추가하는 것은 안전하게 한 자릿수 더 출력하도록 하는 것입니다. 부동소수점 숫자는 반올림 오차와 같은 문제로 인해 정확한 자릿수 이상을 사용하는 것이 안전할 수 있습니다. `+1`을 추가하면 최대 정밀도에 약간의 여유를 둠으로써 더 정확한 값을 출력할 수 있습니다.

### 4. **코드에서의 사용 예시**

코드에서 `setprecision(numeric_limits<float>::digits10 + 1)`를 사용하여 `float_value`, `double_value`, `long_double_value`를 출력할 때 다음과 같은 과정을 따릅니다:

1. **`float` 타입의 유효 자릿수 설정**:
    ```cpp
    setprecision(numeric_limits<float>::digits10 + 1)
    ```
   - `float`의 경우, `numeric_limits<float>::digits10`은 보통 `6`입니다. 따라서 `setprecision(6 + 1)`이 되어 총 `7`자리의 유효 숫자를 출력하도록 설정합니다.

2. **`double` 타입의 유효 자릿수 설정**:
    ```cpp
    setprecision(numeric_limits<double>::digits10 + 1)
    ```
   - `double`의 경우, `numeric_limits<double>::digits10`은 보통 `15`입니다. 따라서 `setprecision(15 + 1)`이 되어 총 `16`자리의 유효 숫자를 출력하도록 설정합니다.

3. **`long double` 타입의 유효 자릿수 설정**:
    ```cpp
    setprecision(numeric_limits<long double>::digits10 + 1)
    ```
   - `long double`의 경우, `numeric_limits<long double>::digits10`은 보통 `18` 이상입니다. 따라서 `setprecision(18 + 1)`이 되어 총 `19`자리 이상의 유효 숫자를 출력하도록 설정합니다.

### 5. **왜 이러한 설정이 필요한가?**

부동소수점 숫자는 컴퓨터 내부에서 근사적으로 표현되기 때문에, 출력을 통해 확인할 때 가능한 한 높은 정밀도로 표시하는 것이 중요합니다. `setprecision`과 `numeric_limits`를 사용하면 각 타입이 제공하는 최대 정밀도에 따라 숫자를 표시할 수 있어, 계산 정확성을 높이고, 예상치 못한 반올림 오차를 피할 수 있습니다.

### 6. **전체 코드에서의 영향**

전체적으로 코드는 `float`, `double`, `long double` 변수의 크기와 값을 가장 높은 정밀도로 출력하여 부동소수점 연산의 정밀도를 확인할 수 있도록 합니다. 이를 통해 데이터 타입 간의 정밀도 차이를 시각적으로 확인할 수 있습니다.

---
</div>
</details>

