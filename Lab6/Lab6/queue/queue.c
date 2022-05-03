//
// queue.c file
// Yuxuan Wang
// B00880845
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

// initialize a queue, return its instance
Queue* queue_initialize(int itemSize, char* type) {
    Queue* queue = malloc(sizeof(*queue));
    
    if(queue == NULL) { return NULL; }
    
    queue -> front = NULL;
    queue -> tail = NULL;
    queue -> size = 0;
    queue -> itemSize = itemSize;
    queue -> type = malloc(strlen(type));
    strcpy(queue -> type, type);

    return queue;
}

// put the given element in to the queue
bool queue_enqueue(Queue* queue, void* item) {
    if(queue == NULL || item == NULL) { return false; }
    
    // a node to store the passing in item
    Node *node = malloc(sizeof(*node));
    node -> data = malloc(sizeof(item));
    memcpy(node -> data, item, sizeof(item));

    // add case: empty queue
    if(queue -> size == 0) {
        queue -> front = node;
        queue -> tail = node;
        node -> next = NULL;
        node -> prev = NULL;
        queue -> size++;
        
        return true;
    }
    
    // add case: non-empty queue
    node -> next = queue -> front;
    queue -> front -> prev = node;
    queue -> front = node;
    queue -> size++;
    
    return true;
}

// pop the tail element
void* queue_dequeue(Queue* queue) {
    if(queue == NULL || queue -> size == 0) { return NULL; }

    void* rmItem = queue -> tail -> data;

    if(queue -> size == 1){
        queue -> front = NULL;
        queue -> tail = NULL;
        queue -> size--;
        free(queue -> front);
        
        return rmItem;
    }
    
    Node* curr = queue -> tail;
    curr -> prev -> next = NULL;
    queue -> tail = curr -> prev;
    curr -> prev = NULL;
    queue -> size--;
    free(curr);
    
    return rmItem;
}

// check the next availble item
void* queue_peek(Queue* queue) {
    if(queue == NULL || queue -> size == 0) { return NULL; }
    
    return queue -> tail -> data;
}

// check the current queue size
int queue_size(Queue* queue) {
    if(queue == NULL) { return -1; }
    
    return queue -> size;
}

// check if the specified item is in the queue
bool queue_contains(Queue* queue, void* target) {
    if(queue == NULL || target == NULL) { return false; }
    if(queue -> size == 0) { return false; }
    
    Node* curr = queue -> front;
    for(int i = 0; i < queue -> size; i++) {
        if(memcmp(curr -> data, target, sizeof(target)) == 0) {
            return true;
        }
        curr = curr -> next;
    }
    return false;
}

// destroy the queue
bool queue_destroy(Queue* queue) {
    // NULL queue
    if(queue == NULL) { return false; }
    
    // free nodes
    if(queue -> size > 0) {
        Node *curr = queue -> front;
        Node *next    = NULL;
            
        for(int i=0; i < queue -> size; i++) {
            next = curr -> next;
            free(curr -> data);
            free(curr);
            curr = next;
        }
        free(queue -> type);
        free(queue);
    }
    return true;
}

