#include <stdio.h>
#include <stdlib.h>
#include "Cqueue.h"

int main (void)
{
    struct Circularqueue *queue;
    queue = createQueue ();

    freeQueue(queue);

    return 0;
}