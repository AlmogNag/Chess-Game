#include "character.h"

// -- this function check if there is a full path from specific position, if we can move across all of the board if it found full path we return list with all moves else we return NULL -- //
chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree) {
    chessPosList* res;
    int height = MAX_HEIGHT; // height should be adapted according to the chess board size and path depth

    res = (chessPosList*)malloc(sizeof(chessPosList));
    if (res == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    makeEmptyList(res);

    pathTree tr = findAllPossibleKnightPaths(&path_tree->root->position); // use the tree of all the options to find the full path 
    findKnightPathCoveringAllBoardHelper(height, tr.root, res);
    return res;
}

void findKnightPathCoveringAllBoardHelper(int height, treeNode* root, chessPosList* res) {
    treeNodeListCell* curr;

    if (height == 0) { // found full path 
        insertDataToStartList(res, root->position); // insert the last move into list 
    }

    if (root == NULL) {
        return;
    }

    else {
        curr = root->next_possible_positions.head;
        while (curr != NULL) {
            findKnightPathCoveringAllBoardHelper(height - 1, curr->node, res);
            if (!isEmptyList(res)) { // check if res list is not empty
                insertDataToStartList(res, root->position);
                return;
            }
            curr = curr->next;
        }
    }
}