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

/* Set every pixel to 0 (black). */
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows );

/*
  Returns a pointer to a freshly allocated array that contains the
  same values as the original array, or a null pointer if the
  allocation fails. The caller is responsible for freeing the array
  later.
*/
uint8_t* copy( const uint8_t array[], 
	       unsigned int cols, 
	       unsigned int rows );

/* Return the darkest color that appears in the array; 
   i.e. the smallest value.
*/
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows );

/* Return the lightest color that appears in the array; 
   i.e. the largest value.
*/
uint8_t max( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows );

/* Replace every instance of pre_color with post_color. */
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color );

/* Flip the image, left-to-right, like in a mirror. */
void flip_horizontal( uint8_t array[], 
		      unsigned int cols, 
		      unsigned int rows );

/* Find the first coordinate of the first pixel with a value that
   equals color. Search from left-to-right, top-to-bottom. If it is
   found, store the coordinates in *x and *y and return 1. If it is
   not found, return 0.
*/
int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y );

/* Invert the image, so that black becomes white and vice
   versa, and light shades of grey become the corresponding dark
   shade.
*/
void invert( uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows );

/*  Defines a region, and sets every pixel within that region to
	an assigned color
*/
void region_set (uint8_t array[],
				 unsigned int cols,
				 unsigned int rows,
				 unsigned int left,
				 unsigned int top,
				 unsigned int right,
				 unsigned int bottom,
				 uint8_t color);