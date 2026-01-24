/*******************************************************************************************************
* NAME: set.h                                                              
*                                                                                                       
* PURPOSE: This file defines the function prototypes for a set implementation                                                                      
*                                                                                                       
* GLOBAL VARIABLES: None                                                                                
*                                                                                                       
*                                                                                                       
* DEVELOPMENT HISTORY:                                                                                  
*                                                                                                       
* Date          Author          Change Id       Release         Description Of Change                   
* ----------    --------------- ---------       -------         -----------------------------------     
* 03-06-2025    Tiago Rodrigues                       1         File preparation     
* 18-01-2026    Tiago Rodrigues                       2         Changed functions for opaqueness        
*
*                                                                                                      
*******************************************************************************************************/

#ifndef SET_H
#define SET_H


/* 0 copyright/licensing */
/**********************************************************************
*
* 2025 Tiago Filipe Rodrigues tiagorodrigues1590@hotmail.com
*
***********************************************************************/

#ifdef __cplusplus
extern "C" {
#endif



/* 1 includes */
/*****************************************************/
#include <stdint.h>
#include <stddef.h>
#include "types.h"

/*****************************************************/

/* 2 defines */
/*****************************************************/

/*****************************************************/

/* 3 external declarations */
/*****************************************************/

/*****************************************************/

/* 4 typedefs */
/*****************************************************/
typedef struct set set_t;

/*****************************************************/

/* 5 global variable declarations */
/*****************************************************/


/*****************************************************/


/* 6 function prototypes */
/*****************************************************/


/******************************************************************
*
* FUNCTION NAME: create_set
*
* PURPOSE: Allocates the needed memory for the set wanted
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------              ----            ---     ------------
* size_of_datatype      size_t          I       byte size of datatype to place in the set
* elements_to_allocate  size_t          I       number of elements to allocate for the set
* compare_func          function        I       function to compare presence of element in the set
* hash_function         function        I       hash function to be used to determine indexes
*
* RETURNS: set_t*
*
*
*
*****************************************************************/
set_t* create_set(size_t size_of_datatype, size_t elements_to_allocate, bool (*compare_func)(const void* val1, const void* val2),size_t (*hash_function)(const void* val));

/******************************************************************
*
* FUNCTION NAME: set_insert        
*
* PURPOSE: Inserts an element into the set
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------	        -------------	---	--------------------------
* id_of_set             set_t*	        I	pointer to the set to insert into
* data_to_insert        const void*	I	pointer to the memory position of the data to insert into the set
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool set_insert(set_t* id_of_set, const void* data_to_insert);

/******************************************************************
*
* FUNCTION NAME: set_erase        
*
* PURPOSE: Erases an element from the set
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------	        -------------	---	--------------------------
* id_of_set             set_t*	        I	pointer to the set to erase from
* element_to_erase      const void*	I	pointer to the memory position of the element to erase from the set
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool set_erase(set_t* id_of_set, const void* element_to_erase);

/******************************************************************
*
* FUNCTION NAME: set_contains        
*
* PURPOSE: Checks if a set contains an element
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------	        -------------	---	--------------------------
* id_of_set             set_t*	        I	pointer to the set
* element_to_check      const void*	I	pointer to the memory position of the element to check if exists
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool set_contains(set_t* id_of_set, const void* element_to_check);

/******************************************************************
*
* FUNCTION NAME: set_is_empty
*
* PURPOSE: Checks if the set is empty or not
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      -------------	---	--------------------------
* id_of_set     set_t*	        I	pointer to the set to check
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool set_is_empty(set_t* id_of_set);

/******************************************************************
*
* FUNCTION NAME: set_size
*
* PURPOSE: Will return the current element count in the set
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* id_of_set     set_t*	        I	pointer to the set to check
*
*
* RETURNS: size_t (size of the set)
*
*
*
*****************************************************************/
size_t set_size(set_t* id_of_set);


/******************************************************************
*
* FUNCTION NAME: free_set
*
* PURPOSE: Frees the memory allocated for the set
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_set     set_t*	        I	pointer to the set to free
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_set(set_t* id_of_set);





#ifdef __cplusplus
}
#endif


#endif












