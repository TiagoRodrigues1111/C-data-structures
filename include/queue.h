
/*******************************************************************************************************
* NAME: queue.h                                                              
*                                                                                                       
* PURPOSE: This file defines the function prototypes for a queue implementation                                                                      
*                                                                                                       
* GLOBAL VARIABLES: None                                                                                
*                                                                                                       
*                                                                                                       
* DEVELOPMENT HISTORY:                                                                                  
*                                                                                                       
* Date          Author          Change Id       Release         Description Of Change                   
* ----------    --------------- ---------       -------         -----------------------------------     
* 14-01-2025    Tiago Rodrigues                       1         File preparation     
* 14-01-2025    Tiago Rodrigues                       1         Added prototype functions                                                                                                       
* 23-01-2025    Tiago Rodrigues                       1         Further changed queue prototypes
* 27-01-2025    Tiago Rodrigues                       1         Added comments to functions
*                                                                                                      
*******************************************************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

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
typedef struct queue queue_t;

/*****************************************************/

/* 5 global variable declarations */
/*****************************************************/


/*****************************************************/


/* 6 function prototypes */
/*****************************************************/


/******************************************************************
*
* FUNCTION NAME: create_queue
*
* PURPOSE: Allocates the needed memory for the queue wanted
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------              ----            ---     ------------
* size_of_datatype      size_t        I       byte size of datatype to place in the stack
* elements_to_allocate  size_t        I       number of elements to allocate for the stack
*
* RETURNS: queue_t*
*
*
*
*****************************************************************/
queue_t* create_queue(size_t size_of_datatype, size_t elements_to_allocate);



/******************************************************************
*
* FUNCTION NAME: queue_front
*
* PURPOSE: Returns the memory position of the element that is currently on the front of the queue
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_queue   const queue_t*	I	pointer to the memory position of the queue to check
* data_at_front void*	        O	pointer to the memory position of the element at the front of the queue
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool queue_front(const queue_t* id_of_queue, void* data_at_front);



/******************************************************************
*
* FUNCTION NAME: check_queue_back    
*
* PURPOSE: Returns the memory position of the element that is currently on the back of the queue
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_queue   const queue_t*	I	pointer to the memory position of the queue to check
* data_at_back  void*	        O	pointer to the memory position of the element at the back of the queue
*
* RETURNS: bool
*
*****************************************************************/
bool queue_back(const queue_t* id_of_queue, void* data_at_back);


/******************************************************************
*
* FUNCTION NAME: queue_pop
*
* PURPOSE: Removes one position from the front of the queue
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_queue   queue_t*	I	pointer to the memory position of the queue to pop from
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool queue_pop(queue_t* id_of_queue);


/******************************************************************
*
* FUNCTION NAME: queue_push
*
* PURPOSE: Pushes an element to the back of the queue
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_queue   queue_t*	I	pointer to the memory position of the queue to which the element is being push to
* data_to_push  void*	        I	pointer to the memory position of the data to push into the queue
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool queue_push(queue_t* id_of_queue, void* data_to_push);


/******************************************************************
*
* FUNCTION NAME: queue_is_empty
*
* PURPOSE: Checks if the queue is empty or not
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_queue   const queue_t*	I	pointer to the memory position of the queue to check
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool queue_is_empty(const queue_t* id_of_queue);



/******************************************************************
*
* FUNCTION NAME: queue_size
*
* PURPOSE: Will return the current element count in the queue
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_queue   const queue_t*	I	pointer to the memory position of the queue to check
*
*
* RETURNS: size_t (size of the queue)
*
*
*
*****************************************************************/
size_t queue_size(const queue_t* id_of_queue);



/******************************************************************
*
* FUNCTION NAME: free_queue
*
* PURPOSE: Frees the memory allocated for the queue
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_queue   queue_t*	I	pointer to the memory position of the queue to free
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_queue(queue_t* id_of_queue);




#ifdef __cplusplus
}
#endif


#endif

























