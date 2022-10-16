//
// Created by Cory Eheart on 1/28/22.
//

#ifndef CIRCULARLYLINKEDLIST_CIRCULARLYLINKEDLIST_H
#define CIRCULARLYLINKEDLIST_CIRCULARLYLINKEDLIST_H

struct Node{
    int data;
    Node *next;
    Node *prev;
};

class CircularlyLinkedList {
private:
    Node *head;
    Node *tail;
public:
    CircularlyLinkedList();
    ~CircularlyLinkedList();
    bool empty();
    void addFront(int i);
    void addBack(int i);
    void removeFront();
    void removeBack();
    void displayCircularlyLinkedList();
};


#endif //CIRCULARLYLINKEDLIST_CIRCULARLYLINKEDLIST_H
