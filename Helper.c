#include "character.h"

void insertDataToEndList(chessPosList* lst, char letter, char number)
{
    chessPosCell* newTail;
    newTail = createNewListNode(letter, number, NULL);
    insertNodeToEndList(lst, newTail);
}

void insertNodeToEndList(chessPosList* lst, chessPosCell* tail)
{
    if (isEmptyList(lst))
        lst->head = lst->tail = tail;
    else {
        lst->tail->next = tail;
        lst->tail = tail;
    }
    tail->next = NULL;
}

chessPosCell* createNewListNode(char letter, char number, chessPosCell* next)
{
    chessPosCell* res;
    res = (chessPosCell*)malloc(sizeof(chessPosCell));
    res->position[0] = letter;
    res->position[1] = number;
    res->next = next;
    return res;
}

bool isEmptyList(chessPosList* lst)
{
    return lst->head == NULL;
}

void makeEmptyList(chessPosList* lst)
{
    lst->head = lst->tail = NULL;
}

void printList(chessPosList* lst)
{
    chessPosCell* curr = lst->head;
    while (curr != NULL) {
        printf("%c%c      ", curr->position[0], curr->position[1]);
        curr = curr->next;
    }
}

treeNode* createNewTNode(chessPos data) {
    treeNode* res;
    res = (treeNode*)malloc(sizeof(treeNode));
    if (res == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    res->position[0] = data[0];
    res->position[1] = data[1];
    return res;
}

// -- this function change the bool array, every position that the Knight was in we change it to true to avois repetittion -- //
void markSteps(bool isSteppedOn[BOARD_SIZE][BOARD_SIZE], chessPos data) {
    int row, col;

    row = data[0] - 'A';
    col = data[1] - '1';
    isSteppedOn[row][col] = true;
}



// -- this function create the list of the possible moves from specific location -- // 
treeNodeListCell* createNewListCellNode(treeNode* root, treeNodeListCell* next)
{
    treeNodeListCell* res;
    res = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
    if (res == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }

    res->node = root;
    res->next = next;
    return res;
}


void insertNodeToEndCellList(treeNodeList* lst, treeNodeListCell* tail)
{
    if (isEmptyCellList(lst))
        lst->head = lst->tail = tail;
    else {
        lst->tail->next = tail;
        lst->tail = tail;
    }
    tail->next = NULL;
}

bool isEmptyCellList(treeNodeList* lst)
{
    return lst->head == NULL;
}