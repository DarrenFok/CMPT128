/* 
 *  point_array.h
 *
 */

#include <stdlib.h>

typedef struct point {
  
  double x, y, z;  // 3D point
  
} point_t;

typedef struct {
  
  // Pointer to an array of point_t structs
  // This array has 'size' cells and currently, 'numOfPts'
  // of them contain a point (i.e., a point_t struct).
  point_t* points;
  
  // Number of points in the array
  size_t numOfPts;
  
  // Size of the array
  size_t size; 
  
} point_array_t;


/* All these functions require a valid (non-NULL) point_array_t pointer
   as their first parameter. They must fail if this is not the case. */

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa );

// Resets the array to be empty, freeing any memory allocated if necessary.
void point_array_reset( point_array_t* pa );

// Append a point to the end of an array. If successful, return 0, else return 1.
int point_array_append( point_array_t* pa, point_t* p );

// Remove the point at index i from the array, reducing the number of elements
// stored in the array by one. The order of points in the array may change.
// If successful, return 0, else return 1. 
int point_array_remove( point_array_t* pa, unsigned int i );
