
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

/*****************************************************/

/* 2 defines */
/*****************************************************/

/*****************************************************/

/* 3 external declarations */
/*****************************************************/

/*****************************************************/

/* 4 typedefs */
/*****************************************************/

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
* id_of_priority_queue	        void**	        I/O	pointer to the memory position of the priority queue to implement
* size_of_datatype              uint64_t        I       byte size of datatype to place in the priority queue
* elements_to_allocate          uint64_t        I       number of elements to allocate for the priority queue
* type_of_priority_queue        uint8_t         I       priority order of the priority queue
* compare_func                  function        I       function to compare two values in the priority queue
*
* RETURNS: void 
*
*
*
*****************************************************************/
void create_priority_queue(void** id_of_priority_queue, uint64_t size_of_datatype, uint64_t elements_to_allocate, uint8_t type_of_priority_queue, int8_t (*compare_func)(void* val1, void* val2));


/******************************************************************
*
* FUNCTION NAME: priority_queue_push        
*
* PURPOSE: Pushes an element to the priority queue 
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------              ----            ---     ------------
* id_of_priority_queue  void*	        I	pointer to the memory position of the priority queue to which the element is being push to
* data_to_push          void*	        I	pointer to the memory position of the data to push into the priority queue
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void priority_queue_push(void* id_of_priority_queue, void* data_to_push);


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
* id_of_priority_queue  void*	        I	pointer to the memory position of the queue to pop from
*
* RETURNS: void
*
*
*
*****************************************************************/
void priority_queue_pop(void* id_of_priority_queue);


/******************************************************************
*
* FUNCTION NAME: priority_queue_top      
*
* PURPOSE:Returns the memory position of the element that is currently on the top of the priority queue
*
* ARGUMENTS:
*
* ARGUMENT              TYPE	        I/O	DESCRIPTION
* --------              ----            ---     ------------
* id_of_priority_queue  void*	        I	pointer to the memory position of the priority queue to check
*
*
* RETURNS: 
*
*
*
*****************************************************************/
void* check_priority_queue_top(void* id_of_priority_queue);


/******************************************************************
*
* FUNCTION NAME: check_priority_queue_is_empty
*
* PURPOSE: Checks if the priority queue is empty or not
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------              ----            ---     ------------
* id_of_priority_queue  void*	        I	pointer to the memory position of the priority queue to check
*
*
* RETURNS: uint8_t
*
*
*
*****************************************************************/
uint8_t check_priority_queue_is_empty(void* id_of_priority_queue);


/******************************************************************
*
* FUNCTION NAME: check_priority_queue_size
*
* PURPOSE: Will return the current element count in the queue
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------              ----            ---     ------------
* id_of_priority_queue  void*	        I	pointer to the memory position of the priority queue to check
*
* RETURNS: uint64_t
*
*
*
*****************************************************************/
uint64_t check_priority_queue_size(void* id_of_priority_queue);


/******************************************************************
*
* FUNCTION NAME: free_priority_queue
*
* PURPOSE: Frees the memory allocated for the priority queue
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------              ----            ---     ------------
* id_of_priority_queue  void*	        I	pointer to the memory position of the priority queue to free
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_priority_queue(void* id_of_priority_queue);



// void change_priority();



#ifdef __cplusplus
}
#endif


#endif

























