/* file:        twins.c                                             */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        15-09-2016                                          */
/* version:     1.0.0                                               */
/* description: This program prints the nth twin primes.            */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>

double sqrt(double s) {
    double r=s/3;
    int i;
    if (s <= 0) {
    	return 0;
    }

    for (i=0; i<64; i++) {
        r = (r + s / r) / 2;
    }
    return r;
}

int isPrime(int n)
{
   int s = 0;
   int i = 0;

   // in case 3 is input
   if ( n == 3 ) {
      return 1;
   }

   // Long trial division
   s = (int)(sqrt(n));

   for ( i = 3; i <= s; i +=2 ) {
      if ( n%i == 0 ) {
         // returns 'false' value
         return 0;
      }
   }
   // returns 'true' value
   return 1;
}

int main(int argc, char *argv []) {

   int i;		// iteration
   int x;		// Assigns a number to every twin prime it finds
   int y;		// Input value
   int a, b;	// Stores values of the two prime numbers	

   scanf("%d", &y);

   // Loop to check for required twin prime, skips all even numbers
   for(i = 3; i <= 1000000 && x < y; i += 2) { 
      if (isPrime(i) && isPrime(i+2)) {
         x++;
         a = i;
         b = i + 2;
      }
   }                       
   printf("%d %d\n", a, b);

   return 0;
}