#include "character.h"

// -- this function get a list of position and remove duplicates values and then display chess board that the values is numbered according to the updat list 
void display(chessPosList* lst)
{
    int counterArr[BOARD_SIZE][BOARD_SIZE] = { 0 };

    eraseDupFromList(lst, counterArr);

    updateMat(counterArr, lst);

    printMat(counterArr);
}


void printMat(int mat[BOARD_SIZE][BOARD_SIZE])
{
    int i, j, index;
    char letter;

    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i + 1);
    }
    printf("\n");

    for (letter = 'A'; letter < 'A' + BOARD_SIZE; letter++) {
        printf("|%c|", letter);
        for (j = 0; j < BOARD_SIZE; j++) {
            index = letter - 'A';
            printf("%2d|", mat[index][j]);
        }
        printf("\n");
    }
}

//  -- this function numbered the place on the board according to the list -- //
void updateMat(int mat[BOARD_SIZE][BOARD_SIZE], chessPosList* lst)
{
    int row;
    int col;
    int placeCounter = 1;
    chessPosCell* curr;

    curr = lst->head;

    while (curr != NULL) {
        row = curr->position[0] - 'A';
        col = curr->position[1] - '1';
        mat[row][col] = placeCounter;
        placeCounter++;
        curr = curr->next;
    }
}

// -- this function is erase the duplicat values from the list --//
void eraseDupFromList(chessPosList* lst, int mat[BOARD_SIZE][BOARD_SIZE])
{
    int row, col;

    chessPosCell* curr, * prev;

    prev = lst->head;
    curr = prev->next;

    // check the first node
    row = prev->position[0] - 'A';
    col = prev->position[1] - '1';
    mat[row][col]++;

    while (curr != NULL) { // check all the noded on the list 
        row = curr->position[0] - 'A';
        col = curr->position[1] - '1';

        if (mat[row][col] == 0) {
            mat[row][col]++;
            prev = prev->next;
            curr = curr->next;
        }
        else { // free the dupicate value
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        }
    }
}
