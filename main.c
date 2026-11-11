
#include <stdio.h>
#include <ctype.h>

struct Question
{
    char question[200];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char answer;
};

int main()
{
    struct Question q[5] =
    {
        {"Which language is used for system programming?",
         "Python", "C", "HTML", "CSS", 'B'},

        {"Which symbol is used to end a C statement?",
         ".", ";", ":", ",", 'B'},

        {"Which function is the starting point of a C program?",
         "start()", "run()", "main()", "printf()", 'C'},

        {"Which header file is used for printf()?",
         "stdlib.h", "string.h", "math.h", "stdio.h", 'D'},

        {"Which loop executes at least once?",
         "for", "while", "do-while", "nested loop", 'C'}
    };

    char choice, playAgain;
    int score, i;

    do
    {
        score = 0;

        printf("\n===== QUIZ APPLICATION =====\n");

        for (i = 0; i < 5; i++)
        {
            printf("\nQ%d. %s\n", i + 1, q[i].question);
            printf("A. %s\n", q[i].optionA);
            printf("B. %s\n", q[i].optionB);
            printf("C. %s\n", q[i].optionC);
            printf("D. %s\n", q[i].optionD);

            printf("Enter your answer (A/B/C/D): ");
            scanf(" %c", &choice);

            choice = toupper((unsigned char)choice);

            if (choice == q[i].answer)
            {
                printf("Correct answer!\n");
                score++;
            }
            else
            {
                printf("Wrong answer! Correct answer: %c\n",
                       q[i].answer);
            }
        }

        printf("\n===== QUIZ RESULT =====\n");
        printf("Total Questions : 5\n");
        printf("Correct Answers : %d\n", score);
        printf("Wrong Answers   : %d\n", 5 - score);
        printf("Your Score      : %d/5\n", score);

        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);

        playAgain = tolower((unsigned char)playAgain);

    } while (playAgain == 'y');

    printf("\nThank you for playing!\n");

    return 0;
}
