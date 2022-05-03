// power.c
// author: YuxuanWang, B00880845

#include <stdio.h>
#include "power.h"

// numbers in the function names indicate the heighest power of a polynomial
void powerRule1(int a, int b) {
	printf("%d\n", a);
}

void powerRule2(int a, int b, int c) {
	printf("%dx + %d\n", (2 * a), b);
}

void powerRule3(int a, int b, int c, int d) {
	printf("%dx^2 + %dx + %d\n", (3 * a), (2 * b), c);
}

void powerRule4(int a, int b, int c, int d, int e) {
	printf("%dx^3 + %dx^2 + %dx + %d\n", (4 * a), (3 * b), (2 * c), d);
}
