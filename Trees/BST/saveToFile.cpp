#include <iostream>
#include "BST.h"

void saveBSTNode(const Node* node, FILE* file) {
    if (node == NULL) {
        fprintf(file, "# ");
        return;
    }

    fprintf(file, "%d ", node->data);

    saveBSTNode(node->left, file);
    saveBSTNode(node->right, file);
}


void saveBST(const Node* tree, const char* filename) {
    // Open the file for writing.
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    saveBSTNode(tree, file);

    fclose(file);
}