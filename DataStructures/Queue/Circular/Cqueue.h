#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

struct Node {
    int data;
    struct Node *next; 
};
struct Circularqueue
{
    struct Node *head;
    struct Node *tail;
};

struct Circularqueue * createQueue ();
void enqueue (struct Circularqueue *queue, int data);
void dequeue (struct Circularqueue *queue);
int isEmpty (struct Circularqueue *queue);
void display (struct Circularqueue *queue);
void freeQueue (struct Circularqueue *queue);
int  getFirst(struct Circularqueue *queue);

#endif