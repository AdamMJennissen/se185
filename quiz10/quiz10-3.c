#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int stringlen(char *string, int len)
{
    if (*string != '\0')
    {
        stringlen(string + 1, len + 1);
    }
    else
        return len;
}

int main(void)
{
    int len;
    char inputStr[30];
    printf("Enter a string: ");
    scanf(" %s", inputStr);
    printf("\nThe length of \"%s\" = %d", inputStr, stringlen(inputStr, len));
    return 0;
}
