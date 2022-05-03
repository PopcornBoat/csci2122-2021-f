//
//  calculator.c
//  Lab4
//
//  Created by Yuxuan Wang on 2021-10-13.
//  B00880845
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "calculator.h"

// initialize a calculator
Calculator* create_calculator(double (**op)(int, int), int opCount) {
    Calculator *cal = malloc(sizeof(Calculator));
    cal -> operationCount = opCount;
    cal -> dataLength = 0;
    cal -> operations = malloc(opCount * sizeof(double (*)(int, int)));
    cal -> operations = op;
    cal -> data = malloc(100 * sizeof(int*));
    
    for(int i = 0; i < 100; ++i) {
        cal -> data[i] = malloc(3 * sizeof(int));
    }
    return cal;
}

// read and store data into calculator, return true on success, false on fail
bool load_calculator_data(Calculator* cal, char* file) {
    FILE *fp = fopen(file, "r");
    if(fp == NULL) {
        printf("No such file!");
        fclose(fp);
        return false;
    }
    
    for(int i = 0; i < 100; ++i) {
        for(int j = 0; j < 3; ++j) {
            fscanf(fp, "%d", &(cal -> data[i][j]));
        }
        ++cal -> dataLength;
    }
    
    fclose(fp);
    return true;
}

// take in instructions as param, perform in order and print out results
void run_calculator(Calculator* cal) {
    for(int i = 0; i < cal -> dataLength; ++i) {
        int op = cal->data[i][0];
        if (op == 0) {
            printf("%.5f\n", cal -> operations[0](cal -> data[i][1], cal -> data[i][2]));
    	    continue;
        }
        if (op == 1) {
            printf("%.5f\n", cal -> operations[1](cal -> data[i][1], cal -> data[i][2]));
    	    continue;
        }
        if (op == 2) {
            printf("%.5f\n", cal -> operations[2](cal -> data[i][1], cal -> data[i][2]));
    	    continue;
        }
        if (op == 3) {
            printf("%.5f\n", cal -> operations[3](cal -> data[i][1], cal -> data[i][2]));
    	    continue;
        }
        if (op == 4) {
            printf("%.5f\n", cal -> operations[4](cal -> data[i][1], cal -> data[i][2]));
    	    continue;
        }
        else { printf("operation error!"); }
    }
}

// free a calculator memory space
bool destroy_calculator(Calculator* cal) {
    for(int i = 0; i < cal -> dataLength; ++i) {
        free(cal -> data[i]);
    }
    
    free(cal -> data);
    free(cal);
    return true;
}

// math operations
double add_calculator(int a, int b) { return (double) a + (double) b; }

double sub_calculator(int a, int b) { return (double) a - (double) b; }

double mul_calculator(int a, int b) { return (double) a * (double) b; }

double div_calculator(int a, int b) { return (double) a / (double) b; }

double mod_calculator(int a, int b) { return a % b; }
