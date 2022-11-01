/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name:	    Adam Jennissen																 -
- 	Section:	8															 -
-	NetID:		adamjenn														     -
-	Date:		9/8/2022															 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
 int a = 6427 + 1725;
 int b = (6971 * 3925) - 95;
 double c = 79 + 12 / 5;
 double d = 3640.0 / 107.9;
 int e = (22 / 3) * 3;
 int f = 22 / (3 * 3) ;
 double g = 22 / (3 * 3);
 double h = 22 /  3* 3;
 double i = (22.0 / 3) * 3.0;
 int j = 22.0 / (3 * 3.0);
 double k = 22.0 / 3.0 * 3.0;

 double l = M_PI * pow((23.576 / M_PI / 2), 2.0); //convert form circumfrence to radius, then find area
 double m = 14.0 * 0.3048; //multiply by the amount of feet in one meter
 double n = (76.0 - 32.0) / 1.8;

printf("%d\n%d\n%lf\n%lf\n%d\n%d\n%lf\n%lf\n%lf\n%d\n%lf\n%lf\n", a, b, c, d, e, f, g, h, i, j, k, l);

 
    return 0;
}
