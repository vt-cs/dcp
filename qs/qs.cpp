#include <iostream>

void swap(int *pos_1, int *pos_2)
{
    int temp = *pos_1;
    *pos_1 = *pos_2;
    *pos_2 = temp;
}

int partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int swap_idx = start-1;
    int arr_idx = start;
    int tmp;
    
    while (arr_idx < end)
    {
        if(arr[arr_idx] <= pivot)
        {
            swap_idx++;
	    swap(&arr[arr_idx], &arr[swap_idx]);
        }
	arr_idx++;
    }
    swap_idx++;
    swap(&arr[swap_idx], &arr[end]);
    return swap_idx;
}

void quick_sort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    printf("%s: start=%d, end=%d\n", __func__, start, end);
    int n = partition(arr, start, end);
    printf("n=%d\n", n);
    quick_sort(arr, start, n-1);
    quick_sort(arr, n+1, end);
}

void print_arr(int *arr, int arr_size)
{
    int idx = 0;
    while (idx <= arr_size)
    {
        printf("%d ", arr[idx++]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int arr[] = {54, 132, 1, 45, 894, 4, 23, 10};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    print_arr(arr, arr_size - 1);
    quick_sort(arr, 0, arr_size - 1);
    print_arr(arr, arr_size - 1);
    return 0;
}
