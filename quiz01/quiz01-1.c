#include <stdio.h>

int main(void)
{
    long long int phoneNum;
    int areaCode;

    printf("Please enter the 10 digits phone number: ");
    scanf("%lld", &phoneNum);

    int oneDigit = phoneNum % 10;
    int temp1 = phoneNum / 10;
    int tenDigit = temp1 % 10;
    int temp2 = temp1 / 10;
    int hundDigit = temp2 % 10;
    int temp3 = temp2 / 10;
    int thouDigit = temp3 % 10;
    int temp4 = temp3 / 10;
    int tenthouDigit = temp4 % 10;
    int temp5 = temp4 / 10;
    int hundthouDigit = temp5 % 10;
    int temp6 = temp5 / 10;
    int twothouDigit = temp6 % 10;
    int temp7 = temp6 / 10;
    int tentwothouDigit = temp7 % 10;
    int temp8 = temp7 / 10;
    int hundtwothouDigit = temp8 % 10;
    int temp9 = temp8 / 10;
    int threethouDigit = temp9 % 10;

    printf("The area code is: %d%d%d\n", threethouDigit, hundtwothouDigit, tentwothouDigit);
    printf("The exchange code is: %d%d%d\n", twothouDigit, hundthouDigit, tenthouDigit);
    printf("The user number is: %d%d%d%d\n", thouDigit, hundDigit, tenDigit, oneDigit);

    return 0;
}