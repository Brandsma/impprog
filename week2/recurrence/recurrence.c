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

	int n;		//Value for input
	int f;		//Value for output
	int i, j; 	// Determines the amount of '(' and ')' every time.

	scanf("%d", &n);
	printf("f(%d)=", n);
	if(n <= 100) {
		labely:
		while(!(f == 91)) {
			i = 1;

			while(n <= 100) {

				n += 11;
				i++;
			

				j = i;

				while(j > 0) {
					printf("f(");
					j--;
				}

				if(n <= 100) {
					goto labelx;
				}
			}

			labelx:

			printf("%d", n);

			while(i > 0) {
				printf(")");
				i--;
			}

			printf("=");
			if(n <= 100){
				goto labely;
			}
			n -= 10;
			f = n - 10;
			
		}
	} else {
		f = n - 10;
	}

	printf("%d\n", f);






/*
	if(!(n > 100)) {
	while(!(f == n - 10)) {
		printf("f(");
		i++;
		if(n <= 100) {
			n += 11;
			printf("f(%d", n);
			i++;
		} else {
			if(i > 0) {
				while(i > 0) {
					printf(")");
					i--;
				}
			} else {
				printf("=");
			}
		}
	} 
	} else {
		printf("f(%d)=%d", n, f-10);
	}
*/
	return 0;
}