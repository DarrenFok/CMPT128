/* 103 */

/* Header comment block */
//Filename: Quiz3.c
//Description: Functions that modify a census struct
//Completed by: Darren Fok
//Completion Date: November 18th, 2021

#include <stdio.h>
#include <stdlib.h>
#include "Quiz3.h"

#define MIN_AGE 0
#define MAX_AGE 130

// Description: Create a census with 0 ages and an array of the given size.
census_t * create_census( unsigned int anArraySize ) {

	census_t * census = malloc(sizeof(census_t));

	if ( census != NULL ) {
		census->ages = malloc(sizeof(int)*anArraySize);
		if ( census->ages == NULL) {
			free( census );
			census = NULL;
			return census;
		}
		census->arraySize = anArraySize;
		census->numOfAges = 0;
	}
	return census;
}

// Description: Destroy a census, releasing all its memory.
void destroy_census( census_t * census ) {

	// Put your code here
	//if there is heap memoery allocated for census
	if (census != NULL){
		//if there is heap memory allocated for the array
		if(census->ages != NULL){
			//then free array
			free(census->ages);
			census->ages = NULL;
		}
		
		//then free census
		free(census);
		census = NULL;
	}
	return;
}

// Description: Insert an age into census. Return 0, if the age is
//              inserted successfully into census. Return 1 otherwise.
unsigned int insert_age( census_t * census, int anAge ) {

	if ( census == NULL ) return 1;
	if ( census->ages == NULL ) return 1;
	if ( census->arraySize == census->numOfAges ) return 1;

	
	census->ages[census->numOfAges] = anAge;
	census->numOfAges++;

    return 0;
}

// Description: Compute and return the sum of all ages recorded in the census.
int sum_of_all_ages( census_t * census ) {
	int sum = 0;

	// Put your code here
	//get sum
	for(unsigned int i = 0; i < census->numOfAges; i++){
		//total all ages into sum
		sum += census->ages[i];
	}

	return sum;
}

// Description: Compute and return the average age of the population recorded
//              in the census. If the recorded ages are 25, 13, 37, 75, 48 and 61
//              then the average returned by this function is 43.16667.
double average_age( census_t * census ) {
	double average = 0;
	double sum = 0; 

	// Put your code here
	//get sum
	for(unsigned int i = 0; i < census->numOfAges; i++){
		//total all ages into sum
		sum += census->ages[i];
	}

	//get average by dividing sum by numOfAges
	average = sum / census->numOfAges;

	return average;
}

// Description: Return the age of the oldest person recorded in the census, 
//              otherwise return the value MIN_AGE - 1 (i.e., -1).
int oldest( census_t * census ) {
	//set max to first number
	int max = census->ages[0]; 

	if(census != NULL){
		// Put most of your code here 
		for(unsigned int i = 0; i < census->numOfAges; i++){
			//compare current index to max, if it is greater then...
			if(census->ages[i] > max){
				//make current index the new max
				max = census->ages[i];
			}
		}

		return max;
	}
	return MIN_AGE-1;
	
}

// Description: Print the content of census as follows (if arraySize = 15):
// There are 6 ages recorded in this census.
// Ages: 25 13 37 75 48 61
// We can record 9 more ages in this census.
void print_census( census_t * census ) {
	if ( census == NULL ) return;

	printf( "There are %d ages recorded in this census.\n", census->numOfAges );
	printf( "Ages: " );
	for ( unsigned int i = 0; i < census->numOfAges; i++ ){
			if ( i < (census->numOfAges-1) ) printf("%d ", census->ages[i]);
			else printf("%d", census->ages[i]);
	}
	printf("\nWe can record %d more ages in this census.\n", census->arraySize - census->numOfAges);
	return;
}
