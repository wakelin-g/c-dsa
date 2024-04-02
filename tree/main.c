#include "tree.h"

int
main(void) {
    int n, i;
    Vertex* root = tree_init();
    for (i = 0; i < 100; i++) {
        tree_add_node(root, i);
    }
    n = tree_count_nodes(root);
    printf("counted %d nodes (includes root)\n", n);
    tree_traverse_nodes(root);

    return 0;
}
