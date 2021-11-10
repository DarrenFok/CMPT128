/*
 * Filename: intarr.c
 *
 * Description: Simple operations on arrays
 *
 * Author: RV
 * Modified by: AL
 *
 * Completed by: Darren Fok and Anushka Kulasekara
 * Completion Date: November 10, 2021
 */

#include <stdlib.h> 
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "intarr.h"

// Create a new intarr_t with initial array size "size".
// If successful (i.e. memory allocation succeeds), returns a pointer
// to a newly-allocated intarr_t. 
// If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int size ){

  //Allocate memory on heap for struct
  intarr_t *ia = malloc(sizeof(intarr_t));
  if(ia != NULL){
  
    //Set the field 'size'
    ia->size = size;
    
    //Allocate memory on heap for array
    ia->data = malloc(size * sizeof(int));
    if(ia -> data == NULL){
      free(ia);
      ia = NULL;
    }
  }
  return ia;
}

// Free all memory allocated for ia. 
// If the pointer is null, do nothing. 
// If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia ) {

  //If heap memory allocated for struct
  if(ia != NULL){

    // If heap memory allocated for array
    if(ia->data != NULL){

      //then free
      free(ia->data);
      ia->data = NULL;
    }
    
    //then free
    free(ia);
    ia = NULL;
  }
  return;
}

// Fill the array with "size" random numbers.
void intarr_fill_with_random( intarr_t* ia ){
  //If struct is not null..
  if(ia != NULL){
    //initiaize random number generator with current time in seconds
    srand(time(NULL));
    
    //fill array with random numbers
    for(unsigned int i = 0; i < ia->size; i++){
      ia->data[i] = rand() % ia->size;
    }
  }
  return;
}

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia, unsigned int index, int val ){
  //check if ia is null
  if(ia == NULL){
    return INTARR_BADARRAY;
  } 
  
  //check if index is valid
  if((index >= 0) && (index < ia->size)){
    ia->data[index] = val;
    return INTARR_OK;
  }
  
  else if((index < 0) && (index >= ia->size)){
    return INTARR_BADARRAY;
  }
}

// If index is valid and val is non-null, set *val to ia->data[index] and return
// INTARR_OK. Otherwise do not modify *val and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia, unsigned int index, int* val ){
  if(ia == NULL){
    return INTARR_BADARRAY;
  }
  
  //check if index is valid
  if(((index >= 0) && (index < ia->size)) && (val != NULL)){
    *val = ia->data[index];
    return INTARR_OK;
  }
  
  else{
    return INTARR_BADINDEX;
  }
}

// Find the first occurrence of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
// Pay close attention to the above description as it indicates which 
// of the two algorithms (seen in our lectures) you are to implement.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i ){
  if(ia != NULL){
    if(i != NULL){
      for(unsigned int loop = 0; loop < ia->size; loop++){
        if(ia->data[loop] == target){
          *i = loop;
          return INTARR_OK;
        }
      }
    }
    return INTARR_NOTFOUND;
  }
  return INTARR_BADARRAY;
}  
  
// Sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return INT/ Sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return INTARR_BADARRAY.
// Implement whichever sort algorithms we have seen in our lectures. Up to you!
intarr_result_t intarr_sort( intarr_t* ia ){
  //Fields
  int min = 0;
  int minPosition = 0;
  int temp = 0;

  if(ia != NULL){
    min = ia->data[0];
    //this loop determines the target (or first number)
    for(unsigned int loop = 0; loop < ia->size; loop++){
      min = ia->data[loop];
      //create a loop that follows the first one and is the index of the second number
      for(unsigned int loop2 = loop; loop2 < ia->size; loop2++){
        //if second number is less than the current target...
        if(ia->data[loop2] <= min){
          min = ia->data[loop2];
          minPosition = loop2; //take note of this position for swapping process later
        }
      }  
      temp = ia->data[loop];
      ia->data[loop] = min;
      ia->data[minPosition] = temp;
    }
   return INTARR_OK;
  }
  return INTARR_BADARRAY;
}

// Resize ia to contain newsize values. 
// Read: https://en.cppreference.com/w/c/memory/realloc)
// It says: if newsize is less than the original array size, 
// the end of the array is discarded. 
// If newsize is greater than the original array size, the values 
// of the new integers will be undefined. Leave them this way,
// but make sure your test driver calls 
// void intarr_fill_with_random( intarr_t* ia ); 
// right after (if this function is successful) to refill this array.
// If the allocation is successful, return INTARR_OK, otherwise 
// return INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newsize ){
  if(ia != NULL){

    //if the desired size is less than the current size...
    if(newsize < ia->size){
      ia->data = realloc(ia->data, newsize * sizeof(int));
      ia->size = newsize;
    }

    //if the desired size is greater than the current size...
    if(newsize > ia->size){
      ia->data = realloc(ia->data, newsize * sizeof(int));
      int oldsize = ia->size;
      ia->size = newsize;
      memset(ia->data, 0, (newsize - oldsize) * sizeof(int));
    }

    //checking if allocation is successful
    if(ia->data != NULL){
      return INTARR_OK;
    }

    else{
      return INTARR_BADALLOC;
    }
  }
  return INTARR_BADARRAY;
}