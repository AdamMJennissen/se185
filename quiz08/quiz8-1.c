#include <stdio.h>

typedef struct complex_num
{
    int realNum;
    int imaginaryNum;
} complexNum;

complexNum ADD(complexNum a, complexNum b);
complexNum SUB(complexNum a, complexNum b);
complexNum MUL(complexNum a, complexNum b);

int main(void)
{
    complexNum a, b, c;

    printf("Enter real and Imaginary Values of number 1: ");
    scanf(" %d %d", &a.realNum, &a.imaginaryNum);

    printf("Enter real and Imaginary Values of number 2: ");
    scanf(" %d %d", &b.realNum, &b.imaginaryNum);

    c = ADD(a, b);
    printf("ADD = %d+%di\n", c.realNum, c.imaginaryNum);
    c = SUB(a, b);

    printf("SUB = %d+%di\n", c.realNum, c.imaginaryNum);
    c = MUL(a, b);

    printf("MUL = %d+%di\n", c.realNum, c.imaginaryNum);

    return 0;
}

complexNum ADD(complexNum a, complexNum b)
{
    complexNum c;
    c.realNum = a.realNum + b.realNum;
    c.imaginaryNum = a.imaginaryNum + b.imaginaryNum;
    return c;
}
complexNum SUB(complexNum a, complexNum b)
{
    complexNum c;
    c.realNum = a.realNum - b.realNum;
    c.imaginaryNum = a.imaginaryNum - b.imaginaryNum;
    return c;
}
complexNum MUL(complexNum a, complexNum b)
{
    complexNum c;
    c.realNum = (a.realNum * b.realNum) - (a.imaginaryNum * b.imaginaryNum);
    c.imaginaryNum = (a.realNum * b.imaginaryNum) + (b.realNum * a.imaginaryNum);
    return c;
}