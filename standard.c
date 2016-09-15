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

	int n;	//Value for input
	int f;	//Value for output
	int i;

	scanf("%d", &n);
	printf("f(%d)=", n)
	f = n;
	i = o;
	if(!(n > 100)) {
	while(!(f == n - 10) && n > 100) {
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
	} else {
		printf("f(%d)=%d", n, f-10)
	}
}
	return 0;
}