#include <stdio.h>
#include <stdlib.h>
#include "Dlinkedlist.h"

int main (void)
{
    struct Doublelinkedlist *linked;
    linked = createDlinked();
    if (linked==NULL)
        return -1;

    freeDlinked(linked);
    
    return 0;
}

