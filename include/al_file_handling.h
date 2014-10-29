/* ---------------------------------------------------------------------------
 * File: al_file_handling.h
 * Description: -
 *
 * Author: saknieme
 * ---------------------------------------------------------------------------
 */

#ifndef AL_FILE_HANDLING_H
#define AL_FILE_HANDLING_H

/*
 * Opens given file with attributes.
 */
FILE* al_fh_open_file( const char* fname, const char* params );

/*
 * Closes file.
 */
void al_fh_close_file( FILE* fd );

/*
 * Writes one line to the given file.
 */
void al_fh_write_line( FILE* fd, const char* line );

#endif /* AL_FILE_HANDLING_H */
