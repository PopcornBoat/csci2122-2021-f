//
// array_list.c
// Yuxuan Wang
// B00880845
//

#include "array_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// initialize an array_list and return it
ArrayList* alist_initialize(int maxSize, int itemSize, char* type) {
    ArrayList *newList = malloc(sizeof(ArrayList));
    newList -> arr = calloc(maxSize, sizeof(void*));
    newList -> size = 0;
    newList -> maxSize = maxSize;
    newList -> itemSize = itemSize;
    newList -> type = type;
    
    return newList;
}

// add item at the end of the array_list, return true if success, false otherwise
bool alist_add(ArrayList* list, void* item) {
    if(list == NULL){
                printf("NUll list\n");
                return false;
        }

    // resize
    if(list -> size == list -> maxSize){
        _alist_resize(list);
    }
    
    // pointer set to end and add
    list -> arr[list -> size] = malloc(sizeof(item));
    if(list -> arr[list -> size] == NULL){
        printf("malloc fail\n");
        return false;
    }
    memcpy(list -> arr[list -> size], item, sizeof(item));
    list -> size++;

    return true;
}

// insert item to a specified index
bool alist_add_at(ArrayList* list, int index, void* item) {
    if(list == NULL){
        printf("NULL list\n");
        return false;
    }

    // resize
    if(list -> size == list -> maxSize) {
        _alist_resize(list);
    }
    
    // malloc for expand slot
    list -> arr[list -> size] = malloc(sizeof(list -> arr[list -> size - 1]));
    if(list -> arr[list -> size] == NULL) {
        printf("malloc fail\n");
        return false;
    }

    // new index is the last of array
    if(index == list -> size) {
        memcpy(list -> arr[index], item, sizeof(item));
        list -> size++;
        return true;
    }

    // add and move right hand items to right
    for(int i = list -> size; i > index; --i){
        memcpy(list -> arr[i], list -> arr[i - 1], sizeof(list -> arr[i - 1]));
    }
    memcpy(list -> arr[index], item, sizeof(item));
    list -> size++;

    return true;
}

// deallocate the given list
void alist_clear(ArrayList* list) {
    for(int i = 0; i < list -> size; ++i){
        if(list -> arr[i] == NULL) { continue; }
        free(list -> arr[i]);
    }
    list -> size = 0;

    return;
}

// get the pointer to the data at given index
void* alist_get(ArrayList* list, int index) {
    if(index >= list -> size || index < 0){
        printf("Invalid index\n");
        return NULL;
    }

    return list -> arr[index];
}

// search for the given item and return its index, return -1 if not found
int alist_index_of(ArrayList* list, void* target) {
    if(list == NULL){
                printf("NULL list\n");
                return -1;
        }

    for(int i = 0; i < list -> size; ++i){
        if(memcmp(list -> arr[i], target, sizeof(target)) == 0) { return i; }
            
    }

    return -1;
}

// remove the item at the given index
void* alist_remove(ArrayList* list, int index) {
    if(list == NULL){
                printf("NULL list\n");
                return NULL;
        }
    
    if(index >= list -> size || index < 0){
        printf("Invalid index\n");
        return NULL;
    }
    
    // store the removed item
    void* rmItem = malloc(sizeof(list->itemSize));
    memcpy(rmItem, list -> arr[index], sizeof(list -> itemSize));
   
    // move items right hand of rmItem to one slot left
    for(int i = index + 1; i < (list -> size); ++i){
        memcpy(&list -> arr[i-1], &list -> arr[i], sizeof(list -> itemSize));
    }
    list -> size --;

    return rmItem;
}

// destroy the given array_list
bool alist_destroy(ArrayList* list) {
    alist_clear(list);
    free(list -> arr);
    free(list);
    return true;
}

// resize the array_list, grow factor = 2
bool _alist_resize(ArrayList* list) {
    list -> arr = realloc(list -> arr, 2 * list -> maxSize * sizeof(void*));
    list -> maxSize *= 2;
    return true;
}
