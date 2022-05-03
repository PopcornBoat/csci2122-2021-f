// YuxuanWang, B00880845
// heap.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

// initialize a heap
Heap* heap_initialize(int itemSize, char* itemType, int (*compare)(void*, void*), void (*print)(void*)){
    Heap* heap = malloc(sizeof(*heap));
    // malloc fail check
    if (heap == NULL) { return NULL; }
    
    // initially has 10 slots
    ArrayList* list = alist_initialize(10, itemSize, itemType);
    if (list == NULL) { return NULL; }
    
    heap->compare = compare;
    heap->print = print;
    heap->list = list;
    
    return heap;
}

// insert an item to the heap
bool heap_insert(Heap* heap, void* item){
    if (heap == NULL || item == NULL) { return false; }
    
    alist_add(heap->list, item);
    
    return _heapify_up(heap, heap->list->size - 1);
}

// remove the root of the heap
void* heap_remove(Heap* heap){
    if (heap == NULL) { return NULL; }
    
    // remove the root and make the last item be the root, then do heapify
    alist_swap(heap->list, 0, heap->list->size-1);
    void* rmItem = alist_remove(heap->list, heap->list->size-1);
    
    if (!_heapify(heap, 0)) { return NULL; }
    return rmItem;
}

// check root item
void* heap_peek(Heap* heap){
    if (heap == NULL) { return NULL; }
    return alist_get(heap->list, 0);
}

// check the size of the heap, -1 on error
int heap_size(Heap* heap){
    if (heap == NULL) { return -1; }
    return heap->list->size;
}

// check if a given item (target) exists in the heap
bool heap_contains(Heap* heap, void* target){
    if (heap == NULL || target == NULL) { return false; }
    if (alist_index_of(heap->list, target) < 0) {
        return false;
    }
    return true;
}

// helper function
// make Heap order again! perform a downward heapify
bool _heapify(Heap* heap, int index){
    if (heap == NULL) { return false; }
    
    // already in order
    if (index >= heap->list->size) { return true; }
    
    int top = index;
    ArrayList* list = heap->list;
    
    bool leftChild = ((2 * index + 1) < list->size) && heap->compare(alist_get(list, top), alist_get(list, (2 * index + 1))) < 0;
   

    if(leftChild){
        top = (2 * index + 1);
    }
    
    bool rightChild = ((2 * index + 2) < list->size) && heap->compare(alist_get(list, top), alist_get(list, (2 * index + 2))) < 0;
    if(rightChild){
        top = (2 * index + 2);
    }

    if (top == index) { return true; }
    alist_swap(heap->list, top, index);   
    return _heapify(heap, top);
}

// upward heapify
bool _heapify_up(Heap* heap, int index){
    if (heap == NULL) { return false; }
    
    bool parent = heap->compare(alist_get(heap->list, (index - 1) / 2), alist_get(heap->list, index)) >= 0;

    if(parent){ return true; }
    else {
        // upward heapify
	// retry my version one with swap
        alist_swap(heap->list, index, (index-1)/2);
        return _heapify_up(heap, (index - 1)/2);    
    }
}

