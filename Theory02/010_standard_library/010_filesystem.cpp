#include <iostream>
#include <string>
#include <filesystem>   // 파일 시스템 헤더 파일
#include <fstream>      // 파일 입출력 헤더 파일

namespace fs = std::filesystem;

int main()
{
    // 1. 디렉터리 생성
    fs::create_directories("MyDirectory"); // 중간 단계의 디렉터리도 생성

    // 2. 파일 생성과 쓰기
    std::ofstream outFile("MyDirectory/myFile.txt");    // ofstream(파일 출력 스트림)
    outFile << "Hello, FlieStream Library!" << std::endl;
    outFile.close();

    // 3. 디렉터리 내의 파일 확인
    std::cout << "Files in MyDirectory:\n";
    for (const fs::directory_entry& entry : fs::directory_iterator("MyDirectory"))
    {
        if (entry.is_regular_file())
        {
            std::cout << entry.path().filename() << std::endl;
        }
    }

    // 4. 파일 읽기
    std::ifstream inFile("MyDirectory/myFile.txt");
    if (!inFile)
    {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
        return 1;
    }

    std::string line;
    while (getline(inFile, line))
        std::cout << line << std::endl;
    inFile.close();

    // 파일과 디렉터리 삭제
    fs::remove_all("MyDirectory");

    return 0;
}