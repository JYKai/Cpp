#include <iostream>
using namespace std;

int main(void)
{
    int num = 12;
    int *ptr = &num;
    int **dptr = &ptr;

    int &ref = num;
    int *(&pref) = ptr;
    int **(&dpref) = dptr;

    cout << ref << endl;        // 12
    cout << *pref << endl;      // 12
    cout << **dpref << endl;    // 12

    return 0;
}