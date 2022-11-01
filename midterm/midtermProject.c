
/*----------------------------------------------------------------------------
-          SE 185: Midterm Project                   -
- List the names of all team members, their roles, and their participation
1-Adam Jennissen - Role: Logic creator and debugger 50%
    (Wrote the rest of the logic for everything except the quizes)
2-Carter Bebee - Role: Quiz creator and debugger 50%
    (Wrote the quizes and code for them.)
-
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
- Includes
-
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*----------------------------------------------------------------------------
-                             Functions Prototypes
-
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-                                 Notes                                    -
-----------------------------------------------------------------------------*/

// Compile with gcc midtermProject.c -o proj

/*----------------------------------------------------------------------------
- Implementation
-
-----------------------------------------------------------------------------*/

int main(void)
{
    int luckyNum;
    double numQs, numQ1s, numQ2s, numQ3s;
    double score, score1, score2, score3;

    double avg, avg1, avg2, avg3;
    int q;
    bool q1, q2, q3;
    bool q1_1, q1_2, q1_3;
    bool q2_1, q2_2, q2_3;
    bool q3_1, q3_2, q3_3;

    char q1_1a, q2_1a, q3_1a;
    char q1_2a, q2_2a, q3_2a;
    char q1_3a[20], q2_3a[20], q3_3a[20];

    printf("Welcome to the quizes, you can take quiz 01, quiz 02, and quiz 03.\n");
    printf("Enter your lucky number from 1-9 to start or -99 to quit: ");
    scanf(" %d", &luckyNum);
    srand(luckyNum);

    while (luckyNum != -99 || !(q1 == 1 && q2 == 1 && q3 == 1))
    {
        while (luckyNum < 1 || luckyNum > 9)
        {
            printf("\nPlease enter a number from 1-9 or -99 to quit:");
            scanf(" %d", &luckyNum);
            srand(luckyNum);
        }

        q = ((rand() % 3) + 1);

        while (q == 1 && q1 != 1)
        {
            printf("Welcome to quiz 01!\n");
            printf("T or F: When declaring an integer, you can't have a number be the first character.\n"); // question
            scanf(" %c", &q1_1a);                                                                           // true or false

            q1_1 = 0;

            if (q1_1a == 'T')
            {
                printf("That was correct!\n");
                score1 += 5;
                q1_1 = 1;
            }
            else
                printf("That was the wrong answer\n");

            printf("What does the operator '==' mean?\n"); // question
            printf("A. Less than\n");
            printf("B. Greater than\n");
            printf("C. Equal to\n");
            printf("D. Not equal to\n");

            scanf(" %c", &q1_2a); // a,b,c,d
            q1_2 = 0;

            if (q1_2a == 'C')
            {
                printf("That was correct!\n");
                score1 += 5;
                q1_2 = 1;
            }
            else
                printf("That was the wrong answer\n");

            printf("Make the following statement correct\n"); // question
            printf("printf(\"Hello__;\n");

            scanf(" %s", q1_3a); // string, fill in blank
            q1_3 = 0;

            if (strcmp(q1_3a, "\")") == 0)
            {
                printf("That was correct!\n");
                score1 += 5;
                q1_3 = 1;
            }
            else
                printf("That was the wrong answer\n");

            if (q1_1 == 1 && q1_2 == 1 && q1_3 == 1)
            {
                numQ1s++;
                avg1 = score1 / numQ1s;
                q1 = 1;
                printf("You completed quiz 01, your average score was %0.2lf, enter a new lucky number from 1-9, or enter -99 to quit: ", avg1);
                scanf(" %d", &luckyNum);
                srand(luckyNum);
                continue;
            }
            else
                numQ1s++;
        }
        while (q == 2 && q2 != 1)
        {
            printf("Welcome to quiz 02!\n");
            // quiz stuff

            // question 1
            printf("T or F: In a scanf statement %%c can be used to describe a string\n"); // question

            scanf(" %c", &q2_1a); // true or false
            q2_1 = 0;

            if (q2_1a == 'F')
            {
                printf("That was correct!\n");
                score2 += 5;
                q2_1 = 1;
            }
            else
                printf("That was the wrong answer\n");

            // question 2
            printf("If an array[5] is stated which way does it count?\n"); // question
            printf("A. 12345\n");
            printf("B. 54321\n");
            printf("C. 01234\n");
            printf("D. 01235\n");

            scanf(" %c", &q2_2a); // a,b,c,d
            q2_2 = 0;

            if (q2_2a == 'C')
            {
                printf("That was correct!\n");
                score2 += 5;
                q2_2 = 1;
            }
            else
                printf("That was the wrong answer\n");

            // question 3

            printf("A __ statement can be used to end a loop.\n"); // question
            scanf(" %s", q2_3a);                                   // string, fill in blank
            q2_3 = 0;

            if (strcmp(q2_3a, "break") == 0)
            {
                printf("That was correct!\n");
                score2 += 5;
                q2_3 = 1;
            }
            else
                printf("That was the wrong answer\n");

            if (q2_1 == 1 && q2_2 == 1 && q2_3 == 1)
            {
                numQ2s++;
                avg2 = score2 / numQ2s;
                q2 = 1;
                printf("You completed quiz 02, your average score was %0.2lf, enter a new lucky number from 1-9, or enter -99 to quit: ", avg2);
                scanf(" %d", &luckyNum);
                srand(luckyNum);
                continue;
            }
            else
                numQ2s++;
        }
        while (q == 3 && q3 != 1)
        {
            printf("Welcome to quiz 03!\n");
            // quiz stuff
            // question 1

            printf("T or F: A for loop only ends if it has a break statement\n"); // question

            scanf(" %c", &q3_1a); // true or false
            q3_1 = 0;

            if (q3_1a == 'F')
            {
                printf("That was correct!\n");
                score3 += 5;
                q3_1 = 1;
            }
            else
                printf("That was the wrong answer\n");

            // question 2
            printf("If array[i]= {1,2,3,4,5} and i=3 what is the output?\n"); // question
            printf("A. 4\n");
            printf("B. 2\n");
            printf("C. 3\n");
            printf("D. 1\n");

            scanf(" %c", &q3_2a); // a,b,c,d
            q3_2 = 0;

            if (q3_2a == 'A')
            {
                printf("That was correct!\n");
                score3 += 5;
                q3_2 = 1;
            }
            else
                printf("That was the wrong answer\n");

            // question 3
            printf("Besides a while loop the other main loop is a __ loop\n"); // question

            scanf(" %s", q3_3a); // string, fill in blank
            q3_3 = 0;

            if (strcmp(q3_3a, "for") == 0)
            {
                printf("That was correct!\n");
                q3_3 = 1;
                score3 += 5;
            }
            else
                printf("That was the wrong answer\n");

            if (q3_1 == 1 && q3_2 == 1 && q3_3 == 1)
            {
                numQ3s++;
                avg3 = score3 / numQ3s;
                q3 = 1;
                printf("You completed quiz 03, your average score was %0.2lf, enter a new lucky number from 1-9, or enter -99 to quit: ", avg3);
                scanf(" %d", &luckyNum);
                srand(luckyNum);
                continue;
            }
            else
                numQ3s++;
        }

        if (q1 == 1 && q2 == 1 && q3 == 1)
            break;
    }
    // average code
    numQs += numQ1s + numQ2s + numQ3s;
    score += score1 + score2 + score3;

    avg = score / numQs;

    printf("Thanks for taking the quizes, your total average score was %0.2lf\n", avg);

    return 0;
}
/* Put your functions here, and be sure to put prototypes above. */