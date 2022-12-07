#include <stdio.h>

#define MAXLINE 1000
int getLine(char line[], int maxLine);     // copies a line of input into line[] and returns its length
int getLineLength(char line[]);            // return the length of line[]
void reverse(char line[], char newLine[]); // reverse line[], requires getLineLength()

int main()
{
    int len;
    char line[MAXLINE], newLine[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (len > 1)
        {
            reverse(line, newLine);
            printf("%s\n", newLine);
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

int getLineLength(char line[])
{
    int i = 0;
    while ((line[i]) != '\0')
    {
        i++;
    }
    return i;
}

void reverse(char line[], char newLine[])
{
    int i, j;
    j = 0;

    for (i = getLineLength(line) - 2; i >= 0; i--)
    {
        newLine[j] = line[i];
        j++;
    }
    newLine[j] = '\0';
}