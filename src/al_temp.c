/* ---------------------------------------------------------------------------
 * File: al_temp.c
 * Description: -
 *
 * Author: saknieme
 * ---------------------------------------------------------------------------
 */

#include <stdlib.h>

#include "al_types.h"
#include "al_common.h"
#include "al_observer.h"
#include "al_observer_list.h"

/* ---------------- LOCAL VARIABLES ---------------------------------------- */

static al_Observer observer = { 0 };

/* ---------------- LOCAL FUNCTIONS ---------------------------------------- */

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
            /* TODO */
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
