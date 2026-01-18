
/*******************************************************************************************************
* NAME: stack.h
*
* PURPOSE: This file defines the function prototypes for our stack implementation
*
* GLOBAL VARIABLES: None
*
*
*
* DEVELOPMENT HISTORY:
*
* Date          Author          Change Id       Release         Description Of Change
* ----------    --------------- ---------       -------         -----------------------------------
* 14-01-2025    Tiago Rodrigues                       1         File preparation
* 14-01-2025    Tiago Rodrigues                       1         Added prototype functions
* 21-01-2025    Tiago Rodrigues                       1         Commmented function preambles
* 23-01-2025    Tiago Rodrigues                       1         Changed create stack to allow for number of
* ----------    --------------- ---------       -------          elements to be sent for allocation
* 17-01-2026    Tiago Rodrigues                       1         Miniscule changes to spaces and tabs
* 17-01-2026    Tiago Rodrigues                       2         Changed return type of check_stack_is_empty from
* ----------    --------------- ---------       -------          uint8_t to bool
* ----------    --------------- ---------       -------         Changed all uint64_t to size_t for sizes
* 18-01-2026    Tiago Rodrigues                       2         Changed functions for opaqueness 
* 
*
*******************************************************************************************************/
#ifndef STACK_H
#define STACK_H

/* 0 copyright/licensing */
/*******************************************************************************************************
*
* 2025 Tiago Filipe Rodrigues tiagorodrigues1590@hotmail.com
*
********************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif


/* 1 includes */
/*****************************************************/
#include <stdint.h>
/*#include <stddef.h>*/
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
typedef struct stack stack_t;

/*****************************************************/

/* 5 global variable declarations */
/*****************************************************/

/*****************************************************/


/* 6 function prototypes */
/*****************************************************/


/******************************************************************
*
* FUNCTION NAME: create_stack
*
* PURPOSE: Allocates the needed memory for the stack wanted
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------              ----            ---     ------------
* size_of_datatype      size_t        I       byte size of datatype to place in the stack
* elements_to_allocate  size_t        I       number of elements to allocate for the stack
*
* RETURNS: stack_t*
*
*
*
*****************************************************************/
stack_t* create_stack(size_t size_of_datatype, size_t elements_to_allocate);



/******************************************************************
*
* FUNCTION NAME: stack_top
*
* PURPOSE: Returns the memory position of the element that is currently on the top of the stack
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_stack   const stack_t*	I	pointer to the memory position of the stack to check
* data_at_top   void*	        O	pointer to the memory position where to copy the data at the top of the stack
* 
*
* RETURNS: bool ( true if successful, false otherwise) 
*
*
*
*****************************************************************/
bool stack_top(const stack_t* id_of_stack, void* data_at_top);


/******************************************************************
*
* FUNCTION NAME: stack_pop       
*
* PURPOSE: Removes one position from the top of the stack
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* id_of_stack   stack_t*	I	pointer to the memory position of the stack to pop from
*
*
* RETURNS: bool 
*
*
*
*****************************************************************/
bool stack_pop(stack_t* id_of_stack);


/******************************************************************
*
* FUNCTION NAME: stack_push        
*
* PURPOSE: Pushes an element to the top of the stack
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* id_of_stack   stack_t*	I	pointer to the memory position of the stack to push to
* data_to_push  void*	        I	pointer to the memory position of the data to push into the stack
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool stack_push(stack_t* id_of_stack, void* data_to_push);


/******************************************************************
*
* FUNCTION NAME: stack_is_empty
*
* PURPOSE: Checks if the stack is empty or not
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* id_of_stack   const stack_t*	I	pointer to the memory position of the stack to check
*
*
* RETURNS: bool ( true or false)
*
*
*
*****************************************************************/
bool stack_is_empty(const stack_t* id_of_stack);


/******************************************************************
*
* FUNCTION NAME: stack_size
*
* PURPOSE: Will return the current element count in the stack
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* id_of_stack   const stack_t*	I	pointer to the memory position of the stack to check
*
*
* RETURNS: size_t (size of the stack)
*
*
*
*****************************************************************/
size_t stack_size(const stack_t* id_of_stack);


/******************************************************************
*
* FUNCTION NAME: free_stack
*
* PURPOSE: Frees the memory allocated for the stack
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* id_of_stack   stack_t*	I	pointer to the memory position of the stack to free
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_stack(stack_t* id_of_stack);



#ifdef __cplusplus
}
#endif


#endif

