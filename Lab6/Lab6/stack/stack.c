//
// stack.c
// Yuxuan Wang
// B00880845
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

// initialize a stack
Stack* stack_initialize(int typeSize, char* type) {
	Stack* stack = malloc(sizeof(*stack));
	
	// malloc fail check
    if(stack == NULL) { return NULL; }
	
	stack -> front = NULL;
	stack -> tail  = NULL;
	stack -> size  = 0;
	stack -> itemSize = typeSize;
	stack -> type = malloc(strlen(type));
	strcpy(stack -> type, type);

	return stack;
}

// add item to the top of the stack
bool stack_push(Stack* stack, void* item) {
    if(stack == NULL || item == NULL) { return false; }

	// put item in a node
	Node *node = malloc(sizeof(*node));
	node -> data = malloc(sizeof(item));
	memcpy(node -> data, item, sizeof(item));

    // push case: empty stack
	if(stack -> size == 0) {
		stack -> front = node;
		stack -> tail = node;
		node -> next = NULL;
		node -> prev = NULL;
		stack -> size++;
		return true;
	}
	
	// push case: non-empty stack
	node -> next = stack -> front;
	stack -> front -> prev = node;
	stack -> front = node;
	stack -> size++;
	return true;
}

// remove the top item of the stack
void* stack_pop(Stack* stack){
    if(stack == NULL || stack -> size == 0) { return NULL; }
	
	void* rmItem = stack -> front -> data;
	
	// case: stack size = 1
	if(stack -> size == 1) {
		stack -> front = NULL;
		stack -> tail = NULL;
		stack -> size--;
		free(stack -> front);
		return rmItem;
	}
	
    // stack size > 1
	Node* curr = stack -> front;
	curr -> next -> prev = NULL;
	stack -> front = curr -> next;
	curr -> next = NULL;
	stack -> size--;
	free(curr);
	return rmItem;
}

// check the top item of the stack
void* stack_peek(Stack* stack){
    if(stack == NULL || stack -> size == 0) { return NULL; }
	return stack -> front -> data;
}

// check the size of the stack, return -1 if empty stack
int stack_size(Stack* stack){
    if(stack == NULL) { return -1; }
	return stack -> size;
}

// check if the specified item is in the item
bool stack_contains(Stack* stack, void* target){
    if(stack == NULL || target == NULL) { return false; }
    if(stack -> size == 0) { return false; }
	
	Node* curr = stack -> front;
	for(int i = 0; i < stack -> size; i++){
        if(memcmp(curr -> data, target, sizeof(target)) == 0) { return true; }
        
		curr = curr -> next;
	}
	return false;
}

// destory the stack
bool stack_destroy(Stack* stack){
	// null stack, return false
    if(stack == NULL) { return false; }
		
	// free nodes
	if(stack -> size > 0) {
		Node *curr = stack -> front;
		Node *next = NULL;
			
		for(int i=0; i < stack -> size; i++) {
			next = curr -> next;
			free(curr -> data);
			free(curr);
			curr = next;
		}
        free(stack -> type);
        free(stack);
	}
    
	return true;
}

