//
//  dictionary.h
//  Lab7
//  Yuxuan Wang, B00880845
//

#ifndef dictionary_h
#define dictionary_h

#include <stdbool.h>
#include "bintree.h"
#include "array_list.h"

typedef struct _Pair {
    void* first;
    void* second;
} Pair;

typedef struct _Dictionary {
    BinaryTree* tree;
} Dictionary;

Dictionary* dict_initialize(int (*)(void*, void*), void (*)(void*));
bool dict_insert(Dictionary*, void*, void*);
void* dict_get(Dictionary*, void*);
ArrayList* dict_key_list(Dictionary*, int);
bool dict_contains(Dictionary*, void*);

// helper function
void _dict_key_list_recursive(BinaryTree*, BinaryTreeNode*, Pair*, ArrayList*);
#endif /* dictionary_h */
