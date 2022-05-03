//
// stack.h
// Yuxuan Wang
// B00880845
//

#ifndef stack_h
#define stack_h

#include <stdbool.h>

typedef struct _Node {
    void* data;
    struct _Node* next;
    struct _Node* prev;
} Node;

typedef struct _Stack {
    Node* front;
    Node* tail;
    int size;
    int itemSize;
    char* type;
} Stack;

Stack* stack_initialize(int, char*);
bool stack_push(Stack*, void*);
void* stack_pop(Stack*);
void* stack_peek(Stack*);
int stack_size(Stack*);
bool stack_contains(Stack*, void*);
bool stack_destroy(Stack*);

#endif /* stack_h */

