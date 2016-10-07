/* file:        palindrome.c                                          */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        22-09-2016                                          */
/* version:     1.0.0                                               */
/* description: This program determines whether the input is a palindrome or not  */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int swapDigits(int m, int n, int x) {
	int temp;
	int i, j;
	int powj, powi;
	temp = x;
	i = m, j = n;
	while(n != 1) { // Determines one number to be swapped based on n
		temp /= 10;
		n--;
	}
	n = temp%10;
	temp = x;
	while(m != 0) { // Determines one number to be swapped based on m
		temp /= 10;
		m--;
	}
	m = temp%10;
	// Putting the numbers in their place
	powj = pow(10, j);				// Now the pow function does not have to run 4 times
	powi = pow(10, i);				//
	j = n * powj;					// Gives a location to the nth number
	i = m * powi;					// Gives a location to the mth number
	x = x - (j+i);					// Removes the numbers that need to be swapped
	x = x + ((n*powi)+(m*powj));	// Adds the numbers, but now in swapped order
	return x;
}

int numberOfDigits(int y) {
	int count=0;
	if(y == 0) {
		return 1;
	}
	while(y != 0) {
		y /= 10;
		count++;
	}
	return count;
}

int reverseDigits(int z) {
	int last, first=0;
	last = numberOfDigits(z);
	while(last >= first) {
		z = swapDigits(first, last, z);
		first++;
		last--;
	}
	return z;
}

int main(int argc, char *argv[]) {
	int in; // Input value

	scanf("%d", &in);

	if(in == reverseDigits(in)) {
		printf("%d is a palindrome.\n", in);
	} else {
		printf("%d is not a palindrome.\n", in);
	}
	return 0;
}