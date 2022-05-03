//
//  calculator.h
//  Lab4
//
//  Created by Yuxuan Wang on 2021-10-09.
//  B00880845
//

#ifndef calculator_h
#define calculator_h

#include <stdbool.h>

typedef struct _Calaulator {
    double (**operations)(int, int);
    int **data;
    int operationCount;
    int dataLength;
} Calculator;

Calculator* create_calculator(double (**)(int, int), int);
bool load_calculator_data(Calculator*, char*);
void run_calculator(Calculator*);
bool destroy_calculator(Calculator*);
double add_calculator(int, int);
double sub_calculator(int, int);
double mul_calculator(int, int);
double div_calculator(int, int);
double mod_calculator(int, int);

#endif /* calculator_h */
