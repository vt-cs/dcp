#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#define RET_ERROR  -1
#define RET_SUCCESS 0


int human_readable_bin_arr (int *arr, int arr_len)
{
    if (arr == NULL || arr_len == 0)
    {
        return RET_ERROR;
    }
    for (int index=arr_len-1; index>=0; --index)
    {
        printf ("%d", arr[index]);
    }
    printf ("\n");
    return RET_SUCCESS;
}

int print_array (int *arr, int arr_len)
{
    if (arr == NULL || arr_len == 0)
    {
        return RET_ERROR;
    }
    for (int index=0; index<arr_len; ++index)
    {
        printf ("%d", arr[index]);
    }
    printf ("\n");
    return RET_SUCCESS;
}

/*
 * bin_repr: int array representing the number in binary format
 * bit_len : number of bits present in the bin_repr
 * this function updates the corresponding decimal number in dec_repr
 */
int binary_to_decimal (int *bin_repr, int bit_len, int *dec_repr)
{
    int num = 0;
    if (bin_repr == NULL || bit_len == 0)
    {
        return RET_ERROR;
    }
    for (int index=0; index<bit_len; ++index)
    {
        num = num + bin_repr[index]*pow(2,index);
    }
    *dec_repr = num;
    return RET_SUCCESS;
}

/*
 * bin_repr array will be malloc()'ed in binary_representation function, caller need to call free()
 * bit_len will be updated by this function to the length of bin_repr array.
 */
int binary_representation (int number, int *bit_len, int **bin_repr)
{
    int tmp_num = 0;
    int len = 0;

    if (bit_len == NULL || bin_repr == NULL)
    {
        return RET_ERROR;
    }

    tmp_num = number;

    while (tmp_num > 0)
    {
        ++len;
	tmp_num = tmp_num/2;
    }

    *bit_len = len;
    *bin_repr = (int*) malloc (sizeof (int)*len);
    tmp_num = 0;

    while (number > 0)
    {
        *(*(bin_repr)+tmp_num) = number%2;
	number = number/2;
	++tmp_num;
    }
    return RET_SUCCESS;
}

int one_complement (int number, int *bits_len, int *one_complement_representation)
{
    return RET_SUCCESS;
}

int two_complement (int number, int *bits_len, int *two_complement_representation)
{
    return RET_SUCCESS;
}

int main (int argc, char **argv)
{
    int num = 0;
    int bit_len = 0;
    int *bin_repr = NULL;

    scanf ("%d", &num);
    if (binary_representation(num, &bit_len, &bin_repr) == RET_SUCCESS)
    {
        human_readable_bin_arr(bin_repr, bit_len);

	binary_to_decimal(bin_repr, bit_len, &num);
	printf ("num = %d\n", num);

	free (bin_repr);
	bin_repr = NULL;
    }


    return 0;
}
