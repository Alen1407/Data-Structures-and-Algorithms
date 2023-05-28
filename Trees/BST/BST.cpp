#include "BST.h"
#include <iostream>

BST::BST() {
    root = nullptr;
}

void BST::insertRecursive(Node*& root, int data) {
    if(!root){
        root = new Node(data);
    }else if(data > root->data){
        insertRecursive(root->right, data);
    }else {
        insertRecursive(root->left, data);
    }
}


void BST::inOrder(Node* root) const {
    if(!root){
        return;
    }

    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}

Node* BST::searchRecursive(Node* root, int data) const{
    if(!root || root->data == data){ return root; }
    else if(data > root->data){
        searchRecursive(root->right, data);
    }else{
        searchRecursive(root->left, data);
    }
}

void BST::deleteRecursive(Node*& root, int data) {
    if (!root) {
        return;
    } else if (data < root->data) {
        deleteRecursive(root->left, data);
    } else if (data > root->data) {
        deleteRecursive(root->right, data);
    } else {
        if (!root->left && !root->right) {
            // Case 1: Node is a leaf
            delete root;
            root = nullptr;
        } else if (!root->left) {
            // Case 2: Node has only right child
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if (!root->right) {
            // Case 2: Node has only left child
            Node* temp = root;
            root = root->left;
            delete temp;
        } else {
            // Case 3: Node has two children
            Node* successor = findMin(root->right);
            root->data = successor->data;
            deleteRecursive(root->right, successor->data);
        }
    }
}

Node* BST::findMin(Node* node) const {
    if (!node || !node->left) {
        return node;
    }
    return findMin(node->left);
}

Node* BST::deleteMin(Node* node) {
    if (!node->left) {
        Node* rightChild = node->right;
        delete node;
        return rightChild;
    }
    node->left = deleteMin(node->left);
    return node;
}

void BST::remove(int data) {
    deleteRecursive(root, data);
}

void BST::insert(int data) {
    insertRecursive(root, data);
}

void BST::inOrder() const {
    inOrder(root);
}

Node* BST::search(int data) const {
    return searchRecursive(root, data);
}




















//ITERATIVELY
void BST::insertIterative(int data) {
    Node* newNode = new Node(data);
    if (!root) {
        root = newNode;
        return;
    }

    Node* current = root;
    while (current) {
        if (data < current->data) {
            if (current->left) {
                current = current->left;
            } else {
                current->left = newNode;
                return;
            }
        } else {
            if (current->right) {
                current = current->right;
            } else {
                current->right = newNode;
                return;
            }
        }
    }
}


void BST::deleteIterative(int data) {
    Node* current = root;
    Node* parent = nullptr;
    bool isLeftChild = false;

    // Find the node to be deleted
    while (current && current->data != data) {
        parent = current;
        if (data < current->data) {
            current = current->left;
            isLeftChild = true;
        } else {
            current = current->right;
            isLeftChild = false;
        }
    }

    if (!current) {
        // Node not found
        return;
    }

    if (!current->left && !current->right) {
        // Case 1: Node is a leaf
        if (!parent) {
            // Deleting the root node
            root = nullptr;
        } else if (isLeftChild) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete current;
    } else if (!current->left) {
        // Case 2: Node has only right child
        if (!parent) {
            // Deleting the root node
            root = current->right;
        } else if (isLeftChild) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
        delete current;
    } else if (!current->right) {
        // Case 3: Node has only left child
        if (!parent) {
            // Deleting the root node
            root = current->left;
        } else if (isLeftChild) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        delete current;
    } else {
        // Case 4: Node has both left and right children
        Node* successor = current->right;
        Node* successorParent = current;

        while (successor->left) {
            successorParent = successor;
            successor = successor->left;
        }

        current->data = successor->data;

        if (successorParent == current) {
            // Successor is the right child of the current node
            current->right = successor->right;
        } else {
            // Successor is not the right child of the current node
            successorParent->left = successor->right;
        }

        delete successor;
    }
}


Node* BST::searchIterative(int data) const {
    Node* current = root;
    while (current) {
        if (data == current->data) {
            return current;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return nullptr;
}
