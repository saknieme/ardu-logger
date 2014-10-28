/* ---------------------------------------------------------------------------
 * File: al_observer_list.c
 * ---------------------------------------------------------------------------
 */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "al_observer_list.h"

/* STRUCTURE DEFINITIONS */

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

/* Observer linked list.  */
static struct al_ObserverList observer_llist;

/* LOCAL FUNCTIONS */

/*
 * Local function for adding given observer into the linked list.
 */
static void append_to_list( const al_Observer* observer )
{
    struct al_ObserverListNode* node = NULL;

    /* Code */

    node = ( struct al_ObserverListNode* )
        malloc( sizeof( struct al_ObserverListNode ) );
    node->observer = observer;
    node->next = NULL;
    node->prev = NULL;
    
    if ( NULL == observer_llist.head )
    {
        observer_llist.head = node;
        observer_llist.tail = node;
    }
    else
    {    
        observer_llist.tail->next = node;
        observer_llist.tail = node;
    }
    
    observer_llist.node_count++;
    
    printf( "AL-OBS-LIST: New observer added. Count: %u\n",
        observer_llist.node_count );
}

/*
 * Local function for removing given observer from the linked list.
 */
static void remove_from_list( const al_Observer* observer )
{
    struct al_ObserverListNode* node = NULL;
    struct al_ObserverListNode* prev = NULL;

    /* Code */

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
    
    
    observer_llist.node_count--;
    
    printf( "AL-OBS-LIST: Observer removed. Count: %u\n",
        observer_llist.node_count );
}

/*
 *
 */
static unsigned int nodes_in_list( void )
{
    return observer_llist.node_count;
}

/*
 *
 */
void al_obs_list_init( void )
{
    observer_llist.head = NULL;
    observer_llist.tail = NULL;
    observer_llist.node_count = 0;
}

/*
 *
 */
void al_obs_list_attach( const al_Observer* observer )
{
    assert( NULL != observer );
    
    append_to_list( observer );
}

/*
 *
 */
void al_obs_list_detach( const al_Observer* observer )
{
    assert( NULL != observer );
    
    remove_from_list( observer );
}

/*
 *
 */
unsigned int al_obs_list_count( void )
{
    return nodes_in_list();
}

/*
 *
 */
void al_obs_list_broadcast( const al_Data* data )
{
    const al_Observer* observer = NULL;
    struct al_ObserverListNode* node = NULL;

    /* Code */
    
    printf( "AL-OBS-LIST: Broadcasting started\n" );
    
    node = observer_llist.head;
    while ( NULL != node )
    {
        observer = node->observer;
        observer->notification( observer->instance, data );
        node = node->next;
    }
    
    printf( "AL-OBS-LIST: Broadcasting ended\n" );
}

/* End of file */
