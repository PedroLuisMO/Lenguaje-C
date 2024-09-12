#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Doublelinkedlist {
    struct Node *head;
    struct Node *tail;
};

struct Doublelinkedlist * createDlinked ();
int isEmpty (struct Doublelinkedlist *linked);
int getSize (struct Doublelinkedlist *linked);
void insertAtBegining (struct Doublelinkedlist *linked, int data);
void insertAtMiddle (struct Doublelinkedlist *linked, int data, int pos);
void insertAtEnd (struct Doublelinkedlist *linked, int data);
void deleteAtBeginig (struct Doublelinkedlist *linked);
void deleteAtMiddle (struct Doublelinkedlist *linked, int pos);
void deleteAtEnd (struct Doublelinkedlist *linked);
void displayFordward (struct Doublelinkedlist *linked);
void displayBackward (struct Doublelinkedlist *linked);
void freeDlinked (struct Doublelinkedlist *linked);

#endif