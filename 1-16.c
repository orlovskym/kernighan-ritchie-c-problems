#include <stdio.h>
#define MAXLINE 1000
int getLine(char line[], int maxLine);
void copy(char to[], char from[]);
int getLineLength(char line[]);

int main()
{
    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
    {
        printf("%s%d%s\n%s", "The length of the longest input line was ", getLineLength(longest), ". That line is below:", longest);
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

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
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