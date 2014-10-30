/* ---------------------------------------------------------------------------
 * File: al_common.h
 * ---------------------------------------------------------------------------
 */

#ifndef AL_COMMON_H
#define AL_COMMON_H

#include <stdio.h>

#define AL_DEBUG_PRINTS

#ifdef AL_DEBUG_PRINTS
#define AL_DEBUG_PRINT( _text ) \
    printf( "%s\n", _text );
#define AL_DEBUG_PRINT_1( _text, _param_1 ) \
    printf( "%s%u\n", _text, _param_1 );
#else /* AL_DEBUG_PRINTS */
#define AL_DEBUG_PRINT
#define AL_DEBUG_PRINT_1
#endif /* AL_DEBUG_PRINTS */
                                                                             
#endif /* AL_COMMON_H */
