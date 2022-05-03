//
//  book.c
//  Lab4
//
//  Created by Yuxuan Wang on 2021-10-09.
//  B00880845
//

#include <stdio.h>
#include <string.h>
#include "book.h"

// create a new book
Book* make_book(int maxLine) {
    Book *book = malloc(sizeof(Book));
    // Initialize values for the newBook:
    book -> characterCount = 0;
    book -> lineCount = 0;
    book -> lines = malloc(maxLine * sizeof(char*));
    return book;
}

// clean lines and destroy the book
void burn_book(Book* book) {
    for(int i = 0; i < book->lineCount; ++i) {
        free(book -> lines[i]);
        book -> lines[i] = NULL;
    }
    
    free(book);
    book = NULL;
}

// store book contents to a file, return true if success, false if fail
bool save_book(Book* book, char* file) {
    FILE *fp = fopen(file, "w");
    if(fp == NULL) {
        fclose(fp);
        return false;
    }

    for(int i = 0; i < book -> lineCount; ++i) {
        fputs(book -> lines[i], fp);
    }

    fclose(fp);
    return true;
}

// read and store a book to a file, return true if success, false if fail
bool fill_book(Book* book, char* file) {
    FILE *fp = fopen(file, "r");
    
    // file not found exception
    if(fp == NULL) {
        printf("No such file!\n");
        fclose(fp);
        return false;
    }
    
    // file exists
    char* chArr = malloc(1500 * sizeof(char));
    while(fgets(chArr, 1500, fp) != NULL) {
        book -> lines[book -> lineCount] = malloc(1500 * sizeof(char));
        strcpy(book -> lines[book -> lineCount], chArr);
        book -> characterCount += strlen(chArr);
        ++book -> lineCount;
    }
    
    fclose(fp);
    free(chArr);
    chArr = NULL;
    return true;
}

// removes a line that contains provided word(s)
int edit_book(Book* book, char* word) {
    int rm = 0;
    for(int i = 0; i < book -> lineCount; ++i) {
        // overwrite the previous line
        if(strstr(book -> lines[i], word) != NULL) {
            book -> characterCount -= strlen(book -> lines[i]);
            for(int j = i; j < book -> lineCount - 1; ++j) {
                book -> lines[j] = book -> lines[j + 1];
            }
 
            --book -> lineCount;
            ++rm;
            --i;
            book -> lines[book -> lineCount] = NULL;
        }
    }
    return rm;
}

// print out the book line-by-line
void read_book(Book* book) {
    for(int i = 0; i < book -> lineCount; ++i) {
        printf("%s", book -> lines[i]);
    }
}
