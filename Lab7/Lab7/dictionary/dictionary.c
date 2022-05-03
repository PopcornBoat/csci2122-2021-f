//
//  dictionary.c
//  Lab7
//  Yuxuan Wang, B00880845
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

// initialize a Dictionary
Dictionary* dict_initialize(int (*compare)(void*, void*), void (*print)(void*)){
    BinaryTree* bintree = bintree_initialize(sizeof(Pair), "Pair", compare, print);
    if(bintree == NULL) { return NULL; }
    Dictionary* map = malloc(sizeof(*map));
    if(map == NULL) { return NULL; }
    map -> tree = bintree;
    return map;
}

// insert a key:value pair into the dictionary
bool dict_insert(Dictionary* map, void* key, void* value){
    if(map == NULL || key == NULL || value == NULL) { return false; }
    
    // make a Pair on the given key and value
    Pair* pair = malloc(sizeof(*pair));
    pair -> first = malloc(sizeof(key));
    pair -> second = malloc(sizeof(value));
    
    // assign data to the pair
    memcpy(pair -> first, key, sizeof(key));
    memcpy(pair -> second, value, sizeof(value));
    
    return bintree_insert_replace(map -> tree, pair);
}

// retrieve the data by given key
void* dict_get(Dictionary* map, void* key){
    if(map == NULL || key == NULL) { return NULL; }
    
    BinaryTreeNode* curr = map -> tree -> top;
    Pair* pair = curr -> data;
    Pair* target = malloc(sizeof(*target));
    target -> first = key;
    if(curr == NULL || pair == NULL) { return NULL; }
    
    int compare = 0;
    // three cases of compare
    while (curr != NULL) {
        compare = map -> tree -> compare(pair, target);
        if(compare < 0){
            if(curr -> left == NULL) { return NULL; }
            curr = curr -> left;
            pair = curr -> data;
            continue;
        }
        if(compare == 0){
            free(target);
            return pair -> second;
        }
        if(compare > 0){
            if(curr -> right == NULL) { return NULL; }
            curr = curr -> right;
            pair = curr -> data;
            continue;
        }
    }
    return NULL;
}

// save all the keys in a list in order, and return the list
ArrayList* dict_key_list(Dictionary* map, int keySize){
    if(map == NULL) { return NULL; }
    
    // the return list
    ArrayList* rtList = alist_initialize(20, keySize, "Key");
    BinaryTreeNode* start = map -> tree -> top;
    Pair* pair = start -> data;
    
    _dict_key_list_recursive(map -> tree, start, pair, rtList);
    return rtList;
}

bool dict_contains(Dictionary* map, void* key){
    if(map == NULL || key == NULL) { return false; }
    Pair* target = malloc(sizeof(*target));
    target -> first = key;
    
    bool res = bintree_search(map -> tree, target);
    free(target);
    
    return res;
}

// helper function
void _dict_key_list_recursive(BinaryTree* bintree, BinaryTreeNode* node, Pair* pair, ArrayList* list){
    if(bintree == NULL || node == NULL) { return; }
    if(pair == NULL || list == NULL) { return; }

    if(node -> left != NULL) {
        _dict_key_list_recursive(bintree, node -> left, node -> left -> data, list);
    }
    alist_add(list, pair -> first);
    if(node -> right != NULL) {
        _dict_key_list_recursive(bintree, node -> right, node -> right -> data, list);
    }
}


