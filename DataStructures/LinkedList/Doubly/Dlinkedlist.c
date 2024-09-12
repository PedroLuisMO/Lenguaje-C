#include <stdio.h>
#include <stdlib.h>
#include "Dlinkedlist.h"

struct Doublelinkedlist * createDlinked ()
{
    struct Doublelinkedlist *temp;
    temp = (struct Doublelinkedlist *) malloc (sizeof(struct Doublelinkedlist));
    if (temp == NULL)
    {
        printf("Error creating linked \n");
        return NULL;
    }
    temp->head = NULL;
    temp->tail = NULL;
    return temp;
}

int isEmpty (struct Doublelinkedlist *linked)
{
    if (linked->head == NULL)
        return 1;
    return 0;
}

int getSize (struct Doublelinkedlist *linked)
{
    int sz = 0;
    if (isEmpty(linked))
        return sz;
    struct Node *temp;
    temp = linked->head;
    while (temp!=NULL)
    {
        sz++;
        temp = temp->next;
    }
    return sz++;
}

void insertAtBegining (struct Doublelinkedlist *linked, int data)
{
    struct Node *newnode;
    newnode = (struct Node *) malloc (sizeof(struct Node));
    if (newnode==NULL)
    {
        printf("Error creating node \n");
        return;
    }
    newnode->data = data;
    newnode->prev = NULL;

    if (isEmpty(linked))
    {
        linked->head = newnode;
        linked->tail = newnode;
        newnode->next = NULL;
    }
    else 
    {
        newnode->next = linked->head;
        linked->head->prev = newnode;
        linked->head = newnode;
    }
}

void insertAtEnd (struct Doublelinkedlist *linked, int data)
{
    struct Node *newNode;
    newNode = (struct Node *) malloc (sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Error creating node \n");
        return;
    }
    newNode->data = data;
    if (isEmpty(linked))
    {
        linked->head = newNode;
        linked->tail = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;        
    }
    else 
    {
        linked->tail->next = newNode;
        newNode->prev = linked->tail;
        newNode->next = NULL;
        linked->tail = newNode;
    }
}

void insertAtMiddle (struct Doublelinkedlist *linked, int data, int pos)
{
    struct Node *newNode;
    int sz = getSize(linked);
    newNode = (struct Node *) malloc (sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Error creating node \n");
        free(newNode);
        return;
    }
    if (pos < 1 || pos > sz+1)
    {
        printf("Position out of bounds \n");
        return;
    }
    else if (pos == 1)
        insertAtBegining(linked,data);
    else if (pos == sz+1)
        insertAtEnd(linked,data);
    else
    {
        newNode->data = data;
        struct Node *temp = linked->head;
        int i=1;
        while (i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        temp->next->prev = newNode;
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAtBeginig (struct Doublelinkedlist *linked)
{
    if (isEmpty(linked))
        printf("Linked is empty \n");
    else if (linked->head == linked->tail) // Just 1 element
    {
        struct Node *dlt;
        dlt = linked->head;
        linked->head = NULL;
        linked->tail = NULL;
        free (dlt);
    } 
    else
    {
        struct Node *dlt;
        dlt = linked->head;
        linked->head = linked->head->next;
        linked->head->prev = NULL;
        free(dlt);   
    }
}

void deleteAtEnd (struct Doublelinkedlist *linked)
{
    if (isEmpty(linked))
        printf("Linked is empty");
    else if (linked->head == linked->tail) // just 1 elemenet
    {
        struct Node *dlt;
        dlt = linked->tail;
        linked->head = NULL;
        linked->tail = NULL;
        free (dlt);
    }
    else 
    {
        struct Node *dlt;
        dlt = linked->tail;
        linked->tail = linked->tail->prev;
        linked->tail->next = NULL;
        free(dlt);
    }
} 

void deleteAtMiddle (struct Doublelinkedlist *linked, int pos)
{
    int sz;
    sz = getSize(linked);
    if (isEmpty(linked))
        printf("Linked is Empty");
    else if (pos < 1 || pos > sz )
        printf("Position out of boundes \n");
    else if (pos == 1)
        deleteAtBeginig(linked);
    else if (pos == sz)
        deleteAtEnd(linked);
    else 
    {
        int i = 1;
        struct Node *dlt = linked->head;
        while (i<pos)
        {
            dlt = dlt->next;
            i++;
        }
        dlt->prev->next = dlt->next;
        dlt->next->prev = dlt->prev;
        free(dlt);
    }
}

void displayFordward (struct Doublelinkedlist *linked)
{
    struct Node *temp;
    temp = linked->head;
    while (temp!=NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

void displayBackward (struct Doublelinkedlist *linked)
{
    struct Node *temp;
    temp = linked->tail;
    while (temp!=NULL)
    {
        printf("%d <-", temp->data);
        temp = temp->prev;
    }
    printf ("NULL \n");
    
}

void freeDlinked (struct Doublelinkedlist *linked)
{
    while (!isEmpty(linked))
        deleteAtBeginig(linked);
    free(linked);
}