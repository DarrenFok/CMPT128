/*
 * Filename: imgops.h
 *
 * Description: Simple operations on images
 *
 * Author: RV
 * Modified by: AL
 * 
 * Date: 2014
 */

/* Get the value in the array at coordinate (x,y). */
uint8_t get_pixel( const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   unsigned int x,
		   unsigned int y );

/* Set the pixel at coordinate {x,y} to the specified color. */
void set_pixel( uint8_t array[], 
		unsigned int cols, 
		unsigned int rows,
		unsigned int x,
		unsigned int y,
		uint8_t color );

/*
  Returns a pointer to a freshly allocated array that contains the
  same values as the original array, or a null pointer if the
  allocation fails. The caller is responsible for freeing the array
  later.
*/
uint8_t* copy( const uint8_t array[], 
	       unsigned int cols, 
	       unsigned int rows );

/* ---------------------- Quiz 2 ---------------------- */

/* Flip the image top-to-bottom. */
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows );
