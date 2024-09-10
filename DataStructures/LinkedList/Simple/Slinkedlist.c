#include <stdio.h>
#include <stdlib.h>
#include "Slinkedlist.h"

struct Simplelinkedlist * createLinked ()
{
    struct Simplelinkedlist *newLinked;
    newLinked = (struct Simplelinkedlist *) malloc (sizeof(struct Simplelinkedlist));
    if (newLinked == NULL)
    {
        printf("Error creating linked \n");
        return NULL;
    }
    newLinked->head = NULL;
    return newLinked;
}

int isEmpty (struct Simplelinkedlist *linked)
{
    if (linked->head == NULL)
        return 1;
    return 0; 
}

void display (struct Simplelinkedlist *linked)
{
    if (isEmpty(linked))
    {
        printf("Linked is empty ... \n");
        return;
    }
    struct Node *temp = linked->head;
    while (temp!= NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int getSize (struct Simplelinkedlist *linked)
{
    int sz = 0;
    struct Node *ptr = linked->head;
    while (ptr != NULL)
    {
        sz++;
        ptr = ptr->next;
    }
    return sz;
}

void insertAtBeginning (struct Simplelinkedlist *linked, int data)
{
    struct Node *newNode;
    newNode = (struct Node *) malloc (sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Error creating new node  \n");
        return;
    }
    newNode->data = data;
    newNode->next = linked->head;
    linked->head = newNode;
}

void insertAtMiddle (struct Simplelinkedlist *linked, int data, int pos)
{
    int size = getSize(linked);
    if (pos > size+2)
    {
        printf("Position given is greater than linked size \n");
        return ;
    }
    if (pos == 1)
    {
        insertAtBeginning(linked,data);
        return;
    }
    if (pos > size+1)
    {
        insertAtEnd(linked,data);
        return;
    }
    struct Node *newNode;
    newNode = (struct Node *) malloc (sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Error creating new node \n");
        return;
    }
    newNode->data = data;
    struct Node *temp = linked->head;
    int i = 1;
    while (i < pos-1)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtEnd (struct Simplelinkedlist *linked, int data)
{
    struct Node *newNode;
    newNode = (struct Node*) malloc (sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Error creating new node \n");
        return;
    }
    if (isEmpty(linked))
    {
        newNode->data = data;
        linked->head = newNode;
        return;
    }
    newNode->data = data;
    struct Node *temp = linked->head;
    while (temp->next!=NULL)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning (struct Simplelinkedlist *linked)
{
    if (isEmpty(linked))
    {
        printf("Linked is empty \n");
        return;
    }
    struct Node *temp;
    temp = linked->head;
    linked->head = temp->next;
    free (temp);
}

void deleteAtMiddle (struct Simplelinkedlist *linked, int pos)
{
    if (pos > getSize(linked))
    {
        printf("Position given is greater than linked size \n");
        return;
    }
    if (pos == 1)
    {
        deleteAtBeginning(linked);
        return;
    }
    if (getSize(linked) ==  pos)
    {
        deleteAtEnd(linked);
        return;
    }
    int i=1;
    struct Node *temp = linked->head;
    struct Node *prev = NULL;
    while (i<pos)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = temp->next;
    free(temp);
}

void deleteAtEnd(struct Simplelinkedlist *linked)
{
    if (isEmpty(linked))
    {
        printf("Linked is empty \n");
        return;
    }
    struct Node *temp;
    struct Node *prev = NULL;
    temp = linked->head;
    if (temp->next == NULL)
    {
        free (temp);
        linked->head = NULL;
        return;
    }
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free (temp);   
}

int* searchByValue (struct Simplelinkedlist *linked, int numSearch,int *sz)
{
    if (isEmpty(linked))
    {
        printf("Linked is empty \n");
        *sz = 0;
        return NULL;
    }
    int *array = NULL;
    int cont = 0;
    int i = 0;
    struct Node *temp = linked->head;
    while (temp!=NULL)
    {
        if (temp->data == numSearch)
        {
            array = (int *) realloc(array,sizeof(int)*(cont+1));
            if (array == NULL)
            {
                printf("Error assigning memory in realloc  \n");
                free(array);
                return NULL;
            }
            array[cont] = (i+1);
            cont++;
        }
        i++;
        temp = temp->next;
    }
    *sz = cont;
    return array;
}

int searchByPos (struct Simplelinkedlist *linked, int posSearch)
{
    if (isEmpty(linked))
    {
        printf("linked is empty \n");
        return -1;
    }
    if (posSearch > getSize(linked) || posSearch < 1)
    {
        printf("Position given is wrong \n");
        return -1;
    }
    struct Node *temp = linked->head;
    int i = 0;
    while (i<posSearch-1)
    {
        temp = temp->next;
        i++;
    }
    return temp->data;
}

void updateByValue (struct Simplelinkedlist *linked, int numSearch, int numUpdate)
{
    if (isEmpty(linked))
    {
        printf("Linked is empty \n");
        return;
    }
    struct Node *temp = linked->head;
    while (temp!=NULL)
    {
        if (temp->data ==  numSearch)
            temp->data = numUpdate;
        temp = temp->next;        
    }
}

void updateByPos (struct Simplelinkedlist *linked, int posSearch, int numUpdate)
{
    if (isEmpty(linked))
    {
        printf("Linked is empty \n");
        return ;
    }
    if (posSearch > getSize(linked) || posSearch < 1)
    {
        printf("Position given is wrong \n");
        return ;
    }
    struct Node *temp = linked->head;
    int i = 1;
    while (i<posSearch)
    {
        temp = temp->next;
        i++;
    }
    temp->data = numUpdate;
}