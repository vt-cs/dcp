#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// check if the array is in non-decreasing order or not
// input: array of integer, size of integer array
// output: true - if array is in non-decreasing order, false - otherwise
// time complexity = O(n) - because it has to go through all the elements of array once to decide
// space complexity = O(1) - using constant space irrespective of size of the input array
bool if_non_decreasing (int *array, size_t array_size)
{
    if (array == NULL || array_size <= 0)
    {
        return false;
    }
    for (int i=1; i<array_size; ++i)
    {
        if (array[i] < array[i-1])
	{
            return false;
	}
    }
    return true;
}


int main (int argc, char **argv)
{
    int *arr = NULL;
    int size = 0;
    scanf("%d", &size);

    if (size > 0)
    {
        arr = (int*) malloc (sizeof(int)*size);
    }
    else
    {
        printf("invalid size!!\n");
	return -1;
    }
    
    for (int i=0; i<size; ++i)
    {
        scanf ("%d", &arr[i]);
    }
    
    printf ("is_array non decreasing = %s\n", if_non_decreasing(arr, size)?"true":"false");

    return 0;
}
