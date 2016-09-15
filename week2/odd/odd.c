/* file:        odd.c                                               */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        12-09-2016                                          */
/* version:     1.0.0                                               */
/* description: This program prints all odd numbers of a given number.  */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {

	float pos;			// Determines the position of the odd number in the final answer.
	int x, y, s, i;		// Variables to store answers in.
	int answer;			// This will store the answer, that will eventually be printed.

	scanf("%d", &x);

	// Assigning values to variables. This stops the compiler from choosing a value at random.
	answer = 0;
	s = 1;
	pos = 0.1;
	while(x >= 10) {
		y = x%10;
		if(y & 1) {
			// Determines position
			s++;
			for(i=0; i<s; i++); {
				pos *= 10;
			}
			answer = answer + (y * pos);
		} 
		x /= 10;
	}

	// Checks for the case where there is only one number given.
	if(x & 1 && answer == 0) {
		printf("%d\n", x);
		return 0;
		
	} else {
		if(x & 1) {
			printf("%d%d\n", x, answer);
		} else {
			printf("%d\n", answer);
		} }

	return 0;
}