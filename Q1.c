#include "character.h"

// -- this function return arry of pointers that point to all possible moves of the knight by according to each slot --//

chessPosArray*** validKnightMoves()
{
    int index, newRow, newCol;
    int row, col;
    chessPosArray*** res;

    res = (chessPosArray***)malloc(BOARD_SIZE * sizeof(chessPosArray**));
    if (res == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }

    for (row = 0; row < BOARD_SIZE; row++) { // build the two-dimensional array of pointers 
        res[row] = (chessPosArray**)malloc(BOARD_SIZE * sizeof(chessPosArray*));
        for (col = 0; col < BOARD_SIZE; col++) {
            res[row][col] = (chessPosArray*)malloc(sizeof(chessPosArray));
            res[row][col]->positions = (chessPos*)malloc(8 * sizeof(chessPos));
            res[row][col]->size = 0;

            int possibleMoves[POSSIBLE_OPTIONS][POSITION] = { // build array of the legal steps 
                {row - 2, col + 1}, {row - 1, col + 2}, {row + 1, col + 2}, {row + 2, col + 1},
                {row + 2, col - 1}, {row + 1, col - 2}, {row - 1, col - 2}, {row - 2, col - 1}

            };

            for (index = 0; index < POSSIBLE_OPTIONS; index++) { //check if the position is legal 
                newRow = possibleMoves[index][0];
                newCol = possibleMoves[index][1];
                if ((newRow >= 0 && newRow < BOARD_SIZE) && (newCol >= 0 && newCol < BOARD_SIZE)) {
                    res[row][col]->positions[res[row][col]->size][0] = 'A' + newRow;
                    res[row][col]->positions[res[row][col]->size][1] = '1' + newCol;
                    res[row][col]->size++;
                }
            }
            res[row][col]->positions = (chessPos*)realloc(res[row][col]->positions, res[row][col]->size * sizeof(chessPos));
        }
    }
    return res;
}