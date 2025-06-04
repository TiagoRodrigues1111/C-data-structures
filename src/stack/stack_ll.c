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
        uint64_t stack_size;
        uint64_t datatype_size;                         // num_of_bytes
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
* id_of_stack	        void**	        I/O	pointer to the memory position of the stack to implement
* size_of_datatype      uint64_t        I       byte size of datatype to place in the stack
* elements_to_allocate  uint64_t        I       number of elements to allocate
*
* NOTES: elements_to_allocate is not needed here, since linked lists are allocated node by node. Its present
*         here to mantain compatibility to stack.h
*
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
        if(NULL == id_of_stack)
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

        ((struct stack*)(*id_of_stack))->stack_size = 0;
        ((struct stack*)(*id_of_stack))->datatype_size = size_of_datatype;
        ((struct stack*)(*id_of_stack))->stack_data = NULL;


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
        


        return (((struct stack*)id_of_stack)->stack_data->data_element);
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
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct data*    auxiliary pointer to deallocation of node
        */
        if(NULL == id_of_stack)
        {
                fprintf(stderr, "Stack pointer location is null\n");
                return ;
        }   

        // TODO: confirm the pointers aren't null
        if(!check_stack_is_empty(id_of_stack))
        {
                struct data *aux_ptr= ((struct stack*)id_of_stack)->stack_data;
                ((struct stack*)id_of_stack)->stack_data = ((struct stack*)id_of_stack)->stack_data->next;

                free(aux_ptr->data_element);
                free(aux_ptr);

                ((struct stack*)id_of_stack)->stack_size--;

        }
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
        *  aux_data_ptr struct data     auxiliary pointer for the allocation of nodes
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


        // Allocate space in the stack for the array of values
        struct data *aux_data_ptr = (struct data*) malloc(1*sizeof(struct data));   
        if(NULL == aux_data_ptr)
        {
                perror("Memory allocation failed");
                return ;
        }

        
        aux_data_ptr->data_element = (void*) malloc(1*((struct stack*)id_of_stack)->datatype_size);
        if(NULL == aux_data_ptr->data_element)
        {
                perror("Memory allocation failed");
                return;
        }

        memcpy(aux_data_ptr->data_element, data_to_push, ((struct stack*)id_of_stack)->datatype_size);
        aux_data_ptr->next = ((struct stack*)id_of_stack)->stack_data;

        ((struct stack*)id_of_stack)->stack_data = aux_data_ptr;

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
        *  Variable        Type         Description
        *  aux_data_ptr    struct data* auxiliary pointer to deallocation of nodes
        */
        if(NULL == id_of_stack)
                return;

        struct data *aux_data_ptr = ((struct stack*)id_of_stack)->stack_data; 
        
        while(NULL != (((struct stack*)id_of_stack)->stack_data))
        {
                ((struct stack*)id_of_stack)->stack_data = ((struct stack*)id_of_stack)->stack_data->next;
                free(aux_data_ptr->data_element);
                free(aux_data_ptr);
                aux_data_ptr = ((struct stack*)id_of_stack)->stack_data;
        }
                
        free(id_of_stack);
        return ;
}