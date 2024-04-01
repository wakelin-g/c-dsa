#ifndef __STACK_H_
#define __STACK_H_

#include <stdio.h>
#include <stdlib.h>

struct Stack_Key {
    char* key;
    struct Stack_Key* prev;
};

typedef struct Stack {
    int n_entries;
    struct Stack_Key* top;
} Stack;

Stack* stack_init();

void stack_push(Stack* s, char* key);

struct Stack_Key* stack_top(Stack* s);

struct Stack_Key* stack_pop(Stack* s);

int stack_empty(Stack* s);

#endif // __STACK_H_
