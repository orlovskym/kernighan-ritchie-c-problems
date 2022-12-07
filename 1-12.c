#include <stdio.h>

int main()
{
    char c;
    int wasSpace = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            wasSpace = 1;
        }
        else
        {
            if (wasSpace == 1)
            {
                putchar('\n');
            }
            putchar(c);
            wasSpace = 0;
        }
    }
}