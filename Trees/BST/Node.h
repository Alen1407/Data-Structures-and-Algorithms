#ifndef _BST_NODE_H
#define _BST_NODE_H
class Node{
public:
    int data;
    Node* left;
    Node* right;

public:
    Node(int data, Node* left = nullptr, Node* right = nullptr) :
            data(data),
            left(left),
            right(right) {}
};
#endif //_BST_NODE_H
