#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*
Si se hace un push o pop al final de la lista, la operacion en tiempo sera O(n), en lo que recorre toda la lista 
Si se hace un push o pop por front, siempre sera el primer elemento, por lo cual, el tiempo sera O(1)
*/ 

int main (void)
{
    struct Stack *stack;
    stack = createStack();
    if (stack==NULL)
        return -1;


    freeStack(stack);

    return 0;
}
