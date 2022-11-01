#include<stdio.h>

int main() 
{
    int a = 15;
    int* ptr_a;

    a /= 3;
    ptr_a = &a;


    *ptr_a += 1;


    if(*ptr_a == a) {
        printf("ptr_a = %d\n" , *ptr_a);
        printf("a = %d\n" , a);
        printf("Therefore, ptr_a = a = %d\n" , *ptr_a);
    }
    return 0;
}