//
// linked_list.c
// Yuxuan Wang
// B00880845
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

// initialize a linked_list with size and type, and return it
LinkedList* llist_initialize(int dataSize, char* dataType) {
	LinkedList* list = malloc(sizeof(LinkedList));
	if (list == NULL) { return NULL; } 
	
	list -> first = NULL;
	list -> last = NULL;
	list -> size = 0;
	list -> itemSize = dataSize;
	list -> type = dataType;

	return list;
}

// insert the given element at the given index in the linked list
bool llist_add_at(LinkedList* list, int index, void* item) {
	if (list == NULL) { 
		printf("NULL list");
		return false;
	}

	if (index > list -> size || index < 0) {
		printf("Invalid index");
		return false;
	}
	
	// add position is first or last
	if (index == 0) { return llist_add_first(list, item); }
	if(index == list->size) { return llist_add_last(list, item); }

	// index in the middle
	Node* node = malloc(sizeof(Node));
	if(node == NULL) { 
		printf("malloc fail");
		return false;
	}
	node -> data = malloc(sizeof(item));
	memcpy(node -> data, item, sizeof(item));
	
	Node* curr = list -> first;
	for (int i = 0; i < index; ++i) {
		curr = curr -> next;
	}
	node -> next = curr -> next;
	node -> prev = curr;
	curr -> next = node;
	node -> next -> prev = node;
	list -> size ++;
	return true;
}

// add item to the front of the linked_list
bool llist_add_first(LinkedList* list, void* item)
{
	if(list == NULL){
                printf("NULL list\n");
                return false;
        }

	Node* node = malloc(sizeof(Node));
        if(node == NULL){
                printf("malloc fail\n");
                return false;
        }
	
        node -> data = malloc(sizeof(item));
        memcpy(node -> data, item, sizeof(item));
	
	// empty list case
	if(list -> size == 0){
		list -> first = node;
		list -> last = node;
		list -> size++;
		return true;
	}

	node -> next = list -> first;
	list -> first -> prev = node;
	list -> first = node;
	list -> size++;

	return true;
}

// add item to the last
bool llist_add_last(LinkedList* list, void* item)
{
	if(list == NULL){
                printf("NULL list\n");
                return false;
        }

        Node* node = malloc(sizeof(Node));
        if(node == NULL){
                printf("malloc fail\n");
                return false;
        }   
        node -> data = malloc(sizeof(item));
        memcpy(node -> data, item, sizeof(item));
	
	// empty list case
        if(list -> size == 0){
                list -> first = node;
                list -> last = node;
                list -> size++;
                return true;
        }

	node -> prev = list->last;
	list -> last->next = node;
	list -> last = node;
	list -> size++;

	return true;
}

// retrieve item at specified index
void* llist_get(LinkedList* list, int index)
{
	if(list == NULL){
                printf("NULL list\n");
                return NULL;
        }

	if(index >= list->size || index < 0){
                printf("Invalid index\n");
                return NULL;
        }

	Node* target = list -> first;
	int pt = 0;
	while(pt != index){
		target = target -> next;
		pt++;
	}

	return target -> data;
}

// find the index of specified item, return -1 on fail
int llist_index_of(LinkedList* list, void* target){
	if(list == NULL){
                printf("NULL list\n");
                return -1;
        }
	
	Node* temp = list -> first;
	for(int i = 0; i < list -> size; ++i){
		if(memcmp(temp -> data, target, sizeof(target) == 0))
			return i;
		temp = temp->next;
	}

	return -1;
}

// remove item at specified index
void* llist_remove(LinkedList* list, int index){
	if(list == NULL){
                printf("NULL list\n");
                return NULL;
        }

        if(index > list->size || index < 0){
                printf("Invalid index\n");
                return NULL;
        }

	// index equals front or last
        if(index == 0) { return llist_remove_first(list); } 
        if(index == list -> size) { return llist_remove_last(list); }
                
	// index in the middle
	Node* rmItem = list -> first;
        int pt = 0;
        while(pt != index){
                rmItem = rmItem -> next;
                pt++;
        }

	rmItem -> prev -> next = rmItem -> next;
	rmItem -> next -> prev = rmItem -> prev;
	rmItem -> prev = NULL;
	rmItem -> next = NULL;
	list -> size--;

	return rmItem;
}

// remove the front node of the list and return the data
void* llist_remove_first(LinkedList* list)
{
	if(list == NULL){
		printf("NULL list\n");
		return NULL;
	}
	
	// empty list
	if(list -> first == NULL) { return NULL; }
	
	Node* rmItem = list -> first;
	
	// contains only 1 item 
	if(list -> size == 1){
		list -> first = NULL;
		list -> last = NULL;
		list -> size--;
		return rmItem;
	}

	Node* curr = list -> first;
	curr -> next -> prev = NULL;
	list -> first = curr->next;
	curr -> next = NULL;
	list -> size--;

	return rmItem;
}

// remove the rear node of the list, and return the removed data
void* llist_remove_last(LinkedList* list)
{
	if(list == NULL){
                printf("NULL list\n");
                return NULL;
        }
	
	// empty list
	if(list -> last == NULL) { return NULL; }
	
	Node* rmItem = list->last;
            
        // contains only 1 item
        if(list -> size == 1){ 
                list -> first = NULL;
                list -> last = NULL;
                list -> size--;
                return rmItem;
        }

	Node* curr = list -> last;
	curr -> prev -> next = NULL;
	list -> last = curr -> prev;
	curr -> prev = NULL;
	list -> size--;

	return rmItem;
}

// destroy the whole list
bool llist_destroy(LinkedList* list){
	if(list == NULL) { return true; }
	
	Node* curr = list -> first;
	for(int i = 0; i < (list -> size - 1); ++i){
		free(curr -> data);
		curr = curr -> next;
		free(curr -> prev);
	}

	free(curr -> data);
	free(curr);
	free(list);
	return true;
}