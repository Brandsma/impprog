/* file:        additives.c                                         */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        11-10-2016                                          */
/* version:     1.0.0                                               */
/* description: This program prints the amount of valid additive expressions for a certain input  */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int printExpressions(int n, int curLength, int sum) {
	if(curLength > n) { // Test whether or not the length of the expressions has reached the input
		if(sum == n) {
			return 1;
		}	
	} else {
		return printExpressions(n, curLength+1, sum+curLength) + printExpressions(n, curLength+1, sum-curLength);
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int input;

	scanf("%d", &input);
	printf("%d\n", printExpressions(input, 2, 1));
	
	return 0;
}