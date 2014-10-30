/* ---------------------------------------------------------------------------
 * File: al_temp.c
 * ---------------------------------------------------------------------------
 */

#include <stdlib.h>
#include <stdio.h>

#include "al_types.h"
#include "al_common.h"
#include "al_observer.h"
#include "al_observer_list.h"

static al_Observer observer;

/*
 *
 */
static void al_temp_data_available(
    void* instance, const al_Data* data )
{
    AL_DEBUG_PRINT( "AL-TEMP: Notification received." );
}

void al_temp_init( void )
{
    observer.instance = NULL;
    observer.notification = al_temp_data_available;
    
    al_obs_list_attach( &observer );
}

void al_temp_close( void )
{
    al_obs_list_detach( &observer );
}

/* End of file */