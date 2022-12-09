#include <stdio.h>
#define MAXLENGTH 100
int firstMatch(char[], char[]);

int main()
{
    char s1[MAXLENGTH] = "This is a test string.";
    char s2[MAXLENGTH] = "cat";
    printf("%d", firstMatch(s1, s2));
    return 0;
}

// return the first index from s1 in which a character from s2 is encountered
int firstMatch(char s1[], char s2[])
{
    int i, j;
    for (i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                return i;
            }
        }
    }
    return -1;
}