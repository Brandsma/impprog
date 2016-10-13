/* file:        takuzu.c                                            */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        13-10-2016                                          */
/* version:     1.0.0                                               */
/* description: This program prints several takuzu strings based on input  */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int takuzu(int n, int answer) {
	if(n == 0) {
		return 1;
	}

}

int main(int argc, char *argv[]) { 
	int n;
	scanf("%d", &n);
	takuzu(n, 0);
	return 0;
}
