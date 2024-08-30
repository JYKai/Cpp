#include <iostream>
#include <random>

int main()
{
    // 1부터 100까지 랜덤 숫자 생성
    std::random_device rd;  // 무작위 시드 생성기
    std::mt19937 gen(rd()); // Mersenne Twister 엔진 초기화
    std::uniform_int_distribution<> dist(1, 100); // 1부터 100 사이의 정수 생성
    int answer = dist(gen);

    int count = 0;

    // 게임 시작
    bool is_correct = false;
    while (!is_correct) {
        try {
            ++count;
            int num;
            std::cout << "1 이상의 정수를 입력하세요: ";
            std::cin >> num;
            
            if (std::cin.fail()) {
                std::cin.clear();   // 실패 상태를 지우고 스트림을 정상 상태로 되돌립니다.
                // ignore() 메서드는 특정 개수의 문자를 무시하거나, 특정 문자가 나올 때까지 입력을 무시합니다.
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 버퍼 비우기
                throw std::invalid_argument("숫자를 입력해주세요!");
            }

            if (num < 1 || num > 100) {
                throw std::out_of_range("1부터 100 사이의 숫자를 입력해주세요!");
            }

            if (num > answer) {
                std::cout << "너무 높아요!" << std::endl << std::endl;
            }
            else if (num < answer) {
                std::cout << "너무 작아요!" << std::endl << std::endl;
            }
            else {
                std::cout << "축하합니다! 정답은 " << answer << "입니다." << std::endl;
                std::cout << count << "번 만에 맞추셨습니다. :)" << std::endl;
                is_correct = true;
            }
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl << std::endl;
        }
    }

    return 0;
}