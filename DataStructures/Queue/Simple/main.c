#include <stdio.h>
#include <stdlib.h>
#include "Simplequeue.h"

int main (void)
{
    struct SimpleQueue *queue;
    queue = createQueue();
    if (queue == NULL)
        return -1;

    freeQueue(queue);
    return 0;
}

