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
	int a, b, x, answer, y;
	scanf("%d %d", &a, &b);
	x = b;
	y = 0;
	answer = 0;
	while(1) {
		if(y%2 == 0) {
			x += y;
			if(x >= b+a*a-1) break;
			answer += x;
		}
		y++;
	}
	printf("%d\n", answer);
	return 0;
}