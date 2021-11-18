/* Quiz3.h */

/* 
 * Wikipedia says that " ... a census is the procedure of systematically calculating, 
 * acquiring and recording information about the members of a given population."
 * In this structure called census, we shall only record the age of a given population. 
*/

typedef struct {
	int * ages;               // Valid ages: 0 to 130
	unsigned int arraySize;
	unsigned int numOfAges;
} census_t;  

// Description: Create a census with 0 ages and an array of the given size.
census_t * create_census( unsigned int anArraySize );

// Description: Destroy a census, releasing all its memory.
void destroy_census( census_t * census );

// Description: Insert an age into census. Return 0, if the age is
//              inserted successfully into census. Return 1 otherwise.
unsigned int insert_age( census_t * census, int anAge );

// Description: Compute and return the sum of all ages recorded in the census.
int sum_of_all_ages( census_t * census);

// Description: Compute and return the average age of the population recorded
//              in the census. If the recorded ages are 25, 13, 37, 75, 48 and 61
//              then the average returned by this function is 43.16667.
double average_age( census_t * census );

// Description: Return the age of the oldest person recorded in the census, 
//              otherwise return the value MIN_AGE - 1 (i.e., -1).
int oldest( census_t * census );

// Description: Print the content of census as follows (if arraySize = 15):
// There are 6 ages recorded in this census.
// Ages: 25 13 37 75 48 61
// We can record 9 more ages in this census.
void print_census( census_t * census );