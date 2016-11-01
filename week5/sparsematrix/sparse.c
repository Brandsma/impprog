/* file:        sparse.c                                            */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        09-10-2016                                          */
/* version:     1.0.0                                               */
/* description: This program tests whether or not two matrices are the same  */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>

void *safeMalloc(int n) {
	void *p = malloc(n);
	if (p == NULL) {
		printf("Error: malloc(%d) failed. Out of memory?\n", n);
		exit(EXIT_FAILURE);
	}
	return p;
}

int **makeIntArray2D(int width, int height) {
	int row, **arr;

	arr = safeMalloc(height*sizeof(int *));
	arr[0] = safeMalloc(width*height*sizeof(int));

	for (row=1; row < height; row++) {
		arr[row] = arr[row-1] + width;
	}
	return arr;
}

void destroyIntArray2D(int **arr) {
	free(arr[0]);
	free(arr);
}

int main(int argc, char *argv[]) {
	int n, m, temp, cd;
	int j = 0;
	int i = 0;
	scanf("%d", &n);

	int **arr1 = makeIntArray2D(n, n);
	int **arr2 = makeIntArray2D(n, n);

	int flip = 0;
	for(i = 0; i<n; i++) {	// Row encoded array
		temp = 0;	
		flip = 0;
		cd = 0;
		while(temp < n) {
			scanf("%d", &m); // Scan the encoding
			temp += m;
			while(m > 0) {
				if(flip == 0) {
					arr1[i][j+cd] = 0;
					m--;
					cd++; // Move one column to the right
				} else {
					arr1[i][j+cd] = 1;
					m--;
					cd++;
				}
			}

			if(flip == 0) { // Flips the encoding so a 1 or a 0 will be outputted
					flip = 1;
				} else {
					flip = 0;
				}
		}	
	}

	i=0;
	for(j = 0; j<n; j++) {	// Column encoded array
		temp = 0;	
		flip = 0;
		cd = 0;
		while(temp < n) {
			scanf("%d", &m); // Scan the encoding
			temp += m;
			while(m > 0) {
				if(flip == 0) {
					arr2[i+cd][j] = 0;
					m--;
					cd++; // Move down one row
				} else {
					arr2[i+cd][j] = 1;
					m--;
					cd++;
				}
			}

			if(flip == 0) { // Flips the encoding so a 1 or a 0 will be outputted
					flip = 1;
				} else {
					flip = 0;
				}
		}	
	}

	for(i=0; i<n; i++) { // Check if the matrices are equal
		for(j=0; j<n; j++) {
			if(arr1[i][j] != arr2[i][j]) {
				printf("DIFFERENT\n");
				return 0;
			}
		}
	}
	printf("EQUAL\n");

	destroyIntArray2D(arr1); // Free up allocated memory from arrays
	destroyIntArray2D(arr2);
	return 0;
}