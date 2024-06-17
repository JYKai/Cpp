#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

char *MakeStrAdr(int len);

int main(void)
{
    char *str = MakeStrAdr(20);
    strcpy(str, "I am so happy~");
    
    cout << str << endl;    // I am so happy~
    free(str);
    return 0;
}

char *MakeStrAdr(int len)
{
    char *str = (char *)malloc(sizeof(char) * len);
    return str;
}