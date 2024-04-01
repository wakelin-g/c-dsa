#include <stdio.h>
#include "queue.h"

int
main(void) {
    Queue* q = queue_init();
    queue_enqueue(q, "val1");
    queue_enqueue(q, "val2");
    queue_enqueue(q, "val3");
    struct Queue_Key* k = queue_dequeue(q);
    printf("key: %s\n", k->key);

    k = queue_dequeue(q);
    printf("key: %s\n", k->key);

    printf("queue front: %s\n", q->front->key);

    return 0;
}
