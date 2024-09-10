#ifndef SIMPLELINKEDLIST_H
#define SIMPLELINKEDLIST_H

struct Node {
    int data;
    struct Node *next;
};

struct Simplelinkedlist {
    struct Node *head;
};

struct Simplelinkedlist * createLinked ();
int isEmpty (struct Simplelinkedlist *linked);
void display (struct Simplelinkedlist *linked);
int getSize (struct Simplelinkedlist *linked);
void insertAtBeginning (struct Simplelinkedlist *linked, int data);
void insertAtMiddle (struct Simplelinkedlist *linked, int data, int pos);
void insertAtEnd (struct Simplelinkedlist *linked, int data);
void deleteAtBeginning (struct Simplelinkedlist *linked);
void deleteAtMiddle (struct Simplelinkedlist *linked, int pos);
void deleteAtEnd(struct Simplelinkedlist *linked);
int* searchByValue (struct Simplelinkedlist *linked, int numSearch,int *sz);
int searchByPos (struct Simplelinkedlist *linked, int posSearch);
void updateByValue (struct Simplelinkedlist *linked, int numSearch, int numUpdate);
void updateByPos (struct Simplelinkedlist *linked, int posSearch, int numUpdate);
void freeSlinked (struct Simplelinkedlist *linked);

#endif