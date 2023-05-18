#ifndef BENCHMAKER_NODE_H
#define BENCHMAKER_NODE_H

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* nextByValue;
    Node* prevByValue;

    Node(int value, Node* next = nullptr, Node* prev = nullptr, Node* nextByValue = nullptr, Node* prevByValue = nullptr):
                                                                                    next(next),
                                                                                    prev(prev),
                                                                                    nextByValue(nextByValue),
                                                                                    prevByValue(prevByValue),
                                                                                    data(value) {}
};

#endif //BENCHMAKER_NODE_H
