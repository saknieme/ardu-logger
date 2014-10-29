/* ---------------------------------------------------------------------------
 * File: al_observer.h
 * ---------------------------------------------------------------------------
 */
 
#ifndef AL_OBSERVER_H
#define AL_OBSERVER_H

#include "al_types.h"

/*
 *
 */ 
typedef void ( *al_DataNotify ) ( void* instance, const al_Data* data );

/*
 *
 */ 
typedef struct
{
    void*           instance;
    al_DataNotify   notification;
} al_Observer;
 
#endif /* AL_OBSERVER_H */
 