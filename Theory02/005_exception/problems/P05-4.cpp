#include <iostream>
#include <stdexcept>
// #include <string>

std::string get_season(int month) {
  if (month >= 3 && month <= 5)
    return "봄";
  else if (month >= 6 && month <= 8)
    return "여름";
  else if (month >= 9 && month <= 11)
    return "가을";
  else // month가 12, 1, 2일 때
    return "겨울";
}

int main()
{
    try
    {
        int month, day;
        std::cout << "월을 입력하세요: "; std::cin >> month;

        if (month < 1 || month > 12)
        {
            throw std::out_of_range("월의 범위를 벗어났습니다.");
        }

        std::cout << "일을 입력하세요: "; std::cin >> day;

        if (day < 1 || day > 31)
        {
            throw std::out_of_range("일의 범위를 벗어났습니다.");
        }

        std::string season = get_season(month);
        std::cout << "입력하신 날짜의 계절은 " << season << "입니다." << std::endl;
    }
    catch (std::out_of_range& ex)
    {
        std::cerr << "예외 발생: " << ex.what() << std::endl;
    }

    return 0;
}