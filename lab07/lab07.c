/*-----------------------------------------------------------------------------
-					          SE 185 Lab 07 - The DS4 Equalizer
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name:    Adam Jennissen
- 	Section: 8
-	NetID:   adamjenn
-	Date:    10/20/2022
-
-   This file provides the outline for your program
-   Please implement the functions given by the prototypes below and
-   complete the main function to make the program complete.
-   You must implement the functions which are prototyped below exactly
-   as they are requested.
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
#define PI 3.141592653589

/* NO GLOBAL VARIABLES ALLOWED */

/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------
    PRE: Arguments must point to double variables or int variables as appropriate
    This function scans a line of DS4 data, and returns
    True when left button is pressed
    False Otherwise
    POST: it modifies its arguments to return values read from the input line.
------------------------------------------------------------------------------------*/
int read_input(int *time,
               double *g_x, double *g_y, double *g_z,
               int *button_T, int *button_C, int *button_X, int *button_S,
               int *l_joy_x, int *l_joy_y, int *r_joy_x, int *r_joy_y);

/*-----------------------------------------------------------------------------
    PRE: ~(-1.0) <= mag <= ~(1.0)
    This function scales the roll/pitch value to fit on the screen.
    Input should be capped at either -1.0 or 1.0 before the rest of your
    conversion.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleMagForScreen(double rad);

/*-----------------------------------------------------------------------------
    PRE: -128 <= mag <= 127
    This function scales the joystick value to fit on the screen.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleJoyForScreen(int rad);

/*----------------------------------------------------------------------------
    PRE: -39 <= number <= 39
    Uses print_chars to graph a number from -39 to 39 on the screen.
    You may assume that the screen is 80 characters wide.
----------------------------------------------------------------------------*/
void graph_line(int number);

/*-----------------------------------------------------------------------------
    PRE: num >= 0
    This function prints the character "use" to the screen "num" times
    This function is the ONLY place printf is allowed to be used
    POST: nothing is returned, but "use" has been printed "num" times
-----------------------------------------------------------------------------*/
void print_chars(int num, char use);

/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
int main()
{
    double x, y, z;                    /* Values of x, y, and z axis*/
    int t;                             /* Variable to hold the time value */
    int b_Up, b_Down, b_Left, b_Right; /* Variables to hold the button statuses */
    int j_LX, j_LY, j_RX, j_RY;        /* Variables to hold the joystick statuses */
    int scaled_pitch, scaled_roll;     /* Value of the roll/pitch adjusted to fit screen display */
    int scaled_joy;                    /* Value of joystick adjusted to fit screen display */
    bool stop;                         // used to tell the program to stop running
    int state;                         // used to determine which bar graph is ouput, 0 == roll, 1 == pitch, 2 == joystick
    bool buttonPressed;                // used to only take in one input of each button press

    /* Put pre-loop preparation code here */

    do
    {
        /* Scan a line of input */
        stop = read_input(&t, &x, &y, &z, &b_Up, &b_Right, &b_Down, &b_Left, &j_LX, &j_LY, &j_RX, &j_RY);
        /* Calculate and scale for pitch AND roll AND joystick */
        scaled_pitch = scaleMagForScreen(y);
        scaled_pitch += 80; // make it a different set of numbers from roll, so that the graph line funciton can print different letters
        scaled_roll = scaleMagForScreen(-x);
        scaled_joy = scaleJoyForScreen(j_RX);
        /* Switch between roll, pitch, and joystick with the up, down, and right button, respectivly */
        if (!buttonPressed)
        {
            /* Output your graph line */
            if (state == 0)
                graph_line(scaled_pitch);
            else if (state == 1)
                graph_line(scaled_roll);
            else if (state == 2)
                graph_line(scaled_joy);

            if (b_Up == 1)
            {
                if (state == 2)
                    state = 0;
                else
                    state++;
                buttonPressed = true;
            }
        }
        else if (buttonPressed)
        {
            if (b_Up == 0)
                buttonPressed = false;
        }

        fflush(stdout);

    } while (!stop); /* Modify to stop when left button is pressed */

    return 0;
}

int read_input(int *time,
               double *g_x, double *g_y, double *g_z,
               int *button_T, int *button_C, int *button_X, int *button_S,
               int *l_joy_x, int *l_joy_y, int *r_joy_x, int *r_joy_y)
{
    scanf(" %d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d", time,
          g_x, g_y, g_z,
          button_T, button_C, button_X, button_S,
          l_joy_x, l_joy_y, r_joy_x, r_joy_y);

    if (*button_S == 1)
        return 1;
    else
        return 0;
}

int scaleMagForScreen(double rad)
{
    // pitch and roll are from -1 to 1, the screen is from -39 to 39
    if (rad > 1.0)
        rad = 1.0;
    else if (rad < -1.0)
        rad = -1.0;

    rad *= 39;
    return rad;
}

int scaleJoyForScreen(int rad)
{
    double temp = rad;
    // joystick input is from -128 to 127, the screen is from -39 to 39
    if (temp > 127)
        temp = 127;
    else if (temp < -128)
        temp = -128;
    if (temp > 0)
        temp /= 127; // get it in terms of 1
    else if (temp < 0)
        temp /= 128; // get it in terms of 1

    temp *= 39;
    return temp;
}

void graph_line(int number)
{
    int i;

    if (number == 0 || number == 80)
    {
        print_chars(39, ' ');
        print_chars(1, '0');
        print_chars(39, ' ');
    }
    else if (number >= -39 && number <= 39)
    {
        for (i = -39; i < 40; i++)
        {
            if (i < number && i <= 0) 
                print_chars(1, ' ');
            else if (i >= number && i < 0)
                print_chars(1, 'L');
            else if (i <= number && i > 0)
                print_chars(1, 'R');
        }
    }
    else if (number >= 41 && number <= 119)
    {
        number -= 80; // rescaling it for the screen
        for (i = -39; i < 40; i++)
        {
            if (i < number && i <= 0)
                print_chars(1, ' ');
            else if (i >= number && i < 0)
                print_chars(1, 'B');
            else if (i <= number && i > 0)
                print_chars(1, 'F');
        }
    }
    print_chars(1, 'n');
}

void print_chars(int num, char use)
{
    int i;
    if (use == 'n')
        printf("\n");
    else
    {
        for (i = 0; i < num; i++)
            printf("%c", use);
    }
}