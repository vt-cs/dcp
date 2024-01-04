#include <stdio.h>

bit no: 
given : 1100 1010 1101 0110
swaped: 1100 0101 1110 1001
swap even bits with odd bits present in its right

step 1:
    mask for even bits: 1010 1010 1010 1010
    mask for odd bits:  0101 0101 0101 0101

step 2:
    right shift input by 1 and mask with odd mask
    0110 0101 0110 1011
    0101 0101 0101 0101

    0100 0101 0100 0001
even bits in odd position

step 3: left shift input by 1 and mask with even mask
    1001 0101 1010 1100
    1010 1010 1010 1010

    1000 0000 1010 1000
odd bits in even position

we need to do bitwise-or on both numbers
    0100 0101 0100 0001
    1000 0000 1010 1000

desired swaped sequence
    1100 0101 1110 1001

