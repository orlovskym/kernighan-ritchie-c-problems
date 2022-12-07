#include <stdio.h>

int main()
{
    char c;
    int i, j, length, lengths[20];
    length = 0;

    for (i = 0; i < 20; i++)
    {
        lengths[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            lengths[length]++;
            length = 0;
        }
        else
        {
            length++;
        }
    }

    printf("Word Length Histogram\n");
    for (i = 1; i < 20; i++)
    {
        if (lengths[i] != 0)
        {
            printf("%2d%2s", i, ": ");
            for (j = 0; j < lengths[i]; j++)
            {
                printf("%c", "*");
            }
            printf("\n");
        }
    }
}