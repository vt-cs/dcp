#include <stdio.h>

/*
 * num = 1010
 * num >> 1 = 0101
 * num >> 1 = 0010
 */

int main()
{
    int num = 0;
    int bit = 0;
    scanf("%d %d", &num, &bit);
    printf("num >> %d = %d\n", bit, num >> bit);
    return 0;
}
