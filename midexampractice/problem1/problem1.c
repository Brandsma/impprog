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
	int a, b, n, x=0, count=1;
	scanf("%d %d %d", &a, &b, &n);
	while(count <= n) {
		if(count%a == 0 && count%b == 0) {
			x++;
		}
		count++;
	}
	printf("%d\n", x);
	return 0;
}