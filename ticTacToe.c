#include <stdio.h> //I did all this with one library :D:D:D::D:D:D It makes me happy because I usually use other libraries as a crutch.

int main(void)
{
    //creating the front end board (the one with characters the user sees)
    char boardFront[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};

    //creating the back end board (the one with numbers the computer sees)
    int boardBack[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    //creating the variable that will determine whose turn it is and what is placed on boardBack
    int player = 0;

    //creating the variable that will hold which position the user inputs
    int pos = -1;

    //creating the variable that will quit the game if someone wins
    int quit = 0;

    //displaying refrence board for extra UX points
    printf("Board position refrences\n1 2 3\n4 5 6\n7 8 9\n\n");

    //game logic vvv
    while (!(boardBack[0] && boardBack[1] && boardBack[2] && boardBack[3] && boardBack[4] && boardBack[5] && boardBack[6] && boardBack[7] && boardBack[8])) //Tie detection
    {
        //determining whose turn it is
        if (!(player == 1))
        {
            //notifying user that it is X's turn
            printf("X's turn\n");

            //setting player variable to appropriate number for X
            player = 1;
        }
        else
        {
            //notifying user that it is O's turn
            printf("O's turn\n");

            //setting player variable to appropriate number for O
            player = 2;
        }

        //Prompting user for position
        while (pos < 0 || pos > 8)
        {
            //prompting/reprompting user for position
            printf("Position: ");

            //getting the computer to read what the user inputed
            scanf("%i", &pos);

            //makes user input array-friendly
            pos = pos - 1;

            //Checking if inputed position is a valid one
            if ((pos < 0 || pos > 8) || boardBack[pos])
            {
                //message telling user that their position is invalid
                printf("\nSorry! That isn't a valid position! Please try again.\n");

                //guarantees that user will be reprompted
                pos = -1;
            }
        }

        //updating boardBack with valid inputed position from user
        boardBack[pos] = player;

        //updating boardFront with valid inputed position from user
        if (player == 1)
        {
            //used when it is X's turn
            boardFront[pos] = 'X';
        }
        else
        {
            //used when it is O's turn
            boardFront[pos] = 'O';
        }

        //helps with program not having a seizure
        pos = -1;

        //win detection
        if ((boardBack[0] == 1 && boardBack[1] == 1 && boardBack[2] == 1) || (boardBack[3] == 1 && boardBack[4] == 1 && boardBack[5] == 1) || (boardBack[6] == 1 && boardBack[7] == 1 && boardBack[8] == 1) || (boardBack[0] == 1 && boardBack[4] == 1 && boardBack[8] == 1) || (boardBack[2] == 1 && boardBack[4] == 1 && boardBack[6] == 1) || (boardBack[0] == 1 && boardBack[3] == 1 && boardBack[6] == 1) || (boardBack[1] == 1 && boardBack[4] == 1 && boardBack[7] == 1) || (boardBack[2] == 1 && boardBack[5] == 1 && boardBack[8] == 1))
        {
            //win detection for X ^^^

            //messages user if X wins
            printf("\n\n\nX wins!");

            //sets quit variable to appropriate number so that the program ends after somebody wins
            quit++;
        }
        else if ((boardBack[0] == 2 && boardBack[1] == 2 && boardBack[2] == 2) || (boardBack[3] == 2 && boardBack[4] == 2 && boardBack[5] == 2) || (boardBack[6] == 2 && boardBack[7] == 2 && boardBack[8] == 2) || (boardBack[0] == 2 && boardBack[4] == 2 && boardBack[8] == 2) || (boardBack[2] == 2 && boardBack[4] == 2 && boardBack[6] == 2) || (boardBack[0] == 2 && boardBack[3] == 2 && boardBack[6] == 2) || (boardBack[1] == 2 && boardBack[4] == 2 && boardBack[7] == 2) || (boardBack[2] == 2 && boardBack[5] == 2 && boardBack[8] == 2))
        {
            //win detection for O ^^^

            //messages user if O wins
            printf("\n\n\nO wins!");

            //sets quit variable to appropriate number so that the program ends after somebody wins
            quit++;
        }

        //displaying the board
        printf("\n%c %c %c\n%c %c %c\n%c %c %c\n\n", boardFront[0], boardFront[1], boardFront[2], boardFront[3], boardFront[4], boardFront[5], boardFront[6], boardFront[7], boardFront[8]);

        //quiting after a player wins
        if (quit)
        {
            return 0;
        }
    }
}
