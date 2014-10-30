/* ---------------------------------------------------------------------------
 * File: al_observer_list.h
 * Description: -
 *
 * Author: saknieme
 * ---------------------------------------------------------------------------
 */
 
#ifndef AL_OBSERVER_LIST_H
#define AL_OBSERVER_LIST_H

/* --------------- FUNCTION PROTOTYPES ------------------------------------- */

/*
 * Initialize.
 */
void al_obs_list_init( void );

/*
 * Attach observer to the list.
 */
void al_obs_list_attach( const al_Observer* observer );

/*
 * Detach observer from the the list.
 */
void al_obs_list_detach( const al_Observer* observer );

/*
 * Returns count of observers in the list.
 */
unsigned int al_obs_list_count( void );

/*
 * Notifies observers in the list.
 */
void al_obs_list_notify( const al_Data* data );

#endif /* AL_OBSERVER_LIST_H */
