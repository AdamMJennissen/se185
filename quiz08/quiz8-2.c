#include <stdio.h>
#include <stdlib.h>

typedef struct time
{
    int hr;
    int min;
    int sec;
} time;

void convTime(int seconds, time *convertedTime);
void printTime(int seconds, time *printedTime);

void main()
{
    time *mileTime;

    mileTime = (time *)malloc(sizeof(time));

    int seconds;
    printf("Total seconds: ");
    scanf("%d", &seconds);
    convTime(seconds, mileTime);
    printTime(seconds, mileTime);

    free(mileTime);
}

void convTime(int seconds, time *convertedTime)
{
    convertedTime->hr = seconds / 3600;
    convertedTime->min = (seconds % 3600) / 60;
    convertedTime->sec = (seconds % 3600) % 60;
}

void printTime(int seconds, time *printedTime)
{
    printf("%d seconds = %d hr %d min %d sec", seconds, printedTime->hr, printedTime->min, printedTime->sec);
}