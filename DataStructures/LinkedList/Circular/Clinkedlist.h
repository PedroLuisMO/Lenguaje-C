#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

struct Node {
    int data;
    struct Node *next;
};

struct Circularlinkedlist {
    struct Node *head;
};

struct Circularlinkedlist * createClinked ();
int isEmpty (struct Circularlinkedlist *linked);
int getSize (struct Circularlinkedlist *linked);
void display(struct Circularlinkedlist *linked);
void insertAtBegining (struct Circularlinkedlist *linked, int data);
void insertAtEnd (struct Circularlinkedlist *linked, int data);
void insertAtMiddle (struct Circularlinkedlist *linked, int data, int pos);
void deleteAtBegining (struct Circularlinkedlist *linked);
void deleteAtEnd (struct Circularlinkedlist *linked);
void deleteAtMiddle (struct Circularlinkedlist *linked, int pos);
void freeClinked (struct Circularlinkedlist *linked);

#endif