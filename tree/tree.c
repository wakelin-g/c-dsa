#include "tree.h"

Vertex*
tree_init() {
    Vertex* root = (Vertex*)malloc(sizeof(Vertex));
    root->left = NULL;
    root->right = NULL;
    root->value = ROOT_VALUE;
    return root;
}

void
tree_add_node(Vertex* root, int value) {
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
tree_count_nodes(Vertex* root) {
    if (root->left != NULL && root->right == NULL) {
        return 1 + tree_count_nodes(root->left);
    } else if (root->left == NULL && root->right != NULL) {
        return 1 + tree_count_nodes(root->right);
    } else if (root->left != NULL && root->right != NULL) {
        return 1 + tree_count_nodes(root->left) + tree_count_nodes(root->right);
    } else {
        return 1;
    }
}

void
tree_traverse_nodes(Vertex* root) {
    if (root->left != NULL && root->right == NULL) {
        printf("node %d\tleft: %d\tright: (empty)\n", root->value, root->left->value);
        tree_traverse_nodes(root->left);
    } else if (root->left == NULL && root->right != NULL) {
        printf("node %d\tleft: (empty)\tright: %d\n", root->value, root->left->value);
        tree_traverse_nodes(root->right);
    } else if (root->left != NULL && root->right != NULL) {
        printf("node %d\tleft: %d\tright: %d\n", root->value, root->left->value, root->right->value);
        tree_traverse_nodes(root->left);
        tree_traverse_nodes(root->right);
    } else {
        return;
    }
}
