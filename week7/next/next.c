/* file:        next.c                                              */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        27-10-2016                                          */
/* version:     1.0.0                                               */
/* description: This program prints the next lexographical sucessor  */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printCharArray(char *array, int size) {
	for(int i = 0; i<size; i++) {
		printf("%c", array[i]);
	}

	printf("\n");
	return;
}

int nextPermutation(char *array, int length) {
	int i, j;
	int temp;
	
	if (length == 0) { // Stops possible segmentation fault
		return 0;
	}
	i = length - 1;
	while (i > 0 && array[i - 1] >= array[i]) { // Test whether there is a sequence of numbers that is bigger than the given one
		i--;
	}
	if (i == 0) {
		return 0;
	}
	
	j = length - 1;
	while (array[j] <= array[i - 1]) { // Swap the entirety of the array to the next possible permutation
		j--;
	}
	temp = array[i - 1];
	array[i - 1] = array[j];
	array[j] = temp;

	j = length - 1;
	while (i < j) {
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i++;
		j--;
	}
	return 1;
}

int main(int argc, char *argv[]) {
	char ch;
	char *array = NULL;
	char *reallocArray = NULL;
	int counter = 0, size = 0;
	while(1) {
		scanf("%c", &ch);
		if(ch == '.') break; // If EOF is read
		size++;
		reallocArray = (char*) realloc(array, size * sizeof(char)); // Resize the array when necessary
		if(reallocArray != NULL) {
			array=reallocArray;
			array[counter] = ch;
			counter++;
		} else { 
			free(array);
			printf("Error (re)allocating memory");
			return -1;
		}
	}

	if(nextPermutation(array, size)) {
		printCharArray(array, size); // Next permutation is possible
	} else {
		printCharArray(array, size); // There is no other permutation, so print input
	}

	free(array);
	return 0;
}