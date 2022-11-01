#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char userPass[50];
    char Pass[50];
    char a = '!';
    int i;

    printf("Please enter a password: ");
    scanf("%s", userPass);

    strcpy(Pass, userPass);

    for (i = 0; i < strlen(userPass); i++)
    {
        if (userPass[i] == 'i')
        {
            Pass[i] = '1';
        }
        else if (userPass[i] == 'a')
        {
            Pass[i] = '@';
        }
        else if (userPass[i] == 'm')
        {
            Pass[i] = 'M';
        }
        else if (userPass[i] == 'B')
        {
            Pass[i] = '8';
        }
        else if (userPass[i] == 's')
        {
            Pass[i] = '$';
        }
        else
        {
            Pass[i] = userPass[i];
        }
    }
    strncat(Pass, &a, 1);

    printf("Your updated password: %s", Pass);
}