#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define INF 9999

typedef int AdjMatrix[MAX][MAX];
typedef enum { FALSE, TRUE } Boolean;

int* dijkstras(AdjMatrix M, int root);
void displayDjk(int arr[], int root);
void initMatrix(AdjMatrix M);
void insertEdge(AdjMatrix M, int edge[3]);
void displayMatrix(AdjMatrix M);

int main() {
    int edges[][3] = {
        {0, 1, 2},  // Edge from 0 to 1 with weight 2
        {0, 2, 4},  // Edge from 0 to 2 with weight 4
        {1, 2, 1},  // Edge from 1 to 2 with weight 1
        {1, 3, 7},  // Edge from 1 to 3 with weight 7
        {2, 4, 3},  // Edge from 2 to 4 with weight 3
        {4, 3, 2}   // Edge from 4 to 3 with weight 2
    };

    int numOfEdges = sizeof(edges) / sizeof(edges[0]);
    
    AdjMatrix M;
    initMatrix(M);

    for(int i = 0; i < numOfEdges; i++) {
        insertEdge(M, edges[i]);
    }

    displayMatrix(M);

    int root = 0;
    int *djk = dijkstras(M, root);
    displayDjk(djk, root);

    return 0;
}

int* dijkstras(AdjMatrix M, int start){
    Boolean visited[MAX] = { FALSE }; // S
    int* weightFromRoot = (int*) malloc (MAX * sizeof(int)); // D

    for (int i = 0; i < MAX; i++){
        weightFromRoot[i] = M[start][i];
    } 
    weightFromRoot[start] = 0;

    for (int i = 0; i < MAX; i++){
        // find vertex with minimum weight
        // for reference:
        // v = 1 2 3 4 5
        // s = F F F F F

        int minWeight = INF, minIndex = -1;

        for (int j = 0; j < MAX; j++){
            if (visited[j] == FALSE && weightFromRoot[j] < minWeight){
                minIndex = j;
                minWeight = weightFromRoot[j];
            }
        }

        if (minIndex != -1){
            visited[minIndex] = TRUE;

            for (int j = 0; j < MAX; j++){
                if (minWeight + M[minIndex][j] < weightFromRoot[j]){
                    weightFromRoot[j] = minWeight + M[minIndex][j];
                }
            }
        }

    }
    return weightFromRoot;
}




void displayDjk(int arr[], int root) {
    printf("\nDijkstra's Paths from %d:\n", root);
    for(int i = 0; i < MAX; i++) {
        
        printf("Path from %d to %d: ", root, i);
        (arr[i] == INF) ? printf("NONE\n") : printf("%d\n", arr[i]);
    }
}

void initMatrix(AdjMatrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            M[i][j] = INF; // initialized to INF if not adjacent
        }
    }
}

void insertEdge(AdjMatrix M, int edge[3]) {
    M[edge[0]][edge[1]] = edge[2];
    M[edge[1]][edge[0]] = edge[2];
}

void displayMatrix(AdjMatrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            (M[i][j] == INF) ? printf("INF ") : printf("%3d ", M[i][j]);
        }
        printf("\n");
    }
}