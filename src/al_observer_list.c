/* ---------------------------------------------------------------------------
 * File: al_observer_list.c
 * Description: -
 *
 * Author: saknieme
 * ---------------------------------------------------------------------------
 */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "al_common.h"
#include "al_observer.h"
#include "al_observer_list.h"

/* ---------------- STRUCTURE DEFINITIONS ---------------------------------- */

/*
 * Structure for observer linked list node.
 */
struct al_ObserverListNode
{
    const al_Observer*          observer;
    struct al_ObserverListNode* next;
    struct al_observerListNode* prev;
};

/*
 * Structure for observer linked list.
 */
struct al_ObserverList
{
    struct al_ObserverListNode* head;
    struct al_ObserverListNode* tail;
    unsigned int                node_count;
};

/* ---------------- LOCAL VARIABLES ---------------------------------------- */

/* Observer linked list.  */
static struct al_ObserverList observer_llist;

/* ---------------- LOCAL FUNCTIONS ---------------------------------------- */

/*
 * Function for initializing the linked list.
 */
static void init_list( void )
{
    observer_llist.head = NULL;
    observer_llist.tail = NULL;
    observer_llist.node_count = 0;
} 

/*
 * Function for adding an observer into the linked list.
 */
static void append_to_list( const al_Observer* observer )
{
    struct al_ObserverListNode* node = NULL;

    /* Code */

    assert( NULL != observer );    

    node = ( struct al_ObserverListNode* )
        malloc( sizeof( struct al_ObserverListNode ) );
    node->observer = observer;
    node->next = NULL;
    node->prev = NULL;
    
    if ( NULL == observer_llist.head )
    {
        assert( NULL == observer_llist.tail );    

        observer_llist.head = node;
        observer_llist.tail = node;
    }
    else
    {    
        observer_llist.tail->next = node;
        observer_llist.tail = node;
    }
    
    observer_llist.node_count++;
    
    AL_DEBUG_PRINT_1( "AL-OBS-LIST: New observer added. Observer count: ",
        observer_llist.node_count );
}

/*
 * Function for removing an observer from the linked list.
 */
static void remove_from_list( const al_Observer* observer )
{
    struct al_ObserverListNode* node = NULL;
    struct al_ObserverListNode* prev = NULL;

    /* Code */

    assert( NULL != observer );    

    node = observer_llist.head;
    while( NULL != node && observer != node->observer )
    {
        prev = node;
        node = node->next;
    }

    assert( NULL != node );

    if ( node != observer_llist.head && node != observer_llist.tail )
    {
        prev->next = node->next;
    }

    if ( node == observer_llist.head )
    {
        observer_llist.head = node->next;
    }
    
    if ( node == observer_llist.tail )
    {
        observer_llist.tail = prev;
    }
    
    free( node );
    node = NULL;

    observer_llist.node_count--;
    
    AL_DEBUG_PRINT_1( "AL-OBS-LIST: Observer removed. Observer count: ",
        observer_llist.node_count );
}

/*
 * Function for getting the count of observers in linked list.
 */
static unsigned int nodes_in_list( void )
{
    return observer_llist.node_count;
}

/*
 * Function for broadcasting new data to the observers.
 */
static void notify_observers_in_list( const al_Data* data )
{
    const al_Observer* observer = NULL;
    struct al_ObserverListNode* node = NULL;

    /* Code */
    

    assert( NULL != data );    

    AL_DEBUG_PRINT( "AL-OBS-LIST: Broadcasting started." );
    
    node = observer_llist.head;
    while ( NULL != node )
    {
        observer = node->observer;
        observer->notification( observer->instance, data );
        node = node->next;
    }
    
    AL_DEBUG_PRINT( "AL-OBS-LIST: Broadcasting ended." );
}

/* --------------- INTERFACE FUNCTIONS ------------------------------------- */

/*
 * See al_observer_list.h for details.
 */
void al_obs_list_init( void )
{
    /* Code */

    init_list();
}

/*
 * See al_observer_list.h for details.
 */
void al_obs_list_attach( const al_Observer* observer )
{
    /* Code */

    append_to_list( observer );
}

/*
 * See al_observer_list.h for details.
 */
void al_obs_list_detach( const al_Observer* observer )
{
    /* Code */

    remove_from_list( observer );
}

/*
 * See al_observer_list.h for details.
 */
unsigned int al_obs_list_count( void )
{
    /* Code */

    return nodes_in_list();
}

/*
 * See al_observer_list.h for details.
 */
void al_obs_list_notify( const al_Data* data )
{
    /* Code */
    
    notify_observers_in_list( data );
}

/* End of file */
