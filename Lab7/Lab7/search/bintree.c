//
//  bintree.c
//  Yuxuan Wang
//  B00880845
//  some functions are modified based on the Lab6 solution provided by Robert
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bintree.h"
#include "queue.h"
#include "stack.h"

// create a node containing the given item
BinaryTreeNode* bintree_create_node(int itemSize, void* item) {
    BinaryTreeNode* node = malloc(sizeof(*node));
    
    // mallco fail, NULL node
    if(node == NULL) { return NULL; }
    
    node -> data = malloc(itemSize);
    memcpy(node -> data, item, itemSize);
    node -> left = NULL;
    node -> right = NULL;
    
    return node;
}

// initialize a binary tree
BinaryTree* bintree_initialize(int typeSize, char* type, int (*compare)(void*, void*), void (*print)(void*)) {
    BinaryTree* bintree = malloc(sizeof(*bintree));
    
    // malloc fail, NULL tree
    if(bintree == NULL) { return NULL; }
    
    bintree -> top = NULL;
    bintree -> itemSize = typeSize;
    bintree -> type = malloc(strlen(type) + 1);
    strcpy(bintree -> type, type);
    bintree -> compare = compare;
    bintree -> print = print;
    
    return bintree;
}

// insert the given item to the tree
bool bintree_insert(BinaryTree* bintree, void* item){
    if(bintree == NULL || item == NULL) { return false; }
    if(bintree->top == NULL) {
    	bintree->top = bintree_create_node(bintree->itemSize, item);

	if(bintree->top == NULL) { return false; }
	return true;
    }
    else{
	return _bintree_insert_recursive(bintree, bintree->top, item);	
    }
}

// search if an item in the tree
bool bintree_search(BinaryTree* bintree, void* target) {
    if(bintree == NULL || target == NULL) { return false; }
    
    // empty tree
    if(bintree -> top == NULL) { return false; }
    else {
        return _bintree_search_recursive(bintree, bintree -> top, target);
    }
}

// in-order travers
void bintree_print_in_order(BinaryTree* bintree) {
   if(bintree == NULL || bintree->top == NULL) { return; }
        
   return _bintree_in_order_recursive(bintree, bintree -> top);
}

// pre-order travers
void bintree_print_pre_order(BinaryTree* bintree) {
    if(bintree == NULL || bintree->top == NULL) { return; }
    else {
        return _bintree_pre_order_recursive(bintree, bintree -> top);
    }
}

// post-order travers
void bintree_print_post_order(BinaryTree* bintree) {
    if(bintree == NULL || bintree->top == NULL) { return; }
    return _bintree_post_order_recursive(bintree, bintree -> top);
}

// reverse order travers
void bintree_print_reverse_order(BinaryTree* bintree){
    if(bintree == NULL || bintree->top == NULL) { return; }
    return _bintree_reverse_order_recursive(bintree, bintree -> top);
}

// below 3 functions are added in Lab7
// perform a BFS
void bintree_print_breadth_first(BinaryTree* bintree) {
    // NULL tree check
    if (bintree == NULL) { return; }
    
    BinaryTreeNode* curr = bintree -> top;
    Queue* store = queue_initialize(sizeof(BinaryTreeNode), "BinaryTreeNode");
    
    // BFS
    if (!queue_enqueue(store, curr)) { return;}
    while (queue_size(store) != 0) {
        curr = queue_dequeue(store);
        bintree -> print(curr -> data);
        if (curr -> left != NULL) { queue_enqueue(store, curr -> left); }
        if (curr -> right != NULL) { queue_enqueue(store, curr -> right); }
    }
    queue_destroy(store);
    return;
}

// perform a DFS
void bintree_print_depth_first(BinaryTree* bintree) {
    // NULL tree check
    if (bintree == NULL) { return; }
    
    BinaryTreeNode* curr = bintree -> top;
    Stack* store = stack_initialize(sizeof(BinaryTreeNode), "BinaryTreeNode");
    
    // DFS
    if (!stack_push(store, curr)) { return; }
    while (stack_size(store) != 0) {
        curr = stack_pop(store);
        bintree -> print(curr -> data);
        if (curr -> right != NULL) { stack_push(store, curr -> right); }
	if (curr -> left != NULL) { stack_push(store, curr -> left); }
    }
    stack_destroy(store);
    return;
}

// insert the given item into the given binary tree
bool bintree_insert_replace(BinaryTree* bintree, void* item) {
    // NULL tree and NULL item check
    if (bintree == NULL || item  == NULL) { return false; }
    
    // insert
    // empty tree, create a node for the data and then insert
    if (bintree -> top == NULL) {
        bintree -> top = bintree_create_node(bintree -> itemSize, item);
        // allocation fail check
        if (bintree -> top == NULL) { return false; }
        return true;
    }
    return _bintree_insert_replace_recursive(bintree, bintree -> top, item);
}

// helper functions below

bool _bintree_insert_recursive(BinaryTree* bintree, BinaryTreeNode* node, void* item){
    if(bintree == NULL || item == NULL) { return false; }
    
    if(bintree -> compare(item, node -> data) > 0){
        if(node -> left != NULL) {
            return _bintree_insert_recursive(bintree, node -> left, item);
        }
        node -> left = bintree_create_node(bintree -> itemSize, item);
        return true;
    }
    else {
        if(node -> right != NULL) {
            return _bintree_insert_recursive(bintree, node -> right, item);
        }
        node -> right = bintree_create_node(bintree -> itemSize, item);
        return true;
    }
}

bool _bintree_search_recursive(BinaryTree* bintree, BinaryTreeNode* node, void* target){
    if(bintree == NULL || target == NULL) { return false; }
    
    if(node == NULL) { return false; }
    
    if(bintree -> compare(target, node -> data) > 0) {
        return _bintree_search_recursive(bintree, node -> left, target);
    }
    else if (bintree -> compare(target, node -> data) < 0) {
        return _bintree_search_recursive(bintree, node -> right, target);
    }
    else { return true; }
}

void _bintree_in_order_recursive(BinaryTree* bintree, BinaryTreeNode* node){
    if(bintree == NULL || node == NULL) { return; }
    
    if(node != NULL) {
        _bintree_in_order_recursive(bintree, node -> left);
        bintree -> print(node -> data);
        _bintree_in_order_recursive(bintree, node -> right);
    }
    return;
}

void _bintree_pre_order_recursive(BinaryTree* bintree, BinaryTreeNode* node){
    if(bintree == NULL || node == NULL) { return; }
    
    if(node != NULL){
        bintree -> print(node -> data);
        _bintree_pre_order_recursive(bintree, node -> left);
        _bintree_pre_order_recursive(bintree, node -> right);
    }
    return;
}

void _bintree_post_order_recursive(BinaryTree* bintree, BinaryTreeNode* node){
    if(bintree == NULL || node == NULL) { return; }
    
    if(node != NULL){
        _bintree_post_order_recursive(bintree, node -> left);
        _bintree_post_order_recursive(bintree, node -> right);
        bintree -> print(node -> data);
    }
    return;
}

void _bintree_reverse_order_recursive(BinaryTree* bintree, BinaryTreeNode* node){
    if(bintree == NULL || node == NULL) { return; }
    
    if(node != NULL){
        _bintree_reverse_order_recursive(bintree, node -> right);
        bintree -> print(node -> data);
        _bintree_reverse_order_recursive(bintree, node -> left);
    }
    return;
}

// this helper function is added in Lab7
// compare the insert item and the current node item
bool _bintree_insert_replace_recursive(BinaryTree* bintree, BinaryTreeNode* node, void* item) {
    // insert and replace
    // case less
    if (bintree -> compare(node -> data, item) < 0) {
        // nothing left on the left branch, create a new node for the item
        if (node -> left == NULL) {
            node -> left = bintree_create_node(bintree -> itemSize, item);
            if (node -> left == NULL) { return false; }
            return true;
        }
        else {
            // recursive insert on left
            return _bintree_insert_replace_recursive(bintree, node -> left, item);
        }
    }
    // case equal
    if (bintree -> compare(node -> data, item) == 0) {
        // !!fixed place
        memcpy(node -> data, item, bintree -> itemSize);
        return true;
    }
    // case greater
    if (bintree -> compare(node -> data, item) > 0) {
        // nothing left on the right branch, create a new node for the item
        if (node -> right == NULL) {
            node -> right = bintree_create_node(bintree -> itemSize, item);
            if (node -> right == NULL) { return false; }
            return true;
        }
        else {
            // recursive insert on right
            return _bintree_insert_replace_recursive(bintree, node -> right, item);
        }
    }
}
