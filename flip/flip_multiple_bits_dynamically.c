#include <stdio.h>
#include <stdlib.h>

/*
 * num  = 1010
 * mask = 0000
 * tmp  = 0001
 *
 * 1 3 4
 * mask | tmp << 1
 * mask | tmp << 3
 * mask | tmp << 4
 *
 * num   = 1010
 * mask  = 1101
 * final = 0111
 */

int main()
{
    int num = 0;
    int num_bits = 0;
    int mask = 0;
    int tmp = 1;
    int *arr_bit = NULL;
    scanf("%d %d", &num, &num_bits);
    if (num_bits > 0)
    {
        arr_bit = (int*) malloc(sizeof(int)*num_bits);
        for (int i=0; i<num_bits; ++i)
        {
            scanf("%d", &arr_bit[i]);
        }
    }
    if (num_bits > 0)
    {
        for(int j=0; j<num_bits; ++j)
	{
            mask = mask | tmp << arr_bit[j]-1;
	}
    }
    printf ("final flipped num=%d\n", num^mask);

    if (arr_bit != NULL)
    {
        printf ("resources freed\n");
        free(arr_bit);
	arr_bit = NULL;
    }

    return 0;
}
