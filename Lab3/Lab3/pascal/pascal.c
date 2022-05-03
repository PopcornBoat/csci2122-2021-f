//
//  pascal.c
//  Lab3
//
//  Created by Yuxuan Wang on 2021-10-07.
//  B00880845

#include <stdio.h>
#include "pascal.h"
#include "mmath.h"

void pascal(int n){
    for(int i = 0; i <= n; ++i){
        printf("%ld ", nchoosek(n, i));
    }
    printf("\n");
}
