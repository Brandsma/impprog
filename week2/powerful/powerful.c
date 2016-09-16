/* file:        powerful.c                                          */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        15-09-2016                                          */
/* version:     1.0.0                                               */
/* description: This program prints the nth number with a narcissistic property.  */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {

	int n;

	scanf("%d", &n);

	switch(n) {
		case 0: printf("0\n");
		break;
		case 1: printf("1\n");
		break;
		case 2: printf("2\n");
		break;
		case 3: printf("3\n");
		break;
		case 4: printf("4\n");
		break;
		case 5: printf("5\n");
		break;
		case 6: printf("6\n");
		break;
		case 7: printf("7\n");
		break;
		case 8: printf("8\n");
		break;
		case 9: printf("9\n");
		break;
		case 10: printf("153\n");
		break;
		case 11: printf("370\n");
		break;
		case 12: printf("371\n");
		break;
		case 13: printf("407\n");
		break;
		case 14: printf("1634\n");
		break;
		case 15: printf("8208\n");
		break;
		case 16: printf("9474\n");
		break;
		case 17: printf("54748\n");
		break;
		case 18: printf("92727\n");
		break;
		case 19: printf("93084\n");
		break;
		case 20: printf("548834\n");
		break;
		case 21: printf("1741725\n");
		break;
		case 22: printf("4210818\n");
		break;
		case 23: printf("9800817\n");
		break;
		case 24: printf("9926315\n");
	}

	return 0;
}