/* file:        Collatz.c (again)                                   */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        13-10-2016                                          */
/* version:     1.0.0                                               */
/* description: This program Determines the longest collatz sequence with a recursive function */

// Includes libraries for functionalities
#include <stdio.h>

#define MAX64 9223372036854775807L /* 2ˆ63 -1 */
#define MAXSIZE 100000000

long C[MAXSIZE];

int lengthCollatz(long n) {
  if(n == 1) {
    return 1;
  }
  if(n < MAXSIZE) {
    if(C[n] != 0) { // Memoization 
      return C[n];
    }

    if(n%2 & 1){
      C[n] = 1 + lengthCollatz(3*n+1);
      return C[n];
    } else {
      C[n] = 1 + lengthCollatz(n/2);
      return C[n];
    }
  } else {
    if(n%2 & 1){
      return 1 + lengthCollatz(3*n+1);
    } else {
      return 1 + lengthCollatz(n/2);
    }
  }

  
}

int main(int argc, char *argv[]) {
  int n, a, b, len=-1;
  scanf ("%d %d", &a, &b);
  while (a <= b) {
    int l = lengthCollatz(a);
    if (l > len) {
      n = a;
      len = l;
    }
    a++;
  }
  printf("%d\n", n);
  return 0;
}
