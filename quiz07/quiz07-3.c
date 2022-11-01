#include <stdio.h>

void examStat(int scores[], int score_size, int results[], int result_size);

int main(void)
{
    const int num_scores = 30;
    const int size_result = 5;
    int midterm1Score[num_scores];
    int result[size_result];
    int i;

    for (i = 0; i < num_scores; i++)
    {
        printf("Score %d = ", (i + 1));
        scanf(" %d", &midterm1Score[i]);
    }

    examStat(midterm1Score, num_scores, result, size_result);

    printf("\nThe average score is: %d\n", result[0]);
    printf("The maximum score is: %d\n", result[1]);
    printf("The minimum score is: %d\n", result[2]);
    printf("The number of students who failed is: %d\n", result[3]);
    printf("The number of students who got an A is: %d\n", result[4]);

    return 0;
}

void examStat(int scores[], int score_size, int results[], int result_size)
{
    int i;
    int temp = 0;

    for (i = 0; i < score_size; i++)
    {
        temp += scores[i];
    }
    results[0] = (temp / score_size);
    
    temp = scores[0];
    for (i = 0; i < score_size; i++)
    {
        if (scores[i] > temp)
            temp = scores[i];
    }
    results[1] = temp;

    temp = scores[0];
    for (i = 0; i < score_size; i++)
    {
        if (scores[i] < temp)
            temp = scores[i];
    }
    results[2] = temp;

    temp = 0;
    for (i = 0; i < score_size; i++)
    {
        if (scores[i] < 60)
            temp++;
    }
    results[3] = temp;

    temp = 0;
    for (i = 0; i < score_size; i++)
    {
        if (scores[i] >= 93)
            temp++;
    }
    results[4] = temp;
}