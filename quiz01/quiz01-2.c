#include <stdio.h>
#include <math.h>

int main(void)
{

    float Mike;
    float Mary;
    float Gary;
    float Logan;
    float schoolx = 15.55;
    float schooly = 55.15;

    Mike = sqrt(pow(schoolx - 22.05, 2.0) + pow(schooly - 85.10, 2.0));
    Mary = sqrt(pow(schoolx - 43.25, 2.0) + pow(schooly - 9.80, 2.0));
    Gary = sqrt(pow(schoolx - 2.55, 2.0) + pow(schooly - 72.86, 2.0));
    Logan = sqrt(pow(schoolx - 15.15, 2.0) + pow(schooly - 40.40, 2.0));

    printf("The E distance for Mike is: %f\n", Mike);
    printf("The E distance for Mary is: %f\n", Mary);
    printf("The E distance for Gary is: %f\n", Gary);
    printf("The E distance for Logan is: %f\n", Logan);
    return 0;
}