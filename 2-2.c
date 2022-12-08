#include <stdio.h>
#define MAXLINE 1000
int getLine(char line[], int maxLine);
int getLine2(char line[], int maxLine);
void clearLine(char line[]);

int main()
{
    char line[MAXLINE];

    //    getLine(line, MAXLINE);
    getLine2(line, MAXLINE);
    printf(line);
}

int getLine(char line[], int maxLine)
{
    int c, i;
    clearLine(line);
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

int getLine2(char line[], int maxLine)
{
    int c, i;
    clearLine(line);
    for (i = 0; i < maxLine - 1; i++)
    {
        c = getchar();
        if (c == EOF)
            break;
        line[i] = c;
        if (c == '\n')
            break;
    }
}

void clearLine(char line[])
{
    int i;
    for (i = 0; i < MAXLINE; i++)
        line[i] = '\0';
}