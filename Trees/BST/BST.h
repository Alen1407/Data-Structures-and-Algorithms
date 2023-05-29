#ifndef _BST_BST_H
#define _BST_BST_H
#pragma once
#include "Node.h"

class BST {
private:
    Node* root;

    void insertRecursive(Node*&, int);
    void deleteRecursive(Node*&, int);
    Node* searchRecursive(Node*, int) const;
    void insertIterative(int);
    void deleteIterative(int);
    Node* searchIterative(int) const;
    void inOrder(Node*) const;
    Node* findMin(Node* node) const;
    Node* deleteMin(Node* node);

public:
    BST();
    void insert(int);
    void inOrder() const;
    Node* search(int) const;
    void remove(int data);
    Node* getRoot();
};


#endif //_BST_BST_H