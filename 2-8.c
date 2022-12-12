#include <stdio.h>
unsigned int rotateRight(unsigned, int);
unsigned int getRightBits(unsigned, int);

int main()
{
    unsigned int x = 0b00011010;
    int n = 4;
    printf("%u", rotateRight(x, n));
    return 0;
}

// returns x rotated n bits to the right
unsigned int rotateRight(unsigned int x, int n)
{
    unsigned int bitsToMove = getRightBits(x, n) << (32 - n); // save the right bits and push them to the left
    x = x >> n;                                               // push x to the right
    return (x | bitsToMove);
}

// return input x's n rightmost bits
unsigned int getRightBits(unsigned x, int n)
{
    return (x & ~(~0 << n));
}
