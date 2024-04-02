#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "stack.h"
#include "stack.c"
#include "queue.h"
#include "queue.c"
#include "set.h"
#include "set.c"
#include "list.h"
#include "list.c"
#include "oList.h"
#include "oList.c"

int menu(){
    printf("--------------------\n");
    printf("        Menu\n");
    printf("--------------------\n");
    printf(" [1] Stack\n");
    printf(" [2] Queue\n");
    printf(" [3] Set\n");
    printf(" [4] List\n");
    printf(" [5] Ordered List\n");
    printf(" [6] Exit\n");
    printf("--------------------\n");
    int choice;
    printf("Enter a choice: ");
    scanf("%d", &choice);
    return choice;
}

int stackSubMenu(){
    printf("--------------------\n");
    printf("       Stack\n");
    printf("--------------------\n");
    printf(" [1] Push\n");
    printf(" [2] Pop\n");
    printf(" [3] Peek\n");
    printf(" [4] Exit\n");
    printf("--------------------\n");
    int choice;
    printf("Enter a choice: ");
    scanf("%d", &choice);
    return choice;
}

int queueSubMenu(){
    printf("--------------------\n");
    printf("       Queue\n");
    printf("--------------------\n");
    printf(" [1] Insert\n");
    printf(" [2] Retrieve\n");
    printf(" [3] Show\n");
    printf(" [4] Exit\n");
    printf("--------------------\n");
    int choice;
    printf("Enter a choice: ");
    scanf("%d", &choice);
    return choice;
}

int setSubMenu(){
    printf("--------------------\n");
    printf("       Set\n");
    printf("--------------------\n");
    printf(" [1] Add\n");
    printf(" [2] Find\n");
    printf(" [3] Show Set\n");
    printf(" [4] Exit\n");
    printf("--------------------\n");
    int choice;
    printf("Enter a choice: ");
    scanf("%d", &choice);
    return choice;
}

int listSubMenu(){
    printf("--------------------\n");
    printf("       List\n");
    printf("--------------------\n");
    printf(" [1] Insert\n");
    printf(" [2] Extract\n");
    printf(" [3] Show Set\n");
    printf(" [4] Exit\n");
    printf("--------------------\n");
    int choice;
    printf("Enter a choice: ");
    scanf("%d", &choice);
    return choice;
}

int oListSubMenu(){
    printf("--------------------\n");
    printf("    Ordered List\n");
    printf("--------------------\n");
    printf(" [1] Insert\n");
    printf(" [2] Extract\n");
    printf(" [3] Show\n");
    printf(" [4] Exit\n");
    printf("--------------------\n");
    int choice;
    printf("Enter a choice: ");
    scanf("%d", &choice);
    return choice;
}

void actionChosen(){
    switch(menu()){
        case 1:
            stackImplementation();
            break;
        case 2:
            queueImplementation();
            break;
        case 3: 
            setImplementation();
            break;
        case 4:
            listImplementation();
            break;
        case 5: 
            orderedListImplementation();
            break;
        case 6:
            exit(0);
    }
}