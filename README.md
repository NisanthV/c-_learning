# Linked List Operations in C++

This repository contains a C++ implementation of basic linked list operations including insertion at the beginning, end, and a specific location, as well as printing the linked list.

## Overview

The code includes the following functions:
- `printList(Node* n)`: Prints all the values in the linked list.
- `insertAtBegin(Node** head, int value)`: Inserts a new node at the beginning of the linked list.
- `insertAtLast(Node** head, int value)`: Inserts a new node at the end of the linked list.
- `tempinsert(Node*& head, int value)`: Inserts a new node at the beginning of the linked list using a reference to a pointer.
- `insertAtSpecificLocation(Node** head, int value, int posValue)`: Inserts a new node after a node with a specific value.

## Code Structure

### Node Class

The `Node` class represents an element in the linked list.

```cpp
class Node {
public:
    int value;
    Node* next;
};
