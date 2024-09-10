#include <stdio.h>
#include <stdlib.h>
#include "Slinkedlist.h"



int main (void)
{
    struct Simplelinkedlist *linked = NULL;
    int sz;
    linked = createLinked();
    if (linked==NULL)
        return -1;

    freeSlinked(linked);
    return 0;
}

