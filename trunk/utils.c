/*
  Miscellaneous utility functions.
  
  @author Rob Hess
  @version 1.0.0-20060404
*/

#include "utils.h"

#include <stdio.h>
#include <stdlib.h>


/*************************** Function Definitions ****************************/


/*
  Prints an error message and aborts the program.  The error message is
  of the form "Error: ...", where the ... is specified by the \a format
  argument
  
  @param format an error message format string (as with \c printf(3)).
*/
void fatal_error(char* format, ...)
{
  fprintf( stderr, "Error: ");
  abort();
}
