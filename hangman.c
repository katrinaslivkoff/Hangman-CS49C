#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXWORDS 20
#define MAXWORDLENGTH 20

//reads words from words.txt and stores them in words[][]
int readWordsFromFile (char words[MAXWORDS][MAXWORDLENGTH], FILE *fptr)
{
  int numOfWords = 0;
  char input[MAXWORDLENGTH];                                                                                            //used to store word read from file

  while (fgets(input, MAXWORDLENGTH - 1, fptr))                                                                         //loops while still able to read from file
  {
    sscanf(input, "%s", words[numOfWords]);                                                                             //stores input into words array
    ++numOfWords;                                                                                                       //increments numOfWords because a new word was added
  }

  return numOfWords;                                                                                                    //returns how many words were added into words array
}

//prints the hidden word user needs to guess along with correctly guessed characters
void printHangmanWord (int wordLength, int guessedLetters[], char correctWord[])
{ 
  printf("%s", "Hangman word:");
  for (int index = 0; index < wordLength; ++index)                                                                      //traverses through guessedLetters
  {
    if (guessedLetters[index] == 1)                                                                                     //if current character was correctly guessed (= 1) then it prints character
    {
      printf("%c", correctWord[index]);
    }
    else
    {
      printf("%s", "_");                                                                                                //otherwise prints _ since it was not guessed yet
    }
  }
  printf("%s", "\n");
}

//checks if the user's input was correct, it it was it replaces that character position to 1 in guessedLetters
int checkGuess (int correctGuesses, int wordLength, int guessedLetters[], char charInput, char correctWord[], int livesLeft)
{                                                 
  for (int loopIndex = 0; loopIndex < wordLength; ++loopIndex)                                                          //traverses through guessedLetters and correctWord
  {
    if (guessedLetters[loopIndex] == 1)                                                                                 //if the current character has already been guessed, then it continues to the next character
    {
      continue;
    }

    if (charInput == correctWord[loopIndex])                                                                            //checks if the user's input matches the current character in correctWord
    {
      guessedLetters[loopIndex] = 1;                                                                                    //when true, sets guessedLetters's current position to 1
      ++correctGuesses;                                                                                                 //increments correctGuesses because a charcter was guessed correctly
    }
  }

  return correctGuesses;                                                                                                //returns the number of correct guesses the user has made
}

//prints if the user's guess was correct or not
int printGuessResult (int correctGuesses, int previousCorrectRec, int livesLeft)
{
  if (previousCorrectRec == correctGuesses)                                                                             //checks if the correctGuesses still equals previousCorrectRec
  {
    --livesLeft;                                                                                                        //when true, decrements livesLeft because no correct guesses were made
    printf("%s\n", "Wrong Guess");                                                                                      //prints incorrect guess message
  }
  else 
  {
    printf("%s\n", "Correct Guess");                                                                                    //prints correct guess message
  }

  return livesLeft;                                                                                                     //returns the number of lives the user has left
}

//prints the end game result
void printGameResult (int quit, int livesLeft, char correctWord[])
{
  if (quit == 1)                                                                                                        //when quit equals 1, prints user has quit message
  {
    printf("%s", "the user quit early\n");
  }
  else if (livesLeft == 0)                                                                                              //when livesLeft equals 0, prints user lost message
  {
    printf("Sorry you lose, the word was: %s\n", correctWord);
  }
  else
  {
    printf("%s\n", "YOU WIN!");                                                                                         //otherwise, prints user won message
  }
}

int main(void) 
{
  //title()
  FILE *fptr = fopen("words.txt", "r");                                                                                 //opens words.txt to be read from

  if (fptr == NULL)                                                                                                     //prints error message if can't open file
  {
    printf("%s\n", "Failed to Open File");
    return 0;
  }

  char guessWords[MAXWORDS][MAXWORDLENGTH];                                                                             //initializes array that will hold the words read from words.txt
  int numOfWords = readWordsFromFile(guessWords, fptr);                                                                 //calls on readWordsFromFile and stores the number of words read in numOfWords
  
  fclose(fptr);                                                                                                         //closes file because it is no longer needed

  srand(time(NULL));                                                                                                    //calls on srand to make sure a different word is chosen everytime the program is ran
  int randomIndex = rand() % numOfWords;                                                                                //calls on rand to get a random index value that will determine the word chosen

  int wordLength = strlen(guessWords[randomIndex]);                                                                     //sets wordLength to the length of the chosen word
  char correctWord[wordLength];                                             
  strcpy(correctWord, guessWords[randomIndex]);                                                                         //copies contents of the chosen word into the correctWord array
  
  //intializes variables
  int guessedLetters[MAXWORDLENGTH] = {0};
  int livesLeft = 6;
  int correctGuesses = 0;
  int previousCorrectRec = 0;
  int quit = 0; 
  char guess[16];
  char charInput;

  //printInstructions();

  //game loop
  while (correctGuesses < wordLength)                                                                                   //loops while correctGuesses is less than the wordLength
  {
    //drawHangman()
    printHangmanWord(wordLength, guessedLetters, correctWord);                                                          //calls on printHangmanWord 
    printf("Number of Lives Left: %d\n", livesLeft);                                                                    //prints number of lives the user has left
    
    printf("%s\n", "Enter a guess letter:");                                                                            //asks user to enter their guess
    fgets(guess, 16, stdin);
    if (strncmp(guess, "quit", 4) == 0)                                                                                 //checks if the user's input is "quit"
    {
      quit = 1;                                                                                                         //if true, sets quit to 1 and breaks while loop
      break;
    }
    charInput = guess[0];                                                                                               //sets charInput to the first character of the user's input
    
    previousCorrectRec = correctGuesses;                                                                                //sets previousCorrectRec to the current value of correctGuesses
    correctGuesses = checkGuess(correctGuesses, wordLength, guessedLetters, charInput, correctWord, livesLeft);         //calls on checkGuess and sets correctGuesses to the updated correctGuesses value produced

    livesLeft = printGuessResult(correctGuesses, previousCorrectRec, livesLeft);                                        //calls on printGuessResult and sets livesLeft to the updated livesLeft value produced

    if (livesLeft == 0)                                                                                                 //if livesLeft is 0, then it breaks out of loop because the game is over
    {
      break;
    }
  }
  
  printGameResult (quit, livesLeft, correctWord);                                                                       //calls on printGameResult 
}