//
//  queue.h
//  Yuxuan Wang
//  B00880845
//

#ifndef queue_h
#define queue_h

#include <stdbool.h>

typedef struct _Node {
    void* data;
    struct _Node* next;
    struct _Node* prev;
} Node;

typedef struct _Queue {
    Node* front;
    Node* tail;
    int size;
    int itemSize;
    char* type;
} Queue;

Queue* queue_initialize(int, char*);
bool queue_enqueue(Queue*, void*);
void* queue_dequeue(Queue*);
void* queue_peek(Queue*);
int queue_size(Queue*);
bool queue_contains(Queue*, void*);
bool queue_destroy(Queue*);

#endif /* queue_h */

