#include <stdio.h>

#define MAX_SIZE 500

int is_valid(int x, int y, int w, int h) {
    return (x >= 0 && x < w && y >= 0 && y < h);
}

void dfs(int x, int y, int w, int h, int grid[MAX_SIZE][MAX_SIZE], int visited[MAX_SIZE][MAX_SIZE]) {
    if (!is_valid(x, y, w, h) || visited[x][y] || grid[x][y] == 0) {
        return;
    }

    visited[x][y] = 1;

    int directions[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    for (int i = 0; i < 8; i++) {
        int new_x = x + directions[i][0];
        int new_y = y + directions[i][1];
        dfs(new_x, new_y, w, h, grid, visited);
    }
}

int count_islands(int w, int h, int grid[MAX_SIZE][MAX_SIZE]) {
    int visited[MAX_SIZE][MAX_SIZE] = {0};
    int island_count = 0;

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                island_count++;
                dfs(i, j, w, h, grid, visited);
            }
        }
    }

    return island_count;
}

int main() {
    int w, h;
    scanf("%d %d", &w, &h);

    int grid[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = count_islands(w, h, grid);

    printf("%d\n", result);

    return 0;
}