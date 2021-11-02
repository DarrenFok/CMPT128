/* 103
 * Filename: imgops.c
 *
 * Description: Simple operations on images
 *
 * Author: RV
 * Modified by: AL
 *
 * Completed by: Darren Fok
 * Completion Date: October 28th, 2021
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-------------------------------------------------
  PART 0: OPERATIONS ON A PIXEL 
*/

/* Get the value in the array at coordinate (x,y). */
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

/* Set the pixel at coordinate {x,y} to the specified color. */
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
    return;
} 

/* ---------------------- Quiz 2 ---------------------- */

/* Flip the image top-to-bottom. */
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{

  //your code here
  uint8_t temp = 0;
  
  for (int loop1 = 0; loop1<cols; loop1++){
    if (rows%2 == 0){
      for(int loop2 = 0; loop2 < rows/2; loop2++){
          temp = array[loop2*cols+loop1];
          array[loop2*cols+loop1] = array[(rows-loop2-1)*cols+loop1];
          array[(rows-loop2-1)*cols+loop1] = temp;
      }      
    }

    else{
      for(int loop2 = 0; loop2<(rows-1)/2; loop2++){
          temp = array[loop2*cols+loop1];
          array[loop2*cols+loop1] = array[(rows-loop2-1)*cols+loop1];
          array[(rows-loop2-1)*cols+loop1] = temp;
      }
    }
  } 
  return;
}
