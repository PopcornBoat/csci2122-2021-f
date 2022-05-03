//
//  book.h
//  Lab4
//
//  Created by Yuxuan Wang on 2021-10-09.
//  B00880845
//

#ifndef book_h
#define book_h

#include <stdlib.h>
#include <stdbool.h>

typedef struct _Book {
    int characterCount;
    int lineCount;
    char **lines;
} Book;

Book* make_book(int);
void burn_book(Book*);
bool save_book(Book*, char*);
bool fill_book(Book*, char*);
int edit_book(Book*, char*);
void read_book(Book*);

#endif /* book_h */
