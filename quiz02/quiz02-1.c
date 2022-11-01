#include <stdio.h>

int main(void)
{

    char firstName[50];
    char lastName[50];
    char major[50];
    char yearCollege[50];
    int gradYear;

    printf("Enter your first name: ");
    scanf(" %s", firstName);
    printf("Enter the last name: ");
    scanf(" %s", lastName);
    printf("Enter your major: ");
    scanf(" %s", major);
    printf("Enter year in college: ");
    scanf(" %s", yearCollege);
    printf("Enter your graduation year: ");
    scanf(" %d", &gradYear);

    printf("\nName (last, first): Name %s, %s\n", lastName, firstName);
    printf("Major: %s\n", major);
    printf("Year: %s\n", yearCollege);
    printf("Graduation year: %d\n", gradYear);
}