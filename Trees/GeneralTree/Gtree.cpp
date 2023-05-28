#include "Gtree.h"
#include <queue>

Gtree::Gtree() : root(nullptr) {}

Node* Gtree::getRoot() { return root; }

void Gtree::setRoot(Node* node) { root = node; }

int Gtree::BFS(Node* root, int x) {
    if (root == nullptr) {
        return -1;
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        x = (current->ptr)(x);

        for (Node* child : current->children) {
            q.push(child);
        }
    }

    return x;
}

int Gtree::execute(int x) {
    return BFS(root, x);
}