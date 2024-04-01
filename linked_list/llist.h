#ifndef __LLIST_H_
#define __LLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
} Node;

Node* init_node(int val);

void insert_node(Node* parent, int val);

void append_node(Node* parent, int val);

void append_nodes(Node* parent, int* vals, int n);

void prepend_node(Node** parent, int val);

void delete_node(Node* l, int val);

Node* find_end(Node* l);

void print_all_vals(Node* l);

void print_all_vals_rev(Node* l);

void traverse_fwd(Node* l, void (*f)(Node*));
void traverse_rev(Node* l, void (*f)(Node*));
void print_node_val(Node* l);
void print_node_addr(Node* l);
void print_node_info(Node* l);

#endif // __LLIST_H_
