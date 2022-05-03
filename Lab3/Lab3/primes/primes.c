//
//  primes.c
//  Lab3
//
//  Created by Yuxuan Wang on 2021-10-07.
//  B00880845
//

#include <stdio.h>
#include "primes.h"

void primes(long n){
    for(int i = 2; i <= n; ++i){
        while(n % i == 0){
            printf("%d ", i);
            n /= i;
        }
    }
    printf("\n");
}
