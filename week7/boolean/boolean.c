/* file:        boolean.c                                           */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        31-10-2016                                          */
/* version:     1.1.0                                               */
/* description: This program determines all possible inputs where the CNF evaluates to true */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>

int *array;
int *negation, satisfiable = 0;
int m, n;

void *safeMalloc(int n) {
  void *p = malloc(n);
  if (p == NULL) {
    printf("Error: malloc(%d) failed. Out of memory?\n", n);
    exit(EXIT_FAILURE);
  }
  return p;
}

int getBinary(int x, int i) {
	i = m - i - 1;
	return ((x & (1 << i)) >> i);
}

void printBinaryNumber(int x) {
	for(int i = 0; i < m; i++) {
		printf("%d", getBinary(x, i));
	}
	printf("\n");
}

int generateArray(int size) {
	int j = 0;
	char ch;

	for(int i = 0; i < size; i++) { // Ignore every character that does not give any information
		scanf(" [");
		do {
			ch = getchar();
			if(ch != 'x'){ // Check for the negation character
				ch = getchar();
				negation[j] = 1;
			}
			
			scanf("%i", array+j);
			j++;

			ch = getchar();
		} while(ch != ']');

		array[j] = m;
		j++;
	}

	return j;
}

int checkCNF(int bitString) { // Check whether the CNF returns a true or a false value
	int i = 0;
	int boolean = 1;

	do {
		int check = 0;
		do {
			if((getBinary(bitString, array[i]) && (!negation[i])) || (!getBinary(bitString, array[i]) && (negation[i]))) { 
				check = 1;
			}

			i++;
		} while(i<n && array[i] != m); // Check whether or not the disjunction has a true value amongst it

		boolean *= check; // If any of the disjunctions return false, make the boolean 0
	} while(i < n-1); // Length of the entire CNF array

	return boolean;
}

void generateExpressions(int n ,int expression) { // Recursive function to generate all possible values
   	//base case
	if(n == 0) {
		if(checkCNF(expression)) {
			printBinaryNumber(expression);
			satisfiable = 1;
		}
		return;
	}
	// Next variable will be set to 0 and moved up 1 location (expression * 2 because of 2-base system)
	generateExpressions(n-1, expression * 2);
	// Next variable will be set to 1
	generateExpressions(n-1, expression * 2 + 1);
}

int main(int argc, char *argv[]) {
	scanf("%d %d", &m, &n);

	negation = safeMalloc( (m*n+n) * sizeof(int)); // The entirety of the CNF is in the array, while the negation array keeps track of where the negation signs are
	array = safeMalloc( (m*n+n) * sizeof(int));
	
	n = generateArray(n); // Generate array from input and determine length

	generateExpressions(m, 0);

	if(!satisfiable) { // If not a single expression has been printed
		printf("UNSATISFIABLE\n");
	}

	free(array);
	free(negation);
	return 0;
}