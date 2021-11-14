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
#include <stdio.h>
#include <stdint.h> 
#include <time.h>
#include <string.h>
#include <math.h>
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

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer.
// We have already done this function during our Lecture 25 Flipped Class
// so use it in this lab's intarr.c.
intarr_t* intarr_copy( const intarr_t* ia ){
  //create new intarr_t
  intarr_t* duplicate = malloc(sizeof(intarr_t));
  //check if memory allocation fails
  if(duplicate == NULL){
    return NULL;
  }
  //duplicate fields
  duplicate->size = ia->size;
  duplicate->data = malloc(sizeof(int)*duplicate->size);

  //copy data of ia to duplicate
  for(unsigned int i = 0; i < ia->size; i++){
    duplicate->data[i] = ia->data[i];
  }
  return duplicate;
}

// Get a deep copy of a portion of ia from index 'first' to index 'last'
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specified section. If an error
// occurs, i.e. ia is null, 'first' or 'last' are out of bounds, 
// 'last' < 'first', or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia, 
								unsigned int first, 
								unsigned int last ){
  //check if ia is NULL, bounds first and last are valid
  if(ia == NULL || first > ia->size || last > ia->size || first > last){
    return NULL;
  }
  //make duplicate subarray
  intarr_t* duplicate_subarray = malloc(sizeof(intarr_t));

  //check if duplicate subarray is NULL
  if(duplicate_subarray == NULL){
    return NULL;
  }

  //if everything is valid...
  else{
    //new size of subarray is last-first+1 (e.g. 2-4 size would be 4-2+1 =3)
    int newSize = last - first + 1;
    int dupLoop = 0;

    //update length and allocate memory
    duplicate_subarray->size = newSize;
    duplicate_subarray->data = malloc(sizeof(int)*newSize);

    //duplicate selected section if ia into the subarray.
    for(unsigned int i = first; i <= last; i++){
      duplicate_subarray->data[dupLoop] = ia->data[i];
      dupLoop++;
    }
    return duplicate_subarray;
  }
  //otherwise return NULL
  return NULL;
}

// Save the entire array ia into a file called 'filename' in a binary
// file format that can be loaded by intarr_load_binary(). 
// Returns zero on success, or a non-zero error code on failure. 
// Arrays of size 0 should produce an output file containing an empty array.
// Make sure you validate the parameters before you use them.
int intarr_save_binary( intarr_t* ia, const char* filename ){
  //check if ia and filename are valid
  if(ia == NULL || filename == NULL){
    return 1;
  }

  //if successful...
  FILE* new = fopen(filename, "w");

  //write contents of array into file
  //fwrite also returns total number of elements successfully written, so if equal to size of array, then it is successful
  if(fwrite(ia->data, sizeof(int), ia->size, new) == ia->size){
    //close file
    fclose(new);
    return 0;
  }
  //otherwise, dont alter file and close it
  else{
    fclose(new);
    return 1;
  }
}

// Load a new array from the file called 'filename', that was
// previously saved using intarr_save_binary(). 
// Returns a pointer to a newly-allocated intarr_t on success, 
// or NULL on failure.
// Make sure you validate the parameter before you use it.
intarr_t* intarr_load_binary( const char* filename ){
  //make sure filename is valid
  if(filename == NULL){
    return NULL;
  }

  //read the file
  FILE* new = fopen(filename, "r");
  //validate that the fopen worked succesfully
  if(new == NULL){
    return NULL;
  }

  //set position to end of file
  fseek(new, 0, SEEK_END);
  //to tell the size of the file, we use ftell to get current position
  //divide by sizeof(int) since ftell returns size in bytes and we want number of elements
  int length = ftell(new)/sizeof(int);

  //set position to beginning of file
  fseek(new, 0, SEEK_SET);

  //create new array
  intarr_t* array = malloc(sizeof(intarr_t));

  //set size and allocate memory
  array->size = length;
  array->data = malloc(sizeof(int)*array->size);

  //if fread reads the same amount of elements that is supposed to read...
  if(fread(array->data, sizeof(int), length, new) == array->size){
    fclose(new);
    return array;
  }

  else{
    fclose(new);
    return NULL;
  }
}
