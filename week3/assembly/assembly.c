/* file:        assembly.c                                          */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        23-09-2016                                          */
/* version:     1.0.0                                               */
/* description: This program simulates a processor with assembly commands  */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void out(int input) {
	printf("%d", input);
}

int main(int argc, char *argv[]) {
	int n=0;					// Determines amount of succesfully parsed items in the scanf function
	char a='x',b='x',c='x';		// Holds the character values entered
	int x=0,y=0,in=0;			// Determines what register will be used and an input value for the LCS command
	int R1=0, R2=0;				// The registers
	while(n!=3) {
		n = scanf(" %c%c%c R%d R%d", &a, &b, &c, &x, &y);
		if(n==4) {	
			switch(a) {
				case 'O':	// Handles the print function.
				switch(x) {
					case 1: printf("%d\n", R1);
					break;
					case 2: printf("%d\n", R2);
				}
				break;
				case 'L':	// Handles the load constant value
				scanf("%d", &in);
				switch(x) {
					case 1: R1 = in;
					break;
					case 2: R2 = in;
				}
				break;
				case 'I':	// Handles the increment-command
				switch(x) {
					case 1: R1 += 1;
					break;
					case 2: R2 += 1;
				}	
				break;
				case 'D':	// Handles the decrement-command
				switch(x) {
					case 1: R1 -= 1;
					break;
					case 2: R2 -= 1;
				}			
			}
		}

		if(n==5) {
			switch(a) {
				case 'A': 	// Handles the addition-command
					if(x==1 && y==1) R1 += R1;
					if(x==1 && y==2) R2 += R1;
					if(x==2 && y==1) R1 += R2;
					if(x==2 && y==2) R2 += R2;
					break;
				case 'S':	// Handles the subtract-command
					if(x==1 && y==1) R1 = R1 - R1;
					if(x==1 && y==2) R2 = R1 - R2;
					if(x==2 && y==1) R1 = R2 - R1;
					if(x==2 && y==2) R2 = R2 - R2;
					break;
				case 'M':	// Handles the multiplication-command
					if(x==1 && y==1) R1 *= R1;
					if(x==1 && y==2) R2 *= R1;
					if(x==2 && y==1) R1 *= R2;
					if(x==2 && y==2) R2 *= R2;
					break;
			}
		}
	}
	return 0;
}