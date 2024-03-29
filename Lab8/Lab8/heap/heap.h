// Yuxuan Wang, B00880845
// heap.h
// array_list.h is from the Lab5 solution provided

#ifndef heap_h
#define heap_h

#include <stdbool.h>
#include "array_list.h"

typedef struct _Heap{
    ArrayList* list;
    int (*compare)(void*, void*);
    void (*print)(void*);
} Heap;

Heap* heap_initialize(int, char*, int (*)(void*, void*), void (*)(void*));
bool heap_insert(Heap*, void*);
void* heap_remove(Heap*);
void* heap_peek(Heap*);
int heap_size(Heap*);
bool heap_contains(Heap*, void*);

bool _heapify(Heap*, int);
bool _heapify_up(Heap*, int);

#endif
