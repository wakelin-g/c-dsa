#include "tree.h"

#define ROOT_VALUE -1

Vertex*
treeInit() {
    Vertex* root = (Vertex*)malloc(sizeof(Vertex));
    root->left = NULL;
    root->right = NULL;
    root->value = ROOT_VALUE;
    return root;
}

void
addNode(Vertex* root, int value) {
    Vertex* node = (Vertex*)malloc(sizeof(Vertex));
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    Vertex* ptr = root;

    while (ptr != NULL) {
        if (ptr->left == NULL) {
            ptr->left = node;
            return;
        } else if (ptr->right == NULL) {
            ptr->right = node;
            return;
        } else {
            if (rand() % 2 == 0) {
                ptr = ptr->left;
            } else {
                ptr = ptr->right;
            }
        }
    }
}

int
countNodes(Vertex* root) {
    if (root->left != NULL && root->right == NULL) {
        return 1 + countNodes(root->left);
    } else if (root->left == NULL && root->right != NULL) {
        return 1 + countNodes(root->right);
    } else if (root->left != NULL && root->right != NULL) {
        return 1 + countNodes(root->left) + countNodes(root->right);
    } else {
        return 1;
    }
}

void
traverseNodes(Vertex* root) {
    if (root->left != NULL && root->right == NULL) {
        printf("node %d\tleft: %d\tright: (empty)\n", root->value, root->left->value);
        traverseNodes(root->left);
    } else if (root->left == NULL && root->right != NULL) {
        printf("node %d\tleft: (empty)\tright: %d\n", root->value, root->left->value);
        traverseNodes(root->right);
    } else if (root->left != NULL && root->right != NULL) {
        printf("node %d\tleft: %d\tright: %d\n", root->value, root->left->value, root->right->value);
        traverseNodes(root->left);
        traverseNodes(root->right);
    } else {
        return;
    }
}
