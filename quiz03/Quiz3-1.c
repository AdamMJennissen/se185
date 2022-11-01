#include <stdio.h>

int main(void)
{
    int grade;

    printf("Enter your grading percentage: ");
    scanf("%d", &grade);
    if (grade > 100 || grade < 0)
    {
        printf("Your grade must be between 0 percent and 100 percent inclusively.");
    }
    else
    {
        printf("Your letter grade is ");

        if (grade >= 93)
        {
            printf("A.");
        }
        else if (grade >= 90)
        {
            printf("A-.");
        }
        else if (grade >= 87)
        {
            printf("B+.");
        }
        else if (grade >= 83)
        {
            printf("B.");
        }
        else if (grade >= 80)
        {
            printf("B-.");
        }
        else if (grade >= 77)
        {
            printf("C+.");
        }
        else if (grade >= 73)
        {
            printf("C.");
        }
        else if (grade >= 70)
        {
            printf("C-.");
        }
        else if (grade >= 67)
        {
            printf("D+.");
        }
        else if (grade >= 63)
        {
            printf("D.");
        }
        else if (grade >= 60)
        {
            printf("D-.");
        }
        else
        {
            printf("F.");
        }
    }
}