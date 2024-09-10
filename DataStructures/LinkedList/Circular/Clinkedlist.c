#include <stdio.h>
#include <stdlib.h>
#include "Clinkedlist.h"

struct Circularlinkedlist * createClinked ()
{
    struct Circularlinkedlist *temp;
    temp = (struct Circularlinkedlist *) malloc (sizeof(struct Circularlinkedlist));
    if (temp == NULL)
    {
        printf("Error creating circular linked list \n");
        return NULL;
    }
    temp->head = NULL;
    return temp;
}

int isEmpty (struct Circularlinkedlist *linked)
{
    if (linked->head == NULL)
        return 1;
    return 0;
}

int getSize (struct Circularlinkedlist *linked)
{
    int sz = 0;
    if (isEmpty(linked))
        return sz;
    else 
    {
        struct Node *temp = linked->head;
        do
        {
            sz ++;
            temp = temp->next;   
        } while (temp!=linked->head);
        return sz;
    }
}

void display(struct Circularlinkedlist *linked) 
{
    if (isEmpty(linked))
    {
        printf("Circular linked list is empty \n");
        return;
    }
    struct Node *temp = linked->head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp!=linked->head);
    printf("\n");
}

void insertAtBegining (struct Circularlinkedlist *linked, int data)
{
    struct Node *newnode;
    newnode = (struct Node *) malloc (sizeof(struct Node));
    if (newnode == NULL)
    {
        printf ("Error creating node \n");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;
    if (isEmpty(linked))
    {
        linked->head = newnode;
        newnode->next = newnode;
    }
    else 
    {
        struct Node *temp = linked->head;
        while (temp->next != linked->head)
            temp = temp->next;
        temp->next = newnode;
        newnode->next = linked->head;
        linked->head = newnode;
    }
}

void insertAtEnd (struct Circularlinkedlist *linked, int data)
{
    struct Node *newnode;
    newnode = (struct Node *) malloc (sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Error creating node \n");
        return;
    }
    newnode->data = data;
    if (isEmpty(linked))
    {
        linked->head = newnode;
        newnode->next = newnode;
    }
    else 
    {
        struct Node *temp = linked->head;
        while (temp->next != linked->head)
            temp = temp->next;
        temp->next = newnode;
        newnode->next = linked->head;
    }
}

void insertAtMiddle (struct Circularlinkedlist *linked, int data, int pos)
{
    int sz;
    sz = getSize(linked);
    if (pos <1 || pos > sz+1)
    {
        printf("Position given is greater or less than size \n");
        return;
    }
    if (pos == 1) // counting start in 1 NOT in 0
    {
        insertAtBegining(linked,data);
        return;
    }
    else if (pos == sz +1)
    {
        insertAtEnd(linked,data);
        return;
    }
    struct Node *newnode;
    newnode = (struct Node *) malloc (sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Error creating node \n");
        return ;
    }
    newnode->data = data;
    struct Node *temp = linked->head;
    int i = 1;
    while (i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteAtBegining (struct Circularlinkedlist *linked)
{
    if (isEmpty(linked))
    {
        printf("Linked is empty \n");
        return;
    }
    struct Node *temp;
    struct Node *dlt;
    temp = linked->head;
    dlt = linked->head;
    if (temp->next == linked->head)
    {
        linked->head = NULL;
        free (dlt);
        return;
    }
    while (temp->next != linked->head)
        temp = temp->next;
    linked->head = linked->head->next;
    temp->next = linked->head;
    free(dlt);
}

void deleteAtEnd (struct Circularlinkedlist *linked)
{
    if (isEmpty(linked))
    {
        printf("Linked is empty \n");
        return ;
    }
    struct Node *temp;
    struct Node *dlt;
    temp = linked->head;
    if (temp->next == linked->head)
    {
        linked->head = NULL;
        free(temp);
        return;
    }
    while (temp->next->next != linked->head)
        temp = temp->next;
    dlt = temp->next;
    temp->next = linked->head;
    free(dlt);
}

void deleteAtMiddle (struct Circularlinkedlist *linked, int pos)
{
    int sz;
    sz = getSize(linked);
    if (isEmpty(linked))
    {
        printf("Linked is Empty \n");
        return;
    }
    else if (pos <1 || pos > sz)
    {
        printf("Position given is greater or less than size \n");
        return;
    }
    else if (pos == 1)
    {
        deleteAtBegining(linked);
        return;
    }
    else if (pos == sz)
    {
        deleteAtEnd(linked);
        return;
    }
    int i = 1;
    struct Node *temp = linked->head;
    struct Node *prev = NULL;
    while (i<pos)
    {
        prev = temp;
        temp = temp ->next;
        i++;
    }
    prev->next = temp->next;
    free(temp);
}

void freeClinked (struct Circularlinkedlist *linked)
{
    while (!isEmpty(linked))
        deleteAtBegining(linked);
    free (linked);
}