#include "queue.h"

Queue*
queue_init() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->back = NULL;
    return q;
}

void
queue_enqueue(Queue* q, char* key) {
    struct Queue_Key* e = (struct Queue_Key*)malloc(sizeof(struct Queue_Key));
    e->key = key;
    e->prev = q->front;
    q->front = e;
}

struct Queue_Key*
queue_dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("queue is empty\n");
        exit(1);
    }
    struct Queue_Key* ret = q->front;
    q->front = ret->prev;
    return ret;
}
