#include <stdio.h>

int main()
{
    char c;
    int wasSpace;
    wasSpace = 0;
    while ((c = getchar()) != EOF)
    {
        // printf(c);
        if (c != ' ')
        {
            if (wasSpace == 1)
            {
                putchar(' ');
            }
            putchar(c);
            wasSpace = 0;
        }
        else
        {
            wasSpace = 1;
        }
    }
}