#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *first_name = NULL;
    char *last_name = NULL;
    char *full_name = NULL;
    int num_letters = 0;

    first_name = (char *)malloc(50 * sizeof(char));
    last_name = (char *)malloc(50 * sizeof(char));

    printf("What's your first name? ");
    scanf(" %s", first_name);

    printf("What's your last name? ");
    scanf(" %s", last_name);

    full_name = (char *)malloc((strlen(first_name) + strlen(last_name) + 2) * sizeof(char));

    strcat(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, last_name);

    printf("First name: %s\n", first_name);
    printf("Last name: % s\n", last_name);
    printf("Full name: % s\n", full_name);

    free(first_name);
    free(last_name);
    free(full_name);

    return 0;
}