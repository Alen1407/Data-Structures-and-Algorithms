#ifndef GTREE_NODE_H
#define GTREE_NODE_H
#pragma once
#include <vector>
using namespace std;
class Node {
public:
    int (*ptr)(int);
    vector<Node*> children;

public:
    Node(int (*func)(int)) : ptr(func) {}

};



#endif //GTREE_NODE_H
