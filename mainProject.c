#include"character.h"


int main()
{
    char chessBoard[BOARD_SIZE][BOARD_SIZE];
    chessPosArray*** res = validKnightMoves();

    int numPLace;
    char letterPlace;


    scanf("%c%d", &letterPlace, &numPLace);

    if (letterPlace < STARTROW || letterPlace > ENDROW) {
        printf("Invalid input");
        exit(1);
    }

    if (numPLace < STARTCOL || numPLace > ENDCOL) {
        printf("Invalid input");
        exit(1);
    }



    chessPos startPos = { letterPlace, numPLace + '0' };
    pathTree allMoves;

    allMoves.root = createNewTNode(startPos);

    chessPosList* fullPath = findKnightPathCoveringAllBoard(&allMoves);
    if (fullPath->head == NULL) {
        printf("No knight's tour");
    }
    else {
        display(fullPath);
    }

    freePathTree(allMoves);

    return 0;
}

