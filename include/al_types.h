/* ---------------------------------------------------------------------------
 * File: al_types.h
 * Description: -
 *
 * Author: saknieme
 * ---------------------------------------------------------------------------
 */

#ifndef AL_TYPES_H
#define AL_TYPES_H

/* --------------- CONSTANT DEFINITIONS ------------------------------------ */

#define AL_ETYPE_TEMP_1     10
#define AL_ETYPE_TEMP_2     20
#define AL_ETYPE_UNKNOWN    255

/* --------------- STRUCTURE DEFINITIONS ----------------------------------- */

/*
 * Structure for a generic data.
 */
typedef struct
{
    unsigned int    type;
    void*           data;
} al_Data;

#endif /* AL_TYPES_H */
