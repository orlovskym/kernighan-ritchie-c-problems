#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fahrToCelsius(float fahr)
{
    return ((5.0 / 9.0) * (fahr - 32.0));
}

int main()
{
    float fahr;

    printf("Farenheit to Celsius\n");
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    {
        printf("%3.0f %6.1f\n", fahr, fahrToCelsius(fahr));
    }

    return 0;
}
