// Lab 09 DS4Talker Skeleton Code

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses/ncurses.h>

#define WORDLENGTH 11
#define MAXWORDS 100
#define DEBUGM 1 // Set this to 0 to disable debug output

#define AVATAR '*'
#define EMPTY_SPACE ' '

/*	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
	POST: Draws character use to the screen and position x,y */
void draw_character(int y, int x, char use);

// Reads words from the file into WL and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int read_words(char *WL[MAXWORDS], char *file_name);

// modifies str to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char *str);

int main(int argc, char *argv[])
{
	// compile with gcc lab9.c -o lab9 -lncurses
	// run with ./ds4rd.exe -d 054c:09cc -D DS4_BT -t -b -j -bt | ./lab9 wordslist.txt
	char *wordlist[MAXWORDS];
	char temp[10];
	int wordcount;
	int i, col;
	int t, T, C, X, S;
	int LJ_X, LJ_Y, RJ_X, RJ_Y;
	int LJ_B, RJ_B, share, options, RB, LB, RT, LT;
	int x = WORDLENGTH - 2;
	int y = 0;
	int temp_x, temp_y;
	int temp_time, isCap;
	int tempLength =0;
	int word, len, pos;
	int word_length[30] ;
	for(int i = 0; i<30;i++)
	{
		word_length[i]= 0;
	}
	int buttonPressed;

	wordcount = read_words(wordlist, argv[1]);

	if (DEBUGM)
	{
		printf("Read %d words from %s \n", wordcount, argv[1]);
		for (i = 0; i < wordcount; i++)
		{
			printf("%s,", wordlist[i]);
		}
		printf("\n");
	}

	// most of your code goes here. Do not forget to include the ncurses library
	scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
		  &t, &T, &C, &X, &S,
		  &RJ_B, &LJ_B, &options, &share, &RT, &LT, &RB, &LB,
		  &LJ_X, &LJ_Y, &RJ_X, &RJ_Y);
	temp_time = t;
	/* 	Setup screen for Ncurses
	The initscr functionis used to setup the Ncurses environment
	The refreash function needs to be called to refresh the outputs
	to the screen */
	initscr();
	refresh();

	for (i = 0; i < wordcount; i++) // print the words to the screen
	{
		if ((i % 15) == 0)
			col += WORDLENGTH;
		if (i == 0)
			mvprintw(0, 8, wordlist[0]);
		else
			mvprintw((i % 15), col, wordlist[i]);
		refresh();
	}
	draw_character(y, x, AVATAR);

	do
	{
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
			  &t, &T, &C, &X, &S,
			  &RJ_B, &LJ_B, &options, &share, &RT, &LT, &RB, &LB,
			  &LJ_X, &LJ_Y, &RJ_X, &RJ_Y);

		temp_x = x;
		temp_y = y;

		if (temp_time + 200 <= t) // move the character around the screen
		{
			temp_time = t;

			if ((LJ_X < -90) && ((x - WORDLENGTH) > 0))
				x -= WORDLENGTH;
			else if ((LJ_X > 90) && ((x + WORDLENGTH) < (WORDLENGTH * 6)))
				x += WORDLENGTH;

			if ((LJ_Y < -90) && (y > 0))
				y -= 1;
			else if ((LJ_Y > 90) && (y < 14))
				y += 1;
		}

		if ((temp_x != x) || (temp_y != y)) // print the characters new location
		{
			draw_character(temp_y, temp_x, EMPTY_SPACE);
			draw_character(y, x, AVATAR);
		}

		word = y + ((x / WORDLENGTH) * 15);

		if (buttonPressed == 0)
		{
			if (C == 1) // capitalize the first letter of the next word added
			{
				buttonPressed = 1;
				strcpy(temp, wordlist[word]);
				temp[0] = toupper(temp[0]);
				isCap = 1;
			}

			if (T == 1) // add a space, then the word
			{
				buttonPressed = 1;
				mvprintw(20, len, " ");
				len++;
				if (isCap == 1)
				{
					mvprintw(20, len, temp);
					isCap = 0;
				}
				else
					mvprintw(20, len, wordlist[word]);
				len += strlen(wordlist[word]);
				tempLength += strlen(wordlist[word]);
				word_length[pos] += tempLength + 1;
				tempLength = 0;
				pos++;
			}

			if (S == 1) // add the word
			{
				buttonPressed = 1;
				if (isCap == 1)
				{
					mvprintw(20, len, temp);
					isCap = 0;
				}
				else
					mvprintw(20, len, wordlist[word]);
				len += strlen(wordlist[word]);
				tempLength += strlen(wordlist[word]);
				word_length[pos] += tempLength;
				tempLength = 0;
				pos++;
			}

			if (X == 1) // undo the previous input
			{
				buttonPressed = 1;
				// mvprintw(20, 20, "test");
				for (i = 0; i <= word_length[pos - 1]; i++)
				{
					mvprintw(20, len - i, " ");
				}
				len -= word_length[pos - 1];
				word_length[pos - 1] = 0;
				if(pos > 0)
					pos--;
			}

			if (LJ_B == 1) // delete the full sentence
			{
				buttonPressed = 1;
				for (i = len; i >= 0; i--)
				{
					mvprintw(20, i, " ");
				}
				for (i = pos; i >= 0; i--)
				{
					word_length[pos] = 0;
				}
				pos = 0;
				len = 0;
			}
		}
		else if (buttonPressed == 1)
		{
			if ((T == 0) && (C == 0) && (X == 0) && (S == 0) && (LJ_B == 0))
				buttonPressed = 0;
		}
		fflush(stdout);
		refresh();
	} while (1);

	/* This function is used to cleanup the Ncurses environment.
	Without it, the characters printed to the screen will persist
	even after the progam terminates */
	endwin();
	return 0;
}

/* 	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
	POST: Draws character use to the screen and position x,y
	THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
	DO NOT NEED TO CHANGE THIS FUNCTION. */
void draw_character(int y, int x, char use)
{
	mvaddch(y, x, use);
	refresh();
}

// DO NOT MODIFY THIS FUNCTION!
void trimws(char *str)
{
	int length = strlen(str);
	int x;
	if (length == 0)
		return;
	x = length - 1;
	while (isspace(str[x]) && (x >= 0))
	{
		str[x] = '\0';
		x -= 1;
	}
}

// DO NOT MODIFY THIS FUNCTION!
int read_words(char *WL[MAXWORDS], char *file_name)
{
	int numread = 0;
	char line[WORDLENGTH];
	char *p;
	FILE *fp = fopen(file_name, "r");
	while (!feof(fp))
	{
		p = fgets(line, WORDLENGTH, fp);
		if (p != NULL)
		{
			trimws(line);
			WL[numread] = (char *)malloc(strlen(line) + 1);
			strcpy(WL[numread], line);
			numread++;
		}
	}
	fclose(fp);
	return numread;
}
