
/*

main.c
Driver program for Nios II SIFT.

April 16 2009, by Mazzotti

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cv.h"
#include "imgfeatures.h"


IplImage* load_pgm (char* file_name);
void display_features (struct feature* features, int n);


int
main (int argc, char **argv)
{
  /* Image. */
  IplImage* img;
  
  /* Features. */
  struct feature* features;
  int n;
  
  /* Argument verification. */
  if (argc != 2)
    {
      printf ("Wrong number of arguments!\n");
      printf ("Usage: sift [image-file]\n\n");
      return 1;
    }
  
  /* Load image from file. */
  img = load_pgm (argv[1]);
  if (img == NULL)
    {
      printf ("Unable to load image file '%s'!\n", argv[1]);
      return 2;
    }
  
  /* Run SIFT. */
  n = sift_features (img, &features);
  display_features (features, n);
  
  /* Release memory. */
  cvReleaseImage (&img);
  free(features);
  
  return 0;
}
/* main */


void
display_features (struct feature* features, int n)
{
  int i;
  int j;
  
  /* For each feature... */
  for (i = 0; i < n; i++)
    {
      printf ("feature_%i: ", i);
      
      /* For each descriptor... */
      for (j = 0; j < features[i].d; j++)
	printf ("%i ", (int)(features[i].descr[j]));
      
      printf ("\n");
    }

   printf("Features found = %d\n", n);
}
/* display_features */


IplImage*
load_pgm (char* file_name)
{
  FILE* file;
  
  /*
    PGM file contents.
    See http://netpbm.sourceforge.net/doc/pgm.html for more information.
  */
  char pgm_id[3];  /* PGM file magic number. P2 is OK. */
  CvSize size;     /* Width and height. Positive integers.   */
  int max_val;     /* Maximum gray value. Must be 255.       */
  char pixel;
  
  IplImage* img;
  
  int i;
  int j;
  
  /* Open file. */
  file = fopen (file_name, "r");
  if (file == NULL)
    return NULL;
  
  /* Read image properties. */
  if (fscanf (file, "%s%i%i%i", pgm_id, &(size.width), &(size.height), &max_val) != 4)
    {
      fclose (file);
      return NULL;
    }
  
  /* Validade image properties. */
  if (strcmp (pgm_id, "P2") || size.width < 0 || size.height < 0 || max_val != 255)
    {
      fclose (file);
      return NULL;
    }
  
  /* Create OpenCV image structure. 1 channel (grayscale) of depth 8 (256 colors). */
  img = cvCreateImage (size, 8, 1);
  if (img == NULL)
    {
      fclose (file);
      return NULL;
    }
  
  /* Read pixels from file. */
  for (i = 0; i < size.width; i++)
    for (j = 0; j < size.height; j++)
      {
	/* Default pixel value is black. */
	if (fscanf (file, "%c", &pixel) != 1)
	  pixel = 0;
	
	((uchar*)(img->imageData + img->widthStep*j))[i] = pixel;
      }
  
  fclose (file);
  return img;
}
/* load_pgm */
