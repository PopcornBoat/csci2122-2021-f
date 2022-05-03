//
//  bintree.c
//  Yuxuan Wang
//  B00880845
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bintree.h"

// create a node containing the given item
BinaryTreeNode* bintree_create_node(int itemSize, void* item) {
    BinaryTreeNode* node = malloc(sizeof(*node));
    
    // mallco fail, NULL node
    if(node == NULL) { return NULL; }
    
    node -> data = malloc(sizeof(item));
    memcpy(node -> data, item, sizeof(item));
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
    bintree -> type = malloc(strlen(type));
    strcpy(bintree -> type, type);
    bintree -> compare = compare;
    bintree -> print = print;
    
    return bintree;
}

// insert the given item to the tree
bool bintree_insert(BinaryTree* bintree, void* item){
    if(bintree == NULL || item == NULL) return false;
    
    // empty tree
    if(bintree -> top == NULL) {
        BinaryTreeNode* node = bintree_create_node(bintree -> itemSize, item);
        bintree -> top = node;
        return true;
    }
    // non-empty tree
    else{
        return _bintree_insert_recursive(bintree, bintree -> top, item);
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
    if(bintree == NULL) { return; }
    
    if(bintree -> top == NULL) { return; }
        
    else {
        return _bintree_in_order_recursive(bintree, bintree -> top);
    }
}

// pre-order travers
void bintree_print_pre_order(BinaryTree* bintree) {
    if(bintree == NULL) { return; }
    
    if(bintree -> top == NULL) { return; }
    else {
        return _bintree_pre_order_recursive(bintree, bintree -> top);
    }
}

// post-order travers
void bintree_print_post_order(BinaryTree* bintree) {
    if(bintree == NULL) { return; }
    
    if(bintree -> top == NULL) { return; }
    else {
        return _bintree_post_order_recursive(bintree, bintree -> top);
    }
}

// reverse order travers
void bintree_print_reverse_order(BinaryTree* bintree){
    if(bintree == NULL) { return; }
    
    if(bintree -> top == NULL) { return; }
    else {
        return _bintree_reverse_order_recursive(bintree, bintree -> top);
    }
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
