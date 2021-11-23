/* Header comment block */

#include <stdint.h> // for uint8_t
#include <stdlib.h> // for malloc()
#include <string.h> // for memset()
#include <stdio.h> 
#include <math.h>

#include "list.h"

int main( int argc, char* argv[] ) {

  printf("Creating list\n");
  list_t* new = list_create();

  printf("\nAppending elements 1-5\n");
  for(unsigned int i = 6; i < 11; i++){
    list_append(new, i);
  }

  printf("Printing list\n");
  list_print(new);

  printf("\nPrepending elements\n");
  for(unsigned int i = 5; i > 0; i--){
    list_prepend(new, i);
  }

  printf("Printing list\n");
  list_print(new);

  //getting 3rd index of list
  printf("\nGetting value at second index of list"); 
  int index = 2;
  element_t* test = list_index(new, index);
  printf("\nValue at at index %d is %d\n", index, test->val);

  list_destroy(new);

  return 0;
}