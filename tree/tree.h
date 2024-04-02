#ifndef __TREE_H_
#define __TREE_H_

#include <stdio.h>
#include <stdlib.h>

#define ROOT_VALUE -1

typedef struct Vertex {
    struct Vertex* left;
    struct Vertex* right;
    int value;
} Vertex;

Vertex* tree_init(void);
void tree_add_node(Vertex* root, int value);
int tree_count_nodes(Vertex* root);
void tree_traverse_nodes(Vertex* root);

#endif
