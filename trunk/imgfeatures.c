/*
  Functions and structures for dealing with image features

  @author Rob Hess
  @version 1.0.0-20060607
*/

#include "utils.h"
#include "imgfeatures.h"

#include <cxcore.h>

void draw_lowe_features( IplImage*, struct feature*, int );
void draw_lowe_feature( IplImage*, struct feature*, CvScalar );

/*
  Draws a set of features on an image
  
  @param img image on which to draw features
  @param feat array of Oxford-type features
  @param n number of features
*/
void draw_features( IplImage* img, struct feature* feat, int n )
{
  int type;

  if( n <= 0  ||  ! feat )
    {
      printf("Warning: no features to send \n");
      return;
    }
  type = feat[0].type;
  switch( type )
    {
    case FEATURE_OXFD:
      printf("Function not prepared to send OXFD features");
      break;
    case FEATURE_LOWE:
      draw_lowe_features( img, feat, n );
      break;
    default:
      printf("Warning: send_features(): unrecognized feature");
      break;
    }
}

/*
  Calculates the squared Euclidian distance between two feature descriptors.
  
  @param f1 first feature
  @param f2 second feature
  
  @return Returns the squared Euclidian distance between the descriptors of
    f1 and f2.
*/
double descr_dist_sq( struct feature* f1, struct feature* f2 )
{
  double diff, dsq = 0;
  double* descr1, * descr2;
  int i, d;

  d = f1->d;
  if( f2->d != d )
    return DBL_MAX;
  descr1 = f1->descr;
  descr2 = f2->descr;

  for( i = 0; i < d; i++ )
    {
      diff = descr1[i] - descr2[i];
      dsq += diff*diff;
    }
  return dsq;
}



/***************************** Local Functions *******************************/

/*
  Draws Lowe-type features
  
  @param img image on which to draw features
  @param feat array of Oxford-type features
  @param n number of features
*/
void draw_lowe_features( IplImage* img, struct feature* feat, int n )
{
  CvScalar color = CV_RGB( 255, 255, 255 );
  int i;

  if( img-> nChannels > 1 )
    color = FEATURE_LOWE_COLOR;
  for( i = 0; i < n; i++ )
    draw_lowe_feature( img, feat + i, color );
}


/*
  Draws a single Lowe-type feature

  @param img image on which to draw
  @param feat feature to be drawn
  @param color color in which to draw
*/
void draw_lowe_feature( IplImage* img, struct feature* feat, CvScalar color )
{
  int len, hlen, blen, start_x, start_y, end_x, end_y, h1_x, h1_y, h2_x, h2_y;
  double scl, ori;
  double scale = 5.0;
  double hscale = 0.75;
  CvPoint start, end, h1, h2;

  /* compute points for an arrow scaled and rotated by feat's scl and ori */
  start_x = cvRound( feat->x );
  start_y = cvRound( feat->y );
  scl = feat->scl;
  ori = feat->ori;
  len = cvRound( scl * scale );
  hlen = cvRound( scl * hscale );
  blen = len - hlen;
  end_x = cvRound( len *  cos( ori ) ) + start_x;
  end_y = cvRound( len * -sin( ori ) ) + start_y;
  h1_x = cvRound( blen *  cos( ori + CV_PI / 18.0 ) ) + start_x;
  h1_y = cvRound( blen * -sin( ori + CV_PI / 18.0 ) ) + start_y;
  h2_x = cvRound( blen *  cos( ori - CV_PI / 18.0 ) ) + start_x;
  h2_y = cvRound( blen * -sin( ori - CV_PI / 18.0 ) ) + start_y;
  start = cvPoint( start_x, start_y );
  end = cvPoint( end_x, end_y );
  h1 = cvPoint( h1_x, h1_y );
  h2 = cvPoint( h2_x, h2_y );

  cvLine( img, start, end, color, 1, 8, 0 );
  cvLine( img, end, h1, color, 1, 8, 0 );
  cvLine( img, end, h2, color, 1, 8, 0 );
}


