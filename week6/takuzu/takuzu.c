/* file:        takuzu.c                                            */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        13-10-2016                                          */
/* version:     1.0.0                                               */
/* description: This program prints several takuzu strings based on input  */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print(char string[], int length) {
	for (int i = 0; i < length; i ++) {
		printf("%c", string[i]);	
	}
	printf("\n");
}

int evenDivision(char string[], int length) {
	int ones = 0;
	int zeros = 0;
	for(int i = 0; i < length; i ++) {
		if(string[i] == '0') {
			zeros++;
		} else { 
			ones++;
		}	
	}
	return (zeros == ones);
}

void takuzu(char curString[], int curLength, int goal) {
	if(curLength == goal) {
		if(evenDivision(curString, curLength)) {
			print(curString, goal);
		}
	} else {
		char one = curString[curLength-2];
		char two = curString[curLength-1];
		
		
		int nr = 0;
		if(two == '1') nr ++;
		if(one == '1') nr += 2;

		char new[32];
		
		for(int i = 0; i < curLength; i ++) {
			new[i] = curString[i];	
		}

		switch(nr) {
			case 0:
				new[curLength] = '1';
				new[curLength+1] = '0';
				takuzu(new, curLength+2, goal); 
				new[curLength+1] = '1';
				takuzu(new, curLength+2, goal);
				break;
			case 1:
				new[curLength] = '0';
				new[curLength+1] = '0';
				takuzu(new, curLength+2, goal); 
				new[curLength+1] = '1';
				takuzu(new, curLength+2, goal);
				new[curLength] = '1';
				new[curLength+1] = '0';
				takuzu(new, curLength+2, goal);
				break;
			case 2:
				new[curLength] = '0';
				new[curLength+1] = '1';
				takuzu(new, curLength+2, goal); 
				new[curLength] = '1';
				new[curLength+1] = '0';
				takuzu(new, curLength+2, goal);
				new[curLength+1] = '1';
				takuzu(new, curLength+2, goal);
				break;
			case 3:
				new[curLength] = '0';
				new[curLength+1] = '0';
				takuzu(new, curLength+2, goal); 
				new[curLength+1] = '1';
				takuzu(new, curLength+2, goal);
				break;
		}
	}
}

int main(int argc, char *argv[]) { 
	int n;
	scanf("%d", &n);
	char zero[32] = {'0','0'}; 
	char one[32] = {'0','1'}; 
	char two[32] = {'1','0'};
	char three[32] = {'1','1'};
	takuzu(zero, 2, 2*n);
	takuzu(one, 2, 2*n);
	takuzu(two, 2, 2*n);
	takuzu(three, 2, 2*n);
	return 0;
}
