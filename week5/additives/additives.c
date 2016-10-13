/* file:        additives.c                                         */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        11-10-2016                                          */
/* version:     1.0.0                                               */
/* description: This program prints the amount of valid additive expressions for a certain input  */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int solveExpressions(int n, int curlength) {
	if(n == test) { // base case
		return 1;
	}
	x++;
	if (x<n) {
		return 1 + solveExpressions(n+1, curlength+1);
	} else {
		return 1 - solveExpressions(n+1, curlength+1);
	}
}

int main(int argc, char *argv[]) {
	int input;
	scanf("%d", &input);
	test = input;
	printf("%d\n", solveExpressions(input, 0));
	return 0;
}