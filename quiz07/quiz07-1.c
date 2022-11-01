#include <stdio.h>

int main(void)
{
    int num = 5;
    int* myPtr;
    *myPtr = num;

    printf("num is stored at: %d\n", &num);
    printf("myPtr is stored at: %d\n", &myPtr);
    printf("num holds the value: %d\n", num);
    printf("myPtr holds the value: %d\n", myPtr);
    printf("myPtr points to this value: %d\n", *myPtr);
    return 0;
}