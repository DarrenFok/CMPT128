/* Header comment block */

#include <stdint.h> // for uint8_t
#include <stdlib.h> // for malloc()
#include <string.h> // for memset()
#include <stdio.h> 

#include "intarr.h"

void print_intarr(intarr_t* ia) {
	
  if (ia != NULL ) {
    printf("Printing intarr of length %d:\n", ia->size);
    for( unsigned int i=0; i < ia->size; i++ )
      printf( "%d ", ia->data[i] );
    puts( "(end)" );
  }
  
  return;
}

int main( int argc, char* argv[] ) {

  printf("Creating test_ia\n"); 
  intarr_t* test_ia = intarr_create( 10 );
  if ( test_ia ==  NULL ) {
    printf("test_ia ==  NULL\n");
    return 1;
  } 

  printf("Populating test_ia\n");
  // Put random data in the array
  intarr_fill_with_random( test_ia );

  printf("Printing test_ia\n"); 
  print_intarr( test_ia );

  printf("Setting third index to 5\n");
  intarr_set(test_ia, 2, 5);

  printf("Printing modified test_ia\n");
  print_intarr(test_ia);

  printf("Sorting test_ia\n");
  intarr_sort(test_ia);

  printf("Printing sorted test_ia\n");
  print_intarr(test_ia);

  printf("Resizing test_ia to one less than original");
  intarr_resize(test_ia, 9);
  intarr_fill_with_random(test_ia);
  print_intarr(test_ia);

  printf("Resizing test_ia to one more than original");
  intarr_resize(test_ia, 11);
  intarr_fill_with_random(test_ia);
  print_intarr(test_ia);


  return 0;
}