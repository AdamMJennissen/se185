#include <stdio.h>
#include <string.h>

int main(void)
{
    char user[40];
    char pass[40];
    char correctUser[40] = "se185@iastate.edu";
    char correctPass[40] = "ds4rd";

    printf("Enter your username: ");
    scanf("%s", user);
    printf("Enter your password: ");
    scanf("%s", pass);

    if (strcmp(user, correctUser) == 0 && strcmp(pass, correctPass) == 0)
    {
        printf("Success!");
    }
    else
    {
        printf("Username or password is incorrect.");
    }
}