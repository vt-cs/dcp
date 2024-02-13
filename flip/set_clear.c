#include <stdio.h>


#define SET_BIT(num, pos) \
	num=num|(1<<pos)

#define CLEAR_BIT(num, pos) \
	num=num&~(1<<pos)

int set_bit (int num, int pos)
{
    int mask = 1;
    mask = mask << pos;
    return num|mask;
}

int clear_bit (int num, int pos)
{
    int mask = 1;
    mask = mask << pos;
    return num&(~mask);
}

/*
 * 10 = 1010, pos = 2 => set => 1110 = 14
 * 10 = 1010, pos = 2 => clear => 1010 = 10
 */

int main ()
{
    int num = 10;
    printf ("%d\n", SET_BIT(num, 2));
    num = 10;
    printf ("%d\n", CLEAR_BIT(num, 2));
    num = 10;
    printf ("%d\n", set_bit(num, 2));
    num = 10;
    printf ("%d\n", clear_bit(num, 2));
}
