#include <stdio.h>

typedef int (*add_number)(int, int);

typedef struct node
{
    add_number myfunc;
}node;


int main(int argc, char **argv)
{
    node hello;
    return 0;
}
