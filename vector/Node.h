#ifndef BENCHMAKER_NODE_H
#define BENCHMAKER_NODE_H

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

#endif //BENCHMAKER_NODE_H
