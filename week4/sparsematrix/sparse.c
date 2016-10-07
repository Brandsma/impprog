/* file:        sparse.c                                            */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        05-10-2016                                          */
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
			scanf("%d", &m);
			temp += m;
			while(m > 0) {
				if(flip == 0) {
					arr1[i][j+cd] = 0;
					m--;
					cd++;
				} else {
					arr1[i][j+cd] = 1;
					m--;
					cd++;
				}
			}

			if(flip == 0) {
					flip = 1;
				} else {
					flip = 0;
				}
		}	
	}

	flip = 0;
	for(j = 0; j<n; j++) {	// Column encoded array
		temp = 0;	
		flip = 0;
		cd = 0;
		while(temp < n) {
			scanf("%d", &m);
			temp += m;
			while(m > 0) {
				if(flip == 0) {
					arr2[i+cd][j] = 0;
					m--;
					cd++;
				} else {
					arr2[i+cd][j] = 1;
					m--;
					cd++;
				}
			}

			if(flip == 0) {
					flip = 1;
				} else {
					flip = 0;
				}
		}	
	}

	for(int i = 0; i<n; i++) { //TEST
		printf("\n");
		for(int j = 0; j<n; j++) {
			printf("%d", arr1[i][j]);
		}
	}
	printf("\n\n");
	for(int i = 0; i<n; i++) { //TEST
		printf("\n");
		for(int j = 0; j<n; j++) {
			printf("%d", arr2[i][j]);
		}
	}
	printf("\n");


	destroyIntArray2D(arr1); // Free up allocated memory from arrays
	destroyIntArray2D(arr2);
	return 0;
}