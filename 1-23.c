#include <stdio.h>
#define MAXLINE 1000

int getLine();
void clearLine(char line[]);
void parseLine();
void copyChar(int i, int j);

char line[MAXLINE];
char outputLine[MAXLINE];
int inBlockComment = 0;
// 0 is normal, 1 is comment, 2 is start block comment, 3 is end block comment

int main()
{
    int lastLoop = 0;
    while (lastLoop == 0)
    {
        if (getLine() == 0)
            lastLoop = 1;
        parseLine();
        printf("%s", outputLine);
    }
    return 0;
}

int getLine()
{
    int i;
    char c;
    clearLine(line);

    // read until hitting \n or EOF
    for (i = 0; i < MAXLINE - 1; i++)
    {
        c = getchar();
        line[i] = c;
        if ((c == '\n'))
            break;
        else if (c == EOF)
        {
            line[i] = '\0';
            return 0;
        }
    }
    return 1;
}

void clearLine(char line[])
{
    int i;
    for (i = 0; i < MAXLINE; i++)
        line[i] = '\0';
}

void parseLine()
{
    int i, j, wasSlash, wasAsterisk;
    i = wasSlash = wasAsterisk = 0;
    j = -1;
    char c;
    clearLine(outputLine);

    for (i = 0; i < MAXLINE; i++)
    {
        c = line[i];
        // normal behavior
        if ((inBlockComment == 0) && (c != '/') && (c != '*'))
        {
            j++;
            // printf("%d%s%d\n", i, " ", j);
            wasAsterisk = wasSlash = 0;
            copyChar(i, j);
        }
        // inBlockComment==0 and a spicy character
        else if ((inBlockComment == 0) && (c == '/'))
        {
            if (wasSlash == 1) // if this is the second slash, we can stop here
            {
                outputLine[j - 1] = '\n';
                outputLine[j] = '\0';
                return;
            } // otherwise just print the slash
            wasSlash = 1;
            wasAsterisk = 0;
            j++;
            copyChar(i, j);
        }
        else if ((inBlockComment == 0) & (c == '*'))
        {
            if (wasSlash == 1) // if we are starting a block comment
            {
                inBlockComment = 1;
                wasSlash = 0;
                outputLine[j - 1] = '\0';
                j--;
            }
            else // otherwise just print the asterisk
            {
                wasAsterisk = 1;
                wasSlash = 0;
                j++;
                copyChar(i, j);
            }
        }
        // inBlockComment==1 and a spicy character
        else if ((inBlockComment == 1) & (c == '*'))
        {
            wasAsterisk = 1;
        }
        else if ((inBlockComment == 1) & (c == '/'))
        {
            if (wasAsterisk == 1)
            {
                wasAsterisk = 0;
                inBlockComment = 0;
            }
        }
        else if (inBlockComment == 1)
            wasAsterisk = wasSlash = 0;
    }
}

void copyChar(int i, int j)
{
    outputLine[j] = line[i];
}