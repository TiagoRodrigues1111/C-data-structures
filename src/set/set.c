
/*******************************************************************************************************************
* FILE NAME: set.c  
*                                                                                                               
* PURPOSE: This file defines the function prototypes for a set implementation     
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
*
*
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:
*
*
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:
*  It is assumed that the set will never have more than 2^64 elements.                               
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
* 04-06-2025    Tiago Rodrigues                         1               File preparation
*
*
* ALGORITHM (PDL)
*    
*
*                                                                                                           
****************************************************************************************************************/




/* 0 copyright/licensing */
/**********************************************************************
*
* 2025 Tiago Filipe Rodrigues tiagorodrigues1590@hotmail.com
*
***********************************************************************/



/* 1 includes */
/*****************************************************/

/* 1.1 Related header */
#include "set.h"

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

struct set
{
        uint64_t set_size;
        uint64_t set_size_allocated;                    // num_of_elements
        uint64_t datatype_size;                         // num_of_bytes
        uint64_t k_aux;                                 // auxiliary 4 bytes for reallocation      
        void *set_data;
        int8_t (*compare_func)(void* val1, void* val2);
};


/*****************************************************/


/* 6 function prototypes */
/*****************************************************/



/*****************************************************/



/* 7 function declarations */
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
* id_of_set	        void**	        I/O	pointer to the memory position of the set to implement
* size_of_datatype      uint64_t        I       byte size of datatype to place in the set
* elements_to_allocate  uint64_t        I       number of elements to allocate for the set
* compare_func          function        I       function to compare presence of element in the set
*
* RETURNS: void
*
*
*
*****************************************************************/
void create_set(void** id_of_set, uint64_t size_of_datatype, uint64_t elements_to_allocate,int8_t (*compare_func)(void* val1, void* val2))
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_set)
        {
                fprintf(stderr, "Set pointer location is null\n");
                return ;
        }
                

        // Allocation of a priority_queue struct
        (*id_of_set) = malloc(1*sizeof(struct set));                       
        if(NULL == *id_of_set)
        {
                perror("Memory allocation failed");
                return ;
        }

        if(0 == elements_to_allocate)
                ((struct set*)(*id_of_set))->set_size_allocated = INITIAL_ALLOC;      // assumed that the number of elements to allocate initially is INITIAL_ALLOC (3 by default)
        else
                ((struct set*)(*id_of_set))->set_size_allocated = elements_to_allocate;

        ((struct set*)(*id_of_set))->set_size = 0;
        ((struct set*)(*id_of_set))->datatype_size = size_of_datatype;
        ((struct set*)(*id_of_set))->k_aux = 1;
        ((struct set*)(*id_of_set))->compare_func = compare_func;

        // Allocate space in the priority_queue for the array of values
        ((struct set*)(*id_of_set))->set_data = (void*) malloc(((struct set*)(*id_of_set))->set_size_allocated*((struct set*)(*id_of_set))->datatype_size);     
        if(NULL == ((struct set*)(*id_of_set))->set_data)
        {
                perror("Memory allocation failed");
                return ;
        }
        
        return ;        
}

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
* id_of_set             void*	        I	pointer to the memory position of the set to insert into
* data_to_insert        void*	        I	pointer to the memory position of the data to insert into the set
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void set_insert(void* id_of_set, void* data_to_insert)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */


        return ;
}

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
* id_of_set             void*	        I	pointer to the memory position of the set to erase from
* element_to_erase      void*	        I	pointer to the memory position of the element to erase from the set
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void set_erase(void* id_of_set, void* element_to_erase)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */


        return ;
}

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
* id_of_set             void*	        I	pointer to the memory position of the set
* element_to_check      void*	        I	pointer to the memory position of the element to check if exists
*
*
* RETURNS: uint8_t
*
*
*
*****************************************************************/
uint8_t set_contains(void* id_of_set, void* element_to_check)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */

        return ;
}

/******************************************************************
*
* FUNCTION NAME: check_set_is_empty
*
* PURPOSE: Checks if the set is empty or not
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* id_of_set   void*	        I	pointer to the memory position of the set to check
*
*
* RETURNS: uint8_t
*
*
*
*****************************************************************/
uint8_t check_set_is_empty(void* id_of_set)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_set)
        {
                fprintf(stderr, "set pointer location is null\n");
                return 0;
        }
                
        if(0 == ((struct set*)id_of_set)->set_size)
                return 1;
        else
                return 0;
}

/******************************************************************
*
* FUNCTION NAME: check_set_size
*
* PURPOSE: Will return the current element count in the set
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* id_of_set   void*	        I	pointer to the memory position of the set to check
*
*
* RETURNS: uint64_t (size of the set)
*
*
*
*****************************************************************/
uint64_t check_set_size(void* id_of_set)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_set)
        {
                fprintf(stderr, "Priority queue pointer location is null\n");
                return 0;
        }

        return ((struct set*)id_of_set)->set_size;
}

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
* id_of_set     void*	        I	pointer to the memory position of the set to free
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_set(void* id_of_set)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_set)
                return;

        if(NULL != ((struct set*)id_of_set)->set_data)
                free(((struct set*)id_of_set)->set_data);
        
        free(id_of_set);

        return ;
}















