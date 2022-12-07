#include <stdio.h>

#define MAXLINE 1000
int getLine(char line[], int maxLine);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (len > 80)
        {
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
