/* file:        odd.c                                               */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        12-09-2016                                          */
/* version:     1.0.0                                               */
/* description: This program prints all odd numbers of a given number.  */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int squareDigits(int n) {
	int x, ans = 0;
	while(n!=0) {
		x = n%10;
		x *= x;
		ans += x;
		n /= 10;
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int n, answer, x;
	scanf("%d", &n);
	answer = 0;
	while(n != 0) {
		x = n;
		while(1) {
			x = squareDigits(x);
			if(x == 89) {
				answer++;
				break;
			}
			if(x == 1) break;
		}
		n--;
	}
	printf("%d\n", answer);
	return 0;
}





/*
:: Determines number of digits in a given number
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
:: Determines whether the input is a prime
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
:: Check if input is a prime palindrome
int palin(int n){
	int i;
	int l = log10(n) + 1;
	int* a = toArray(n);
	for(i = 0; i < (l/2); i++){
		if(a[i] != a[(l-i-1)]){
			return 0;
		}
	}
	return 1;
}
:: Greatest common divisor
int gcd ( int a, int b ){
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}
:: Least common multiple
int lcm(int a, int b){
  int max;
  max = (b > a) ? a : b; 
  while(1)
  {
      if(max % a == 0 && max % b == 0)
      {
          printf("%d", max);
          break;
      }
      max++;
  }
  return 0;
}
:: Calculates factorials
int factorial(int n) {
	int m = 1;
	while(n != 0) {
		m *= n;
		n--;
	}
	return m;
}
:: Gives the final number in a fibonacci serie of length n
int fibonacci(int n) {
	int first = 0, second = 1, next, c;

   for ( c = 0 ; c < n ; c++ )
   {
      if ( c <= 1 )
         next = c;
      else
      {
         next = first + second;
         first = second;
         second = next;
      }
   }
 
   return next;
}
:: Is m a divisor of n?
int isDivisor(int n, int m) {
	n /= m;
	if(n%2 == 0) {
		return 1;
	} else {
		return 0;
	}
}
:: is the input a palindrome?
int isPalindrome(int n) {
	int reversedInteger = 0, remainder, originalInteger;

    originalInteger = n;
    while( n!=0 ) {
        remainder = n%10;
        reversedInteger = reversedInteger*10 + remainder;
        n /= 10;
    }
    if(originalInteger == reversedInteger)
        return 1;
    else
        return 0;
}
*/
