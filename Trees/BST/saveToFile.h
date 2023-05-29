#ifndef _BST_SAVETOFILE_H
#define _BST_SAVETOFILE_H
#include "BST.h"
#include <fstream>
void saveBSTNode(const Node* node, FILE* file);
void saveBST(const Node* tree, const char* filename);
#endif //_BST_SAVETOFILE_H
