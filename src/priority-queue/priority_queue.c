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
        size_t priority_queue_size;
        size_t priority_queue_size_allocated;         // num_of_elements
        size_t datatype_size;                         // num_of_bytes
        size_t k_aux;                                 // auxiliary 4 bytes for reallocation      
        void *priority_queue_data;
        bool (*compare_func)(void* val1, void* val2);
};


/*****************************************************/


/* 6 function prototypes */
/*****************************************************/

/*****************************************************/



/* 7 function declarations */
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
* size_of_datatype              size_t          I       byte size of datatype to place in the priority queue
* elements_to_allocate          size_t          I       number of elements to allocate for the priority queue
* compare_func                  function        I       function to compare two values in the priority queue
*
* RETURNS: priority_queue_t* 
*
*
*
*****************************************************************/
priority_queue_t* create_priority_queue(size_t size_of_datatype, size_t elements_to_allocate, bool (*compare_func)(void* val1, void* val2))
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */

        priority_queue_t* id_of_priority_queue = NULL;

        // Allocation of a priority_queue struct
        id_of_priority_queue = malloc(1*sizeof(struct priority_queue));                       
        if(NULL == id_of_priority_queue)
        {
                perror("Memory allocation failed");
                return NULL;
        }

        if(0 == elements_to_allocate)
                id_of_priority_queue->priority_queue_size_allocated = INITIAL_ALLOC;      // assumed that the number of elements to allocate initially is INITIAL_ALLOC (3 by default)
        else
                id_of_priority_queue->priority_queue_size_allocated = elements_to_allocate;

        id_of_priority_queue->priority_queue_size = 0;
        id_of_priority_queue->datatype_size = size_of_datatype;
        id_of_priority_queue->k_aux = 1;
        id_of_priority_queue->compare_func = compare_func;

        // Allocate space in the priority_queue for the array of values
        id_of_priority_queue->priority_queue_data = (void*) malloc(id_of_priority_queue->priority_queue_size_allocated*id_of_priority_queue->datatype_size);     
        if(NULL == id_of_priority_queue->priority_queue_data)
        {
                perror("Memory allocation failed");
                return NULL;
        }

        return id_of_priority_queue;        
}



/******************************************************************
*
* FUNCTION NAME: priority_queue_top      
*
* PURPOSE:Returns the memory position of the element that is currently on the top of the priority queue
*
* ARGUMENTS:
*
* ARGUMENT              TYPE	                I/O	DESCRIPTION
* --------              ----                    ---     ------------
* id_of_priority_queue  const priority_queue_t*	I	pointer to the memory position of the priority queue to check
* data_at_top           void*	                O	pointer to the memory position of the data at the top of the priority queue
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool priority_queue_top(const priority_queue_t* id_of_priority_queue, void* data_at_top)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_priority_queue)
        {
                fprintf(stderr, "Priority queue pointer location is null\n");
                return false;
        }
               

        if(priority_queue_is_empty(id_of_priority_queue))                       
                return false;


        memcpy(data_at_top, (void *) &((uint8_t*)(id_of_priority_queue->priority_queue_data))[0], (id_of_priority_queue->datatype_size));

        return true;
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
* id_of_priority_queue  priority_queue_t*	I	pointer to the memory position of the queue to pop from
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool priority_queue_pop(priority_queue_t* id_of_priority_queue)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_priority_queue)
        {
                fprintf(stderr, "Priority queue pointer location is null\n");
                return false;
        }   
        if(!priority_queue_is_empty(id_of_priority_queue))
        {
                
                memcpy((void *)&((uint8_t*)(id_of_priority_queue->priority_queue_data))[0],(void *)&((uint8_t*)(id_of_priority_queue->priority_queue_data))[(priority_queue_size(id_of_priority_queue)-1)*id_of_priority_queue->datatype_size], id_of_priority_queue->datatype_size);   
                id_of_priority_queue->priority_queue_size--;

                size_t left, right, best, index;
                index = 0;
                void *aux = NULL;
                aux = malloc(1*(id_of_priority_queue->datatype_size));
                if(NULL == aux)
                {
                        perror("Memory allocation failed");
                        return false;
                }


                while (1) 
                {
                        left = 2 * index + 1;
                        right = 2 * index + 2;
                        best = index;

                        

                        if(left < priority_queue_size(id_of_priority_queue) && (id_of_priority_queue->compare_func((void *) &((uint8_t*)(id_of_priority_queue->priority_queue_data))[(best)*id_of_priority_queue->datatype_size],(void *) &((uint8_t*)(id_of_priority_queue->priority_queue_data))[(left)*id_of_priority_queue->datatype_size])))
                        {
                                best = left;
                        }

                        if(right < priority_queue_size(id_of_priority_queue) && (id_of_priority_queue->compare_func((void *) &((uint8_t*)(id_of_priority_queue->priority_queue_data))[(best)*id_of_priority_queue->datatype_size],(void *) &((uint8_t*)(id_of_priority_queue->priority_queue_data))[(right)*id_of_priority_queue->datatype_size])))
                        {
                                best = right;
                        }

                        if (best != index) 
                        {

                                memcpy(aux, (void *) &((uint8_t*)(id_of_priority_queue->priority_queue_data))[(index)*id_of_priority_queue->datatype_size], id_of_priority_queue->datatype_size);     
                                memcpy((void *) &((uint8_t*)(id_of_priority_queue->priority_queue_data))[(index)*id_of_priority_queue->datatype_size], (void *) &((uint8_t*)(id_of_priority_queue->priority_queue_data))[(best)*id_of_priority_queue->datatype_size], id_of_priority_queue->datatype_size);     
                                memcpy((void *) &((uint8_t*)(id_of_priority_queue->priority_queue_data))[(best)*id_of_priority_queue->datatype_size],aux, id_of_priority_queue->datatype_size);
                                index = best;
                        }
                        else 
                        {
                                break;
                        }
                }

                free(aux);

                return true;
        }


        return false;
}



/******************************************************************
*
* FUNCTION NAME: priority_queue_push        
*
* PURPOSE: Pushes an element to the priority queue 
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	                I/O	DESCRIPTION
* --------              ----                    ---     ------------
* id_of_priority_queue  priority_queue_t*	I	pointer to the memory position of the priority queue to which the element is being push to
* data_to_push          const void*	        I	pointer to the memory position of the data to push into the priority queue
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool priority_queue_push(priority_queue_t* id_of_priority_queue,const void* data_to_push)
{

       /* LOCAL VARIABLES:
        *  Variable     Type    Description
        *  --------     ----    -----------
        *  queue_aux    void*   auxiliary pointer for the realloc operation
        */
        if(NULL == id_of_priority_queue)
        {
                fprintf(stderr, "Priority queue pointer location is null\n");
                return false;
        }
        if(UINT64_MAX == id_of_priority_queue->priority_queue_size)
        {
                fprintf(stderr, "Priority queue full, can't add more elements\n");
                return false;
        }
        if(NULL == data_to_push)
        {
                fprintf(stderr, "Data pointer is null\n");
                return false;
        }




        id_of_priority_queue->priority_queue_size++;

        // reallocate memory if num of elements in priority_queue becomes larger than the max num of elements allocated for the priority_queue 
        if(id_of_priority_queue->priority_queue_size > id_of_priority_queue->priority_queue_size_allocated)
        {
                void* priority_queue_aux = NULL;
                // tries to allocate double the size of the current priority_queue;
                if(1 == id_of_priority_queue->k_aux)
                {
                        priority_queue_aux = realloc(id_of_priority_queue->priority_queue_data, (id_of_priority_queue->priority_queue_size_allocated + id_of_priority_queue->priority_queue_size_allocated)*id_of_priority_queue->datatype_size);                 
                        if(NULL != priority_queue_aux)                   // this is not needed, and could be placed after the while, however the shift left is a bit faster than the addition
                        {
                                id_of_priority_queue->priority_queue_size_allocated <<= 1;                        
                        }
                }
                else
                {
                        while (NULL == priority_queue_aux)
                        {
                                perror("Memory reallocation failed");
                                printf("Attempting smaller reallocation\n");
                                id_of_priority_queue->k_aux <<= 1;                              // always times 2 (TODO: might be faster to shift at the end again, and add 1 (check the lim->))
                                 
                                if(0 == (id_of_priority_queue->priority_queue_size_allocated/(id_of_priority_queue->k_aux)))
                                {
                                        fprintf(stderr, "Impossible to reallocate priority_queue\n");
                                        //perror("Impossible to reallocate priority_queue");
                                        return false;
                                }
                                priority_queue_aux = realloc(id_of_priority_queue->priority_queue_data, (id_of_priority_queue->priority_queue_size_allocated + (id_of_priority_queue->priority_queue_size_allocated / (id_of_priority_queue->k_aux)))*id_of_priority_queue->datatype_size);
                        }

                        id_of_priority_queue->priority_queue_size_allocated += (id_of_priority_queue->priority_queue_size_allocated/(id_of_priority_queue->k_aux));          

                }
                
                id_of_priority_queue->priority_queue_data = priority_queue_aux;
        }

        memcpy((void *) &((uint8_t*)(id_of_priority_queue->priority_queue_data))[(id_of_priority_queue->priority_queue_size-1)*id_of_priority_queue->datatype_size], data_to_push, id_of_priority_queue->datatype_size);


        size_t index = id_of_priority_queue->priority_queue_size - 1;
        void *aux = NULL;
        aux = malloc(1*id_of_priority_queue->datatype_size);
        
        

        while (index > 0) 
        {
                size_t parent = (index - 1) / 2;
                
                if(id_of_priority_queue->compare_func((void *) &((uint8_t*)(id_of_priority_queue->priority_queue_data))[(parent)*id_of_priority_queue->datatype_size],(void *) &((uint8_t*)(id_of_priority_queue->priority_queue_data))[(index)*id_of_priority_queue->datatype_size]))
                {
                        
                        memcpy(aux, (void *) &((uint8_t*)(id_of_priority_queue->priority_queue_data))[(index)*id_of_priority_queue->datatype_size], id_of_priority_queue->datatype_size);     
                        memcpy((void *) &((uint8_t*)(id_of_priority_queue->priority_queue_data))[(index)*id_of_priority_queue->datatype_size], (void *) &((uint8_t*)(id_of_priority_queue->priority_queue_data))[(parent)*id_of_priority_queue->datatype_size], id_of_priority_queue->datatype_size);     
                        memcpy((void *) &((uint8_t*)(id_of_priority_queue->priority_queue_data))[(parent)*id_of_priority_queue->datatype_size],aux, id_of_priority_queue->datatype_size);
                       
                        index = parent;
                } 
                else
                {
                        break;
                }
        }

        free(aux);

        return true;
}



/******************************************************************
*
* FUNCTION NAME: priority_queue_is_empty
*
* PURPOSE: Checks if the priority queue is empty or not
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	                I/O	DESCRIPTION
* --------              ----                    ---     ------------
* id_of_priority_queue  const priority_queue_t*	I	pointer to the memory position of the priority queue to check
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool priority_queue_is_empty(const priority_queue_t* id_of_priority_queue)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_priority_queue)
        {
                fprintf(stderr, "Queue pointer location is null\n");
                return false;
        }
                
        if(0 == id_of_priority_queue->priority_queue_size)
                return true;
        else
                return false;


}


/******************************************************************
*
* FUNCTION NAME: priority_queue_size
*
* PURPOSE: Will return the current element count in the queue
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	                I/O	DESCRIPTION
* --------              ----                    ---     ------------
* id_of_priority_queue  const priority_queue_t*	I	pointer to the memory position of the priority queue to check
*
* RETURNS: size_t
*
*
*
*****************************************************************/
size_t priority_queue_size(const priority_queue_t* id_of_priority_queue)
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

        return id_of_priority_queue->priority_queue_size;



}

/******************************************************************
*
* FUNCTION NAME: free_priority_queue
*
* PURPOSE: Frees the memory allocated for the priority queue
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	                I/O	DESCRIPTION
* --------              ----                    ---     ------------
* id_of_priority_queue  priority_queue_t*	I	pointer to the memory position of the priority queue to free
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_priority_queue(priority_queue_t* id_of_priority_queue)
{

        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_priority_queue)
                return;

        if(NULL != id_of_priority_queue->priority_queue_data)
                free(id_of_priority_queue->priority_queue_data);
        
        free(id_of_priority_queue);
        return;


}