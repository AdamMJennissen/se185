#include <stdio.h>

typedef struct student
{
    char name[20];
    double exams[3];

} student;

int main(void)
{
    int i, j;
    FILE *outputFile = NULL;

    student students[4];
    student students2[4];
    double avgScore[4];

    // get input for data
    for (i = 0; i < 4; i++)
    {
        printf("Enter student%d name and three exam score: ", i + 1);
        scanf("%s %lf %lf %lf", students[i].name, &students[i].exams[0], &students[i].exams[1], &students[i].exams[2]);
    }

    // Open file
    outputFile = fopen("student_data.txt", "w");
    if (outputFile == NULL)
    {
        printf("Could not open file student_data.txt.\n");
        return -1; // -1 indicates error
    }

    // Write to file
    for (i = 0; i < 4; i++)
    {
        fprintf(outputFile, "%s %.2lf %.2lf %.2lf\n", students[i].name, students[i].exams[0], students[i].exams[1], students[i].exams[2]);
    }

    // print data to terminal
    for (i = 0; i < 4; i++)
    {
        printf("%s exam scores = %.2lf, %.2lf, %.2lf\n", students[i].name, students[i].exams[0], students[i].exams[1], students[i].exams[2]);
    }

    // Done with file, so close it
    fclose(outputFile);

    FILE *inputFile = NULL;

    // Open file
    inputFile = fopen("student_data.txt", "r");
    if (inputFile == NULL)
    {
        printf("Could not open file student_data.txt.\n");
        return -1; // -1 indicates error
    }

    // get data from terminal
    for (i = 0; i < 4; i++)
    {
        fscanf(inputFile, "%s %lf %lf %lf\n", &students2[i].name, &students2[i].exams[0], &students2[i].exams[1], &students2[i].exams[2]);
    }

    // calculate average
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            avgScore[i] += students2[i].exams[j];
        }
        avgScore[i] /= 3;
    }

    for (i = 0; i < 4; i++)
    {
        printf("%s exam average = %.2lf\n", students2[i].name, avgScore[i]);
    }
    // Done with file, so close it
    fclose(outputFile);
    return 0;
}