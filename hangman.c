/*
Very simple ASCII art hang man game. Variation of a C tutorial by Bluefever Software

Noah Winkel
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void drawHangMan();

int main() {

    srand(time(NULL));    

    char guessWords[][16] = {"red", "orange", "yellow", "green", "blue", "white", "black", "brown", "purple"};

    int randomIndex = rand() % 5;    
    
    int numLives = 6;
    int numCorrect = 0;
    int oldCorrect = 0;

    int lengthOfWord = strlen(guessWords[randomIndex]);
    int letterGuessed[8] = {0, 0, 0, 0, 0, 0, 0, 0};    

    int quit = 0;

    char guess[16];
    char letterEntered;                    

    //printf("GuessWords: %s RandomIndex: %d LenghOfWord: %d \n", guessWords[randomIndex], randomIndex, lengthOfWord); //debug assistant

    //Game loop
    while(numCorrect < lengthOfWord) {
        system("clear");
        drawHangMan(numLives); 

        for(int i = 0; i < lengthOfWord; i++) {

            if(letterGuessed[i] == 1) {
                printf("%c", guessWords[randomIndex][i]);
            } else {
                printf("-");
            }

        }

        printf("\n");

        printf("Number of lives %d \n", numLives); 
        printf("Enter a letter: ");
        fgets(guess, 16, stdin);

        if(strncmp(guess, "quit", 4) == 0) {
            quit = 1;
        } 

        letterEntered = guess[0];

        oldCorrect = numCorrect; 

        for(int i = 0; i < lengthOfWord; i++) {

            if(letterGuessed[i] == 1) {
                continue;
            }
            
            if(letterEntered == guessWords[randomIndex][i]) {

                letterGuessed[i] = 1;
                numCorrect++; 
            }
        }               

        if(oldCorrect == numCorrect) {
            numLives--;

            if(numLives == 0) {
                system("clear");
                drawHangMan(numLives);
                printf("You failed!\nThe word was: %s\n", guessWords[randomIndex]);
                break;
            }
        }

    }

    if(numLives != 0) {
        system("clear");
        drawHangMan(numLives);
        printf("%s \n", guessWords[randomIndex]);
        printf("You Win! \n"); 
    }

    return 0;
}




//animation bits
void drawHangMan(int numLives) {

    switch(numLives) {
        case 6:
            printf("                                \n\
                         _______                     \n\
                        |      |                      \n\
                        |                              \n\
                        |                               \n\
                        |                                \n\
                        |                                 \n\
                        |                                  \n\
                        |                                   \n\
                     ___|____                                \n");
            
            break; 

        case 5:
            printf("                                \n\
                         _______                     \n\
                        |    __|__                    \n\
                        |    | - -|                    \n\
                        |    |  ~ |                     \n\
                        |                                \n\
                        |                                 \n\
                        |                                  \n\
                        |                                   \n\
                     ___|____                                \n\n");        

            break;  

        case 4:
            printf("                                \n\
                         _______                     \n\
                        |    __|__                    \n\
                        |    | - -|                    \n\
                        |    |  ~ |                     \n\
                        |       |                        \n\
                        |       |                         \n\
                        |                                  \n\
                        |                                   \n\
                     ___|____                                \n\n");
        
        break; 

        case 3:
            printf("                                \n\
                         _______                     \n\
                        |    __|__                    \n\
                        |    | - -|                    \n\
                        |    |  ~ |                     \n\
                        |     / |                        \n\
                        |    /  |                         \n\
                        |                                  \n\
                        |                                   \n\
                     ___|____                                \n\n");

            break; 

        case 2:
            printf("                                \n\
                         _______                     \n\
                        |    __|__                    \n\
                        |    | - -|                    \n\
                        |    |  ~ |                     \n\
                        |     / |\\                      \n\
                        |    /  | \\                      \n\
                        |                                  \n\
                        |                                   \n\
                     ___|____                                \n\n");

            break;

        case 1:
            printf("                                \n\
                         _______                     \n\
                        |    __|__                    \n\
                        |    | - -|                    \n\
                        |    |  ~ |                     \n\
                        |     / |\\                      \n\
                        |    /  | \\                      \n\
                        |      /                           \n\
                        |     /                             \n\
                     ___|____                                \n\n");

            break;

        case 0: 
            printf("                                \n\
                         _______                     \n\
                        |    __|__                    \n\
                        |    | - -|                    \n\
                        |    |  ~ |                     \n\
                        |     / |\\                      \n\
                        |    /  | \\                      \n\
                        |      / \\                        \n\
                        |     /   \\                        \n\
                     ___|____                                \n\n");

            break; 
   
}
   
}