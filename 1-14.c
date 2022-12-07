#include <stdio.h>

#define MAX 400
int main()
{
    char c;
    int i, j, lengths[MAX];

    for (i = 0; i < MAX; i++)
    {
        lengths[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        lengths[c]++;
    }

    printf("Character Count Histogram\n");
    for (i = 0; i < MAX; i++)
    {
        if (lengths[i] != 0)
        {
            printf("%1c%2s", i, ": ");
            for (j = 0; j < lengths[i]; j++)
            {
                printf("%c", "*");
            }
            printf("\n");
        }
    }
}