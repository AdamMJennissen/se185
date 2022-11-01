#include <stdio.h>

double CalcAvg(int grades[]);

char CalcGrade(double avg);


int main(void)
{
	double avg;
	int grades[2][4];
	int i, j;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("Student-%d Assignment-%d grade: ", i+1, j+1);
			scanf(" %d", &grades[i][j]);
		}
	}


	printf("\nStudent 1 Avg = %.2lf\n", CalcAvg(grades[0]));
	printf("Student 1 Grade = %c\n", CalcGrade(CalcAvg(grades[0])));
	printf("Student 2 Avg = %.2lf\n", CalcAvg(grades[1]));
	printf("Student 2 Grade = %c\n", CalcGrade(CalcAvg(grades[1])));


	return 0;
}

double CalcAvg(int grades[])
{
	double avg;
	int i;

	for (i = 0; i < 4; i++)
	{
		avg += grades[i];
	}
	avg /= 4;

	return avg;
}

char CalcGrade(double avg)
{
	char grade;
	if (85 <= avg && avg <= 100)
		grade = 'A';
	else if (74 <= avg && avg < 85)
		grade = 'B';
	else if (60 <= avg && avg < 75)
		grade = 'c';
	else
		grade = 'f';

	return grade;
}