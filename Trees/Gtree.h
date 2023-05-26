#ifndef GTREE_GTREE_H
#define GTREE_GTREE_H
#include "Node.h"

class Gtree {
private:
    Node* root;

public:
    Gtree();
    int BFS(Node*, int);
    int execute(int);
    Node* getRoot();
    void setRoot(Node*);
};


#endif //GTREE_GTREE_H