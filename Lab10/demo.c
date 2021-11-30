/* 
 *  main.c
 *
 *  Description: Test driver for point_array.h
 *
 */

#include <stdio.h>

#include "point_array.h"

void point_print( point_t* p ) {
  
  if( p == NULL ) {
    puts( "(NULL)" );
    return;
  }

  printf( "(%.1f %.1f %.1f)", p->x, p->y, p->z );
  return;
}

void point_array_print( point_array_t* pa ) {

  if( pa == NULL ) {
    puts( "(NULL)" );
    return;
  }

  printf( "size:%d\n", (int)pa->size );

  for( int i=0; i<pa->size; i++ ) {
      printf( " [%d]-", i );
      point_print( pa->points+i );
      printf( "\n" );
  }
  printf( "\n" );

}

int main( int argc, char** argv ) {

  point_t p;
  p.x = 1.35;
  p.y = 6.79;
  p.z = 9.81;

  point_t p2;
  p2.x = 4.20;
  p2.y = 3.09;
  p2.z = 5.18;

  point_t p3;
  p3.x = 6.90;
  p3.y = 6.90;
  p3.z = 6.90;

  point_array_t A;
  
  //Creating array
  point_array_init( &A );
  point_array_append(&A, &p);
  point_array_print( &A );

  //Adding another point
  printf("Adding a second point\n");
  point_array_append(&A, &p2);
  point_array_print(&A);

  //Adding third point
  printf("Adding a third point\n");
  point_array_append(&A, &p3);
  point_array_print(&A);

  //Removing first point
  printf("Removing first point\n");
  point_array_remove(&A, 0);
  point_array_print(&A);

  return 0;
}
