#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum {CLERK, SENIOR, ASSIST, MANAGER};

    void ShowPositionInfo(int pos)
    {
        switch (pos)
        {
        case CLERK:
            cout << "사원" << endl;
            break;
        case SENIOR:
            cout << "주임" << endl;
            break;
        case ASSIST:
            cout << "대리" << endl;
            break;
        case MANAGER:
            cout << "과장" << endl;
            break;
        }
    }
}

class NameCard
{
private:
    char *name;
    char *company;
    char *number;
    int position;

public:
    NameCard(char *emName, char *comName, char *pNum, int pos)
        : position(pos)
    {
        name = new char[strlen(emName) + 1];
        strcpy(name, emName);

        company = new char[strlen(comName) + 1];
        strcpy(company, comName);

        number = new char[strlen(pNum) + 1];
        strcpy(number, pNum);
    }

    NameCard(const NameCard &copy) : position(copy.position)
    {
        name = new char[strlen(copy.name) + 1];
        strcpy(name, copy.name);

        company = new char[strlen(copy.company) + 1];
        strcpy(company, copy.company);

        number = new char[strlen(copy.number) + 1];
        strcpy(number, copy.number);
    }

    void ShowNameCardInfo(void) const
    {
        cout << "이름: " << name << endl;
        cout << "회사: " << company << endl;
        cout << "전화번호: " << number << endl;
        cout << "직급: "; COMP_POS::ShowPositionInfo(position);
        cout << endl;
    }

    ~NameCard()
    {
        delete []name;
        delete []company;
        delete []number;
    }
};


int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSENIOR;

    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();

    return 0;
}