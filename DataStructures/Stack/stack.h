#ifndef STACK_H
#define STACK_H

struct Node {
    int data;
    struct Node *next;
};

struct Stack {
    struct Node *top;
};

struct Stack * createStack ();
int isEmpty(struct Stack *stack);
void display (struct Stack *stack);
int getTop (struct Stack *stack);
int getSize (struct Stack *stack);
void push (struct Stack *stack, int data);
void pop (struct Stack *stack);
void freeStack(struct Stack *stack);

#endif