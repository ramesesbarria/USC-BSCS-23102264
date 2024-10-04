#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char letter;
    struct node* next;
} *List;

void insertLast(List* L, char letter);
void insertFirstIfUnique(List *L, char letter);
void display(List L);
int lengthOfSentence(char sentence[]);

int main(){

    char sentence[100] = {};
    printf("What sentence do you want to store? Enter: ");
    scanf("%[^\n]", sentence);
    int length = lengthOfSentence(sentence);

    List L = NULL;

    for (int i = 0; i < length; i++){
        insertLast(&L, sentence[i]);
    }

    display(L);

    char letter;
    printf("\nInsert a unique letter: ");
    scanf(" %c", &letter);
    insertFirstIfUnique(&L, letter);
    display(L);
}

int lengthOfSentence(char sentence[]){
    int count = strlen(sentence);
    return count;
}

void insertLast(List* L, char letter){
    List* trav = L;
    for (;(*trav) != NULL; trav = &(*trav)->next){}
    (*trav) = (List)malloc(sizeof(struct node));
    (*trav)->letter = letter;
    (*trav)->next = NULL;
}

void insertFirstIfUnique(List *L, char letter){
    List* trav = L;
    for (;(*trav) != NULL && (*trav)->letter != letter; trav = &(*trav)->next){}
    if ((*trav) == NULL){
        List newNode = (List) malloc (sizeof(struct node));
        newNode->letter = letter;
        newNode->next = *L;
        *L = newNode;
    }
}

void display(List L){
    List trav = L;
    printf("This is printed from a linked list: ");
    for (;trav != NULL; trav = trav->next){
        printf("%c", trav->letter);
    }
}








