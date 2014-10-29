/* ---------------------------------------------------------------------------
 * File: al_temp.c
 * Description: -
 *
 * Author: saknieme
 * ---------------------------------------------------------------------------
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "al_types.h"
#include "al_common.h"
#include "al_file_handling.h"
#include "al_observer.h"
#include "al_observer_list.h"

/* ---------------- LOCAL CONSTANTS ---------------------------------------- */

static const char* al_TempFilename = "data/al_temp.dat";
static const char* al_TempFileParams = "a";
static const char* al_TempFileFormat = "";

/* ---------------- LOCAL STRUCTURES --------------------------------------- */

/*
 *
 */
struct al_TempContainer
{
    FILE* fd;
    const char* fname;
};

/* ---------------- LOCAL VARIABLES ---------------------------------------- */

static al_Observer observer = { 0 };
static struct al_TempContainer container = { 0 };

/* ---------------- LOCAL FUNCTIONS ---------------------------------------- */

/*
 *
 */
static void format_line_and_write( const al_Data* data )
{
    time_t raw_time = { 0 };
    struct tm* time_info = NULL;
    char formatted_time[ 25 ] = { 0 };
    char formatted_line[ 25 + 10 ] = { 0 };
    float* temp = NULL;

    /* Code */
    
    /* Get and format local time. */
    time( &raw_time );
    time_info = localtime( &raw_time );
    strftime( formatted_time, 80, "%c", time_info );

    /* Format final string */
    temp = ( float* ) data->data;
    
    sprintf( formatted_line, "%s|%f\n", formatted_time, *temp );
    
    /* Write entry to file. */
    al_fh_write_line( container.fd, formatted_line );
}

/*
 * Function which is used to handle temperature noitification events received.
 */
static void handle( void* instance, const al_Data* data )
{
    /* Code */

    AL_DEBUG_PRINT_1( "AL-TEMP: Notification received. Type: ", data->type );

    switch ( data->type )
    {
        case AL_ETYPE_TEMP_1:
            format_line_and_write( data );  
            break;
        case AL_ETYPE_TEMP_2:
            /* TODO */
            break;
        default:
            /* Pass through */
            break;
    }
}

/*
 * Function which is used to initialize the module.
 */
static void init( void )
{
    container.fname = al_TempFilename;
    container.fd = al_fh_open_file( container.fname, al_TempFileParams );

    observer.instance = NULL;
    observer.notification = handle;
    al_obs_list_attach( &observer );
}

/*
 * Function which is used to clean memory reserved by the module.
 */
static void clean( void )
{
    al_obs_list_detach( &observer );
    
    al_fh_close_file( container.fd );
}

/* --------------- INTERFACE FUNCTIONS ------------------------------------- */

/*
 * See al_temp.h for details.
 */
void al_temp_init( void )
{
    /* Code */
    
    init();
}

/*
 * See al_temp.h for details.
 */
void al_temp_close( void )
{
    /* Code */
    
    clean();
}

/* End of file */
