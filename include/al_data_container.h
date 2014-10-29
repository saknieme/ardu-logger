/* ---------------------------------------------------------------------------
 * File: al_data_container.h
 * ---------------------------------------------------------------------------
 */
 
#ifndef AL_DATA_CONTAINER_H
#define AL_DATA_CONTAINER_H

#include "al_data_observer.h"

/*
 *
 */
void attach( const al_data_observer* observer );

/*
 *
 */
void detach( const al_data_observer* observer );

#endif /* AL_DATA_CONTAINER_H */