//
// Created by Cory Eheart on 1/28/22.
//

#include "CircularlyLinkedList.h"
#include <iostream>

using namespace std;

CircularlyLinkedList::CircularlyLinkedList() {
    head = NULL;
    tail = NULL;
}

CircularlyLinkedList::~CircularlyLinkedList() {
    Node *ptr;

    for (ptr = head; head; ptr = head){
        head = head->next;
        delete(ptr);
    }
}

bool CircularlyLinkedList::empty() {
    if (head == NULL && tail == NULL)
        return true;
    return false;
}

void CircularlyLinkedList::addFront(int i) {
    Node *ptr = new Node{i, NULL, NULL};
    if (head == NULL){
        head = ptr;
        tail = ptr;
    } else if (head == tail){
        Node *ptr2 = tail;
        ptr->next = ptr->prev = tail;
        head = ptr;
        ptr2->next = ptr2->prev = head;
        tail = ptr2;
    } else {
        Node *ptr2 = tail;
        ptr->next = head;
        ptr->prev = tail;
        head->prev = ptr;
        ptr2->next = ptr;
        head = ptr;
    }
}

void CircularlyLinkedList::addBack(int i) {
    Node *ptr = new Node{i, NULL, NULL};
    if (head == NULL){
        head = ptr;
        tail = ptr;
    } else if (head == tail){
        Node *ptr2 = head;
        ptr->next = ptr->prev = head;
        tail = ptr;
        ptr2->next = ptr2->prev = tail;
        head = ptr2;
    } else {
        Node *ptr2 = head;
        ptr->next = head;
        ptr->prev = tail;
        tail->next = ptr;
        ptr2->prev = ptr;
        tail = ptr;
        delete(head);
        head = ptr2;
    }
}

void CircularlyLinkedList::removeFront() {
    if (head == NULL){
        cout << "\nThe list is empty - Cannot remove from front\n";
    } else if (head == tail){
        head = NULL;
        tail = NULL;
    } else {
        Node *ptr = head->next;
        ptr->prev = tail;
        tail->next = ptr;
        delete(head);
        head = ptr;
        if (head == tail){
            head->next = NULL;
            head->prev = NULL;
            tail->next = NULL;
            tail->prev = NULL;
        }
    }
}

void CircularlyLinkedList::removeBack() {
    if (head == NULL){
        cout << "\nThe list is empty - Cannot remove from back\n";
    } else if (head == tail){
        head = NULL;
        tail = NULL;
    } else if (head->next == tail){
        delete(tail);
        tail = head;
        head->prev = head->next = tail->prev = tail->next = NULL;
    } else {
        Node *ptr = head;
        while (ptr->next->next != head){
            ptr = ptr->next;
        }
        ptr->next = head;
        delete(tail);
        tail = ptr;
        head->prev = tail;
    }
}

void CircularlyLinkedList::displayCircularlyLinkedList() {
    if (empty()){
        cout << "\nThe list is empty - Cannot display list\n";
    } else {
        Node *ptr = head;
        if (ptr->next != NULL) {
            while (ptr->next != head) {
                cout << "\n" << ptr->data;
                ptr = ptr->next;
            }
        }
        cout << "\n" << ptr->data;
    }
}