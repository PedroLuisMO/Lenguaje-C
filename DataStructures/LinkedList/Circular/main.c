#include <stdio.h>
#include <stdlib.h>
#include "Clinkedlist.h"


int main (void)
{
    struct Circularlinkedlist *linked;
    linked = createClinked ();
    if (linked == NULL)
        return -1;
    insertAtBegining(linked,2);
    insertAtBegining(linked,1);
    insertAtEnd(linked,6);
    deleteAtMiddle(linked,2);
    display(linked);

    freeClinked(linked);

    return 0;
}

