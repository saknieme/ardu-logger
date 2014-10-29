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
void attach( const al_Observer* observer );

/*
 *
 */
void detach( const al_Observer* observer );

#endif /* AL_OBSERVER_LIST_H */
