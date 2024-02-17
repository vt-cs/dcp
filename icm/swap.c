#include <stdio.h>

/*
 * 8 = 0 0 0 00001000
 * -8 = 1 1 1 11111000
 */

int main ()
{
    int input;
    int count = 0;

    scanf ("%d", &input);
    for (int i=0; i < sizeof (int) * 8; ++i)
    {
        count += input & 1;
	input = input >> 1;
    }
    printf ("count=%d\n", count);

    return 0;
}
