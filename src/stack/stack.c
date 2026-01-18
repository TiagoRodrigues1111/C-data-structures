/*******************************************************************************************************************
* FILE NAME: stack.c
*
* PURPOSE: This file implements the functions defined in stack.h
*
* FILE REFERENCES:
*
* Name                          I/O                     Description
* ----                          ---                     -----------
* none

* EXTERNAL VARIABLES:
*
*
* Name          Type            I/O                     Description
* ----          ----            ---                     -----------
* none
*
*
* EXTERNAL REFERENCES:
* Name                          Description
* ----                          -----------
* malloc                        allocates memory space                                                          https://man7.org/linux/man-pages/man3/free.3.html
* realloc                       reallocates memory space                                                        https://man7.org/linux/man-pages/man3/realloc.3p.html
* memcpy                        copies x number of bytes from one memory position to another memory position    https://man7.org/linux/man-pages/man3/memcpy.3.html
* fprintf                       writes formatted data to a stream                                               https://man7.org/linux/man-pages/man3/fprintf.3p.html
*
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:
*
*
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:
*  It is assumed that the stack will never have more than 2^64 elements.
*  It is assumed that the user will grab only 1 element size from the memory position returned from check_stack_top
*
*
* NOTES:
*
*
* REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:
*
*
* DEVELOPMENT HISTORY:
*
* Date          Author                  Change Id       Release         Description Of Change
* ----------    ---------------         ---------       -------         ---------------------
* 14-01-2025    Tiago Rodrigues                               0         File preparation
* 17-01-2025    Tiago Rodrigues                               0         Initial Implementation of stack, for uint8_t
* 20-01-2025    Tiago Rodrigues                               0         Changed operations to use memcpy
* 21-01-2025    Tiago Rodrigues                               0         Changed some operations for edge cases,
* ----------    ---------------         ---------       -------          and commmented function preambles
* 23-01-2025    Tiago Rodrigues                               0         Updated create_stack function, and added
* ----------    ---------------         ---------       -------          a few good C practices
* 31-01-2025    Tiago Rodrigues                           1.0.1         Added better error handling
* 17-01-2026    Tiago Rodrigues                               2         Changed return type of check_stack_is_empty from
* ----------    ---------------         ---------       -------          uint8_t to bool
* ----------    ---------------         ---------       -------         Changed all uint64_t to size_t for sizes
* 18-01-2026    Tiago Rodrigues                               2         Changed functions for opaqueness 
*
*
* ALGORITHM (PDL)
*
*
*
****************************************************************************************************************/


/* 0 copyright/licensing */
/***************************************************************************************************************/
/*
*       2025 Tiago Filipe Rodrigues tiagorodrigues1590@hotmail.com
*/
/***************************************************************************************************************/


/* 1 includes */
/*****************************************************/

/* 1.1 Related header */
#include "stack.h"

/* 1.2 C system headers */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*#include <errno.h>*/

/* 1.3 C++ standard library headers*/

/* 1.4 other libraries' headers*/

/* 1.5 project's headers */
#include "types.h"





/*****************************************************/


/* 2 defines */
/*****************************************************/
#define INITIAL_ALLOC 3

/*****************************************************/


/* 3 external declarations */
/*****************************************************/

/*****************************************************/


/* 4 typedefs */
/*****************************************************/

/*typedef uint8_t stack_datatype;*/





/*****************************************************/


/* 5 global variable declarations */
/*****************************************************/
//void *stack = NULL;
//uint64_t stack_size = 0;

// uint64_t stack_size_allocated = 0;                      // num_of_bytes
// uint64_t datatype_size = 0;                             // num_of_bytes

struct stack
{
        size_t stack_size;
        size_t stack_size_allocated;                  // num_of_elements
        size_t datatype_size;                         // num_of_bytes
        size_t k_aux;                                 // auxiliary 4 bytes for reallocation      
        void *stack_data;
};


/*****************************************************/


/* 6 function prototypes */
/*****************************************************/



/*****************************************************/



/* 7 function declarations */
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
stack_t* create_stack(size_t size_of_datatype, size_t elements_to_allocate)           
{
        /* LOCAL VARIABLES:
        *  Variable      Type           Description
        *  --------      ----           -----------
        *  id_of_stack   stack_t*       pointer to the memory position of the stack created
        */

        stack_t* id_of_stack = NULL;                

        /* Allocation of a stack struct */
        id_of_stack = malloc(1*sizeof(struct stack));                       
        if(NULL == id_of_stack)
        {
                perror("Memory allocation failed");
                return NULL;
        }

        if(0 == elements_to_allocate)
                id_of_stack->stack_size_allocated = INITIAL_ALLOC;      /* assumed that the number of elements to allocate initially is INITIAL_ALLOC (3 by default) */
        else
                id_of_stack->stack_size_allocated = elements_to_allocate;


        id_of_stack->stack_size = 0;
        id_of_stack->datatype_size = size_of_datatype;
        id_of_stack->k_aux = 1;

        // Allocate space in the stack for the array of values
        id_of_stack->stack_data = (void*) malloc(id_of_stack->stack_size_allocated*id_of_stack->datatype_size);     
        if(NULL == id_of_stack->stack_data)
        {
                perror("Memory allocation failed");
                return NULL;
        }

        return id_of_stack;        
}



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
* RETURNS: void 
*
*
*
*****************************************************************/
bool stack_top(const stack_t* id_of_stack, void* data_at_top)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_stack)
        {
                fprintf(stderr, "Stack pointer location is null\n");
                return false;
        }
               

        if(stack_is_empty(id_of_stack))                       
                return false;
        
        memcpy(data_at_top, (void *)&((uint8_t*)(id_of_stack->stack_data))[(id_of_stack->stack_size-1)*id_of_stack->datatype_size], ((struct stack*)id_of_stack)->datatype_size);

        return true;
}



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
bool stack_pop(stack_t* id_of_stack)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_stack)
        {
                fprintf(stderr, "Stack pointer location is null\n");
                return false;
        }   
        if(false == stack_is_empty(id_of_stack))
                id_of_stack->stack_size--;


        return true;
}




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
* id_of_stack   const stack_t*	I	pointer to the memory position of the stack to push to
* data_to_push  void*	        I	pointer to the memory position of the data to push into the stack
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool stack_push(stack_t* id_of_stack, void* data_to_push)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  stack_aux    void*           auxiliary pointer for the realloc operation
        *  
        */
        if(NULL == id_of_stack)
        {
                fprintf(stderr, "Stack pointer location is null\n");
                return false;
        }
        if(UINT64_MAX == stack_size(id_of_stack))
        {
                fprintf(stderr, "Stack full, can't add more elements\n");
                return false;
        }
        if(NULL == data_to_push)
        {
                fprintf(stderr, "Data pointer is null\n");
                return false;
        }



        id_of_stack->stack_size++;
        // reallocate memory if num of elements in stack becomes larger than the max num of elements allocated for the stack 
        if(id_of_stack->stack_size > id_of_stack->stack_size_allocated)
        {
                void* stack_aux = NULL;
                // tries to allocate double the size of the current stack;
                if(1 == id_of_stack->k_aux)
                {
                        stack_aux = realloc(id_of_stack->stack_data, (id_of_stack->stack_size_allocated + id_of_stack->stack_size_allocated)*id_of_stack->datatype_size);                 
                        if(NULL != stack_aux)                   // this is not needed, and could be placed after the while, however the shift left is a bit faster than the addition
                        {
                                id_of_stack->stack_size_allocated <<= 1;                        
                        }
                }
                else
                {
                        while (NULL == stack_aux)
                        {
                                perror("Memory reallocation failed");
                                // printf("Attempting smaller reallocation\n");
                                (id_of_stack->k_aux)<<=1;                              // always times 2 (TODO: might be faster to shift at the end again, and add 1 (check the lim->))
                                 
                                if(0 == (id_of_stack->stack_size_allocated/(id_of_stack->k_aux)))
                                {
                                        fprintf(stderr, "Impossible to reallocate stack\n");
                                        //perror("Impossible to reallocate stack");
                                        return false;
                                }
                                stack_aux = realloc(id_of_stack->stack_data, (id_of_stack->stack_size_allocated + (id_of_stack->stack_size_allocated / (id_of_stack->k_aux)))*id_of_stack->datatype_size);
                        }

                        id_of_stack->stack_size_allocated += (id_of_stack->stack_size_allocated/(id_of_stack->k_aux));          

                }
                
                id_of_stack->stack_data = stack_aux;
        }

        //return (void *) &((uint8_t*)(((struct stack*)id_of_stack)->stack_data))[(((struct stack*)id_of_stack)->stack_size-1)*((struct stack*)id_of_stack)->datatype_size];        
                
        

        memcpy((void *) &((uint8_t*)(id_of_stack->stack_data))[(id_of_stack->stack_size-1)*id_of_stack->datatype_size], data_to_push, id_of_stack->datatype_size);

        return true;
}





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
bool stack_is_empty(const stack_t* id_of_stack)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_stack)
        {
                fprintf(stderr, "Stack pointer location is null\n");
                return false;
        }
                
        if(0 == id_of_stack->stack_size)
                return true;
        else
                return false;
}


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
size_t stack_size(const stack_t* id_of_stack)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_stack)
        {
                fprintf(stderr, "Stack pointer location is null\n");
                return 0;
        }

        return id_of_stack->stack_size;
}


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
void free_stack(stack_t* id_of_stack)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_stack)
                return;

        if(NULL != (id_of_stack->stack_data))
                free(id_of_stack->stack_data);
        
        free(id_of_stack);
        return ;
}