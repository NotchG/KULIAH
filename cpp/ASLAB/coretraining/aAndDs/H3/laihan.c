#include <stdio.h>
#define SIZE 4

//

typedef struct Edge {
    int source;
    int destination;
    int weight;
} Edge;

int main() {
    Edge edges[10];
    int edgeCount = 0;
    int graph[SIZE][SIZE] = {
        {0,5,10,-1},
        {5,0,4,11},
        {10,4,0,5},
        {-1, 11,5,0}
    };

    for (int i = 0;i < SIZE;i++) {
        for (int j = 0;j < SIZE;j++) {
            if (graph[i][j] != 0) {
                edges[edgeCount].destination = j;
                edges[edgeCount].source = i;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }

    int visited[SIZE] = {0};

    int totalEdge = 0, possibleEdge = 0;

    //PRIM

    puts("Prim: ");
    visited[0] = 1;
    while (totalEdge < SIZE - 1) {
        int minWeight = 999999;
        int src = 0,dest = 0;
        for (int i = 0;i < edgeCount;i++){
            if (edges[i].weight < minWeight && visited[edges[i].source] == 1 && visited[edges[i].destination] == 0 && edges[i].weight != -1) {
                minWeight = edges[i].weight;
                src = edges[i].source;
                dest = edges[i].destination;
            }
        }
        printf("Src: %d ----> Dest: %d with weight %d\n", src, dest, minWeight);
        visited[src] = 1;
        visited[dest] = 1;
        totalEdge++;
    }

    return 0;
}