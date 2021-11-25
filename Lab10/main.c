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
  p.x = 1.23;
  p.y = 4.56;
  p.z = 7.89;

  point_array_t A;
  
  point_array_init( &A );

  point_array_append( &A, &p );

  point_array_print( &A );

  return 0;
}
