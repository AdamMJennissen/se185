#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int evenNums[8];
    int curr;
    int count = 0;
    int i = 0;

    FILE *fp = fopen("numbers.txt", "w");
    if (fp == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fprintf(fp, "12 7 3 0 28 74 37 299");
    fclose(fp);

    FILE *fip = fopen("numbers.txt", "r");
    if (fip == NULL)
    {
        printf("Error!");
        exit(1);
    }
    for (i = 0; i < 8; i++)
    {
        fscanf(fip, " %d", &evenNums[i]);
    }
    fclose(fip);

    for (i = 0; i < 8; i++)
    {
        if ((evenNums[i] % 2) == 0)
            printf("%d ", evenNums[i]);
    }

    return 0;
}