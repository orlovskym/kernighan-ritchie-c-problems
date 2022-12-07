#include <stdio.h>
#define SPACES 8

int getBlock();
void spaceToTab();
char string[SPACES - 1];

int main()
{
    int lastLoop = 0;

    while (lastLoop == 0)
    {
        if (getBlock() == 0)
            lastLoop = 1;
        spaceToTab();
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
        string[i] = c;
        if ((c == '\n'))
            break;
    }
    return 1;
}

void spaceToTab()
{
    int i = SPACES - 1;

    // check for spaces, set i to the last non-space index
    while (string[i] == ' ')
        i--;
    // return if there were no spaces
    if (i == SPACES - 1)
        return;
    // change the first space to a tab
    string[i + 1] = '\t';
    // change the character after the tab to a \0, or else return
    if (i + 2 < SPACES)
        string[i + 2] = '\0';
    else
        return;
}