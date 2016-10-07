/* file:        overlap.c                                           */
/* author:      Abe Brandsma (email: abe.brandsma.6@student.rug.nl) */
/* date:        10-06-2016                                          */
/* version:     1.0.0                                               */
/* description: This program determines whether or not two rectangles overlap */

// Includes libraries for functionalities
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int firstx, firsty;   // Coordinates of first point
int secondx, secondy; // Coordinates of second point
int thirdx, thirdy;   // Coordinates of third point
int fourthx, fourthy; // Coordinates of fourth point

	int main(int argc, char *argv[]) {

	scanf("%d %d %d %d %d %d %d %d", &firstx, &firsty, &secondx, &secondy, &thirdx, &thirdy, &fourthx, &fourthy);

	// Determines whether the second point lies within the rectangle made by the third and fourth point
	if(secondx >= thirdx && secondx <= fourthx && secondy >= thirdy && secondy <= fourthy) {
		printf("overlap\n");
	} else {
	if(secondx <= thirdx && secondx >= fourthx && secondy <= thirdy && secondy >= fourthy) {
		printf("overlap\n");
	} else {
	if(secondx <= thirdx && secondx >= fourthx && secondy >= thirdy && secondy <= fourthy) {
		printf("overlap\n");
	} else {
	if(secondx >= thirdx && secondx <= fourthx && secondy <= thirdy && secondy >= fourthy) {
		printf("overlap\n");
	} else {
		
	// Determines whether the first point lies within the rectangle made by the third and fourth point
	if(firstx >= thirdx && firstx <= fourthx && firsty >= thirdy && firsty <= fourthy) {
		printf("overlap\n");
	} else {
	if(firstx <= thirdx && firstx >= fourthx && firsty <= thirdy && firsty >= fourthy) {
		printf("overlap\n");	
	} else {
	if(firstx <= thirdx && firstx >= fourthx && firsty >= thirdy && firsty <= fourthy) {
		printf("overlap\n");	
	} else {
	if(firstx >= thirdx && firstx <= fourthx && firsty <= thirdy && firsty >= fourthy) {
		printf("overlap\n");
	} else {

	// Determines whether the third point lies with the rectangle made by the first and second point
	if(thirdx >= firstx && thirdx <= secondx && thirdy >= firsty && thirdy <= secondy) {
		printf("overlap\n");
	} else {
	if(thirdx <= firstx && thirdx >= secondx && thirdy <= firsty && thirdy >= secondy) {
		printf("overlap\n");	
	} else {
	if(thirdx <= firstx && thirdx >= secondx && thirdy >= firsty && thirdy <= secondy) {
		printf("overlap\n");	
	} else {
	if(thirdx >= firstx && thirdx <= secondx && thirdy <= firsty && thirdy >= secondy) {
		printf("overlap\n");
	} else {
		printf("no overlap\n");
	}
	return 0;
} } } } } } } } } } } }