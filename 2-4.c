#include <stdio.h>
#define MAXLENGTH 100
void stripMatching(char[], char[]);
void popFromIndex(char[], int);
void checkForMatch(int, char[], char[]);

int main()
{
    char s1[MAXLENGTH] = "actactactatcatctccccattacctttacactconcatatacioatacacattaccattacatcatctatctactctatctatctactacn";
    char s2[MAXLENGTH] = "cat";
    stripMatching(s1, s2);
    printf("%s", s1);
    return 0;
}

// delete all characters in s1 that match a character in s2
void stripMatching(char s1[], char s2[])
{
    int i;
    for (i = 0; s1[i] != '\0'; i++)
        checkForMatch(i, s1, s2);
}

void popFromIndex(char s[], int i)
{
    for (i; s[i] != '\0'; i++)
        s[i] = s[i + 1];
}

void checkForMatch(int i, char s1[], char s2[])
{
    int j;
    for (j = 0; s2[j] != '\0'; j++)
    {
        if (s1[i] == s2[j])
        {
            popFromIndex(s1, i);
            checkForMatch(i, s1, s2);
            break;
        }
    }
}