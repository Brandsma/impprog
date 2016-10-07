/* file:        sparse.c                                            */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        05-10-2016                                          */
/* version:     1.0.0                                               */
/* description: This program tests whether or not two matrices are the same  */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void *safeMalloc(int n) {
	void *p = malloc(n);
	if (p == NULL) {
		printf("Error: malloc(%d) failed. Out of memory?\n", n);
		exit(EXIT_FAILURE);
	}
	return p;
}

char **makeCharArray2D(char width, char height) {
	char row, **arr;

	arr = safeMalloc(height*sizeof(char *));
	arr[0] = safeMalloc(width*height*sizeof(char));

	for (row=1; row < height; row++) {
		arr[row] = arr[row-1] + width;
	}
	return arr;
}

void destroyCharArray2D(char **arr) {
	free(arr[0]);
	free(arr);
}

int rowDirection(int dir) {
	switch(dir) {
		case 0: return 0;
		case 1: return 0;
		case 2: return 1;
		case 3: return 1;
		case 4: return 1;
		case 5: return -1;
		case 6: return -1;
		case 7: return -1;
	}
	return 0;
}

int colDirection(int dir) {
	int rowDirection(int dir) {
	switch(dir) {
		case 0: return 1;		// North
		case 1: return -1;		// South	
		case 2: return 1;		// North East
		case 3: return 0;		// East
		case 4: return -1;		// South East
		case 5: return 1;		// North West
		case 6: return 0;		// West
		case 7: return -1;		// South West
	}
	return 0;
}

}

int main(int argc, char *argv[]) {
	int n, wordlength;
	char ch;
	char word[256];
	scanf("%d", &n);
	char **wordSearch = makeCharArray2D(n, n);
	char **solutionGrid = makeCharArray2D(n, n);

	for(int i = 0; i<n; i++) { // Initialize arrays
		for(int j = 0; j<n; j++) {
			scanf("%c", &ch);
			wordSearch[i][j] = ch;
			solutionGrid[i][j] = ch;
		}
	}

	while(word[0] != '.') { // Stop case
		scanf("%s", word);
		wordlength = strlen(word); // length of word
		printf("%d", wordlength);
		for(int i = 0; i<n; i++) { 
			for(int j = 0; j<n; j++) {

				if(wordSearch[i][j] == word[0]) { // Does first letter match?

				for(int dir = 0; dir < 8; dir++) { // Determine direction
					int rd = rowDirection(dir);	
					int cd = colDirection(dir);

					if(wordSearch[i+rd][j+cd] == word[1]) {
						for(int iter = 0; iter<wordlength; iter++) {
							if(wordSearch[i+(iter*rd)][i+(iter*cd)] == word[iter]) {
								
							}
						}
					}
				}

				}
			}
		}
	}


	destroyCharArray2D(wordSearch);
	destroyCharArray2D(solutionGrid);

	return 0;
}