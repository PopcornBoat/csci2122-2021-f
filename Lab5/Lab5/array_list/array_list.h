//
// array_list.h
// Yuxuan Wang
// B00880845
//
#ifndef _array_list_h
#define _array_list_h

#include <stdbool.h>

typedef struct _AList
{
	void** arr;
	int size;
	int maxSize;
	int itemSize;
	char* type;	
} ArrayList;

ArrayList* alist_initialize(int, int, char*);
bool alist_add(ArrayList*, void*);
bool alist_add_at(ArrayList*, int, void*);
void alist_clear(ArrayList*);
void* alist_get(ArrayList*, int);
int alist_index_of(ArrayList*, void*);
void* alist_remove(ArrayList*, int);
bool alist_destroy(ArrayList*);
bool _alist_resize(ArrayList*);

#endif
