// triangle.c
// author: YuxuanWang, B00880845

#include <stdio.h>
#include <math.h>
#include "triangle.h"

double findOppositePyth(double b, double c, double x, double y) {
    double a = sqrt(pow(c, 2) - pow(b, 2));
    toString(a, b, c, x, y);
    return a;
}

double findAdjacentPyth(double a, double c, double x, double y) {
    double b = sqrt(pow(c, 2) - pow(a, 2));
    toString(a, b, c, x, y);
    return b;
}

double findHypotenusePyth(double a, double b, double x, double y) {
    double c = sqrt(pow(a, 2) + pow(b, 2));
    toString(a, b, c, x, y);
    return c;
}

double findOppositeTrig(double b, double c, double x, double y) {
    double a = (c * sin(x));
    toString(a, b, c, x, y);
    return a;
}

double findAdjacentTrig(double a, double c, double x, double y) {
    double b = (c * cos(x));
    toString(a, b, c, x, y);
    return b;

}

double findHypotenuseTrig(double a, double b, double x, double y) {
    double c = (b / cos(x));
    toString(a, b, c, x, y);
    return c;

}

void toString(double a, double b, double c, double x, double y) {
    printf("\nopposite = %.2f\nadjacent = %.2f\nhypotenuse = %.2f\nx = %.2f\ny = %.2f\n\n", a, b, c, x, y);
}
