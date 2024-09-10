#ifndef SIMPLEQUEUE_H
#define SIMPLEQUEUE_H

struct node {
    int data;
    struct node *next;
};

struct SimpleQueue{
    struct node *tail;
    struct node *head;
};

struct SimpleQueue * createQueue ();
void enqueue (struct SimpleQueue *queue, int data);
void dequeue (struct SimpleQueue *queue);
int isEmpty (struct SimpleQueue *queue);
void display (struct SimpleQueue *queue);
void freeQueue (struct SimpleQueue *queue);
int  getFirts(struct SimpleQueue *queue);

#endif