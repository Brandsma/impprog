/* file:        scheduling.c                                        */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        10-06-2016                                          */
/* version:     1.0.0                                               */
/* description: This program determines the smallest average time to complete all tasks */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x, y, z;             // These are the three variables for the input
int temp1, temp2, temp3; // Assign assorted values from low to high
float answer;		     // The variable that stores the answer

int main(int argc, char *argv[]) {

	scanf("%d %d %d", &x, &y, &z);

	// Assort values from low to high
	if (x > y && x > z) {
		if (y > z) {
			temp1 = z;
			temp2 = y;
			temp3 = x;
			goto label;
		} else {
			temp1 = y;
			temp2 = z;
			temp3 = x;
			goto label;
		}
	} else {
		if (y > x && y > z) {
			if (x > z) {
				temp1 = z;
				temp2 = x;
				temp3 = y;
				goto label;
			} else {
				temp1 = x;
				temp2 = z;
				temp3 = y;
				goto label;
			}
		} else {
			if (z > x && z > y) {
				if (x > y) {
					temp1 = y;
					temp2 = x;
					temp3 = z;
					goto label;
				} else {
					temp1 = x;
					temp2 = y;
					temp3 = z;
					goto label;
				}
			} else {
				answer = x + (y+x) + (z+y+x);
				answer /= 3;
				goto label2;
			}
		}
	}
	//
	label:

	// Calculates the average time needed to complete all tasks
	answer = temp1 + (temp1+temp2) + (temp1+temp2+temp3);
	answer /= 3;

	label2:
	// Prints result to screen
	printf("%.1f\n", answer);

	return 0;
}