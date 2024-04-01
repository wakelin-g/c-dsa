#include "stack.h"

Stack*
stack_init() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    s->n_entries = 0;
    return s;
}

void
stack_push(Stack* s, char* key) {
    struct Stack_Key* e = (struct Stack_Key*)malloc(sizeof(struct Stack_Key));
    e->key = key;
    e->prev = s->top;
    s->top = e;
    s->n_entries++;
}

struct Stack_Key*
stack_top(Stack* s) {
    return s->top;
}

struct Stack_Key*
stack_pop(Stack* s) {
    struct Stack_Key* ret = s->top;
    s->top = ret->prev;
    s->n_entries--;
    return ret;
}

int
stack_empty(Stack* s) {
    return (s->n_entries == 0);
}
