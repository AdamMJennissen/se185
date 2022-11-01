/*----------------------------------------------------------------------------
-		                 SE 185: Lab 04 - Debugging Code	    	         -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
void how_many_whole_digits(int number);

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
/* This program calculates the number of digits in a number from 1 to 10000000 */
// Compile with gcc lab04-2_2.c -o lab04-2_2
// Run with ./lab04-2_2

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int input;

    printf("Please input an integer from 1 up to 10000000: ");

    scanf("%d", &input);

    if (input > 10000000 || input < 1)
    {
        printf("Invalid number!\n");
        return -1;
    }

    how_many_whole_digits(input);

    return 0;
}

/**
 * This function divides a number by the 10^n, to
 * see if the divided number has "n" digits
 *
 * @param number - The number to determine how many whole digits exist within.
 */
void how_many_whole_digits(int number)
{
    // if ((double) number / 10000000 != 0)
    if ( number / 10000000 != 0)//removed double
    {
        printf("8 digits\n");
    } 
    // else if ((double) number / 1000000 != 0)
    else if ( number / 1000000 != 0)//removed double
    {
        printf("7 digits\n");
    } 
    // else if ((double) number / 100000 != 0)
    else if ( number / 100000 != 0)//removed double
    {
        printf("6 digits\n");
    } 
    // else if ((double) number / 10000 != 0)
    else if ( number / 10000 != 0)//removed double
    {
        printf("5 digits\n");
    } 
    // else if ((double) number / 1000 != 0)
    else if ( number / 1000 != 0)//removed double
    {
        printf("4 digits\n");
    } 
    // else if ((double) number / 100 != 0)
    else if ( number / 100 != 0)//removed double
    {
        printf("3 digits\n");
    } 
    // else if ((double) number / 10 != 0)
    else if ( number / 10 != 0)//removed double
    {
        printf("2 digits\n");
    } 
    // else if ((double) number / 1 != 0)
    else if (number / 1 != 0)//removed double
    {
        printf("1 digit\n");
    }
}
