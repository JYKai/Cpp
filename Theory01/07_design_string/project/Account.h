/*
 * 파일이름 : Account.h
 * 작성자 : 김지윤
 * 업데이트 정보 : [2024, 06, 22] 파일버전 0.9
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
    int accID;      // 계좌번호
    int balance;    // 잔   액
    char *cusName; // 고객 이름

public:
    Account(int ID, int money, char * name);
    Account(const Account &copy);
    Account& operator=(const Account& ref);

    int GetAccID(void) const;
    virtual void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo(void) const;
    ~Account();
};
#endif