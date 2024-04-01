#ifndef __QUEUE_H_
#define __QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

struct Queue_Key {
    char* key;
    struct Queue_Key* prev;
};

typedef struct Queue {
    struct Queue_Key* front;
    struct Queue_Key* back;
} Queue;

Queue* queue_init();

void queue_enqueue(Queue* q, char* key);

struct Queue_Key* queue_dequeue(Queue* q);

#endif // __QUEUE_H_
