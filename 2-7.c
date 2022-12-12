#include <stdio.h>
int invert(unsigned, unsigned, unsigned);
int getRightBits(unsigned, int);
unsigned clearRightBits(unsigned, int);

int main()
{
    // printf("%d", invert(0b00001001, 4, 2)); // expected 00010001 = 17
    printf("%d", invert(0b10011101, 6, 2)); // expected 011111101 = 257
    return 0;
}

// returns x with n bits starting at position p inverted
int invert(unsigned x, unsigned p, unsigned n)
{
    int leftmost = clearRightBits(x, n + p - 1);
    int center = getRightBits(x, p + n - 1);
    center = ~center;
    center = getRightBits(center, p + n - 1);
    center = clearRightBits(center, p - 1);
    int rightmost = getRightBits(x, p - 1);

    // printf("%d%s%d%s%d\n", leftmost, " and ", center, " and ", rightmost); for troubleshooting
    return (leftmost | center | rightmost);
}

// return input x's n rightmost bits
int getRightBits(unsigned x, int n)
{
    return (x & ~(~0 << n));
}

// return input x with zeroed n rightmost bits
unsigned clearRightBits(unsigned x, int n)
{
    return (x >> n << n);
}