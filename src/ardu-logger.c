/* ---------------------------------------------------------------------------
 * File: ardu-logger.c
 * Description: -
 *
 * Author: saknieme
 * ---------------------------------------------------------------------------
 */

#include <stdio.h>

#include "al_types.h"
#include "al_temp.h"
#include "al_observer.h"
#include "al_observer_list.h"

static void init_ardu_logger( void )
{
  /* Init observer linked list */
  al_obs_list_init();
  
  /* Init temperature catcher */
  al_temp_init();

}

static void clean_ardu_logger( void )
{
  al_temp_close();
}

int main( void )
{
  al_Data data;
  data.type = 1;
  
  /* Initialize system. */
  init_ardu_logger();

  al_obs_list_notify( &data );
  
  /* Clean system. */
  clean_ardu_logger();
  
  return 0;
}