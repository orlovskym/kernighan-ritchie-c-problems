#include <stdio.h>
#define SPACES 30

int getBlock();
void breakString();
char string[SPACES - 1];

int main()
{
    int lastLoop = 0;

    while (lastLoop == 0)
    {
        if (getBlock() == 0)
            lastLoop = 1;
        breakString();
        // printf("%s", string);
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
    // read up to n chars
    for (i = 0; i < SPACES; i++)
    {
        c = getchar();
        if (c == EOF)
            return 0;
        if ((c == '\n'))
            return 1;
        string[i] = c;
    }
    return 1;
}

void breakString()
{
    int i = SPACES - 1;

    // check for spaces, set i to the last non-blank index
    while ((string[i] == ' ') || (string[i] == '\t'))
        i--;
    // print and return if there were no blanks
    if (i == SPACES - 1)
    {
        printf("%s%s\n", string, "-");
        return;
    }
    // change the first blank to a newline and print
    string[i + 1] = '\n';
    printf("%s", string);
}