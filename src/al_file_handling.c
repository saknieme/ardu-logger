/* ---------------------------------------------------------------------------
 * File: al_file_handling.c
 * Description: -
 *
 * Author: saknieme
 * ---------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "al_common.h"
#include "al_file_handling.h"

/* ---------------- INTERFACE FUNCTIONS ----------------------------------- */

/*
 * See al_file_handling.h for details.
 */
FILE* al_fh_open_file( const char* fname, const char* params )
{
  FILE* fd = NULL;
  
  /* Code */

  assert( NULL != fname );
  assert( NULL != params );
  
  fd = fopen( fname, params );
  if ( NULL == fd )
  {
    perror( "Error when opening file.\n" );
    return fd; /* NULL */
  }

  AL_DEBUG_PRINT_S( "AL-FH: File opened. Filename: ", fname );
  return fd;
}

/*
 * See al_file_handling.h for details.
 */
void al_fh_close_file( FILE* fd )
{
  /* Code */

  assert( NULL != fd );
  
  fclose( fd );
  fd = NULL;

  AL_DEBUG_PRINT( "AL-FH: File closed." );
}

/*
 * See al_file_handling.h for details.
 */
void al_fh_write_line( FILE* fd, const char* line )
{
  /* Code */
  
  assert( NULL != fd );
  assert( NULL != line );
  
  if ( EOF == fputs( line, fd ) )
  {
    AL_DEBUG_PRINT_1( "AL-FH: Line writing failed. Code: ", ferror( fd ) );
    return;
  }

  AL_DEBUG_PRINT_S( "AL-FH: Line written. Line: ", line );  
}

/* End of file */
