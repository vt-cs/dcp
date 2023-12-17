#include <iostream>
#include <cstdio>

/*
 * num = 11
 * 11/2 5 1
 * 5/2  2 1
 * 2/2  1 0
 * 1/2  0 1
 *
 * 11 = 1011
 */


int main()
{
    int num = 0;
    int bits = 0;
    int tmp = 0;
    int *bin_rep = NULL;

    std::cin >> num;
    tmp = num;
    while (tmp > 0)
    {
        tmp = tmp/2;
	++bits;
    }

    bin_rep = (int*) malloc(sizeof(int)*bits);
    tmp = 0;
    while(num > 0)
    {
        bin_rep[tmp] = num%2;
	num = num/2;
	++tmp;
    }

    for (int i=bits-1; i>=0; --i)
    {
        std::cout << bin_rep[i];
    }
    std::cout << "\n";

    if (bin_rep != NULL)
    {
        free(bin_rep);
	bin_rep = NULL;
    }

    return 0;
}
