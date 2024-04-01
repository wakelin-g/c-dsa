#include <stdio.h>
#include "stack.h"

int
main(void) {
    Stack* s = stack_init();
    stack_push(s, "entry_1");
    stack_push(s, "entry_2");
    stack_push(s, "entry_3");

    struct Stack_Key* k = stack_pop(s);
    printf("stack_key->%s\n", k->key);
    printf("n_elements->%d\n", s->n_entries);

    k = stack_pop(s);
    printf("stack_key->%s\n", k->key);
    printf("n_elements->%d\n", s->n_entries);

    k = stack_pop(s);
    printf("stack_key->%s\n", k->key);
    printf("n_elements->%d\n", s->n_entries);

    return 0;
}
