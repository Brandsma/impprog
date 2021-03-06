/* file:        function.c                                          */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        20-09-2016                                          */
/* version:     1.0.0                                               */
/* description: This program solves a serie of function and prints out its answer  */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	scanf("%d %d", &a, &b);
	printf("%d*%d=", a, b);
	while(b!=0) {
		if(b%2 & 1) {
			printf("%d", a);
			answer += a;
		}
		a *= 2;
		b /= 2;
	}
	printf("=%d", answer);
	return 0;
}