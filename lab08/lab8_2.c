/*-----------------------------------------------------------------------------
-					  		SE 185 Lab 08
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name: Adam Jennissen
- Section: 08
-	NetID: adamjenn
-	Date: 10/27/2022
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
/* Mathmatical constants */
#define PI 3.14159

/* 	Screen geometry
    Use ROWS and COLUMNS for the screen height and width (set by system)
    MAXIMUMS */
#define COLUMNS 100
#define ROWS 80

/* 	Character definitions taken from the ASCII table */
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '

/*	Number of samples taken to form an moving average for the gyroscope data
    Feel free to tweak this. */
#define NUM_SAMPLES 10


/*-----------------------------------------------------------------------------
-								Static Data
-----------------------------------------------------------------------------*/
/* 2D character array which the maze is mapped into */
char MAZE[COLUMNS][ROWS];


/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*	POST: Generates a random maze structure into MAZE[][]
    You will want to use the rand() function and maybe use the output %100.
    You will have to use the argument to the command line to determine how
    difficult the maze is (how many maze characters are on the screen). */
void generate_maze(int difficulty);

/*	PRE: MAZE[][] has been initialized by generate_maze()
    POST: Draws the maze to the screen */
void draw_maze(void);

/*	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y */
void draw_character(int x, int y, char use);

/*	PRE: -1.0 < mag < 1.0
    POST: Returns tilt magnitude scaled to -1.0 -> 1.0
    You may want to reuse the roll function written in previous labs. */
double calc_roll(double mag);

/* 	Updates the buffer with the new_item and returns the computed
    moving average of the updated buffer */
double m_avg(double buffer[], int avg_size, double new_item);


/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
/*	Main - Run with './ds4rd.exe -t -g -b' piped into STDIN */
void main(int argc, char* argv[])
{
    int t, temp_time;
    int T, C, X, S;
    double new_x, new_y, new_z;
    double avg_x, avg_y, avg_z;
    int temp_x, temp_y, point_x, point_y;
    double x[NUM_SAMPLES], y[NUM_SAMPLES], z[NUM_SAMPLES];
    int i, j;
    char *a = argv[1];
  if (argc != 2 )
  {
      printw("You must enter the difficulty level on the command line.");
      refresh();
      return;
  }
  else
  {
    /* 	Setup screen for Ncurses
        The initscr functionis used to setup the Ncurses environment
        The refreash function needs to be called to refresh the outputs
        to the screen */
    initscr();
    refresh();

    /* WEEK 2 Generate the Maze */
    srand(time(NULL));
    generate_maze(atoi(a)); //I dont think this works right *******************************************************************************
    draw_maze();
    point_x = rand() % COLUMNS + 1;
    point_y = 0;
    while (MAZE[point_x][point_y] == WALL)
    {
        point_x = rand() % COLUMNS + 1;
    }
    draw_character(point_x, point_y, AVATAR);


    /* Read gyroscope data and fill the buffer before continuing */
    for(i = 0; i < NUM_SAMPLES; i++)
    {
        scanf(" %d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &new_x, &new_y, &new_z, &T, &C, &X, &S);
        x[i] = new_x;
        y[i] = new_y;
        z[i] = new_z;
    }
    temp_time = t;
    /* Event loop */
    do
    {
        /* Read data, update average */
        scanf(" %d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &new_x, &new_y, &new_z, &T, &C, &X, &S);

        avg_x = m_avg(x, NUM_SAMPLES, new_x);
        avg_y = m_avg(y, NUM_SAMPLES, new_y);
        avg_z = m_avg(z, NUM_SAMPLES, new_z);

        /* Is it time to move?  if so, then move avatar */
            temp_x = point_x;
            temp_y = point_y;

        if (temp_time + 250 <= t && (MAZE[point_x][point_y + 1] != WALL))
        {
            temp_time = t;
            point_y += 1;      
        }
        //add time delay ****************************************************************************************************************************************
        if ((avg_x > .5) && (point_x > 0) && (MAZE[point_x - 1][point_y] != WALL))
            point_x -= 1;
        else if ((avg_x < -.5) && (point_x < COLUMNS) && (MAZE[point_x + 1][point_y] != WALL))
            point_x += 1;
            
        if((temp_x != point_x) || (temp_y != point_y))
        {
            draw_character(temp_x, temp_y, EMPTY_SPACE);
            draw_character(point_x, point_y, AVATAR);
        }

        fflush(stdout);
        // add lose message ******************************************************************************************************************************************
    } while(point_y != ROWS && ((MAZE[point_x + 1][point_y] != WALL) || (MAZE[point_x - 1][point_x] != WALL) || (MAZE[point_x][point_y + 1] != WALL))); // Change this to end game at right time

    /* Print the win message */


    /* This function is used to cleanup the Ncurses environment.
    Without it, the characters printed to the screen will persist
    even after the progam terminates */
    endwin();

  }

    printf("YOU WIN!\n");
}

double m_avg(double buffer[], int avg_size, double new_item)
{
    int i;
    double sum = 0;

    for(i = 0; i < (avg_size - 1); i++)
    {
        buffer[i] = buffer[i + 1];
    }
    buffer[avg_size - 1] = new_item;


    for (i = 0; i < avg_size; i++)
    {
        sum += buffer[i];
    }

    return (sum / avg_size);
}

void generate_maze(int difficulty)
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i <= COLUMNS; i++)
    {
        for (j = 0; j <= ROWS; j++)
        {
            if ((((rand() % 100) + 1) - difficulty) <= 0)
            {
                MAZE[i][j] = WALL;
            }
        }
    }
}

void draw_maze(void)
{
    int i, j;
    for (i = 0; i <= COLUMNS; i++)
    {
        for (j = 0; j <= ROWS; j++)
        {
            if (MAZE[i][j] == WALL)
            {
                draw_character(i, j, WALL);
            }
        }
    }
}


/* 	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y
    THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
    DO NOT NEED TO CHANGE THIS FUNCTION. */
void draw_character(int x, int y, char use)
{
    mvaddch(y,x,use);
    refresh();
}