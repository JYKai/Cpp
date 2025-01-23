#include <iostream>
#include <stdexcept>

std::string get_season(int month)
{
    if (month >= 3 && month <= 5)
        return "봄";
    else if (month >= 6 && month <= 8)
        return "여름";
    else if (month >= 9 && month <= 11)
        return "가을";
    else
        return "겨울";
}

int main()
{
    try
    {
        int month, day;

        std::cout << "월을 입력하세요: ";
        std::cin >> month;

        if (month < 1 || month > 12)
            throw std::out_of_range("월은 1부터 12까지의 정수여야 한다.");
        
        std::cout << "일을 입력하세요: ";
        std::cin >> day;

        if (day < 1 || day > 31)
            throw std::out_of_range("일은 1부터 31까지의 정수여야 한다.");

        std::string string_season = get_season(month);
        std::cout << "입력하신 날짜의 계절은 " << string_season << "입니다." << std::endl;
    }
    catch(const std::out_of_range &ex)
    {
        std::cerr << ex.what() << '\n';
    }
    
    return 0;
}