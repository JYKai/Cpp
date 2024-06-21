/*
 * 파일이름 : AccountHandler.h
 * 작성자 : 김지윤
 * 업데이트 정보 : [2024, 06, 21] 파일버전 0.8
 */

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler
{
private:
    BoundCheckAccountPtrArray accArr;
    int accNum;

public:
    AccountHandler();
    void ShowMenu(void);        // 메뉴출력
    void MakeAccount(void);     // 계좌개설을 위한 함수
    void DepositMoney(void);    // 입   금
    void WithdrawMoney(void);   // 출   금
    void ShowAllAccInfo(void);  // 잔액조회
    ~AccountHandler();

protected:
    void MakeNormalAccount(void);
    void MakeCreditAccount(void);
};
#endif