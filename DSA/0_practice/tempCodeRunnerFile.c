    int numElements = sizeof(chars) / sizeof(chars[0]);

    for (int i = 0; i < numElements; i++){
        insertLast(&L, chars[i]);
    }

    insertFirst(&L, 'A');
    InsertAfterPos(&L, 'B');
    deleteFirst(&L);
    countList(&L);
    displayList(L);
    deleteChar(&L, 'B');
    displayList(L);    
    findMember(&L, 'H');
    findMember(&L, 'E');
}

// Implement operations

void insertFirst(List *L, char data){
    List new_node = (List)malloc(sizeof(ctype));
    new_node->elem = data;
    new_node->link = *L;
    *L = new_node;
}

void insertLast(List *L, char data){
    List *p = L;
    while (*p != NULL) {
        p = &(*p)->link;
    }
    *p = (List)malloc(sizeof(ctype));
    (*p)->elem = data;
    (*p)->link = NULL;
}

void InsertAfterPos(List *L, char data){
    List *p = L;
    int choice;
    printf("Character ");
    countList(p);
    printf("Pick a number to place the character after that position\n");
    printf("Picking 0 places the character at the first position: ");
    scanf("%d", &choice);
    
    if (choice == 0){