/* ---------------------------------------------------------------------------
 * File: al_data_observer.h
 * ---------------------------------------------------------------------------
 */
 
#ifndef AL_DATA_OBSERVER_H
#define AL_DATA_OBSERVER_H

#include "al_data_types.h"

/*
 *
 */ 
typedef void ( *al_data_notification )
    ( void* instance, const al_data* data );

/*
 *
 */ 
typedef struct
{
    void* instance;
    al_data_notification notification;
} al_data_observer;
 
 #endif /* AL_DATA_OBSERVER_H */
 