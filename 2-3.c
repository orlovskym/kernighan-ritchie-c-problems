#include <stdio.h>
#include <string.h>
#include <ctype.h>
int validateIsHex(char string[]);
int htoi(char string[]);
int power(int base, int exponent);

int main()
{
    char string[] = "08adfc";
    if (validateIsHex(string) == 1)
        printf("%d", htoi(string));
    return 0;
}

int validateIsHex(char string[])
{
    char c;
    int i;
    int len = strlen(string);

    for (i = 0; i < len; i++)
    {
        c = string[i];
        if (!(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F'))
            return 0;
    }
    return 1;
}

int htoi(char string[])
{
    int c, i;
    int n = 0;
    int len = strlen(string);

    for (i = len - 1; i >= 0; i--)
    {
        if (string[i] >= 'a' && string[i] <= 'f')
            string[i] = toupper(string[i]);
        if (string[i] >= 'A' && string[i <= 'F'])
            c = string[i] - 55;
        if (string[i] >= '0' && string[i] <= '9')
            c = string[i] - 48;
        n = n + (power(16, (len - 1 - i))) * c;
    }
    return n;
}

int power(int base, int exponent)
{
    int i;
    int n = base;
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;
    for (i = 1; i < exponent; i++)
        n = n * base;
    return n;
}