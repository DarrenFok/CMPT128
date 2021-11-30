#include <stdio.h>
#include "point_array.h"

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa ){
    pa->size = 0;
    pa->numOfPts = 0;
    pa->points = realloc(pa->points, sizeof(point_t));
}

// Resets the array to be empty, freeing any memory allocated if necessary.
void point_array_reset( point_array_t* pa ){
    //set all xyz of each element to 0
    for(unsigned int i = 0; i < pa->size; i++){
        pa->points[i].x = 0;
        pa->points[i].y = 0;
        pa->points[i].z = 0;
    }
    //set size back to 0
    pa->size = 0;

    //set numOfPts back to 0;
    pa->numOfPts = 0;

    //realloc memory so its size is 0, basically frees it
    pa->points = realloc(pa->points, 0);
}

// Append a point to the end of an array. If successful, return 0, else return 1.
int point_array_append( point_array_t* pa, point_t* p ){
    //validate parameters
    if(pa == NULL || p == NULL){
        return 1;
    }
    if(pa->size == 0){ //if the array is empty
        pa->size = 1;
        pa->points = realloc(pa->points, sizeof(point_t)*pa->size*2);
        pa->numOfPts = 2; //double length by 2 
        //implement fields of p into last index
        pa->points[pa->size].x = p->x;
        pa->points[pa->size].y = p->y;
        pa->points[pa->size].z = p->z;
    } 

    else{ //if not empty (basically if it has any size other than 0)
        //implement fields of p into last index
        pa->points[pa->size].x = p->x;
        pa->points[pa->size].y = p->y;
        pa->points[pa->size].z = p->z;
        //increase size by 1
        pa->size = pa->size+1;
    }

    //if we have reached the maximum memory, multiply by 2 again
    if(pa->numOfPts == pa->size){
        pa->numOfPts = pa->numOfPts*2;
        pa->points = realloc(pa->points, sizeof(point_t) * pa->numOfPts);
    }
    return 0;

}

// Remove the point at index i from the array, reducing the number of elements
// stored in the array by one. The order of points in the array may change.
// If successful, return 0, else return 1. 
int point_array_remove( point_array_t* pa, unsigned int i ){
    if(i >= pa->size || pa->size = 0){
        return 1;
    }
    //switch desired element with last element, and get rid of last element
    pa->points[i].x = pa->points[pa->size-1].x;
    pa->points[i].y = pa->points[pa->size-1].y;
    pa->points[i].z = pa->points[pa->size-1].z;
    //set last element's fields to empty and decrease size
    pa->points[pa->size-1].x = 0;
    pa->points[pa->size-1].y = 0; 
    pa->points[pa->size-1].z = 0;

    pa->size = pa->size-1;
    return 0; 
}