#include "tree.h"

int
main(void) {
    int n, i;
    Vertex* root = treeInit();
    for (i = 0; i < 100; i++) {
        addNode(root, i);
    }
    n = countNodes(root);
    printf("counted %d nodes (includes root)\n", n);
    traverseNodes(root);

    return 0;
}
