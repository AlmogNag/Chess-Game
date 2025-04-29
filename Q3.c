#include "character.h"

// -- this function build a tree that with all the optional path that the knight can do from each position -- //
pathTree findAllPossibleKnightPaths(chessPos* startingPosition) {
    pathTree tr;
    chessPosArray*** moves;
    int row, col;

    bool isSteppedOn[BOARD_SIZE][BOARD_SIZE] = { false };

    tr.root = createNewTNode(*startingPosition);

    markSteps(isSteppedOn, *startingPosition); // mark the place that we got

    moves = validKnightMoves();
    findAllPossibleKnightPathsHelper(tr.root, isSteppedOn, moves);

    return tr;
}


void findAllPossibleKnightPathsHelper(treeNode* root, bool steps[BOARD_SIZE][BOARD_SIZE], chessPosArray*** knightMoves) {
    int i;
    int row, col;
    int innerRow, innerCol; // will contain the position from the optinal moves 
    treeNode* newNode;
    treeNodeListCell* newCell;

    row = root->position[0] - 'A';
    col = root->position[1] - '1';


    chessPosArray* moves = knightMoves[row][col];

    for (i = 0; i < moves->size; i++) {
        chessPos currPos;
        currPos[0] = moves->positions[i][0];
        currPos[1] = moves->positions[i][1];

        int innerRow = currPos[0] - 'A';
        int innerCol = currPos[1] - '1';

        if (!steps[innerRow][innerCol]) { // check if the specific position is false - means that we dont write this option and we and to add this option to the list 

            newNode = createNewTNode(currPos);

            newCell = createNewListCellNode(newNode, NULL);
            insertNodeToEndCellList(&root->next_possible_positions, newCell);

            steps[innerRow][innerCol] = true;
            findAllPossibleKnightPathsHelper(newNode, steps, knightMoves);
            steps[innerRow][innerCol] = false;

        }

    }

}

// -- this function change the bool array, every position that the Knight was in we change it to true to avois repetittion -- //
void markSteps(bool isSteppedOn[BOARD_SIZE][BOARD_SIZE], chessPos data) {
    int row, col;

    row = data[0] - 'A';
    col = data[1] - '1';
    isSteppedOn[row][col] = true;
}