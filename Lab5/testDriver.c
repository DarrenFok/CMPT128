/*
 * testDriver.c - Test functions from imgops.c
 * Author: RV - 2014
 * 
 * Modified by: AL - 2021
 */

#include <stdlib.h> // for random()
#include <stdint.h> // for explicit integer types, eg. uint8_t
#include <string.h> // for memset()
#include <assert.h>
#include <stdio.h>

// image drawing functions
#include "draw.h"

// load PNG image function
#include "png.h"

// image manipulation functions
#include "imgops.h"


int main( int argc, char* argv[] )
{
  const unsigned int winwidth  = 400;
  const unsigned int winheight = 400;

  unsigned int imgwidth  = winwidth / 4;
  unsigned int imgheight = winheight / 4 ;

  // Initialize the graphics system
  // ********************************************************
  // Get a first window
  draw_startup( (char*)"Window 1", winwidth, winheight );

  uint8_t* img = NULL;

  if( argc == 2 ) // If a filename was specified: open it
  {
      uint32_t depth=0;
      int alpha=0;
      if( LoadPngImage( argv[1], &imgwidth, &imgheight, &depth, &alpha, &img ) == 0 )
	  {
         printf( "failed to load image %s\n", argv[1] );
         exit(1);
      }
  }
  else // No filename specified: create a blank image
  {
      // Allocate an array for our image
      img = malloc( imgwidth * imgheight * sizeof(uint8_t) );
      if( img == NULL )
      {
         printf( "failed to allocate memory for image.\n" );
         exit(1);
      }

      // Set the whole array to zero (black)
      memset( img, 0, imgwidth * imgheight * sizeof(img[0] ));
    }

  // Draw the array as a grey-scale image in the window
  // This function returns after a user clicks or presses a button in the window
  printf( "Original image\n" );
  draw_image_grey( img, imgwidth, imgheight );

  // ********************************************************
  // Get a second window
  draw_startup( (char*)"Window 2", winwidth, winheight );

  // Get a copy of original image
  printf( "Image copied\n" );
  uint8_t* img_Inverted = copy( img, imgwidth, imgheight );

  // Invert color
  printf( "Image inverted\n" );
  invert( img_Inverted, imgwidth, imgheight );

  // Flip image horizontally
  printf("Image flipped horizontally\n");
  flip_horizontal (img_Inverted, imgwidth, imgheight);

  // draw the array as a grey-scale image in the window
  // This function returns after a user clicks or presses a button in the window
  draw_image_grey( img_Inverted, imgwidth, imgheight );

  // ********************************************************
  //For this test, don't input hadfield.png so we can test the now-white inverted photo since it's not as noticeable. However, with hadfield.png you may see irregular
  //black dots, meaning that this test has worked. 

  draw_startup( (char*)"Window 3", winwidth, winheight);

  //Copy of original image
  printf( "Image copied\n");
  uint8_t* img_colorChange = copy (img_Inverted, imgwidth, imgheight);

  //Change white to black
  printf("Color changed of original black from white to black\n");
  replace_color(img_colorChange, imgwidth, imgheight, 255, 0);

  //Draw image
  draw_image_grey(img_colorChange, imgwidth, imgheight);

  //*********************************************************

  printf("returning darkest color of img... ");
  printf("%d\n", max(img, winwidth, winheight));

  printf("retruning lightest color of img... ");
  printf("%d\n", min(img, winwidth, winheight));

  //*********************************************************

  draw_startup( (char*) "Window 4", winwidth, winheight);

  uint8_t* img_black = copy(img, imgwidth, imgheight);

  zero(img_black, imgwidth, imgheight);

  draw_image_grey(img_black, imgwidth, imgheight);

  //*********************************************************

  // Finalize the graphics system, freeing its resources
  draw_shutdown();

  // Every malloc() should have a matching free()
  free(img);
    
  // Let's get in the habit of setting all freed pointers to NULL
  img = NULL;
  
  return 0;
}
