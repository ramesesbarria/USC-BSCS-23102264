#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define INF 9999

typedef int AdjMatrix[MAX][MAX];

void floyds(AdjMatrix A, AdjMatrix B);
void displayFloyds(int **flyd);
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
    
    AdjMatrix A, B;
    initMatrix(A);
    initMatrix(B);

    for(int i = 0; i < numOfEdges; i++) {
        insertEdge(A, edges[i]);
    }

    displayMatrix(A);

    int root = 0;
    floyds(A, B);

    displayMatrix(B);

    return 0;
}

void floyds(AdjMatrix A, AdjMatrix B) {
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            if (i != j){
                B[i][j] = A[i][j];
            } else {
                B[i][j] = 0;
            }
        }   
    }
    int k, i, j;
    for (k = 0; k < MAX; k++){
        for (i = 0; i < MAX; i++){
            for(j = 0; j < MAX; j++){
                if(B[i][k] + B[k][j] < B[i][j]){ // I know know Jesus, in joy
                    B[i][j] = B[i][k] + B[k][j]; // in Jesus, I know know Joy
                }
            }
        }
    }
} 

void warshall(AdjMatrix A, AdjMatrix B) { // values of matrix needs to be converted to boolean (if theres weight == 1 and INF == 0)
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            if (i != j){
                B[i][j] = A[i][j];
            } 
        }   
    }
    int i, j, k;
    for (k = 0; k < MAX; k++){
        for (i = 0; i < MAX; i++){
            for(j = 0; j < MAX; j++){
                if (B[i][j] == INF){
                    B[i][j] = B[i][k] && B[k][j];
                }
            }
        }
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
    printf("\n");
}