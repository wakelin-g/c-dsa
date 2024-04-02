#ifndef __TREE_H_
#define __TREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex {
    struct Vertex* left;
    struct Vertex* right;
    int value;
} Vertex;

Vertex* treeInit(void);
void addNode(Vertex* root, int value);
int countNodes(Vertex* root);
void traverseNodes(Vertex* root);

#endif
