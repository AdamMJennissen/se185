/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name:	    Adam Jennissen																 -
- 	Section:	8															 -
-	NetID:		adamjenn														     -
-	Date:		9/8/2022														 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>   // Google this header file to learn more! :)

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    double a, b, c;
   

    /* Put your code after this line */
    printf("Enter the value for a: ");
    scanf("%lf", &a);
    printf("Enter the value for b: ");
    scanf(" %lf", &b);


    /* This next line will calculate the square root of whatever value is
     * inside the parenthesis and assigns it to the variable filler. */
    c = sqrt((pow(a, 2.0) + pow(b, 2.0)));

    printf("The hypotenuse is %lf", c);

    return 0;
}
