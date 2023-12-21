#include <stdio.h>
#define SIZE 4
#define ROWS 20
#define COLS 20

typedef struct Cell {
    int up;
    int down;
    int left;
    int right;
} Cell;

typedef struct Wall {
    int source;
    int destination;
} Wall;

typedef struct Subset {
    int parent;
    int rank;
} Subset;

Cell maze[ROWS][COLS];
Wall walls[ROWS * COLS * 2];
Subset subsets[ROWS * COLS];

void initSubset() {
    int length = ROWS * COLS;
    for (int i = 0;i < length;i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
}

int initWalls() {
    int count = 0;

    for (int i = 0;i < ROWS;i++) {
        for (int j = 0;j < COLS;j++) {
            if (i < ROWS - 1) {
                walls[count].source = i * COLS + j;
                walls[count].destination = (i+1) * COLS + j;
                count++;
            }
            if (i < COLS - 1) {
                walls[count].source = i * COLS + j;
                walls[count].destination = i * COLS + (j+1);
                count++;
            }
        }
    }
    return count;
}

void initMaze() {
    for (int i = 0;i < ROWS;i++) {
        for (int j = 0;j < COLS;j++) {
            maze[i][j].up = i > 0 ? 1 : 0;
            maze[i][j].down = i < ROWS - 1 ? 1 : 0;
            maze[i][j].left = j > 0 ? 1 : 0;
            maze[i][j].right = j < COLS - 1 ? 1 : 0;
        }
    }
}

int find(Subset subsets[], int curr) {
    if (subsets[curr].parent != curr) {
        subsets[curr].parent = find(subsets, subsets[curr].parent);
    }

    return subsets[curr].parent;
}

void unionSets(Subset subsets[], int src, int dest) {
    int srcRoot, destRoot;
    srcRoot = find(subsets, src);
    destRoot = find(subsets, dest);

    if (subsets[srcRoot].rank < subsets[destRoot].rank) {
        subsets[srcRoot].parent = destRoot;
    } else if (subsets[srcRoot].rank > subsets[destRoot].rank) {
        subsets[destRoot].parent = srcRoot;
    } else {
        subsets[destRoot].parent = srcRoot;
        subsets[srcRoot].rank++;
    }
}

int main() {
    return 0;
}