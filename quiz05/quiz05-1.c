#include <stdio.h>

int main(void)
{
	int i;
	double hw[5], exam[3], avg[3] = {0,0,0};
	

	for (i = 0; i < 5; i++)
	{
		printf("Enter your grade (%%) for HW #0%d: ", i + 1);
		scanf(" %lf", &hw[i]);
	}

	for (i = 0; i < 3; i++)
	{
		printf("Enter your grade (%%) for Exam #0%d: ", i + 1);
		scanf(" %lf", &exam[i]);
	}

	for (i = 0; i < 5; i++)
	{
		avg[0] += hw[i];
	}
	avg[0] /= 5;

	for (i = 0; i < 3; i++)
	{
		avg[1] += exam[i];
	}
	avg[1] /= 3;


	avg[2] = (0.40 * avg[0]) + (0.60 * avg[1]);


	printf("\nFinal grade = %.2lf%%\n", avg[2]);

	return 0;
}