/* file:        survivors.c                                         */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        04-10-2016                                          */
/* version:     1.0.0                                               */
/* description: This program gives the nth surviving number.        */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	int input;

	int array[5000], c;
	int i = 0, j;
	int m = 3;
	int odd = 1;

	for(i=0; i<5000; i++) { // Initialize array with odd numbers
		array[i] = odd;
		odd += 2;
	}

	i = 0;
	while(m <= 1118) { // Generate array with surviving numbers
		j = m;
		while(j < 5000) {
    		for (c = j - 1; c < 5000 - 1; c++) {
        		array[c] = array[c+1];
    		}
    		j += m-1;
    	}
    	m = array[2+i];
    	i++;
    }

	scanf("%d", &input);			// Give the nth array element
	printf("%d\n", array[input-1]);

	return 0;
}