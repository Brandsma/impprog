/* file:        splitters.c                                         */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        19-10-2016                                          */
/* version:     1.0.0                                               */
/* description: This program determines whether there exists a balanced splitter and, if true, prints it */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int array[101] = {0};
	int size = 1, input = 1;
	int maxval = 0;
	int left = 0, right = 0;
	int i;

	while(1) { // Initialize the frequency histogram
		scanf("%d", &input);
		if(input == 0) break;
		array[input] += 1;
		if(maxval < input) {
			maxval = input;
		}
	}

	while(size != maxval) { // Frequency histogram is not relevant past the maxval value
		for(i = 1; i <= size; i++) { // Count up everything left from the pivot
			left += array[i];
		}
		for(i = maxval; i > size + 1; i--) { // Count up everything right from the pivot
			right += array[i];
		}
		if(left == right) {
			printf("%d\n", size + 1); // note: the pivot is at location size + 1
			return 0;
		}
		left = 0;
		right = 0;
		size++;
	}

	printf("UNBALANCED\n"); 

	return 0;
}