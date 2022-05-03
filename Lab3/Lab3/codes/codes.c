//
//  codes.c
//  Lab3
//
//  Created by Yuxuan Wang on 2021-10-07.
//  B00880845
//

#include <math.h>
#include <stdio.h>
#include "codes.h"
#include "mmath.h"

int encrypt(int start, int offset, char target){
    int cipher = bitrevc(target);
    cipher = cipher << start;
    cipher = cipher >> offset;
    return cipher;
}

char decrypt(int start, int offset, int cipher){
    cipher = cipher << offset;
    cipher = cipher >> start;
    char target = bitrevc(cipher);
    return target;
}
