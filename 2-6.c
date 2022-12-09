#include <stdio.h>
int setbits(unsigned, int, int, unsigned);
int getbits(unsigned, int);
int clearbits(unsigned, int);

int main()
{
    int n = 4;
    n = n & 7;
    printf("%d", setbits(0b11111111, 5, 2, 0b00000011));
    return 0;
}

// returns x, with the n bits starting at position p replaced with the n rightmost bits from y
int setbits(unsigned x, int p, int n, unsigned y) // this needs work
{
    // printf("%d%s%d\n", clearbits(x, p), " and ", getbits(y, n));
    return (clearbits(x, p) | (getbits(y, n)) << (p - n));
}

// return input x's n rightmost bits
int getbits(unsigned x, int n)
{
    return (x & ~(~0 << n));
}

// return input x with zeroed n rightmost bits
int clearbits(unsigned x, int n)
{
    return (x >> n << n);
}