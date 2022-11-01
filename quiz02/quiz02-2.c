#include <stdio.h>
#include <math.h>

double DrivingCost(double drivenMiles, double milesPerGallon, double dollarsPerGallon)
{
    double cost = dollarsPerGallon * (drivenMiles / milesPerGallon);

    return cost;
}

int main(void)
{
    double miles;
    double mpg;
    double dpg;

    printf("Enter driven Miles:");
    scanf("%lf", &miles);
    printf("\nEnter Miles per Gallon:");
    scanf("  %lf", &mpg);
    printf("\nEnter dollars per Gallon:");
    scanf("  %lf", &dpg);

    printf("\nDriving Cost= %.2lf\n", DrivingCost(miles, mpg, dpg));
}