/*******************************************************************************************************************
* FILE NAME: deque_ll.c
*                                                                                                               
* PURPOSE: This file implements the functions defined in deque.h, with a linked list
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
*    
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:                                                  
*             
*                                                                                                  
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:                                                                       
*  It is assumed that the deque will never have more than 2^64 elements.                               
*  It is assumed that the user will grab only 1 element size from the memory position returned from check_deque_front and check_deque_back                              
* 
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
* 14-01-2025    Tiago Rodrigues                               1         File preparation     
* 23-01-2025    Tiago Rodrigues                               1         Implementation of deque using a linked list     
* 27-01-2025    Tiago Rodrigues                               1         Added Comments to functions  
* 03-02-2025    Tiago Rodrigues                               1         Added fix to data being NULL bug
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

#include "deque.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

struct data
{
        void* data_element;
        struct data* next;
        struct data* previous;        
};


struct deque
{
        uint64_t datatype_size;                         
        uint64_t deque_size;                                    // needed for the check_size(otherwise O(k))
        struct data* deque_front;
        struct data* deque_back; 

        // struct data *deque_data;
};


/*****************************************************/


/* 6 function prototypes */
/*****************************************************/

/*****************************************************/



/* 7 function declarations */
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
deque_t* create_deque(size_t size_of_datatype, size_t elements_to_allocate)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
                
        deque_t* id_of_deque = NULL;

        // Allocation of a deque struct
        id_of_deque = malloc(1*sizeof(struct deque));                       
        if(NULL == id_of_deque)
        {
                perror("Memory allocation failed");
                return NULL;
        }

        id_of_deque->deque_front = NULL;
        id_of_deque->deque_back = NULL;
        id_of_deque->deque_size = 0;
        id_of_deque->datatype_size = size_of_datatype;

        return id_of_deque;        
}



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
bool deque_front(const deque_t* id_of_deque, void* data_at_front)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_deque)
        {
                fprintf(stderr, "deque pointer location is null\n");
                return NULL;
        }


        if(deque_is_empty(id_of_deque))                       
                return false;

        if(NULL != ((struct deque*)id_of_deque)->deque_front)
        {
                memcpy(data_at_front, ((struct deque*)id_of_deque)->deque_front->data_element, ((struct deque*)id_of_deque)->datatype_size);
                return true;
        }
        return false;
}

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
bool deque_back(const deque_t* id_of_deque, void* data_at_back)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_deque)
        {
                fprintf(stderr, "deque pointer location is null\n");
                return false;
        }


        if(NULL != ((struct deque*)id_of_deque)->deque_back)
        {
                memcpy(data_at_back, ((struct deque*)id_of_deque)->deque_back->data_element, ((struct deque*)id_of_deque)->datatype_size);
                return true;
        }


        return false;
}




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
bool deque_pop_front(deque_t* id_of_deque)
{
        /* LOCAL VARIABLES:
        *  Variable        Type         Description
        *  --------        ----         -----------
        *  aux_ptr         struct data* pointer to data node to be removed
        */
        if(NULL == id_of_deque)
        {
                fprintf(stderr, "Deque pointer location is null\n");
                return false;
        }   
        if(!deque_is_empty(id_of_deque))
        {
                

                struct data *aux_ptr = id_of_deque->deque_front;

                id_of_deque->deque_front = id_of_deque->deque_front->next;
                if(NULL != id_of_deque->deque_front)
                        id_of_deque->deque_front->previous = NULL;
                
                free(aux_ptr->data_element);
                free(aux_ptr);

                id_of_deque->deque_size--;

                if(0 == id_of_deque->deque_size)
                        id_of_deque->deque_back = NULL;                        // TODO: check if there are other places where this might be a problem

                return true;
        }
        return false;
}


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
bool deque_pop_back(deque_t* id_of_deque)
{
        /* LOCAL VARIABLES:
        *  Variable        Type         Description
        *  --------        ----         -----------
        *  aux_ptr         struct data* pointer to data node to be removed
        */
        if(NULL == id_of_deque)
        {
                fprintf(stderr, "Deque pointer location is null\n");
                return false;
        }   
        if(!deque_is_empty(id_of_deque))
        {
                

                struct data *aux_ptr = id_of_deque->deque_back;

                id_of_deque->deque_back = id_of_deque->deque_back->previous;
                if(NULL != id_of_deque->deque_back)
                        id_of_deque->deque_back->next = NULL;    

                free(aux_ptr->data_element);
                free(aux_ptr);

                id_of_deque->deque_size--;

                if(0 == id_of_deque->deque_size)
                        id_of_deque->deque_front = NULL;                        // TODO: check if there are other places where this might be a problem


                return true;
        }
        return false;
}




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
bool deque_push_back(deque_t* id_of_deque, const void* data_to_push)
{
       /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ------------    -----------
        *  aux_data_ptr struct data*    pointer to the new node to allocate and push into the deque
        */
        if(NULL == id_of_deque)
        {
                fprintf(stderr, "Deque pointer location is null\n");
                return false;
        }
        if(UINT64_MAX == deque_size(id_of_deque))
        {
                fprintf(stderr, "Deque full, can't add more elements\n");
                return false;
        }
        if(NULL == data_to_push)
        {
                fprintf(stderr, "Data pointer is null\n");
                return false;
        }
       
        // Allocate space in the deque for the array of values
        struct data *aux_data_ptr = (struct data*) malloc(1*sizeof(struct data));   
        if(NULL == aux_data_ptr)
        {
                perror("Memory allocation failed");
                return false;
        }

        aux_data_ptr->data_element = (void*) malloc(1*id_of_deque->datatype_size);
        if(NULL == aux_data_ptr->data_element)
        {
                perror("Memory allocation failed");
                return false;
        }

        memcpy(aux_data_ptr->data_element, data_to_push, id_of_deque->datatype_size);
        aux_data_ptr->next = NULL;
        aux_data_ptr->previous = NULL;

        if(0 == id_of_deque->deque_size)
        {
                id_of_deque->deque_front = aux_data_ptr;
                id_of_deque->deque_back = aux_data_ptr;
        }
        else
        {
                id_of_deque->deque_back->next = aux_data_ptr;
                aux_data_ptr->previous = id_of_deque->deque_back;
                id_of_deque->deque_back = id_of_deque->deque_back->next;
        }

        id_of_deque->deque_size++;

        return true;

}


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
bool deque_push_front(deque_t* id_of_deque, const void* data_to_push)
{
       /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ------------    -----------
        *  aux_data_ptr struct data*    pointer to the new node to allocate and push into the deque
        */
        if(NULL == id_of_deque)
        {
                fprintf(stderr, "Deque pointer location is null\n");
                return false;
        }
        if(UINT64_MAX == deque_size(id_of_deque))
        {
                fprintf(stderr, "Deque full, can't add more elements\n");
                return false;
        }
        if(NULL == data_to_push)
        {
                fprintf(stderr, "Data pointer is null\n");
                return false;
        }
       
        // Allocate space in the deque for the array of values
        struct data *aux_data_ptr = (struct data*) malloc(1*sizeof(struct data));   
        if(NULL == aux_data_ptr)
        {
                perror("Memory allocation failed");
                return false;
        }

        aux_data_ptr->data_element = (void*) malloc(1*id_of_deque->datatype_size);
        if(NULL == aux_data_ptr->data_element)
        {
                perror("Memory allocation failed");
                return false;
        }

        memcpy(aux_data_ptr->data_element, data_to_push, id_of_deque->datatype_size);
        aux_data_ptr->next = NULL;
        aux_data_ptr->previous = NULL;

        if(0 == id_of_deque->deque_size)
        {
                id_of_deque->deque_front = aux_data_ptr;
                id_of_deque->deque_back = aux_data_ptr;
        }
        else
        {
                aux_data_ptr->next = id_of_deque->deque_front;
                id_of_deque->deque_front->previous = aux_data_ptr;
                id_of_deque->deque_front = aux_data_ptr;
        }

        id_of_deque->deque_size++;

        return true;

}





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
bool deque_is_empty(const deque_t* id_of_deque)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_deque)
        {
                fprintf(stderr, "Deque pointer location is null\n");
                return false;
        }

        if(0 == id_of_deque->deque_size)
                return true;
        else
                return false;


}


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
size_t deque_size(const deque_t* id_of_deque)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_deque)
        {
                fprintf(stderr, "Deque pointer location is null\n");
                return 0;
        }

        return id_of_deque->deque_size;

}

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
void free_deque(deque_t* id_of_deque)
{

        /* LOCAL VARIABLES:
        *  Variable        Type         Description
        *  --------        ------------ -----------
        *  aux_data_ptr    struct data* auxiliary pointer to data node to deallocate
        */
        if(NULL == id_of_deque)
                return;

        struct data *aux_data_ptr = id_of_deque->deque_front; 

        while(NULL != id_of_deque->deque_front)
        {
                id_of_deque->deque_front = id_of_deque->deque_front->next;
                free(aux_data_ptr->data_element);
                free(aux_data_ptr);
                aux_data_ptr = id_of_deque->deque_front;
        }

        free(id_of_deque);
        return ;


}