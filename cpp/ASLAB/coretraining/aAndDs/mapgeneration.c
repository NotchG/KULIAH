#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

// Define directions (up, down, left, right)
const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Function to check if a given cell is within bounds
bool isInside(int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
}

// Function to print the maze
void printMaze(int maze[WIDTH][HEIGHT]) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (maze[i][j] == 1) {
                printf("  "); // Path
            } else {
                printf("██"); // Wall
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if there is a path from start to end
bool isPathExists(int maze[WIDTH][HEIGHT], int startX, int startY, int endX, int endY) {
    if (!isInside(startX, startY) || !isInside(endX, endY) || maze[startX][startY] == 0 || maze[endX][endY] == 0) {
        return false; // Invalid start or end positions
    }

    // DFS to check if there is a path from start to end
    bool visited[WIDTH][HEIGHT] = {false};
    visited[startX][startY] = true;

    for (int i = 0; i < 4; i++) {
        int newX = startX + directions[i][0];
        int newY = startY + directions[i][1];

        if (isInside(newX, newY) && maze[newX][newY] == 1 && !visited[newX][newY]) {
            if (newX == endX && newY == endY) {
                return true; // Path found
            } else if (isPathExists(maze, newX, newY, endX, endY)) {
                return true; // Continue searching
            }
        }
    }

    return false; // No path found
}

// Function to generate a maze using the Hunt and Kill algorithm
void huntAndKill(int maze[WIDTH][HEIGHT]) {
    srand(time(NULL));

    // Initialize maze with walls
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            maze[i][j] = 0;
        }
    }

    // Start carving paths
    int currentX = rand() % WIDTH;
    int currentY = rand() % HEIGHT;
    maze[currentX][currentY] = 1; // Mark the starting cell as visited

    while (1) {
        // Hunt phase
        int found = 0;

        for (int i = 0; i < WIDTH && !found; i++) {
            for (int j = 0; j < HEIGHT && !found; j++) {
                if (maze[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int newX = i + directions[k][0];
                        int newY = j + directions[k][1];

                        if (isInside(newX, newY) && maze[newX][newY] == 1) {
                            // Carve a path to the nearest visited cell
                            maze[i][j] = 1;
                            found = 1;
                            break;
                        }
                    }
                }
            }
        }

        if (!found) {
            break; // No unvisited cells found, exit the loop
        }

        // Kill phase
        while (1) {
            int direction = rand() % 4;
            int newX = currentX + directions[direction][0];
            int newY = currentY + directions[direction][1];

            if (isInside(newX, newY) && maze[newX][newY] == 0) {
                maze[currentX][currentY] = 1; // Mark the current cell as visited
                maze[newX][newY] = 1;          // Carve a path
                currentX = newX;
                currentY = newY;
                break;
            }
        }
    }
}

int main() {
    int maze[WIDTH][HEIGHT];

    huntAndKill(maze);
    printMaze(maze);

    int startX = 0;
    int startY = 0;
    int endX = WIDTH - 1;
    int endY = HEIGHT - 1;

    if (isPathExists(maze, startX, startY, endX, endY)) {
        printf("There is a path from (%d, %d) to (%d, %d).\n", startX, startY, endX, endY);
    } else {
        printf("There is no path from (%d, %d) to (%d, %d).\n", startX, startY, endX, endY);
    }

    return 0;
}
