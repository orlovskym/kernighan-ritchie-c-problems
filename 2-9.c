#include <stdio.h>
int bitcount(unsigned x);

int main()
{
    unsigned int x = 0b11011010;
    printf("%d", bitcount(x));
    return 0;
}

int bitcount(unsigned x)
{
    if (x == 0)
        return 0;
    int b;
    for (b = 1; x &= (x - 1); b++)
        ;
    return b;
}
