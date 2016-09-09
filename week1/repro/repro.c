/* file:        repro.c                                             */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        09-06-2016                                          */
/* version:     1.0.0                                               */
/* description: This program calculates the required number of packs of paper.  */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x;   // The number of required sheets of paper
int y;   // The number of required packs of paper
int z;   // placeholder for adding one pack of paper, only when the remainder is greater than zero 

int main(int argc, char *argv[])  {

	// Asks for input
	scanf("%d", &x);

	// This calculates the amount of required packs, and if there is a remainder adds an extra required pack
	if(x%500 > 0) {
		z = 1;
	} 
		else {
		z = 0;
	}

	y = x/500 + z;

	// Prints result
	printf("%d\n", y);

	return 0;
}