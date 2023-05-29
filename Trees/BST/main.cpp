#include <iostream>
#include "BST.h"
#include "saveToFile.h"

int main() {
    BST bst;
    bst.insert(6);
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    bst.insert(4);
    bst.insert(5);
    bst.insert(7);
    bst.remove(7);
    bst.inOrder();

    saveBST(bst.getRoot(), "/home/alen/Desktop/1");

    return 0;
}