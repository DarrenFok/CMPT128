#include <stdlib.h> 
#include <stdlib.h>
#include <time.h>

#include "intarr.h"

// Create a new intarr_t with initial array size "size".
// If successful (i.e. memory allocation succeeds), returns a pointer
// to a newly-allocated intarr_t. 
// If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int size ){
  
  //Allocate memory on heap for struct
  intarr_t* *ia = malloc(sizeof(intarr_t));
  if(ia != NULL){
    
    //Set the field 'size'
    ia -> size = size;
    
    //Allocate memory on heap for array
    ia -> data = malloc(size * sizeof(int));
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
void intarr_destroy( intarr_t* ia ){
  //If heap memory is allocated for struct...
  if(ia != NULL){
    //If heap memory is allocated for array...
    if(ia -> data != NULL){
      //free heap memory for array
      free(ia -> data);
      ia -> data = NULL;
    }
  
    //free heap memory for struct
    free(ia);// Sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return INTARR_BADARRAY.
// Implement whichever sort algorithms we have seen in our lectures. Up to you!
intarr_result_t intarr_sort( intarr_t* ia );
    ia = NULL;
  }
  return;
}

// Fill the array with "size" random numbers.
void intarr_fill_with_random( intarr_t* ia ){
  //If struct is not null..
  if(ia != NULL){
    //initiaize random number generator with current time in seconds
    srand(time(NULL);
    
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
        if(ia->data[i] == target){
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
// ia are sorted on return. If ia is null, return INTARR_BADARRAY.
// Implement whichever sort algorithms we have seen in our lectures. Up to you!
intarr_result_t intarr_sort( intarr_t* ia ){
  if(ia != NULL){
    for(unsigned int loop = 0; loop < ia->size; loop++){
      
                          
  
