#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float float_value = 9.87654321f;
    double double_value = 9.87654321987654321;
    long double long_double_value = 9.87654321987654321l;

    cout << "float : " << sizeof(float) << " bytes" << endl;
    cout << "float_value : " <<
        setprecision(numeric_limits<float>::digits10 + 1) << 
        float_value << endl << endl;

    // setprecision은 C++ 표준 라이브러리의 <iomanip> 헤더에 정의된 함수로, 출력할 때 숫자의 유효 자릿수를 설정하는 데 사용됩니다.
    // numeric_limits<float>::digits10은 float 타입이 일반적으로 정확하게 표현할 수 있는 십진수 자릿수(유효 숫자)를 나타냅니다.

    cout << "double : " << sizeof(double) << " bytes" << endl;
    cout << "double_value : " <<
        setprecision(numeric_limits<double>::digits10 + 1) <<
        double_value << endl << endl;
    
    cout << "long double : " << sizeof(long double) << " bytes" << endl;
    cout << "long_double_value : " <<
        setprecision(numeric_limits<long double>::digits10 + 1) <<
        long_double_value << endl << endl;

    return 0;
}