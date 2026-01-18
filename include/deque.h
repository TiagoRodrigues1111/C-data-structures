
/*******************************************************************************************************
* NAME: deque.h                                                              
*                                                                                                       
* PURPOSE: This file defines the function prototypes for a deque implementation                                                                      
*                                                                                                       
* GLOBAL VARIABLES: None                                                                                
*                                                                                                       
*                                                                                                       
* DEVELOPMENT HISTORY:                                                                                  
*                                                                                                       
* Date          Author          Change Id       Release         Description Of Change                   
* ----------    --------------- ---------       -------         -----------------------------------     
* 03-02-2025    Tiago Rodrigues                       1         File preparation and prototype functions
* 18-01-2026    Tiago Rodrigues                       2         Changed functions for opaqueness       
*                                                                                                      
*******************************************************************************************************/
#ifndef DEQUE_H
#define DEQUE_H

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
typedef struct deque deque_t;

/*****************************************************/

/* 5 global variable declarations */
/*****************************************************/


/*****************************************************/


/* 6 function prototypes */
/*****************************************************/


/******************************************************************
*
* FUNCTION NAME: create_deque
*
* PURPOSE: Allocates the needed memory for the deque wanted
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------              ----            ---     ------------
* size_of_datatype      size_t        I       byte size of datatype to place in the deque
* elements_to_allocate  size_t        I       number of elements to allocate for the deque
*
* RETURNS: deque_t*
*
*
*****************************************************************/
deque_t* create_deque(size_t size_of_datatype, size_t elements_to_allocate);


/******************************************************************
*
* FUNCTION NAME: deque_front
*
* PURPOSE: Returns the memory position of the element that is currently on the front of the deque
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_deque   const deque_t*	I	pointer to the memory position of the deque to check
* data_at_front void*	        O	pointer to the memory position of the element at the front of the deque
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool deque_front(const deque_t* id_of_deque, void* data_at_front);




/******************************************************************
*
* FUNCTION NAME: deque_back    
*
* PURPOSE: Returns the memory position of the element that is currently on the back of the deque
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_deque   const deque_t*	I	pointer to the memory position of the deque to check
* data_at_back  void*	        O	pointer to the memory position of the element at the back of the deque
*
* RETURNS: bool
*
*
*****************************************************************/
bool deque_back(const deque_t* id_of_deque, void* data_at_back);


/******************************************************************
*
* FUNCTION NAME: deque_pop_front
*
* PURPOSE: Removes one position from the front of the deque
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_deque   deque_t*	I	pointer to the memory position of the deque to pop from
*
*
* RETURNS: bool
*
*
*****************************************************************/
bool deque_pop_front(deque_t* id_of_deque);

/******************************************************************
*
* FUNCTION NAME: deque_pop_back
*
* PURPOSE: Removes one position from the back of the deque
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_deque   deque_t*	I	pointer to the memory position of the deque to pop from
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool deque_pop_back(deque_t* id_of_deque);



/******************************************************************
*
* FUNCTION NAME: deque_push_front
*
* PURPOSE: Pushes an element to the front of the deque
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_deque   deque_t*	I	pointer to the memory position of the deque to which the element is being push to
* data_to_push  const void*	I	pointer to the memory position of the data to push into the deque
*
*
* RETURNS: bool
*
*
*****************************************************************/
bool deque_push_front(deque_t* id_of_deque, const void* data_to_push);


/******************************************************************
*
* FUNCTION NAME: deque_push_back
*
* PURPOSE: Pushes an element to the back of the deque
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_deque   deque_t*	I	pointer to the memory position of the deque to which the element is being push to
* data_to_push  const void*	I	pointer to the memory position of the data to push into the deque
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool deque_push_back(deque_t* id_of_deque, const void* data_to_push);


/******************************************************************
*
* FUNCTION NAME: deque_is_empty
*
* PURPOSE: Checks if the deque is empty or not
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_deque   const deque_t*	I	pointer to the memory position of the deque to check
*
*
* RETURNS: bool
*
*
*****************************************************************/
bool deque_is_empty(const deque_t* id_of_deque);



/******************************************************************
*
* FUNCTION NAME: deque_size
*
* PURPOSE: Will return the current element count in the deque
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_deque   const deque_t*	I	pointer to the memory position of the deque to check
*
*
* RETURNS: size_t (size of the deque)
*
*
*
*****************************************************************/
size_t deque_size(const deque_t* id_of_deque);


/******************************************************************
*
* FUNCTION NAME: free_deque
*
* PURPOSE: Frees the memory allocated for the deque
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_deque   deque_t*	I	pointer to the memory position of the deque to free
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_deque(deque_t* id_of_deque);





#ifdef __cplusplus
}
#endif


#endif

























