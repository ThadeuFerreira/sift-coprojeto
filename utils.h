/**@file
   Miscellaneous utility functions.
   
   @author Rob Hess
   @version 1.0.0-20060404
*/

#ifndef UTILS_H
#define UTILS_H

#include "cxcore.h"
#include "cv.h"

#include <stdio.h>

/* absolute value */
#ifndef ABS
#define ABS(x) ( ( x < 0 )? -x : x )
#endif

/***************************** Inline Functions ******************************/


/**
   A function to get a pixel value from an 8-bit unsigned image.
   
   @param img an image
   @param r row
   @param c column
   @return Returns the value of the pixel at (\a r, \a c) in \a img
*/
static inline int pixval8( IplImage* img, int r, int c )
{
  return (int)( ( (uchar*)(img->imageData + img->widthStep*r) )[c] );
}


/**
   A function to set a pixel value in an 8-bit unsigned image.
   
   @param img an image
   @param r row
   @param c column
   @param val pixel value
*/
static inline void setpix8( IplImage* img, int r, int c, uchar val)
{
  ( (uchar*)(img->imageData + img->widthStep*r) )[c] = val;
}


/**
   A function to get a pixel value from a 32-bit floating-point image.
   
   @param img an image
   @param r row
   @param c column
   @return Returns the value of the pixel at (\a r, \a c) in \a img
*/
static inline float pixval32f( IplImage* img, int r, int c )
{
  return ( (float*)(img->imageData + img->widthStep*r) )[c];
}


/**
   A function to set a pixel value in a 32-bit floating-point image.
   
   @param img an image
   @param r row
   @param c column
   @param val pixel value
*/
static inline void setpix32f( IplImage* img, int r, int c, float val )
{
  ( (float*)(img->imageData + img->widthStep*r) )[c] = val;
}


/**
   A function to get a pixel value from a 64-bit floating-point image.
   
   @param img an image
   @param r row
   @param c column
   @return Returns the value of the pixel at (\a r, \a c) in \a img
*/
static inline double pixval64f( IplImage* img, int r, int c )
{
  return (double)( ( (double*)(img->imageData + img->widthStep*r) )[c] );
}


/**
   A function to set a pixel value in a 64-bit floating-point image.
   
   @param img an image
   @param r row
   @param c column
   @param val pixel value
*/
static inline void setpix64f( IplImage* img, int r, int c, double val )
{
  ( (double*)(img->imageData + img->widthStep*r) )[c] = val;
}


/**************************** Function Prototypes ****************************/


/**
   Prints an error message and aborts the program.  The error message is
   of the form "Error: ...", where the ... is specified by the \a format
   argument
   
   @param format an error message format string (as with \c printf(3)).
*/
extern void fatal_error( char* format, ... );


#endif
