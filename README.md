# Knight’s Tour (C) — My First Project

This is my first C project. It explores the Knight’s Tour on a 5×5 chessboard:  
given a starting square, the program builds a move tree and tries to find a path that visits every cell exactly once.  
If a full tour is found, it prints the board with step indices; otherwise, it reports that no tour exists.

## Files (updated names)
- `mainProject.c` — program entry; reads the start position and runs the search
- `characters.h` — header with types, constants, and function prototypes
- `helper.c` — list/tree utilities (`createNewTNode`, list ops, etc.)
- `knight_moves.c` — (renamed from `Q1.c`) implements `validKnightMoves`
- `board_display.c` — (renamed from `Q2.c`) implements `display`, `printMat`, `updateMat`, `eraseDupFromList`
- `path_tree.c` — (renamed from `Q3.c`) implements `findAllPossibleKnightPaths` and helper
- `knight_tour.c` — (renamed from `Q4.c`) implements `findKnightPathCoveringAllBoard` and helper

> Only the four files above were renamed; all other filenames remain as in the original project.

## Features
- 5×5 board with coordinates `A..E` (rows) and `1..5` (columns)
- Precomputation of all legal knight moves for every square
- Move-tree construction from a given start position
- Depth-first search for a full board-covering path (Knight’s Tour)
- Duplicate-position cleanup before printing
- Console output of the final indexed board

## Build
**Visual Studio (IDE)**
Create a new Console C project.
Add all .c files and the header characters.h.
Build the project to produce the executable.

---


## Run
The program expects a starting square as letter + number (for example C3).
Valid input ranges:
Rows: A to E
Columns: 1 to 5

---

## Examples:
Input:  C3
Output: (either a numbered 5×5 grid or the message "No knight's tour")
If a tour is found, the output is a table where each visited cell is numbered by the step order, e.g.:

    1  2  3  4  5
|A| 7| 0| 9| 0|11|
|B| 0|13| 0|15| 0|
|C| 5| 0| 3| 0| 1|
|D| 0|17| 0|19| 0|
|E|21| 0|23| 0|25|
(Values are illustrative; actual indices depend on the found path.)
