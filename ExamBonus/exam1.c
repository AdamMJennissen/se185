//Student: Adam Jennissen

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int luckyNum, sum1, sum2, roll1, roll2;

	printf("Welcome to the dice game!\n");
	
	while (luckyNum != -99)
	{
		printf("Enter your lucky number or -99 to quit: ");
		scanf(" %d", &luckyNum);

		if (luckyNum == -99)
			break;

		srand(luckyNum);
		roll1 = (rand() % 6 + 1);
		roll2 = (rand() % 6 + 1);

		sum1 = roll1 + roll2;

		printf("Player 1 Dice: %d - %d\n", roll1, roll2);
		printf("Player 1 sum: %d\n", sum1);

		srand(time(NULL));
		roll1 = (rand() % 6 + 1);
		roll2 = (rand() % 6 + 1);

		sum1 = roll1 + roll2;

		printf("Player 2 Dice: %d - %d\n", roll1, roll2);
		printf("Player 2 sum: %d\n", sum1);

		if (sum1 == sum2)
			printf("No one is lucky today. It is a tie");
		else if (sum1 > sum2)
			printf("Player 1 is the winner");
		else if (sum2 > sum1)
			printf("Player 2 is the winner");

	}

	return 0;
}