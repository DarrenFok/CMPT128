/* testDriver.c */

#include <stdio.h>
#include "Quiz3.h"

int main( void ) {

	printf("--------------census1----------------\n");
	
	census_t * census1 = create_census( 15 );

	if ( insert_age( census1, 25 ) == 1) {
		printf("Problem adding 25.\n");
		return 1;
    }
	if ( insert_age( census1, 13 ) == 1) {
		printf("Problem adding 13.\n");
		return 1;
 	}
	if ( insert_age( census1, 37 ) == 1) {
		printf("Problem adding 37.\n");
		return 1;
 	}
	if ( insert_age( census1, 75 ) == 1) {
		printf("Problem adding 75.\n");
		return 1;
 	}
	if ( insert_age( census1, 48 ) == 1) {
		printf("Problem adding 48.\n");
		return 1;
 	}
	if ( insert_age( census1, 61 ) == 1) {
		printf("Problem adding 61.\n");
		return 1;
 	}

  	print_census( census1 );

	//printing sum
	int sum = sum_of_all_ages(census1);
	printf("This is the sum: %d\n", sum);
	printf("\n");

	//printing average
	double average = average_age(census1);
	printf("This is the average: %.5f\n", average);
	printf("\n");

	//finding oldest
	int old = oldest(census1);
	printf("This is the oldest age: %d\n", old);

	destroy_census( census1 );

	return 0;
}