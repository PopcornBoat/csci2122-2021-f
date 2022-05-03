// coins.c 
// author: YuxuanWang, B00880845

#include <stdio.h>
#include "coins.h"

void calculateCoins(int n_pennies)
{
	// instance variables
	int dollar, quarter, dime, nickel;
	
	// conversion
	dollar = n_pennies / 100;
	n_pennies = n_pennies % 100;
	quarter = n_pennies / 25;
	n_pennies = n_pennies % 25;
	dime = n_pennies / 10;
	n_pennies = n_pennies % 10;
	nickel = n_pennies / 5;
	n_pennies = n_pennies % 5;

	// output
	printf("%d dollars, %d quarters, %d dimes, %d nickels, %d pennies\n", dollar, quarter, dime, nickel, n_pennies);
}
