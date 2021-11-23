/* 
 * Filename: list.c
 *
 * Description: Functions that do operations on linked lists
 *
 * Completed by: Darren Fok and Anushka Kulasekara
 * Date: November 24th, 2021
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/* Implements a linked list of integers

 A list is comprised of a single header and zero or more elements. The
 header contains pointers to the first and last elements in the list,
 or NULL if the list is empty. The first element contains a pointer to
 the next element, and so on. The last element in the list has its
 "next" pointer set to NULL.

 ** Global Precondition **

 Functions that operate on an existing list require a valid pointer to
 a list_t header as their first argument.
*/

// Returns a pointer to a new header for an empty list, or NULL if
// memory allocation fails.
list_t* list_create( void ) {

  list_t* l = malloc( sizeof(list_t) );
  if ( l ) {
    l->head = NULL;
    l->tail = NULL;
    return l;
  }

  return NULL;
}

// Frees all the memory used by the list.
void list_destroy( list_t* list ) {
    element_t* current = list->head;
    //keep looping until we hit a null pointer
    while(current != NULL){
        //set the next element to free
        element_t* next = current->next;
        //free current
        free(current);
        current = next;
    }

  free(list);
}

// Returns a pointer to a new list element containing integer i and
// next-pointer set to NULL, or NULL if memory allocation fails.
element_t* element_create( int i ) {

  element_t* el = malloc( sizeof(element_t) );
  //check if allocation was successful
  if(el == NULL){
      return NULL;
  }
  else{
      el->val = i;
      el->next = NULL;
      return el;
  }

  return NULL;
}

// Appends a new element containing integer i to the end of the
// list. Returns 0 on success, else 1.
int list_append( list_t* list, int i ) {
  //create element with given value i
  element_t* new = malloc(sizeof(element_t));
  //check for allocation success 
  if(new == NULL){
      return 1;
  }
  if(new != NULL){
      new->val = i;
      new->next = NULL;
  }
  
  //if linked list is empty, make this new element the first one  
  if(list == NULL){
      list->head = new;
  }
  
  //if last element in list is not NULL, make its next the new one and update tail
  if(list->tail != NULL){
      list->tail->next = new;
  }
  
  list->tail = new;
  
  //return 0 on success
  return 0; 
}

// Prepends a new element containing integer i to the front of the
// list. Returns 0 on success, else 1.
int list_prepend( list_t* list, int i ) {
  element_t* el = element_create( i );
  //check for allocation success 
  if ( el == NULL ) {
      return 1;
  }

  if(el != NULL){
      el->val = i;
      el->next = NULL;
  }
  
  //check whether linked list is empty, if it is, then make it the first/last (technically)
  if(list->tail == NULL){
      list->tail = el;
  }
  
  //if it isn't empty, update new element's next to first one 
  if(list->head != NULL){
      el->next = list->head;
  }
  
  list->head = el;
  
  //return 0 if successful
  return 0;
}

// Returns a pointer to the ith list element, where the list head is
// 0, head->next is 1, etc., or NULL if i is out of range
element_t* list_index( list_t* list, unsigned int i ) {
  
  element_t* el = list->head;
  unsigned int now = 0;
    
  //check if list is empty
  if(list->head == NULL){
      return NULL;
  }
  
  //while we haven't checked last element (since last is null)
  while(el != NULL){
      //if at desired index 
      if(now == i){
          //return element 
          return (el);
      }
      //otherwise increment now and move to next element
      now++;
      el = el->next;
  }
  //if i is out of range, return null 
  return NULL;
}

// Prints a list in human-readable form from the first to last
// elements, between curly braces.
void list_print( list_t* list ) {
  printf( "{" );
  
  for( element_t* el = list->head; el; el = el->next )
    printf( " %d", el->val );

  printf( " }\n" );
  
  return;
}




