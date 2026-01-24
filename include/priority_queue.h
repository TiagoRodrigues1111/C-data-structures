
/*******************************************************************************************************
* NAME: priority_queue.h                                                              
*                                                                                                       
* PURPOSE: This file defines the function prototypes for a priority_queue implementation                                                                      
*                                                                                                       
* GLOBAL VARIABLES: None                                                                                
*                                                                                                       
*                                                                                                       
* DEVELOPMENT HISTORY:                                                                                  
*                                                                                                       
* Date          Author          Change Id       Release         Description Of Change                   
* ----------    --------------- ---------       -------         -----------------------------------     
* 06-02-2025    Tiago Rodrigues                       1         File preparation     
* 18-01-2026    Tiago Rodrigues                       2         Changed functions for opaqueness
*                                                                                                      
*******************************************************************************************************/
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

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
typedef struct priority_queue priority_queue_t;


/*****************************************************/

/* 5 global variable declarations */
/*****************************************************/


/*****************************************************/


/* 6 function prototypes */
/*****************************************************/


/******************************************************************
*
* FUNCTION NAME: create_priority_queue
*
* PURPOSE: Allocates the needed memory for the priority queue wanted      
*
* ARGUMENTS:
*
* ARGUMENT 	                TYPE	        I/O	DESCRIPTION
* --------                      ----            ---     ------------
* size_of_datatype              size_t          I       byte size of datatype to place in the priority queue
* elements_to_allocate          size_t          I       number of elements to allocate for the priority queue
* compare_func                  function        I       function to compare two values in the priority queue
*
* RETURNS: priority_queue_t* 
*
*
*
*****************************************************************/
priority_queue_t* create_priority_queue(size_t size_of_datatype, size_t elements_to_allocate, bool (*compare_func)(void* val1, void* val2));


/******************************************************************
*
* FUNCTION NAME: priority_queue_push        
*
* PURPOSE: Pushes an element to the priority queue 
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	                I/O	DESCRIPTION
* --------              ----                    ---     ------------
* id_of_priority_queue  priority_queue_t*	I	pointer to the memory position of the priority queue to which the element is being push to
* data_to_push          const void*	        I	pointer to the memory position of the data to push into the priority queue
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool priority_queue_push(priority_queue_t* id_of_priority_queue,const void* data_to_push);


/******************************************************************
*
* FUNCTION NAME: priority_queue_pop
*
* PURPOSE: Removes one position from the top of the priority queue
*
* ARGUMENTS:
*
* ARGUMENT              TYPE	        I/O	DESCRIPTION
* --------              ----            ---     ------------
* id_of_priority_queue  priority_queue_t*	I	pointer to the memory position of the queue to pop from
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool priority_queue_pop(priority_queue_t* id_of_priority_queue);


/******************************************************************
*
* FUNCTION NAME: priority_queue_top      
*
* PURPOSE:Returns the memory position of the element that is currently on the top of the priority queue
*
* ARGUMENTS:
*
* ARGUMENT              TYPE	                I/O	DESCRIPTION
* --------              ----                    ---     ------------
* id_of_priority_queue  const priority_queue_t*	I	pointer to the memory position of the priority queue to check
* data_at_top           void*	                O	pointer to the memory position of the data at the top of the priority queue
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool priority_queue_top(const priority_queue_t* id_of_priority_queue, void* data_at_top);


/******************************************************************
*
* FUNCTION NAME: priority_queue_is_empty
*
* PURPOSE: Checks if the priority queue is empty or not
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	                I/O	DESCRIPTION
* --------              ----                    ---     ------------
* id_of_priority_queue  const priority_queue_t*	I	pointer to the memory position of the priority queue to check
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool priority_queue_is_empty(const priority_queue_t* id_of_priority_queue);


/******************************************************************
*
* FUNCTION NAME: priority_queue_size
*
* PURPOSE: Will return the current element count in the queue
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	                I/O	DESCRIPTION
* --------              ----                    ---     ------------
* id_of_priority_queue  const priority_queue_t*	I	pointer to the memory position of the priority queue to check
*
* RETURNS: size_t
*
*
*
*****************************************************************/
size_t priority_queue_size(const priority_queue_t* id_of_priority_queue);


/******************************************************************
*
* FUNCTION NAME: free_priority_queue
*
* PURPOSE: Frees the memory allocated for the priority queue
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	                I/O	DESCRIPTION
* --------              ----                    ---     ------------
* id_of_priority_queue  priority_queue_t*	I	pointer to the memory position of the priority queue to free
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_priority_queue(priority_queue_t* id_of_priority_queue);



// void change_priority();



#ifdef __cplusplus
}
#endif


#endif

























