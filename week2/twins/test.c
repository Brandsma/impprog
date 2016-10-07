/* file:        twins.c                                             */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        15-09-2016                                          */
/* version:     1.0.0                                               */
/* description: This program prints the nth twin primes.            */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>

int isPrime(int n) {
	int i=5;
	int s=2;
	// in case 2 or 3 is input
	if(n == 3 || n == 2) {
    	return 1;
  	}
	if(n % 2 == 0 || n % 3 == 0) {
  		return 0;
  	}
  	while(i*i <= n) {
  		if(n % i == 0) {
  			return 0;
  		}

  		i += s;
  		s = 6 - s;
  	}
  	return 1; 
}

int main(int argc, char *argv []) {

  int i;		// iteration

  scanf("%d", &i);
  i = isPrime(i);
  if(i==1) {
    printf("is prime\n");
  } else {
    printf("is not prime\n");
  }

  return 0;
}