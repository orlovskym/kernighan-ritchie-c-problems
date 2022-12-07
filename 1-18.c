#include <stdio.h>

#define MAXLINE 1000
int getLine(char line[], int maxLine); // copies a line of input into line[] and returns its length
char trimSpaces(char line[]);          // remove trailing spaces from line[], requires getLineLength()
int getLineLength(char line[]);        // return the length of line[]

int main()
{
    int len;
    char line[MAXLINE], newLine[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (len > 1)
        {
            trimSpaces(line);
            printf("%s\n", line);
        }
    }

    return 0;
}

int getLine(char line[], int maxLine)
{
    int c, i;

    for (i = 0; i < maxLine - 1 && (c = getchar()) != EOF; i++)
    {
        line[i] = c;
        if (c == '\n')
        {
            i++;
            break;
        }
    }
    line[i] = '\0';
    return i;
}

char trimSpaces(char line[])
{
    int i, len;
    len = getLineLength(line) - 1;
    // printf("%d\n", len); the length is correct

    while (line[len - 1] == ' ' || line[len - 1] == '\t')
    {
        len--;
    }

    line[len] = '\0';

    return 0;
}

int getLineLength(char line[])
{
    int i = 0;
    while ((line[i]) != '\0')
    {
        i++;
    }
    return i;
}