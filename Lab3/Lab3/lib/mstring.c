//
//  mstring.c
//  Lab3
//
//  Created by Yuxuan Wang on 2021-10-06.
//  B00880845
//

#include <string.h>
#include "mstring.h"

// reverse a string in place
void strrev(char *str){
    int len = strlen(str);
    char temp;

    for(int i = 0; i < (len / 2); ++i){
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
