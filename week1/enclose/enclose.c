/* file:        Enclose.c                                           */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        09-06-2016                                          */
/* version:     1.0.0                                               */
/* description: This program determines the enclosing number of an integer */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int base;   // The integer that will be the input
int first;  // The enclosing number on the left side
int last;   // The enclosing number on the right side


int main(int argc, char *argv[])  {

	// Asks for input
	scanf("%d", &base);

	// Determines the enclosing number on the left side
	first = base;
	while (first >= 10) {

		first = first/10;

	}


	// Determines the enclosing number on the right side
	last = base%10;

	// Prints result to screen
	printf("%d%d encloses %d.\n", first, last, base);


	return 0;
}