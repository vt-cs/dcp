#include <stdio.h>

/*
num =  1010
mask = 0001

*/
       
       


int main(int argc, char **argv)
{
    int mask = 1;
    int num = 0;
    int bit = 0;
    scanf("%d %d", &num, &bit);
    printf("num=%d, bit=%d\n", num, bit);
    printf("bit %d flipped\n", bit);
    printf("new num=%d\n", num^(mask << bit-1));

    return 0;
}
