/* ---------------------------------------------------------------------------
 * File: al_observer_list.h
 * ---------------------------------------------------------------------------
 */
 
#ifndef AL_OBSERVER_LIST_H
#define AL_OBSERVER_LIST_H

#include "al_observer.h"

/*
 *
 */
void al_obs_list_init( void );

/*
 *
 */
void al_obs_list_attach( const al_Observer* observer );

/*
 *
 */
void al_obs_list_detach( const al_Observer* observer );

/*
 *
 */
unsigned int al_obs_list_count( void );

/*
 *
 */
void al_obs_list_broadcast( const al_Data* data );

#endif /* AL_OBSERVER_LIST_H */
