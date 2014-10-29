/* ---------------------------------------------------------------------------
 * File: al_data_container.c
 * ---------------------------------------------------------------------------
 */

#include <stdlib.h>
#include <assert.h>

#include "al_data_observer.h"

/*
 *
 */
struct al_container_node
{
    const al_data_observer* observer;
    struct al_container_node* next;
};

static struct al_container_node* observers = NULL;

/*
 *
 */
static void append_to_list( const al_data_observer* observer )
{
    struct al_container_node* node = NULL;
    struct al_container_node* temp = observers;

    /* Create a new node to be added into the linked-list. */
    node = ( struct al_container_node* )
        malloc( sizeof( struct al_container_node ) );
    node->observer = observer;
    node->next = NULL;

    /* Add a new node into the linked list. */    
    if( NULL == observers )
    {
        observers = node;
    }
    else
    {
        while ( NULL != temp->next )
        {
            temp = temp->next;
        }
        temp->next = node;
    }   
}

/*
 *
 */
static void remove_from_list( const al_data_observer* observer )
{
    struct al_container_node* node = NULL;
    struct al_container_node* temp = observers;

    while( observer != temp->observer )
    {
        temp = temp->next;        
    }
    
    temp = temp->next;
}

/*
 *
 */
static void handle( const al_data* data )
{
    const al_data_observer* observer = NULL;
    struct al_container_node* node = observers->next;

    /* Walkthrough the linked-list and notify each observer about new data. */
    while ( NULL != node )
    {
        observer = node->observer;
        observer->notification( observer->instance, data );
        node = node->next;
    }
}

/*
 *
 */
void init( void )
{
    /* TODO */
}

/*
 *
 */
void attach( const al_data_observer* observer )
{
    assert( NULL != observer );
    
    append_to_list( observer );
}

/*
 *
 */
void detach( const al_data_observer* observer )
{
    assert( NULL != observer );
    
    remove_from_list( observer );
}
