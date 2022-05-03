//
//  adjmult.c
//  Lab3
//
//  Created by Yuxuan Wang on 2021-10-06.
//  B00880845
//

#include <stdio.h>
#include "adjmult.h"

int largestProduct(){
    int matrix[20][20];
    int max = 0, temp = 1, k = 3;
    
    // pass the input grid to a matrix
    for(int i = 0; i < 20; ++i){
        for(int j = 0; j < 20; ++j){
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for(int i = 0; i < 20; ++i){
        for(int j = 0; j < 20; ++j){
            
            // bot to top
            if( i >= 3){
                while(k >= 0){
                    temp *= matrix[i - k][j];
                    --k;
                }
                if(temp > max){ max = temp; }
                k = 3;
                temp = 1;
            }
            
            // top to bot
            if(i <= 16){
                while(k >= 0){
                    temp *= matrix[i + k][j];
                    --k;
                }
                if(temp > max){ max = temp; }
                k = 3;
                temp = 1;
            }
            
            // right to left
            if(j >= 3){
                while(k >= 0){
                    temp *= matrix[i][j - k];
                    --k;
                }
                if(temp > max){ max = temp; }
                k = 3;
                temp = 1;
            }
            
            // left to right
            if(j <= 16){
                while(k >= 0){
                    temp *= matrix[i][j + k];
                    --k;
                }
                if(temp > max){ max = temp; }
                k = 3;
                temp = 1;
            }
            
            
            // to top-left
            if(j >= 3 && i >= 3){
                while(k >= 0){
                    temp *= matrix[i - k][j - k];
                    --k;
                }
                if(temp > max){ max = temp; }
                k = 3;
                temp = 1;
            }
            
            // tp bot-left
            if(j >= 3 && i <= 16){
                while(k >= 0){
                    temp *= matrix[i + k][j - k];
                    --k;
                }
                if(temp > max){ max = temp; }
                k = 3;
                temp = 1;
            }
            
            // to top-right
            if(j <= 16 && i >= 3){
                while(k >= 0){
                    temp *= matrix[i - k][j + k];
                    --k;
                }
                if(temp > max){ max = temp; }
                k = 3;
                temp = 1;
            }
            
            // to bot-right
            if(j <= 16 && i <= 16){
                while(k >= 0){
                    temp *= matrix[i + k][j + k];
                    --k;
                }
                if(temp > max){ max = temp; }
                k = 3;
                temp = 1;
            }
        }
    }
    return max;
}
