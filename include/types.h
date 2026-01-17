

/*******************************************************************************************************
* NAME: types.h
*
* PURPOSE: This file defines helpful types for the data structures in the library  
*
* GLOBAL VARIABLES: None
*
*
* DEVELOPMENT HISTORY:
*
* Date          Author          Change Id       Release         Description Of Change
* ----------    --------------- ---------       -------         -----------------------------------
* 17-01-2026    Tiago Rodrigues                       1         File preparation
*
*
* 
*
* 
******************************************************************************************************/
#ifndef TYPES_H
#define TYPES_H

/* 0 copyright/licensing */
/*******************************************************************************************************
*
* 2025 Tiago Filipe Rodrigues tiagorodrigues1590@hotmail.com
*
********************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif


/* Boolean */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #include <stdbool.h>
#else
        typedef enum {false = 0, true = 1 } bool;
#endif







#ifdef __cplusplus
}
#endif


#endif

