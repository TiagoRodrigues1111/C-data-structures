/*******************************************************************************************************************
* FILE NAME: stack_ll.c
*                                                                                                               
* PURPOSE: This file implements the functions defined in stack.h, with linked lists    
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
* memcpy                        copies x number of bytes from one memory position to another memory position    https://man7.org/linux/man-pages/man3/memcpy.3.html
* fprintf                       writes formatted data to a stream                                               https://man7.org/linux/man-pages/man3/fprintf.3p.html
*   
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:
*             
*                                                                                                  
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:
*  It is assumed that the stack will never have more than 2^64 elements. 
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
* 21-01-2025    Tiago Rodrigues                               1         Copy of stack.c, followed by changing the 
* ----------    ---------------         ---------       -------          datatypes and functions to implement the 
* ----------    ---------------         ---------       -------          stack data as a linked list      
* 23-01-2025    Tiago Rodrigues                               1         Updated create_stack function, and added 
* ----------    ---------------         ---------       -------          a few good C practices
* 31-01-2025    Tiago Rodrigues                           1.0.1         Added better error handling 
* 17-01-2026    Tiago Rodrigues                               2         Changed return type of check_stack_is_empty from
* ----------    ---------------         ---------       -------          uint8_t to bool
* 18-01-2026    Tiago Rodrigues                               2         Changed functions for opaqueness      
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
// #include <errno.h>

/* 1.3 C++ standard library headers*/

/* 1.4 other libraries' headers*/

/* 1.5 project's headers */
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

// typedef uint8_t stack_datatype;





/*****************************************************/


/* 5 global variable declarations */
/*****************************************************/
//void *stack = NULL;
//uint64_t stack_size = 0;

// uint64_t stack_size_allocated = 0;                      // num_of_bytes

struct data
{
        void *data_element;
        struct data *next;
};

struct stack
{
        size_t stack_size;
        size_t datatype_size;                         // num_of_bytes
        struct data *stack_data;
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
* NOTES: elements_to_allocate is not needed here, since linked lists are allocated node by node. Its present
*         here to mantain compatibility to stack.h
*

* RETURNS: stack_t*
*
*
*
*****************************************************************/
stack_t* create_stack(size_t size_of_datatype, size_t elements_to_allocate)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */

        stack_t* id_of_stack = NULL;
        // Allocation of a stack struct
        id_of_stack = malloc(1*sizeof(struct stack));                       
        if(NULL == id_of_stack)
        {
                perror("Memory allocation failed");
                return NULL;
        }

        id_of_stack->stack_size = 0;
        id_of_stack->datatype_size = size_of_datatype;
        id_of_stack->stack_data = NULL;

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
* RETURNS: bool ( true if successful, false otherwise) 
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
        


        memcpy(data_at_top, id_of_stack->stack_data->data_element, id_of_stack->datatype_size);

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
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct data*    auxiliary pointer to deallocation of node
        */
        if(NULL == id_of_stack)
        {
                fprintf(stderr, "Stack pointer location is null\n");
                return false;
        }

        // TODO: confirm the pointers aren't null
        if(!stack_is_empty(id_of_stack))
        {
                struct data *aux_ptr= id_of_stack->stack_data;
                id_of_stack->stack_data = id_of_stack->stack_data->next;

                free(aux_ptr->data_element);
                free(aux_ptr);

                id_of_stack->stack_size--;

                return true;
        }

        return false;
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
* id_of_stack   stack_t*	I	pointer to the memory position of the stack to push to
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
        *  aux_data_ptr struct data     auxiliary pointer for the allocation of nodes
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


        // Allocate space in the stack for the array of values
        struct data *aux_data_ptr = (struct data*) malloc(1*sizeof(struct data));   
        if(NULL == aux_data_ptr)
        {
                perror("Memory allocation failed");
                return false;
        }

        
        aux_data_ptr->data_element = (void*) malloc(1*id_of_stack->datatype_size);
        if(NULL == aux_data_ptr->data_element)
        {
                perror("Memory allocation failed");
                return false;
        }

        memcpy(aux_data_ptr->data_element, data_to_push, id_of_stack->datatype_size);
        aux_data_ptr->next = id_of_stack->stack_data;

        id_of_stack->stack_data = aux_data_ptr;

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
        *  Variable        Type         Description
        *  aux_data_ptr    struct data* auxiliary pointer to deallocation of nodes
        */
        if(NULL == id_of_stack)
                return;

        struct data *aux_data_ptr = id_of_stack->stack_data; 
        
        while(NULL != id_of_stack->stack_data)
        {
                id_of_stack->stack_data = id_of_stack->stack_data->next;
                free(aux_data_ptr->data_element);
                free(aux_data_ptr);
                aux_data_ptr = id_of_stack->stack_data;
        }
                
        free(id_of_stack);
        return ;
}