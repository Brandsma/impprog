/* file:        queens.c                                            */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        04-10-2016                                          */
/* version:     1.0.0                                               */
/* description: This program gives whether a certain setup is valid according to the 8-queens problem. */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ABS(a) ((a)<0 ? (-(a)) : (a))

int main(int argc, char *argv[]) {
	int pos[8];
	int column;

	for(int i=0; i<8; i++) {
		scanf("%d", &column);
		pos[i] = column;
		int r;
		for(r=0; r < i; r++) {
			if((pos[r] == column || (ABS(pos[r]-column) == i-r))) {
				printf("invalid\n");
				return 0;
			}
		}
	}
	printf("valid\n");

	return 0;
}