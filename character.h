#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define BOARD_SIZE 5
#define POSSIBLE_OPTIONS 8
#define POSITION 2
#define ROW 0
#define COL 0
#define STARTROW 'A'
#define ENDROW 'E'
#define STARTCOL 1
#define ENDCOL 5
#define MAX_HEIGHT 24

typedef char chessPos[2];

typedef struct _treeNode treeNode;

typedef struct _treeNodeListCell treeNodeListCell;

typedef struct _treeNodeList {
    treeNodeListCell* head;
    treeNodeListCell* tail;
} treeNodeList;

typedef struct _treeNodeListCell {
    treeNode* node;
    struct _treeNodeListCell* next;
} treeNodeListCell;

typedef struct _treeNode {
    chessPos position;
    treeNodeList next_possible_positions; // רשימת מיקומים 
} treeNode;


typedef struct _pathTree {
    treeNode* root;
} pathTree;

typedef struct _chessPosArray {
    unsigned int size;
    chessPos* positions;
} chessPosArray;

typedef struct _chessPosCell {
    chessPos position;
    struct _chessPosCell* next;
} chessPosCell;

typedef struct _chessPosList {
    chessPosCell* head;
    chessPosCell* tail;
} chessPosList;



// prototypes
chessPosArray*** validKnightMoves();
void display(chessPosList* lst);
void insertDataToEndList(chessPosList* lst, char letter, char number);
void insertNodeToEndList(chessPosList* lst, chessPosCell* tail);
chessPosCell* createNewListNode(char letter, char number, chessPosCell* next);
bool isEmptyList(chessPosList* lst);
void makeEmptyList(chessPosList* lst);
void printList(chessPosList* lst);
void printMat(int mat[BOARD_SIZE][BOARD_SIZE]);
void updateMat(int mat[BOARD_SIZE][BOARD_SIZE], chessPosList* lst);
void eraseDupFromList(chessPosList* lst, int mat[BOARD_SIZE][BOARD_SIZE]);
void printTree(pathTree pt);
void printTreeHelper(treeNode* root, int depth);
treeNode* createNewTNode(chessPos data);
pathTree findAllPossibleKnightPaths(chessPos* startingPosition);
void markSteps(bool isSteppedOn[BOARD_SIZE][BOARD_SIZE], chessPos data);
void findAllPossibleKnightPathsHelper(treeNode* root, bool steps[BOARD_SIZE][BOARD_SIZE], chessPosArray*** knightMoves);
treeNodeListCell* createNewListCellNode(treeNode* root, treeNodeListCell* next);
void insertNodeToEndCellList(treeNodeList* lst, treeNodeListCell* tail);
bool isEmptyCellList(treeNodeList* lst);
chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree);
void findKnightPathCoveringAllBoardHelper(int height, treeNode* root, chessPosList* res);
void insertNodeToStartList(chessPosList* lst, chessPosCell* head);
void insertDataToStartList(chessPosList* lst, chessPos data);
void freePathTree(pathTree pTree);
void freePathTreeHelper(treeNode * root);
