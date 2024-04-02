#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void printThis(struct node *trav)
{
    while(trav->next!=NULL)
    {
        trav = trav->next;
        printf("%i\n",trav->data);
    }
}
void insertAtEnd(struct node *trav, int newData)
{
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = newData;
    new->next=NULL;
    if(trav->next == NULL)
    {
        trav->next = new;
    }
    else
    {
        for(;trav->next!=NULL; trav=trav->next){}
        trav->next = new;
    }
}

void insertAtStart(struct node **head, int newData)
{
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = newData;
    new->next = *head;
    *head = new;
}

void insertSorted(struct node *head, int newData)
{
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = newData;
    new->next = NULL;
    if (head == NULL || head->data >= newData)
    {
        new->next = head;
        head = new;
    }
    else
    {
        struct node *current = head;
        while (current->next != NULL && current->next->data < newData)
        {
            current = current->next;
        }
        new->next = current->next;
        current->next = new;
    }
}

void deleteByValue(struct node **head, int value)
{
    struct node *temp = *head, *prev;
    if (temp != NULL && temp->data == value)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

void deleteByLocation(struct node **head, int position)
{
    if (*head == NULL)
        return;
    struct node *temp = *head;
    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
        return;
    struct node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int main() {
    struct node *head = (struct node *) malloc(sizeof(struct node));
    insertAtEnd(head, 1);
    insertAtEnd(head, 3);
    insertAtEnd(head, 5);
    insertAtEnd(head, 7);
    insertAtEnd(head, 9);
    printThis(head);

    printf("Inserting 4 at start:\n");
    insertAtStart(&head, 4);
    printThis(head);

    printf("Inserting 6 in sorted order:\n");
    insertSorted(head, 6);
    printThis(head);

    printf("Deleting node with value 4:\n");
    deleteByValue(&head, 4);
    printThis(head);

    printf("Deleting node at position 2:\n");
    deleteByLocation(&head, 2);
    printThis(head);

    return 0;
}
