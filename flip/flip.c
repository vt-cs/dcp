#include <stdio.h>
/*
num = 1010
m   = 1000
*/

int main()
{
    int num = 0xA;
    int mask = 0x8;
    printf("int size=%lu\n", sizeof(int));
    printf("num=%x\n", num);
    printf("num=%d\n", num);
    printf("num^mask=%x\n", num^mask);
    return 0;
}
