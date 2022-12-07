#include <stdio.h>
#include <limits.h>
#include <float.h>

// char, short, int, long (signed and unsigned)
int main()
{
    printf("%s%d%s%d\n", "Signed Char: ", SCHAR_MIN, "-", SCHAR_MAX);
    printf("%s%u%s%u\n", "Unsigned Char: ", 0, "-", UCHAR_MAX);
    printf("%s%d%s%d\n", "Signed Short: ", SHRT_MIN, "-", SHRT_MAX);
    printf("%s%u%s%u\n", "Unsigned Short: ", 0, "-", USHRT_MAX);
    printf("%s%i%s%i\n", "Signed Int: ", INT_MIN, "-", INT_MAX);
    printf("%s%u%s%u\n", "Unsigned Int: ", 0, "-", UINT_MAX);         //
    printf("%s%ld%s%ld\n", "Signed Long: ", LONG_MIN, "-", LONG_MAX); //
    printf("%s%lu%s%lu\n", "Unsigned Long: ", 0, "-", ULONG_MAX);
}