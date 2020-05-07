#include <stdio.h>
#include <stdlib.h>

void title(void); //function prototype for title
void inst(void);       //function prototype for instructions
void hangman(int);   //function prototype for hangman
//void credits(void);      //function prototype for credits

void delay(unsigned int secs) {
    unsigned int end = time(0) + secs;
    while (time(0) < end);
}

void title(void)   //defining title
{

    printf("--------------------------------------------\n");
    printf("| #  #   #   #   #  #### #   #   #   #   # |\n");
    printf("| #  #  # #  ##  # #     ## ##  # #  ##  # |\n");
    printf("| #### ##### # # # #  ## # # # ##### # # # |\n");
    printf("| #  # #   # #  ## #   # #   # #   # #  ## |\n");
    printf("| #  # #   # #   #  ###  #   # #   # #   # |\n");
    printf("--------------------------------------------\n\n");

    delay(2);

    printf("\033[0;0H\033[2J");
}
void inst(void)    //defining instructions
{

    printf("\n\n\n\t\t INSTRUCTIONS \n\t\t ============");
    printf("\n\n   1: HANGAMN IS THE GAME WHERE YOU HAVE TO GUESS THE WORD.");
    printf("\n   2: YOU WILL HAVE TO GUESS THE MAXIMUM WORDS FOR THE MAXIMUM SCORE.");
    printf("\n   3: EVERY LEVEL WILL HAVE THE NEW WORD .");
    printf("\n   4: 1 CORRECT LETTER = 1 SCORE");
    printf("\n   5: YOU HAVE THE n CHOICES TO FIND THE MAXIMUM WORDS\n\n\n");

    delay(5);
    printf("\033[0;0H\033[2J");

    printf("\n\n\n\n\t\t   HOW TO PLAY \n\t\t ===========");
    printf("\nUse your keyboard and guess the word . if you press any letter and the letter is in the word the game will tell you the position of the game . \nguess more , score more . \n\n \t\t\t BEST OF LUCK !");

    delay(5);
    printf("\033[0;0H\033[2J");

}
void hangman(int a) {    //defining hangman
    switch (a) {
    case 6:
        {
            printf("\n\t\t\tAmount of wrong letters: %d\n\n", a);
            printf("  _______\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|_________\n\n");

        }
        break;

    case 5:
        printf("\n\t\t\tAmount of wrong letters: %d\n\n", a);
        printf("  _______\n");
        printf("  |/   | \n");
        printf("  |    O \n");
        printf("  |\n");
        printf("  |\n");
        printf("  |\n");
        printf("__|_________\n\n");

        break;

    case 4:
        printf("\n\t\t\tAmount of wrong letters: %d\n\n", a);
        printf("  _______\n");
        printf("  |/   | \n");
        printf("  |    O \n");
        printf("  |    |\n");
        printf("  |    |\n");
        printf("  |\n");
        printf("__|_________\n\n");

        break;

    case 3:
        printf("\n\t\t\tAmount of wrong letters: %d\n\n", a);
        printf("  _______\n");
        printf("  |/   | \n");
        printf("  |    O \n");
        printf("  |    |/\n");
        printf("  |    |\n");
        printf("  |\n");
        printf("__|_________\n\n");

        break;


    case 2:
        printf("\n\t\t\tAmount of wrong letters: %d\n\n", a);
        printf("  _______\n");
        printf("  |/   | \n");
        printf("  |    O \n");
        printf("  |   \\|/\n");
        printf("  |    |\n");
        printf("  |\n");
        printf("__|_________\n\n");

        break;

    case 1:
    printf("\n\t\t\tAmount of wrong letters: %d\n\n", a);
    printf("  _______\n");
    printf("  |/   | \n");
    printf("  |    O \n");
    printf("  |   \\|/\n");
    printf("  |    |\n");
    printf("  |   /  \n");
    printf("__|_________\n\n");

    break;

    case 0:
    printf("\n\t\t\tAmount of wrong letters: %d\n\n", a);
    printf("  _______\n");
    printf("  |/   | \n");
    printf("  |    x \n");
    printf("  |   \\|/\n");
    printf("  |    |\n");
    printf("  |   / \\\n");
    printf("__|_________\n\n");

    break;

    }
}
