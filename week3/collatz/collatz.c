/* file:        collatz.c                                           */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        21-09-2016                                          */
/* version:     1.0.0                                               */
/* description: This program prints the length of the collatz sequence when it is largest within a certain boundary  */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>

int lengthOfCollatzSequence(int n) {
    int length = 1;
    while(n != 1) {
        if(n%2 == 0) {
            n /= 2;
        } else {
            n = n*3 + 1;
        }
        length++;
    }
    return length;
}

int main(int argc, char *argv[]) {
    int i=0, max=0; // Values that help determine the maximum value of lengthOfCollatzSequence
    int n, count;   // Keeps track of the amount of steps for Collatz Sequence both for every step and the max step
    int a, b;       // Input values that gives the boundaries

    scanf("%d %d", &a, &b);
    for (n=a; n<=b; n++) {
        i=lengthOfCollatzSequence(n);
        if (i>max) {
            max=i;  
            count=n; // Keeps track of the amount of steps it takes to finish the collatz sequence when at max
        }
    }
    printf("%d\n", count);
    return 0;
}