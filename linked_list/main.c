#include "llist.h"

int
main(void) {
    Node* node = init_node(10);
    int n[] = {20, 30, 40, 50, 60};
    append_nodes(node, n, 5);
    prepend_node(&node, 5);
    traverse_fwd(node, print_node_info);

    return 0;
}
