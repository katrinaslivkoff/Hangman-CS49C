#include <stdio.h>
#include <stdlib.h>

void title(void); 
void inst(void);       
void hangman(int);   

//defines the delay method to delay the screen
void delay(unsigned int secs) {
    unsigned int end = time(0) + secs;
    while (time(0) < end);
}

//defines the title and authors
void title(void)  
{

    printf("\n\n--------------------------------------------\n");
    printf("| #  #   #   #   #  #### #   #   #   #   # |\n");
    printf("| #  #  # #  ##  # #     ## ##  # #  ##  # |\n");
    printf("| #### ##### # # # #  ## # # # ##### # # # |\n");
    printf("| #  # #   # #  ## #   # #   # #   # #  ## |\n");
    printf("| #  # #   # #   #  ###  #   # #   # #   # |\n");
    printf("--------------------------------------------\n\n");

    delay(2); // delay screen for 2 seconds

    printf("\033[0;0H\033[2J"); // clears the screen

    printf("\n\nby Katrina Slivkoff and Ianna Duran \n");

    delay(2); // delays the screen for 2 seconds

    printf("\033[0;0H\033[2J"); // clears the screen
}

//defines the instruction of the game
void inst(void)   
{

    printf("\n\n         ------------\n\t\t INSTRUCTIONS \n\t\t ------------");
    printf("\n\n   1: HANGAMN IS A GAME WHERE YOU HAVE TO GUESS THE CORRECT WORD");
    printf("\n   2: EACH TURN YOU WILL GUESS A LETTER");
    printf("\n   3: EVERY WRONG LETTER = -1 LIFE");
    printf("\n   4: YOU HAVE 6 LIVES\n");

    delay(5); // delay screen for 5 seconds

    printf("\033[0;0H\033[2J"); // clears the screen

    printf("\n\n\n\n\t\t HOW TO PLAY \n\t\t ===========");
    printf("\n Use your keyboard to guess a letter. If correct, the letter will be placed           \n where it is supposed to be in the word. If incorrect, no letters are                 \n placed and the hangamn starts to get drawn.                                          \n GOOD LUCK!!! \n");

    delay(6); // delay screen for 6 seconds

    printf("\033[0;0H\033[2J"); // clears the screen

}

//defines the hangman drawing for each case
void hangman(int a) 
{    
    switch (a) {
    case 6:
        printf("\n  _______\n");
        printf("  |/\n");
        printf("  |\n");
        printf("  |\n");
        printf("  |\n");
        printf("  |\n");
        printf("__|_________\n\n");
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
