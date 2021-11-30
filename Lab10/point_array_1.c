/* 
 * Filename: point_array_1.c
 *
 * Description: Functions that do operations on linked lists
 *
 * Completed by: Darren Fok and Anushka Kulasekara
 * Date: November 24th, 2021
 *
 */

#include <stdio.h>
#include "point_array.h"

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa ){
    pa->size = 0;
}

// Resets the array to be empty, freeing any memory allocated if necessary.
void point_array_reset( point_array_t* pa ){
    //set each xyz in each point back to 0
    for(unsigned int i = 0; i < pa->size; i++){
        pa->points[i].x = 0;
        pa->points[i].y = 0;
        pa->points[i].z = 0;
    }

    //set size back to 0
    pa->size = 0;

    //free allocated memory for pa->points
    pa->points = realloc(pa->points , 0);
}

// Append a point to the end of an array. If successful, return 0, else return 1.
int point_array_append( point_array_t* pa, point_t* p ){
    //check parameters
    if(p == NULL){
        return 0;
    }
    //increase the size of the array
    pa->size = pa->size+1;
    //allocate more memory for increased size array
    pa->points = realloc(pa->points, pa->size*sizeof(point_t));
    //check if the reallocation was successful
    if(pa->points == NULL){
        return 1;
    }
    //update new element's fields to that of the p's
    pa->points[pa->size-1].x = p->x;
    pa->points[pa->size-1].y = p->y;
    pa->points[pa->size-1].z = p->z;

    return 0;
}

// Remove the point at index i from the array, reducing the number of elements
// stored in the array by one. The order of points in the array may change.
// If successful, return 0, else return 1. 
int point_array_remove( point_array_t* pa, unsigned int i ){
    //check if given index i is out of bounds
    if(i >= pa->size){
        return 1;
    }

    //swap index i's with the last index
    pa->points[i].x = pa->points[pa->size-1].x;
    pa->points[i].y = pa->points[pa->size-1].y;
    pa->points[i].z = pa->points[pa->size-1].z;

    //shrink size by one so that it deletes the last index
    pa->size = pa->size-1;

    //realloc memory to shrink the size
    pa->points = realloc(pa->points, sizeof(point_t) * pa->size);
    return 0;
}





