#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef enum{TRUE, FALSE} boolean;
typedef enum{EMPTY = -1, DELETED = -2} status;
typedef int Dictionary[MAX];

void initDict(Dictionary D){
    for (int i = 0; i < MAX; i++){
        D[i] = EMPTY;
    }
}

int hash(int data){
    return data % MAX;
}

void insert(Dictionary D, int data){
    int sindex = hash(data); //starting index
    int fdel = -1; //to hold the index of possible deleted spaces
    int findex = (sindex + MAX - 1) % MAX; //index to stop looking at
    int i;
    for (i = sindex; i != findex && D[i] != data && D[i] != EMPTY; i = (i + 1) % MAX){
        if (fdel == -1 && D[i] == DELETED){
            fdel = i;
        }
    }
    if(D[i] == EMPTY || D[i] == DELETED){
        D[(fdel == -1) ? i : fdel] = data;
    }
}

void delete(Dictionary D, int data){
    int sindex = hash(data);
    int stop = (sindex + MAX - 1) % MAX;
    int i;
    for (i = sindex; i != stop && D[i] != EMPTY && D[i] != data; i = (i + 1) % MAX){}
    if (D[i] == data){
        D[i] = DELETED;
    }
}