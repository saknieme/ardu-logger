/* ---------------------------------------------------------------------------
 * File: al_common.h
 * Description: -
 *
 * Author: saknieme
 * ---------------------------------------------------------------------------
 */

#ifndef AL_COMMON_H
#define AL_COMMON_H

#include <stdio.h>

#define AL_DEBUG_PRINTS /* Comment this to remove debug prints. */

#ifdef AL_DEBUG_PRINTS
#define AL_DEBUG_PRINT( _text ) \
    printf( "%s\n", _text );
#define AL_DEBUG_PRINT_1( _text, _param_1 ) \
    printf( "%s%u\n", _text, _param_1 );
#define AL_DEBUG_PRINT_S( _text, _text_1 ) \
    printf( "%s%s\n", _text, _text_1 );
#else /* AL_DEBUG_PRINTS */
#define AL_DEBUG_PRINT
#define AL_DEBUG_PRINT_1
#define AL_DEBUG_PRINT_S
#endif /* AL_DEBUG_PRINTS */
                                            
#endif /* AL_COMMON_H */
