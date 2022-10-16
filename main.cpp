#include <iostream>
#include "Classes/CircularlyLinkedList.h"

using namespace std;

int main() {
    CircularlyLinkedList *list = new CircularlyLinkedList();
    list->addFront(2);
    list->addFront(3);
    list->addFront(4);

    list->displayCircularlyLinkedList();

    return 0;
}
