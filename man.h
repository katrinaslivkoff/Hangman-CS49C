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

    printf("\n\n--------------------------------------------\n");
    printf("| #  #   #   #   #  #### #   #   #   #   # |\n");
    printf("| #  #  # #  ##  # #     ## ##  # #  ##  # |\n");
    printf("| #### ##### # # # #  ## # # # ##### # # # |\n");
    printf("| #  # #   # #  ## #   # #   # #   # #  ## |\n");
    printf("| #  # #   # #   #  ###  #   # #   # #   # |\n");
    printf("--------------------------------------------\n\n");

    delay(2);

    printf("\033[0;0H\033[2J");

    printf("\n\nby Katrina Slivkoff and Ianna Duran \n");

    delay(2);

    printf("\033[0;0H\033[2J");
}

void inst(void)    //defining instructions
{

    printf("\n\n         ------------\n\t\t INSTRUCTIONS \n\t\t ------------");
    printf("\n\n   1: HANGAMN IS A GAME WHERE YOU HAVE TO GUESS THE CORRECT WORD");
    printf("\n   2: EACH TURN YOU WILL GUESS A LETTER");
    printf("\n   3: EVERY WRONG LETTER = -1 LIFE");
    printf("\n   4: YOU HAVE 6 LIVES\n");

    delay(5);
    printf("\033[0;0H\033[2J");

    printf("\n\n\n\n\t\t HOW TO PLAY \n\t\t ===========");
    printf("\n Use your keyboard to guess a letter. If correct, the letter will be placed           \n where it is supposed to be in the word. If incorrect, no letters are                 \n placed and the hangamn starts to get drawn.                                          \n GOOD LUCK!!! \n");

    delay(6);
    printf("\033[0;0H\033[2J");

}
void hangman(int a) {    //defining hangman
    switch (a) {
    case 6:
        {
            printf("\n  _______\n");
            printf("  |/\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|_________\n\n");

        }
        break;

    case 5:
        printf("\n  _______\n");
        printf("  |/   | \n");
        printf("  |    O \n");
        printf("  |\n");
        printf("  |\n");
        printf("  |\n");
        printf("__|_________\n\n");

        break;

    case 4:
        printf("\n  _______\n");
        printf("  |/   | \n");
        printf("  |    O \n");
        printf("  |    |\n");
        printf("  |    |\n");
        printf("  |\n");
        printf("__|_________\n\n");

        break;

    case 3:
        printf("\n  _______\n");
        printf("  |/   | \n");
        printf("  |    O \n");
        printf("  |    |/\n");
        printf("  |    |\n");
        printf("  |\n");
        printf("__|_________\n\n");

        break;


    case 2:
        printf("\n  _______\n");
        printf("  |/   | \n");
        printf("  |    O \n");
        printf("  |   \\|/\n");
        printf("  |    |\n");
        printf("  |\n");
        printf("__|_________\n\n");

        break;

    case 1:
      printf("\n  _______\n");
      printf("  |/   | \n");
      printf("  |    O \n");
      printf("  |   \\|/\n");
      printf("  |    |\n");
      printf("  |   /  \n");
      printf("__|_________\n\n");

    break;

    case 0:
      printf("\n  _______\n");
      printf("  |/   | \n");
      printf("  |    x \n");
      printf("  |   \\|/\n");
      printf("  |    |\n");
      printf("  |   / \\\n");
      printf("__|_________\n\n");

    break;

    }
}
