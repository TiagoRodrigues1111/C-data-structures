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
// #include <errno.h>

/* 1.3 C++ standard library headers*/

/* 1.4 other libraries' headers*/

/* 1.5 project's headers */






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

// typedef uint8_t stack_datatype;





/*****************************************************/


/* 5 global variable declarations */
/*****************************************************/
//void *stack = NULL;
//uint64_t stack_size = 0;

// uint64_t stack_size_allocated = 0;                      // num_of_bytes
// uint64_t datatype_size = 0;                             // num_of_bytes

struct stack
{
        uint64_t stack_size;
        uint64_t stack_size_allocated;                  // num_of_elements
        uint64_t datatype_size;                         // num_of_bytes
        uint64_t k_aux;                                 // auxiliary 4 bytes for reallocation      
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
* id_of_stack	        void**	        I/O	pointer to the memory position of the stack to implement
* size_of_datatype      uint64_t        I       byte size of datatype to place in the stack
* elements_to_allocate  uint64_t        I       number of elements to allocate for the stack
*
* RETURNS: void
*
*
*****************************************************************/
void create_stack(void** id_of_stack, uint64_t size_of_datatype, uint64_t elements_to_allocate)                 
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_stack)                                                         // TODO: is this actually a problem?
        {
                fprintf(stderr, "Stack pointer location is null\n");
                return ;
        }
                

        // Allocation of a stack struct
        (*id_of_stack) = malloc(1*sizeof(struct stack));                       
        if(NULL == *id_of_stack)
        {
                perror("Memory allocation failed");
                return ;
        }

        if(0 == elements_to_allocate)
                ((struct stack*)(*id_of_stack))->stack_size_allocated = INITIAL_ALLOC;      // assumed that the number of elements to allocate initially is INITIAL_ALLOC (3 by default)
        else
                ((struct stack*)(*id_of_stack))->stack_size_allocated = elements_to_allocate;

        ((struct stack*)(*id_of_stack))->stack_size = 0;
        ((struct stack*)(*id_of_stack))->datatype_size = size_of_datatype;
        ((struct stack*)(*id_of_stack))->k_aux = 1;

        // Allocate space in the stack for the array of values
        ((struct stack*)(*id_of_stack))->stack_data = (void*) malloc(((struct stack*)(*id_of_stack))->stack_size_allocated*((struct stack*)(*id_of_stack))->datatype_size);     
        if(NULL == ((struct stack*)(*id_of_stack))->stack_data)
        {
                perror("Memory allocation failed");
                return ;
        }
        

        
        return ;        
}




/******************************************************************
*
* FUNCTION NAME: check_stack_top       
*
* PURPOSE: Returns the memory position of the element that is currently on the top of the stack
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------      ----            ---     ------------
* id_of_stack   void*	        I	pointer to the memory position of the stack to check
* 
*
* RETURNS: void* (pointer to the memory position of the top element of the stack)
*
*
*
*****************************************************************/
void* check_stack_top(void* id_of_stack)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_stack)
        {
                fprintf(stderr, "Stack pointer location is null\n");
                return NULL;
        }
               

        if(check_stack_is_empty(id_of_stack))                       
                return NULL;

        return (void *) &((uint8_t*)(((struct stack*)id_of_stack)->stack_data))[(((struct stack*)id_of_stack)->stack_size-1)*((struct stack*)id_of_stack)->datatype_size];               //increment the right amount of bytes, then convert back to void
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
* id_of_stack   void*	        I	pointer to the memory position of the stack to pop from
*
* NOTES: The data is not deleted, therefore it could still be accessed by an adversarial party 
*         (example, check_stack_top and increment the memory position accordingly) 
*
* RETURNS: void
*
*
*
*****************************************************************/
void stack_pop(void* id_of_stack)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_stack)
        {
                fprintf(stderr, "Stack pointer location is null\n");
                return ;
        }   
        if(!check_stack_is_empty(id_of_stack))
                ((struct stack*)id_of_stack)->stack_size--;
        return;
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
* id_of_stack   void*	        I	pointer to the memory position of the stack to push to
* data_to_push  void*	        I	pointer to the memory position of the data to push into the stack
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void stack_push(void* id_of_stack, void* data_to_push)
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
                return ;
        }
        if(UINT64_MAX == check_stack_size(id_of_stack))
        {
                fprintf(stderr, "Stack full, can't add more elements\n");
                return ;
        }
        if(NULL == data_to_push)
        {
                fprintf(stderr, "Data pointer is null\n");
                return ;
        }



        ((struct stack*)id_of_stack)->stack_size++;
        // reallocate memory if num of elements in stack becomes larger than the max num of elements allocated for the stack 
        if(((struct stack*)id_of_stack)->stack_size > ((struct stack*)id_of_stack)->stack_size_allocated)
        {
                void* stack_aux = NULL;
                // tries to allocate double the size of the current stack;
                if(1 == (((struct stack*)id_of_stack)->k_aux))
                {
                        stack_aux = realloc(((struct stack*)id_of_stack)->stack_data, (((struct stack*)id_of_stack)->stack_size_allocated + ((struct stack*)id_of_stack)->stack_size_allocated)*((struct stack*)id_of_stack)->datatype_size);                 
                        if(NULL != stack_aux)                   // this is not needed, and could be placed after the while, however the shift left is a bit faster than the addition
                        {
                                ((struct stack*)id_of_stack)->stack_size_allocated <<= 1;                        
                        }
                }
                else
                {
                        while (NULL == stack_aux)
                        {
                                perror("Memory reallocation failed");
                                printf("Attempting smaller reallocation\n");
                                (((struct stack*)id_of_stack)->k_aux)<<=1;                              // always times 2 (TODO: might be faster to shift at the end again, and add 1 (check the lim->))
                                 
                                if(0 == (((struct stack*)id_of_stack)->stack_size_allocated/(((struct stack*)id_of_stack)->k_aux)))
                                {
                                        fprintf(stderr, "Impossible to reallocate stack\n");
                                        //perror("Impossible to reallocate stack");
                                        return ;
                                }
                                stack_aux = realloc(((struct stack*)id_of_stack)->stack_data, (((struct stack*)id_of_stack)->stack_size_allocated + (((struct stack*)id_of_stack)->stack_size_allocated / (((struct stack*)id_of_stack)->k_aux)))*((struct stack*)id_of_stack)->datatype_size);
                        }

                        ((struct stack*)id_of_stack)->stack_size_allocated += (((struct stack*)id_of_stack)->stack_size_allocated/(((struct stack*)id_of_stack)->k_aux));          

                }
                
                ((struct stack*)id_of_stack)->stack_data = stack_aux;
        }

        memcpy(check_stack_top(id_of_stack), data_to_push, ((struct stack*)id_of_stack)->datatype_size);

        return ;
}





/******************************************************************
*
* FUNCTION NAME: check_stack_is_empty
*
* PURPOSE: Checks if the stack is empty or not
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* id_of_stack   void*	        I	pointer to the memory position of the stack to check
*
*
* RETURNS: uint8_t (as 0 or 1)
*
*
*
*****************************************************************/
uint8_t check_stack_is_empty(void* id_of_stack)
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
                
        if(0 == ((struct stack*)id_of_stack)->stack_size)
                return 1;
        else
                return 0;
}


/******************************************************************
*
* FUNCTION NAME: check_stack_size
*
* PURPOSE: Will return the current element count in the stack
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* id_of_stack   void*	        I	pointer to the memory position of the stack to check
*
*
* RETURNS: uint64_t (size of the stack)
*
*
*
*****************************************************************/
uint64_t check_stack_size(void* id_of_stack)
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

        return ((struct stack*)id_of_stack)->stack_size;
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
* id_of_stack   void*	        I	pointer to the memory position of the stack to free
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_stack(void* id_of_stack)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_stack)
                return;

        if(NULL != ((struct stack*)id_of_stack)->stack_data)
                free(((struct stack*)id_of_stack)->stack_data);
        
        free(id_of_stack);
        return ;
}