/* file:        recurrence.c                                        */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        16-09-2016                                          */
/* version:     1.0.0                                               */
/* description: This program prints all computation steps for solving a recursive function.  */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {

	int n;		//Value for input
	int f;		//Value for output
	int i, j; 	// Determines the amount of '(' and ')' every time.

	i = 1;
	scanf("%d", &n);
	printf("f(%d)=", n);
	if(n <= 100) {
		while(!(f == 91)) {
			// Determines which function it should solve and then solves it, also adds required notation.
			n += 11;
			i++;
			
			j = i;
			//Function for when n <= 100
			while(j > 0) {
				printf("f(");
				j--;
			}

			j = i;

			printf("%d", n);

			while(i > 0) {
				printf(")");
				i--;
			}

			i = j;

			printf("=");
			// Label from line 77
			labelx:
			// Function for when n > 100
			if(n > 100) {

				n -= 10;
				i--;
				j = i;

				while(j > 0) {
					printf("f(");
					j--;
				}

				j = i;
				printf("%d", n);

				while(i > 0) {
					printf(")");
					i--;
				}
				printf("=");
				i = j;
			}
			f = n - 10;		
		}
	} else {
		f = n - 10;
	}
	// Checks whether all function are solved, before giving final answer.
	if(f == 91 && !(i == 1)) {
		// Label is on line 46
		goto labelx;
	}
	//Prints out final answer
	printf("%d\n", f);

	return 0;
}