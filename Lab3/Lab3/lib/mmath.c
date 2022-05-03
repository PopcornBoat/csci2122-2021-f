//
//  mmath.c
//  Lab3
//
//  Created by Yuxuan Wang on 2021-10-06.
//  B00880845
//

#include "mmath.h"

// return the factorial of n
long fact(int n){
    long k = n;
    if (k == 0) { return 1; }
    for(int i = n - 1; 1 < i; --i) { k *= i; }
    return k;
}

// return combination C(k, n)
long nchoosek(int n, int k){
    long res = fact(n) / (fact(k) * fact(n - k));
    return res;
}

// Check if number n is a prime, 1 for True, 0 for False
// Euler Sieve, learn equation from wekipedia
int prime(long num){
    if(1 < num && num <=3) { return 1; }
    if(num % 6 != 1 && num % 6 != 5) return 0;
    return 1;
}

// return the greatest common divisor of a and b
int gcd(int a, int b){
    if (b == 0) { return a; }
    return gcd(b, a % b);
}

// reutrn the lowest common multiple of a and b
int lcm(int a, int b){
    return a * b / gcd(a, b);
}

// bit reversion of a char value.
char bitrevc(char c){
    char a = 0;
    for(int i = 0; i < 8; ++i){
        if((c & 1) == 1){
            a |= (1 << (7 - i));
        }
        c = c >> 1;
    }
    return a;
}
