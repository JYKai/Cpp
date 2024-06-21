/*
 * 파일이름 : AccountArray.cpp
 * 작성자 : 김지윤
 * 업데이트 정보 : [2024, 06, 21] 파일버전 0.8
 */

#include "BankingCommonDecl.h"
#include "AccountArray.h"

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len) : arrlen(100)
{
    arr = new ACCOUNT_PTR[len];
}
ACCOUNT_PTR& BoundCheckAccountPtrArray::operator[] (int idx)
{
    if (idx < 0 || idx >= arrlen)
    {
        cout << "Array index out of bound exception" << endl;
        exit(1);
    }
    return arr[idx];
}

ACCOUNT_PTR& BoundCheckAccountPtrArray::operator[] (int idx) const
{
    if (idx < 0 || idx >= arrlen)
    {
        cout << "Array index out of bound exception" << endl;
        exit(1);
    }
    return arr[idx];
}

int BoundCheckAccountPtrArray::GetArrLen() const { return arrlen; }

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray()
{
    delete []arr;
}