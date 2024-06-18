#include <iostream>

namespace BestComImpl
{
    void SimpleFunc(void);
}

namespace BestComImpl
{
    void PrettyFunc(void);
}

namespace ProgComImpl
{
    void SimpleFunc(void);
}

int main(void)
{
    BestComImpl::SimpleFunc();
    return 0;
}

void BestComImpl::SimpleFunc(void)
{
    std::cout << "BestCom이 정의한 함수" << std::endl;
    PrettyFunc(); // 동일한 이름 공간
    ProgComImpl::SimpleFunc(); // 다른 이름 공간
}