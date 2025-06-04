/*******************************************************************************************************************
* FILE NAME: priority_queue.c
*                                                                                                               
* PURPOSE: This file defines the functions declared in priority_queue.h, using arrays
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
*
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
* 06-02-2025    Tiago Rodrigues                               1         File preparation   
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

#include "priority_queue.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
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


/*****************************************************/


/* 5 global variable declarations */
/*****************************************************/

// Possible solutions:  queue_front and queue_size (increment to find the back )
//                      queue_front and queue_back (initiate queue_back as always +1 than it should )
struct priority_queue
{
        uint64_t priority_queue_size;
        uint64_t priority_queue_size_allocated;         // num_of_elements
        uint64_t datatype_size;                         // num_of_bytes
        uint64_t k_aux;                                 // auxiliary 4 bytes for reallocation      
        void *priority_queue_data;
        int8_t type_of_priority_queue;
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
* FUNCTION NAME: create_queue       
*
* PURPOSE: Allocates the needed memory for the queue wanted
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* id_of_queue	        void**	        I/O	pointer to the memory position of the queue to implement
* size_of_datatype      uint64_t        I       byte size of datatype to place in the queue
* elements_to_allocate  uint64_t        I       number of elements to allocate for the queue
*
* RETURNS: void
*
*
*
*****************************************************************/
void create_priority_queue(void** id_of_priority_queue, uint64_t size_of_datatype, uint64_t elements_to_allocate, uint8_t type_of_priority_queue, int8_t (*compare_func)(void* val1, void* val2))   // uint64_t elements_to_allocate
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_priority_queue)
        {
                fprintf(stderr, "Priority queue pointer location is null\n");
                return ;
        }
                

        // Allocation of a priority_queue struct
        (*id_of_priority_queue) = malloc(1*sizeof(struct priority_queue));                       
        if(NULL == *id_of_priority_queue)
        {
                perror("Memory allocation failed");
                return ;
        }

        if(0 == elements_to_allocate)
                ((struct priority_queue*)(*id_of_priority_queue))->priority_queue_size_allocated = INITIAL_ALLOC;      // assumed that the number of elements to allocate initially is INITIAL_ALLOC (3 by default)
        else
                ((struct priority_queue*)(*id_of_priority_queue))->priority_queue_size_allocated = elements_to_allocate;

        ((struct priority_queue*)(*id_of_priority_queue))->priority_queue_size = 0;
        ((struct priority_queue*)(*id_of_priority_queue))->datatype_size = size_of_datatype;
        ((struct priority_queue*)(*id_of_priority_queue))->k_aux = 1;
        ((struct priority_queue*)(*id_of_priority_queue))->compare_func = compare_func;
        ((struct priority_queue*)(*id_of_priority_queue))->type_of_priority_queue = type_of_priority_queue;

        // Allocate space in the priority_queue for the array of values
        ((struct priority_queue*)(*id_of_priority_queue))->priority_queue_data = (void*) malloc(((struct priority_queue*)(*id_of_priority_queue))->priority_queue_size_allocated*((struct priority_queue*)(*id_of_priority_queue))->datatype_size);     
        if(NULL == ((struct priority_queue*)(*id_of_priority_queue))->priority_queue_data)
        {
                perror("Memory allocation failed");
                return ;
        }
        
        return ;        
}



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
void* check_priority_queue_top(void* id_of_priority_queue)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_priority_queue)
        {
                fprintf(stderr, "Priority queue pointer location is null\n");
                return NULL;
        }
               

        if(check_priority_queue_is_empty(id_of_priority_queue))                       
                return NULL;

        return (void *) &((uint8_t*)(((struct priority_queue*)id_of_priority_queue)->priority_queue_data))[0];  


}




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
void priority_queue_pop(void* id_of_priority_queue)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_priority_queue)
        {
                fprintf(stderr, "Priority queue pointer location is null\n");
                return ;
        }   
        if(!check_priority_queue_is_empty(id_of_priority_queue))
        {
                memcpy((void *)&((uint8_t*)(((struct priority_queue*)id_of_priority_queue)->priority_queue_data))[0],(void *)&((uint8_t*)(((struct priority_queue*)id_of_priority_queue)->priority_queue_data))[(check_priority_queue_size(id_of_priority_queue)-1)*((struct priority_queue*)id_of_priority_queue)->datatype_size], ((struct priority_queue*)id_of_priority_queue)->datatype_size);   
                ((struct priority_queue*)id_of_priority_queue)->priority_queue_size--;

                uint64_t left, right, smallest, index;
                index = 0;
                void *aux = NULL;
                aux = malloc(1*((struct priority_queue*)id_of_priority_queue)->datatype_size);

                int8_t cmp_aux = 0;
                if(0 == ((struct priority_queue*)id_of_priority_queue)->type_of_priority_queue)
                        cmp_aux = -1;
                else
                {
                        cmp_aux = 1;
                }


                while (1) 
                {
                        left = 2 * index + 1;
                        right = 2 * index + 2;
                        smallest = index;

                        

                        if(left < check_priority_queue_size(id_of_priority_queue) && (cmp_aux == ((struct priority_queue*)id_of_priority_queue)->compare_func((void *) &((uint8_t*)(((struct priority_queue*)id_of_priority_queue)->priority_queue_data))[(left)*((struct priority_queue*)id_of_priority_queue)->datatype_size],(void *) &((uint8_t*)(((struct priority_queue*)id_of_priority_queue)->priority_queue_data))[(smallest)*((struct priority_queue*)id_of_priority_queue)->datatype_size])))
                        {
                                smallest = left;
                        }

                        if(right < check_priority_queue_size(id_of_priority_queue) && (cmp_aux == ((struct priority_queue*)id_of_priority_queue)->compare_func((void *) &((uint8_t*)(((struct priority_queue*)id_of_priority_queue)->priority_queue_data))[(right)*((struct priority_queue*)id_of_priority_queue)->datatype_size],(void *) &((uint8_t*)(((struct priority_queue*)id_of_priority_queue)->priority_queue_data))[(smallest)*((struct priority_queue*)id_of_priority_queue)->datatype_size])))
                        {
                                smallest = right;
                        }

                        if (smallest != index) 
                        {
                                
                                memcpy(aux, (void *) &((uint8_t*)(((struct priority_queue*)id_of_priority_queue)->priority_queue_data))[(index)*((struct priority_queue*)id_of_priority_queue)->datatype_size], ((struct priority_queue*)id_of_priority_queue)->datatype_size);     
                                memcpy((void *) &((uint8_t*)(((struct priority_queue*)id_of_priority_queue)->priority_queue_data))[(index)*((struct priority_queue*)id_of_priority_queue)->datatype_size], (void *) &((uint8_t*)(((struct priority_queue*)id_of_priority_queue)->priority_queue_data))[(smallest)*((struct priority_queue*)id_of_priority_queue)->datatype_size], ((struct priority_queue*)id_of_priority_queue)->datatype_size);     
                                memcpy((void *) &((uint8_t*)(((struct priority_queue*)id_of_priority_queue)->priority_queue_data))[(smallest)*((struct priority_queue*)id_of_priority_queue)->datatype_size],aux, ((struct priority_queue*)id_of_priority_queue)->datatype_size);
                                index = smallest;
                        }
                        else 
                        {
                                break;
                        }
                }


                free(aux);
        }


        return;
}



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
void priority_queue_push(void* id_of_priority_queue, void* data_to_push)
{

       /* LOCAL VARIABLES:
        *  Variable     Type    Description
        *  --------     ----    -----------
        *  queue_aux    void*   auxiliary pointer for the realloc operation
        */
        if(NULL == id_of_priority_queue)
        {
                fprintf(stderr, "Priority queue pointer location is null\n");
                return ;
        }
        if(UINT64_MAX == ((struct priority_queue*)id_of_priority_queue)->priority_queue_size)
        {
                fprintf(stderr, "Priority queue full, can't add more elements\n");
                return ;
        }
        if(NULL == data_to_push)
        {
                fprintf(stderr, "Data pointer is null\n");
                return ;
        }




        ((struct priority_queue*)id_of_priority_queue)->priority_queue_size++;

        // reallocate memory if num of elements in priority_queue becomes larger than the max num of elements allocated for the priority_queue 
        if(((struct priority_queue*)id_of_priority_queue)->priority_queue_size > ((struct priority_queue*)id_of_priority_queue)->priority_queue_size_allocated)
        {
                void* priority_queue_aux = NULL;
                // tries to allocate double the size of the current priority_queue;
                if(1 == (((struct priority_queue*)id_of_priority_queue)->k_aux))
                {
                        priority_queue_aux = realloc(((struct priority_queue*)id_of_priority_queue)->priority_queue_data, (((struct priority_queue*)id_of_priority_queue)->priority_queue_size_allocated + ((struct priority_queue*)id_of_priority_queue)->priority_queue_size_allocated)*((struct priority_queue*)id_of_priority_queue)->datatype_size);                 
                        if(NULL != priority_queue_aux)                   // this is not needed, and could be placed after the while, however the shift left is a bit faster than the addition
                        {
                                ((struct priority_queue*)id_of_priority_queue)->priority_queue_size_allocated <<= 1;                        
                        }
                }
                else
                {
                        while (NULL == priority_queue_aux)
                        {
                                perror("Memory reallocation failed");
                                printf("Attempting smaller reallocation\n");
                                (((struct priority_queue*)id_of_priority_queue)->k_aux)<<=1;                              // always times 2 (TODO: might be faster to shift at the end again, and add 1 (check the lim->))
                                 
                                if(0 == (((struct priority_queue*)id_of_priority_queue)->priority_queue_size_allocated/(((struct priority_queue*)id_of_priority_queue)->k_aux)))
                                {
                                        fprintf(stderr, "Impossible to reallocate priority_queue\n");
                                        //perror("Impossible to reallocate priority_queue");
                                        return ;
                                }
                                priority_queue_aux = realloc(((struct priority_queue*)id_of_priority_queue)->priority_queue_data, (((struct priority_queue*)id_of_priority_queue)->priority_queue_size_allocated + (((struct priority_queue*)id_of_priority_queue)->priority_queue_size_allocated / (((struct priority_queue*)id_of_priority_queue)->k_aux)))*((struct priority_queue*)id_of_priority_queue)->datatype_size);
                        }

                        ((struct priority_queue*)id_of_priority_queue)->priority_queue_size_allocated += (((struct priority_queue*)id_of_priority_queue)->priority_queue_size_allocated/(((struct priority_queue*)id_of_priority_queue)->k_aux));          

                }
                
                ((struct priority_queue*)id_of_priority_queue)->priority_queue_data = priority_queue_aux;
        }

        memcpy((void *) &((uint8_t*)(((struct priority_queue*)id_of_priority_queue)->priority_queue_data))[(((struct priority_queue*)id_of_priority_queue)->priority_queue_size-1)*((struct priority_queue*)id_of_priority_queue)->datatype_size], data_to_push, ((struct priority_queue*)id_of_priority_queue)->datatype_size);


        uint64_t index = ((struct priority_queue*)id_of_priority_queue)->priority_queue_size - 1;
        void *aux = NULL;
        aux = malloc(1*((struct priority_queue*)id_of_priority_queue)->datatype_size);
        
        
        int8_t cmp_aux = 0;
        if(0 == ((struct priority_queue*)id_of_priority_queue)->type_of_priority_queue)
                cmp_aux = 1;
        else
        {
                cmp_aux = -1;
        }

        while (index > 0) 
        {
                uint64_t parent = (index - 1) / 2;
                
                if((cmp_aux == ((struct priority_queue*)id_of_priority_queue)->compare_func((void *) &((uint8_t*)(((struct priority_queue*)id_of_priority_queue)->priority_queue_data))[(parent)*((struct priority_queue*)id_of_priority_queue)->datatype_size],(void *) &((uint8_t*)(((struct priority_queue*)id_of_priority_queue)->priority_queue_data))[(index)*((struct priority_queue*)id_of_priority_queue)->datatype_size])))
                {
                        
                        memcpy(aux, (void *) &((uint8_t*)(((struct priority_queue*)id_of_priority_queue)->priority_queue_data))[(index)*((struct priority_queue*)id_of_priority_queue)->datatype_size], ((struct priority_queue*)id_of_priority_queue)->datatype_size);     
                        memcpy((void *) &((uint8_t*)(((struct priority_queue*)id_of_priority_queue)->priority_queue_data))[(index)*((struct priority_queue*)id_of_priority_queue)->datatype_size], (void *) &((uint8_t*)(((struct priority_queue*)id_of_priority_queue)->priority_queue_data))[(parent)*((struct priority_queue*)id_of_priority_queue)->datatype_size], ((struct priority_queue*)id_of_priority_queue)->datatype_size);     
                        memcpy((void *) &((uint8_t*)(((struct priority_queue*)id_of_priority_queue)->priority_queue_data))[(parent)*((struct priority_queue*)id_of_priority_queue)->datatype_size],aux, ((struct priority_queue*)id_of_priority_queue)->datatype_size);
                       
                        index = parent;
                } 
                else
                {
                        break;
                }
        }

        free(aux);
}



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
uint8_t check_priority_queue_is_empty(void* id_of_priority_queue)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_priority_queue)
        {
                fprintf(stderr, "Queue pointer location is null\n");
                return 0;
        }
                
        if(0 == ((struct priority_queue*)id_of_priority_queue)->priority_queue_size)
                return 1;
        else
                return 0;


}


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
uint64_t check_priority_queue_size(void* id_of_priority_queue)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_priority_queue)
        {
                fprintf(stderr, "Priority queue pointer location is null\n");
                return 0;
        }

        return ((struct priority_queue*)id_of_priority_queue)->priority_queue_size;



}

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
void free_priority_queue(void* id_of_priority_queue)
{

        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_priority_queue)
                return;

        if(NULL != ((struct priority_queue*)id_of_priority_queue)->priority_queue_data)
                free(((struct priority_queue*)id_of_priority_queue)->priority_queue_data);
        
        free(id_of_priority_queue);
        return ;


}