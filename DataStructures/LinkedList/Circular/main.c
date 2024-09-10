#include <stdio.h>
#include <stdlib.h>
#include "Clinkedlist.h"


int main (void)
{
    struct Circularlinkedlist *linked;
    linked = createClinked ();
    if (linked == NULL)
        return -1;
     
    freeClinked(linked);

    return 0;
}

