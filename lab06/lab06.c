/*----------------------------------------------------------------------------
-		                    SE 185: Lab 06 - Bop-It!	    	             -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
int Triangle(double t, double allotedt, int triangle, int circle, int cross, int square);
int Circle(double t, double allotedt, int triangle, int circle, int cross, int square);
int Cross(double t, double allotedt, int triangle, int circle, int cross, int square);
int Square(double t, double allotedt, int triangle, int circle, int cross, int square);

/*----------------------------------------------------------------------------
-	                            Notes                                        -
-----------------------------------------------------------------------------*/
// Compile with gcc lab06.c -o lab06
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b | ./lab06

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    double t;
    int triangle, circle, cross, square;
    int tri, circ, x, sq;
    bool play, started, buttonPressed;
    int button, rounds;
    double initialt, allotedt;
    srand(time(NULL)); /* This will ensure a random game each time. */

    printf("This is a Bop-It Game!\n");
    printf("Press a button to start the game.\n");
    button = (rand() % 4);
    while (1)
    {
        scanf("%lf, %d, %d, %d, %d",
              &t, &triangle, &circle, &cross, &square);

        if (!buttonPressed)
        {
            if (play)
            {
                switch (button)
                {
                case 0:
                    tri = Triangle(t, allotedt, triangle, circle, cross, square);
                    if (tri == 1)
                    {
                        allotedt -= 100;
                        rounds++;
                        button = (rand() % 4); // 1 == triangle, 2 == circle, 3 == cross, 4 == square
                    }
                    else if (tri == 0)
                        play = false;
                    buttonPressed = true;
                    break;
                case 1:
                    circ = Circle(t, allotedt, triangle, circle, cross, square);
                    if (circ == 1)
                    {
                        allotedt -= 100;
                        rounds++;
                        button = (rand() % 4); // 1 == triangle, 2 == circle, 3 == cross, 4 == square
                    }
                    else if (circ == 0)
                        play = false;
                    buttonPressed = true;
                    break;
                case 2:
                    x = Cross(t, allotedt, triangle, circle, cross, square);
                    if (x == 1)
                    {
                        allotedt -= 100;
                        rounds++;
                        button = (rand() % 4); // 1 == triangle, 2 == circle, 3 == cross, 4 == square
                    }
                    else if (x == 0)
                        play = false;
                    buttonPressed = true;
                    break;
                case 3:
                    sq = Square(t, allotedt, triangle, circle, cross, square);
                    if (sq == 1)
                    {
                        allotedt -= 100;
                        rounds++;
                        button = (rand() % 4); // 1 == triangle, 2 == circle, 3 == cross, 4 == square
                    }
                    else if (sq == 0)
                        play = false;
                    buttonPressed = true;
                    break;
                default:
                    break;
                }
            }
            if ((triangle == 1 || circle == 1 || cross == 1 || square == 1) && !started)
            {
                play = true;
                started = true;
                allotedt = 2500;
                button = (rand() % 4) + 1; // 1 == triangle, 2 == circle, 3 == cross, 4 == square
            }

            if (triangle == 1 || circle == 1 || cross == 1 || square == 1)
                buttonPressed = true;
        }
        else if (buttonPressed && started)
        {
            if (!(triangle == 1 || circle == 1 || cross == 1 || square == 1))
                buttonPressed = false;
        }

        if (!play && started)
        {
            printf("You lose!\n");
            printf("You made it through %d rounds!\n", rounds);
            break;
        }
    }

    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
int Triangle(double t, double allotedt, int triangle, int circle, int cross, int square)
{
    printf("Press the triangle button!\n");
    printf("You have %.0lf miliseconds to respond!\n", allotedt);
    bool play = true;
    bool buttonPressed;
    double initialt = t;
    while (play)
    {
        scanf("%lf, %d, %d, %d, %d",
              &t, &triangle, &circle, &cross, &square);

        if (!buttonPressed)
        {
            if (((initialt + allotedt) < t))
            {
                printf("You ran out of time. :(\n");
                play = false;
                return 0;
                break;
            }
            else if (triangle == 1)
            {
                play = false;
                return 1;
                break;
            }
            else if (circle == 1 || cross == 1 || square == 1)
            {
                printf("Wrong button! :(\n");
                play = false;
                return 0;
                break;
            }
            if (triangle == 1 || circle == 1 || cross == 1 || square == 1)
                buttonPressed = true;
        }
        else if (buttonPressed)
        {
            if (!(triangle == 1 || circle == 1 || cross == 1 || square == 1))
                buttonPressed = false;
        }
    }
}
int Circle(double t, double allotedt, int triangle, int circle, int cross, int square)
{
    printf("Press the circle button!\n");
    printf("You have %.0lf miliseconds to respond!\n", allotedt);
    bool play = true;
    bool buttonPressed;
    double initialt = t;
    while (play)
    {
        scanf("%lf, %d, %d, %d, %d",
              &t, &triangle, &circle, &cross, &square);

        if (!buttonPressed)
        {

            if (((initialt + allotedt) < t))
            {
                printf("You ran out of time. :(\n");
                play = false;
                return 0;
                break;
            }
            else if (circle == 1)
            {
                play = false;
                return 1;
                break;
            }
            else if (triangle == 1 || cross == 1 || square == 1)
            {
                printf("Wrong button! :(\n");
                play = false;
                return 0;
                break;
            }

            if (triangle == 1 || circle == 1 || cross == 1 || square == 1)
                buttonPressed = true;
        }
        else if (buttonPressed)
        {
            if (!(triangle == 1 || circle == 1 || cross == 1 || square == 1))
                buttonPressed = false;
        }
    }
}
int Cross(double t, double allotedt, int triangle, int circle, int cross, int square)
{
    printf("Press the cross button!\n");
    printf("You have %.0lf miliseconds to respond!\n", allotedt);
    bool play = true;
    bool buttonPressed;
    double initialt = t;
    while (play)
    {

        scanf("%lf, %d, %d, %d, %d",
              &t, &triangle, &circle, &cross, &square);

        if (!buttonPressed)
        {
            if (((initialt + allotedt) < t))
            {
                printf("You ran out of time. :(\n");
                play = false;
                return 0;
                break;
            }
            else if (cross == 1)
            {
                play = false;
                return 1;
                break;
            }
            else if (circle == 1 || triangle == 1 || square == 1)
            {
                printf("Wrong button! :(\n");
                play = false;
                return 0;
                break;
            }

            if (triangle == 1 || circle == 1 || cross == 1 || square == 1)
                buttonPressed = true;
        }
        else if (buttonPressed)
        {
            if (!(triangle == 1 || circle == 1 || cross == 1 || square == 1))
                buttonPressed = false;
        }
    }
}

int Square(double t, double allotedt, int triangle, int circle, int cross, int square)
{
    printf("Press the square button!\n");
    printf("You have %.0lf miliseconds to respond!\n", allotedt);
    bool play = true;
    bool buttonPressed;
    double initialt = t;
    while (play)
    {
        scanf("%lf, %d, %d, %d, %d",
              &t, &triangle, &circle, &cross, &square);

        if (!buttonPressed)
        {

            if (((initialt + allotedt) < t))
            {
                printf("You ran out of time. :(\n");
                play = false;
                return 0;
                break;
            }
            else if (square == 1)
            {
                play = false;
                return 1;
                break;
            }

            else if (circle == 1 || cross == 1 || triangle == 1)
            {
                printf("Wrong button! :(\n");
                play = false;
                return 0;
                break;
            }

            if (triangle == 1 || circle == 1 || cross == 1 || square == 1)
                buttonPressed = true;
        }
        else if (buttonPressed)
        {
            if (!(triangle == 1 || circle == 1 || cross == 1 || square == 1))
                buttonPressed = false;
        }
    }
}
