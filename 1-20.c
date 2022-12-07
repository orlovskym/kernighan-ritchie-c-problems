#include <stdio.h>
#define SPACES 8

int getBlock();
char string[SPACES - 1];

int main()
{
    int lastLoop = 0;

    while (lastLoop == 0)
    {
        if (getBlock() == 0)
            lastLoop = 1;
        printf("%s", string);
    }

    return 0;
}

int getBlock()
{
    char c;
    int i;
    // zero the string
    for (i = 0; i < SPACES; i++)
        string[i] = '\0';
    // read up to 8 chars
    for (i = 0; i < SPACES; i++)
    {
        c = getchar();
        if (c == EOF)
            return 0;
        if (c == '\t')
        {
            for (i; i < SPACES; i++)
            {
                string[i] = ' ';
            }
            return 1;
        }
        string[i] = c;

        if (c == '\n')
            break;
    }
    return 1;
}
