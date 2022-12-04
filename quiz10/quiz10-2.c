#include <stdlib.h>
#include <stdio.h>

int Power(int base, int power)
{
    if (power != 0)
    {
        return base * Power(base, power - 1);
    }
    else
        return 1;
}

int main(void)
{
    char inputStr[10];
    int base, power;
    printf("Enter number to power: ");
    scanf(" %d %s %d", &base, inputStr, &power);
    printf("\n%d to the power %d = %d", base, power, Power(base, power));
    return 0;
}