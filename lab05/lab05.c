/*----------------------------------------------------------------------------
-		         SE 185: Lab 05 - Conditionals (What's up?)	    	         -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
double magnitude(double x, double y, double z);
int close_to(double tolerance, double point, double value);
char *Orientation(double x, double y, double z, double mag);

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab05.c -o lab05
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -a -g -b | ./lab05

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int triangle = 0, circle, x_button, square;
    double ax, ay, az, gx, gy, gz;
    char *orientation;

    while (triangle != 1)
    {
        scanf("%lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d",
              &ax, &ay, &az, &gx, &gy, &gz, &triangle, &circle, &x_button, &square);

        /* printf for observing values scanned in from ds4rd.exe,
         * be sure to comment or remove in final program */
        // printf("Echoing output: %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n",
        //        ax, ay, az, gx, gy, gz, triangle, circle, x_button, square);

        /* It would be wise (mainly save time) if you copy your code to calculate
         * the magnitude from lab03-1.c. You will also need to copy your
         * prototypes and functions to the appropriate sections in this program. */

        // printf("The acceleration's current magnitude is: %lf\n", /*t,*/ magnitude(ax, ay, az));

        if ((orientation != Orientation(gx, gy, gz, magnitude(ax, ay, az))) && (Orientation(gx, gy, gz, magnitude(ax, ay, az)) != NULL))
        {
            orientation = Orientation(gx, gy, gz, magnitude(ax, ay, az));
            printf("The orientation is: %s\n", orientation);
        }
    }

    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
int close_to(double tolerance, double point, double value)
{
    if ((value >= (point - tolerance)) && (value <= (point + tolerance)))
        return 1;
    else
        return 0;
}

char *Orientation(double x, double y, double z, double mag)
{
    char *orientation;

    if (close_to(.125, 0, mag))
        if (close_to(.2, 1, y))
        {
            orientation = "TOP";
        }
        else if (close_to(.2, -1, y))
        {
            orientation = "BOTTOM";
        }
        else if (close_to(.2, -1, z))
        {
            orientation = "FRONT";
        }
        else if (close_to(.2, 1, z))
        {
            orientation = "BACK";
        }
        else if (close_to(.2, -1, x))
        {
            orientation = "RIGHT";
        }
        else if (close_to(.2, 1, x))
        {
            orientation = "LEFT";
        }

    return orientation;
}

/**
 * Calculates and returns the magnitude of three given values.
 *
 * @param x - The x-axis scanned values from the DS4 controller.
 * @param y - The y-axis scanned values from the DS4 controller.
 * @param z - The z-axis scanned values from the DS4 controller.
 * @return - The magnitude of the given values.
 */
double magnitude(double x, double y, double z)
{
    return sqrt(pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0));
}
