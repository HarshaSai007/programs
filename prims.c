#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

struct Graph {
    int numVertices;
    int graph[MAX_VERTICES][MAX_VERTICES];
};

int minKey(int key[], int mstSet[], int numVertices) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < numVertices; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printMST(int parent[], struct Graph* graph) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < graph->numVertices; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph->graph[i][parent[i]]);
    }
}

void primMST(struct Graph* graph) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int mstSet[MAX_VERTICES];

    for (int i = 0; i < graph->numVertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < graph->numVertices - 1; count++) {
        int u = minKey(key, mstSet, graph->numVertices);
        mstSet[u] = 1;

        for (int v = 0; v < graph->numVertices; v++) {
            if (graph->graph[u][v] && mstSet[v] == 0 && graph->graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    struct Graph graph = {
        .numVertices = 5,
        .graph = {
            {0, 2, 0, 6, 0},
            {2, 0, 3, 8, 5},
            {0, 3, 0, 0, 7},
            {6, 8, 0, 0, 9},
            {0, 5, 7, 9, 0}
        }
    };

    primMST(&graph);

    return 0;
}
