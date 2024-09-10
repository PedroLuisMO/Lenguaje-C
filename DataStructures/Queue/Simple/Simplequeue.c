#include <stdio.h>
#include <stdlib.h>
#include "Simplequeue.h"

struct SimpleQueue * createQueue ()
{
    struct SimpleQueue *temp;
    temp = (struct SimpleQueue *) malloc (sizeof(struct SimpleQueue));
    if (temp == NULL)
    {
        printf("Error creating Queue \n");
        return NULL;
    }
    temp->head = NULL;
    temp->tail = NULL;
    return temp;
}

int isEmpty (struct SimpleQueue *queue)
{
    if (queue->head == NULL)
        return 1;
    return 0;
}

void enqueue (struct SimpleQueue *queue, int data)
{
    struct node *newNode;
    newNode = (struct node *) malloc (sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Error assigning memory to node \n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (queue->tail == NULL)
    {
        queue->head = newNode;
        queue->tail = newNode;
    }
    else 
    {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
}

void dequeue (struct SimpleQueue *queue)
{
    if (queue->tail == NULL)
    {
        printf("Queue is empty \n");
        return;
    }
    struct node *temp;
    temp = queue->head;
    queue->head = queue ->head ->next;
    if (queue->head == NULL)
        queue->tail = NULL;
    free(temp);
}

void display (struct SimpleQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty \n");
        return;
    }
    struct node *temp = queue->head;
    while (temp!=NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n"); 
}

void freeQueue (struct SimpleQueue *queue)
{
    while (!isEmpty(queue))
        dequeue(queue);
    free(queue);
}

int  getFirst(struct SimpleQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty \n");
        return -1;
    }
    return queue->head->data;
}