/*----------------------------------------------------------------------------
-		    SE 185: Lab 03 - Introduction to the DS4 and Functions	    	 -
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
int ButtonsPressed(int t, int c, int s, int x);

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab03-2.c -o lab03-2
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -b | ./lab03-2

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
int t, c, s, x;

    while (1)
    {

        scanf("%d, %d, %d, %d", &t, &c, &s, &x);

        printf("%d\n", ButtonsPressed(t, c, s, x));

        fflush(stdout);
    }

    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
int ButtonsPressed(int t, int c, int s, int x)
{
    return (t + c + s + x);
}

