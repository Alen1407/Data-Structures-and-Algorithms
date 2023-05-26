#include <iostream>
#include <queue>
#include <vector>
#include "Node.h"
#include "Gtree.h"


int add2(int x){
    return x+2;
}

int mul2(int x){
    return x*2;
}

int ret(int x){
    return x;
}

int square(int x){
    return x*x;
}


int main() {
    Gtree gtree;
    // Create a sample tree
    gtree.setRoot(new Node{ret});
    gtree.getRoot()->children.push_back(new Node{mul2});
    gtree.getRoot()->children.push_back(new Node{add2});
    gtree.getRoot()->children.push_back(new Node{square});
    gtree.getRoot()->children.push_back(new Node{mul2});
    gtree.getRoot()->children[0]->children.push_back(new Node{add2});
    gtree.getRoot()->children[1]->children.push_back(new Node{square});

    cout << gtree.execute(2);

    return 0;
}
