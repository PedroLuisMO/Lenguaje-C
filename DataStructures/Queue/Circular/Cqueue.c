#include <stdio.h>
#include <stdlib.h>
#include "Cqueue.h"

struct Circularqueue * createQueue ()
{
    struct Circularqueue *temp;
    temp = (struct Circularqueue *) malloc (sizeof(struct Circularqueue));
    if (temp == NULL)
    {
        printf("Error creating Queue \n");
        return NULL;
    }
    temp->head = NULL;
    temp->tail = NULL;
    return temp;
}

void enqueue (struct Circularqueue *queue, int data)
{
    struct Node *newnode;
    newnode = (struct Node *) malloc (sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Error creating node \n");
        return ;
    }
    newnode->data = data;
    if (isEmpty(queue))
    {
        queue->head = newnode;
        queue->tail = newnode;
        newnode->next = newnode;
    }
    else 
    {
        queue->tail->next = newnode;
        queue->tail = newnode;
        newnode->next = queue->head;
    }
}

void dequeue (struct Circularqueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty \n");
        return ;
    }
    struct Node *temp = queue->head;
    if (queue->head == queue->tail)
        queue->head = queue->tail = NULL;
    else 
    {
        queue->head = temp->next;
        queue->tail->next = queue->head;
    }
    free (temp);
}

int isEmpty (struct Circularqueue *queue)
{
    if (queue->head == NULL)
        return 1;
    return 0;
}

void display (struct Circularqueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty \n");
        return;
    }
    struct Node *temp = queue->head;
    do {
        printf(" %d", temp->data);
        temp = temp->next;
    } while (temp!=queue->head);
    printf("\n");
}

void freeQueue (struct Circularqueue *queue)
{
    while (!isEmpty(queue))
        dequeue(queue);
    free(queue);
}

int  getFirst(struct Circularqueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty \n");
        return -1;
    }
    return queue->head->data;
}