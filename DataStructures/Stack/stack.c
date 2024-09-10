#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack * createStack ()
{
    struct Stack *temp;
    temp = (struct Stack *) malloc (sizeof(struct Stack));
    if (temp == NULL)
    {
        printf("Error creating stack \n");
        return NULL;
    }
    temp->top = NULL;
    return temp;
}

int isEmpty(struct Stack *stack)
{
    if (stack->top == NULL)
        return 1;
    return 0;
}

void display (struct Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is empty \n");
        return;
    }
    struct Node *temp = stack->top;
    while (temp!=NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int getTop (struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty, there is not a top \n");
        return -1;
    }
    return stack->top->data;
}

int getSize (struct Stack *stack)
{
    int size = 0;
    struct Node *temp = stack->top;
    while (temp!=NULL)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

void push (struct Stack *stack, int data)
{
    struct Node *newNode;
    newNode = (struct Node *) malloc (sizeof(struct Node));
    if (newNode==NULL)
    {
        printf("Error creating node \n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop (struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty \n");
        return;
    }
    struct Node *temp = stack->top;
    stack->top = temp->next;
    free(temp);
}

void freeStack(struct Stack *stack)
{
    while (!isEmpty(stack))
        pop(stack);
    free (stack);
}