#include <iostream>
#include <random>
#include <stdexcept>

int main()
{
    // 1부터 100까지 랜덤 숫자 생성
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    int answer = dist(gen);

    // 게임 시작
    bool is_correct = false;
    while (!is_correct)
    {
        try
        {
            int num;
            std::cout << "1 ~ 100사이의 숫자를 입력하세요: ";
            std::cin >> num;

            if (num < 1 || num > 100)
                throw std::out_of_range("입력하신 숫자는 1부터 100사이의 수여야 합니다!");

            if (num > answer)
                std::cout << "너무 높아요!" << std::endl;
            else if (num < answer)
                std::cout << "너무 낮아요!" << std::endl;
            else
            {
                is_correct = true;
                std::cout << "축하합니다!" << std::endl;
            }
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}