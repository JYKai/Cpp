#include <iostream>
#include <cstring>
using namespace std;


class MyFriendInfo
{
private:
    char *name;
    int age;

public:
    MyFriendInfo(char *name, int age) : age(age)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    void ShowMyFriendInfo(void)
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
    ~MyFriendInfo()
    {
        delete []name;
    }
};


class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char *addr;
    char *phone;

public:
    MyFriendDetailInfo(char *name, int age, char *addr, char *phone)
        : MyFriendInfo(name, age)
    {
        this->addr = new char[strlen(addr) + 1];
        this->phone = new char[strlen(phone) + 1];
        strcpy(this->addr, addr);
        strcpy(this->phone, phone);
    }
    void ShowMyFriendDefailInfo(void)
    {
        ShowMyFriendInfo();
        cout << "주소: " << addr << endl;
        cout << "전화번호: " << phone << endl << endl;
    }
    ~MyFriendDetailInfo()
    {
        delete []addr;
        delete []phone;
    }
};


int main(void)
{
    MyFriendDetailInfo frd1("Kim", 22, "Incheon", "010-1111-2222");
    frd1.ShowMyFriendDefailInfo();

    MyFriendDetailInfo frd2("Lee", 33, "Seoul", "010-4444-3333");
    frd2.ShowMyFriendDefailInfo();

    return 0;
}