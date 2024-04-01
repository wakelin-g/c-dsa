#include "llist.h"

Node*
init_node(int val) {
    Node* l = (Node*)malloc(sizeof(Node));
    l->val = val;
    l->next = NULL;
    l->prev = NULL;
    return l;
}

void
append_node(Node* parent, int val) {
    Node* ptr;
    Node* l = init_node(val);
    ptr = find_end(parent);
    l->prev = ptr;
    ptr->next = l;
}

void
append_nodes(Node* parent, int vals[], int n) {
    for (int i = 0; i < n; i++) {
        append_node(parent, vals[i]);
    }
}

void
prepend_node(Node** parent, int val) {
    Node* l = init_node(val);
    (*parent)->prev = l;
    l->next = *parent;
    *parent = l;
}

void
delete_node(Node* parent, int val) {
    Node* ptr = parent;
    Node* curr = NULL;
    for (;;) {
        if (ptr->next == NULL) {
            printf("not found: %d\n", val);
            return;
        }

        curr = ptr;
        ptr = ptr->next;
        if (ptr->val == val) {
            curr->next = ptr->next;
            free(ptr);
            return;
        }
    }
}

Node*
find_end(Node* l) {
    Node* ptr = l;
    for (;;) {
        if ((ptr->next) == NULL) {
            return ptr;
        } else {
            ptr = ptr->next;
        }
    }
}

void
print_all_vals(Node* l) {
    Node* ptr = l;
    while (ptr != NULL) {
        printf("%d\n", ptr->val);
        ptr = ptr->next;
    }
}

void
print_all_vals_rev(Node* l) {
    Node* ptr = find_end(l);
    while (ptr != NULL) {
        printf("%d\n", ptr->val);
        ptr = ptr->prev;
    }
}

void
traverse_fwd(Node* l, void (*f)(Node*)) {
    Node* ptr = l;
    while (ptr != NULL) {
        (*f)(ptr);
        ptr = ptr->next;
    }
}

void
traverse_rev(Node* l, void (*f)(Node*)) {
    Node* ptr = find_end(l);
    while (ptr != NULL) {
        (*f)(ptr);
        ptr = ptr->prev;
    }
}

void
print_node_val(Node* l) {
    printf("%d\n", l->val);
}

void
print_node_addr(Node* l) {
    printf("%p\n", &(*l));
}

void
print_node_info(Node* l) {
    printf("-------------------------------\n");
    printf("val:      %14d\n", l->val);
    printf("address:  %p\n", &(*l));
    printf("-------------------------------\n");
}
