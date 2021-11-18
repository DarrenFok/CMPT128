/* 
 * intarr.h
 *
 * Provides a bounds-checked, resizable array of integers 
 * and several utility functions that operate on them.
 * 
 * Do not change this file as your intarr.c will be compiled using it as it is.
*/

/* Structure type that encapsulates our safe int array. */
typedef struct {
  int* data;
  unsigned int size;
} intarr_t;

/* A type for returning status codes */
typedef enum {
  INTARR_OK,
  INTARR_BADARRAY,
  INTARR_BADINDEX,
  INTARR_BADALLOC,
  INTARR_NOTFOUND
} intarr_result_t;

// Find the first occurrence of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
// Pay close attention to the above description as it indicates which 
// of the two algorithms (seen in our lectures) you are to implement.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i );
// Create a new intarr_t with initial array size "size".
// If successful (i.e. memory allocation succeeds), returns a pointer
// to a newly-allocated intarr_t. 
// If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int size );

// Free all memory allocated for ia. 
// If the pointer is null, do nothing. 
// If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia );

// Fill the array with "size" random numbers.
void intarr_fill_with_random( intarr_t* ia );

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia, 
                            unsigned int index, 
                            int val );

// If index is valid and val is non-null, set *val to ia->data[index] and return
// INTARR_OK. Otherwise do not modify *val and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia, 
                            unsigned int index, 
                            int* val );

// Find the first occurrence of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
// Pay close attention to the above description as it indicates which 
// of the two algorithms (seen in our lectures) you are to implement.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i );

// Sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return INTARR_BADARRAY.
// Implement whichever sort algorithms we have seen in our lectures. Up to you!
intarr_result_t intarr_sort( intarr_t* ia );

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
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newsize );
