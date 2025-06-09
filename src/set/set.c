
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
#define INITIAL_ALLOC 10
#define LOAD_FACTOR 0.75
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


struct bucket
{
        void *data;
        struct bucket *next;
};



struct set
{
        uint64_t set_size;
        uint64_t set_size_allocated;                    // num_of_elements
        uint64_t datatype_size;                         // num_of_bytes
        uint64_t k_aux;                                 // auxiliary 4 bytes for reallocation      
        // uint64_t load_factor;                        // could give the user the ability to choose his load factor                                       
        struct bucket **set_data_buckets;
        int8_t (*compare_func)(void* val1, void* val2);
        uint64_t (*hash_function)(void* val);
};


/*****************************************************/


/* 6 function prototypes */
/*****************************************************/

// uint64_t hash_function(void* data);

void resize_set(void* id_of_set);

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
* hash_function         function        I       hash function to be used to determine indexes
*
* RETURNS: void
*
*
*
*****************************************************************/
void create_set(void** id_of_set, uint64_t size_of_datatype, uint64_t elements_to_allocate,int8_t (*compare_func)(void* val1, void* val2),uint64_t (*hash_function)(void* val))
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  i            uint64_t        Simple increment variable
        * 
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
        ((struct set*)(*id_of_set))->hash_function = hash_function;

        // Allocate space in the priority_queue for the array of values
        ((struct set*)(*id_of_set))->set_data_buckets = (struct bucket**) malloc(((struct set*)(*id_of_set))->set_size_allocated*sizeof(struct bucket*));     
        if(NULL == ((struct set*)(*id_of_set))->set_data_buckets)
        {
                perror("Memory allocation failed");
                return ;
        }
        for(uint64_t i = 0; i < ((struct set*)(*id_of_set))->set_size_allocated; i++)
        {
                ((struct set*)(*id_of_set))->set_data_buckets[i] = NULL;
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
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  idx          uint64_t        index of the bucket to add the new element
        *  new_entry    struct bucket*  helps allocate the memory to the new data to insert   
        */

        if (1 == set_contains(id_of_set, data_to_insert)) 
                return ; 

        uint64_t idx = ((struct set*)(id_of_set))->hash_function(data_to_insert) % ((struct set*)(id_of_set))->set_size_allocated;
        
        struct bucket *new_entry = NULL;

        new_entry = malloc(1* sizeof(struct bucket));
        if(NULL == new_entry)
        {
                perror("Memory allocation failed");
                return ;
        }


        new_entry->data = malloc(1*((struct set*)(id_of_set))->datatype_size);
        if(NULL == new_entry->data)
        {
                perror("Memory allocation failed");
                return ;
        }
        memcpy(new_entry->data, data_to_insert,((struct set*)(id_of_set))->datatype_size);       
        new_entry->next = (((struct set*)(id_of_set))->set_data_buckets[idx]);
       
    
        
        (((struct set*)(id_of_set))->set_data_buckets[idx]) = new_entry;
        ((struct set*)(id_of_set))->set_size++;

        resize_set(id_of_set);

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
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  idx          uint64_t        index of the bucket to add the new element
        *  element      struct bucket*  pointer to the bucket
        *  prev         struct bucket*  auxiliary pointer to the previous bucket in the bucket linked list
        */

        uint64_t idx = ((struct set*)(id_of_set))->hash_function(element_to_erase) % ((struct set*)(id_of_set))->set_size_allocated;

        struct bucket *element = ((struct set*)(id_of_set))->set_data_buckets[idx];
        struct bucket *prev = NULL;

        while (element) 
        {
            if (0 == ((struct set*)(id_of_set))->compare_func(element->data, element_to_erase)) 
            {
                if (NULL != prev) 
                        prev->next = element->next;
                else 
                        ((struct set*)(id_of_set))->set_data_buckets[idx] = element->next;
                
                free(element->data);
                free(element);
                ((struct set*)(id_of_set))->set_size--;
                return ;
            }
            prev = element;
            element = element->next;
        }

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
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  idx          uint64_t        index of the bucket to add the new element
        *  bucket_aux   struct bucket*  pointer to the bucket
        *
        */

        uint64_t idx = ((struct set*)(id_of_set))->hash_function(element_to_check) % ((struct set*)(id_of_set))->set_size_allocated;
        struct bucket *bucket_aux = (((struct set*)(id_of_set))->set_data_buckets[idx]);
        
        while (NULL != bucket_aux) {
            if (0 == ((struct set*)(id_of_set))->compare_func(bucket_aux->data, element_to_check)) 
                return 1;
            bucket_aux = bucket_aux->next;
        }
        return 0;
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
* id_of_set     void*	        I	pointer to the memory position of the set to check
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
* PURPOSE: Returns the current element count in the set
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* id_of_set     void*	        I	pointer to the memory position of the set to check
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
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  i            uint64_t        Simple increment variable
        *  aux          struct bucket*  auxiliary pointer to current bucket being freed
        *  aux_next     struct bucket*  auxiliary pointer to next bucket
        */
        if(NULL == id_of_set)
                return;


        for(int i=0;i<((struct set*)id_of_set)->set_size_allocated;i++)
        {
                struct bucket *aux = ((struct set*)id_of_set)->set_data_buckets[i];
                while(NULL != aux)
                {
                        struct bucket *aux_next = aux->next;
                        
                        free(aux->data);
                        free(aux);
                        
                        aux = aux_next;

                }
        }

        free(id_of_set);
        return ;
}





/******************************************************************
*
* FUNCTION NAME: hash_function
*
* PURPOSE: 
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------              ----            ---     ------------
* data                  void*           I       data to check hash
*
* RETURNS: uint64_t
*
*
*
*****************************************************************/
// uint64_t hash_function(void* data) 
// {
//         /* LOCAL VARIABLES:
//         *  Variable        Type    Description
//         *  --------        ----    -----------
//         *  None
//         */
//         uint64_t hash = 0;


//         return hash;
// }



/******************************************************************
*
* FUNCTION NAME: resize_set
*
* PURPOSE: Resizes a set, whenever it gets too full
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------              ----            ---     ------------
* id_of_set             void*	        I	pointer to the memory position of the set to resize
*
* RETURNS: void
*
*
*
*****************************************************************/
void resize_set(void* id_of_set) 
{
        /* LOCAL VARIABLES:
        *  Variable             Type            Description
        *  --------             ----            -----------
        *  set_bucket_aux       struct bucket** auxiliary pointer to new memory position to place the set 
        *  new_size             uint64_t        holds the new value allocated for the size of the array of buckets 
        *  i                    uint64_t        increment variable
        *  element              struct bucket*  pointer to the current element being sent to the new memory position
        *  next                 struct bucket*  pointer to the next bucket to element
        *  idx                  uint64_t        index of the bucket in the new memory position to place the bucket
        */
        if ((float)((struct set*)(id_of_set))->set_size/((struct set*)(id_of_set))->set_size_allocated < LOAD_FACTOR) 
                return ;



        struct bucket **set_bucket_aux = NULL;
        
        uint64_t new_size = 0;

        // tries to allocate double the size of the current stack;
        if(1 == ((struct set*)(id_of_set))->k_aux)
        {
                set_bucket_aux = (struct bucket**) malloc((((struct set*)(id_of_set))->set_size_allocated + ((struct set*)(id_of_set))->set_size_allocated)*(sizeof(struct bucket*)));                 
                if(NULL != set_bucket_aux)                   // this is not needed, and could be placed after the while, however the shift left is a bit faster than the addition
                {
                        new_size = ((struct set*)(id_of_set))->set_size_allocated << 1;                        
                }
        }
        else
        {
                while (NULL == set_bucket_aux)
                {
                        perror("Memory reallocation failed");
                        printf("Attempting smaller reallocation\n");
                        ((struct set*)(id_of_set))->k_aux<<=1;                              // always times 2 (TODO: might be faster to shift at the end again, and add 1 (check the lim->))
                         
                        if(0 == (((struct set*)(id_of_set))->set_size_allocated/((struct set*)(id_of_set))->k_aux))
                        {
                                fprintf(stderr, "Impossible to reallocate stack\n");
                                //perror("Impossible to reallocate stack");
                                return ;
                        }
           
                        set_bucket_aux = (struct bucket**) malloc((((struct set*)(id_of_set))->set_size_allocated + (((struct set*)(id_of_set))->set_size_allocated / ((struct set*)(id_of_set))->k_aux))*(sizeof(struct bucket*)));
                }

                new_size = ((struct set*)(id_of_set))->set_size_allocated + (((struct set*)(id_of_set))->set_size_allocated/((struct set*)(id_of_set))->k_aux);          
        }  
        for(uint64_t i = 0; i < new_size; i++)
        {       
                set_bucket_aux[i] = NULL;
        }



        for (uint64_t i = 0; i < ((struct set*)(id_of_set))->set_size_allocated; i++) 
        {

                struct bucket *element = ((struct set*)(id_of_set))->set_data_buckets[i];

                while (NULL != element) 
                {
                    struct bucket *next = element->next;
                    
                    uint64_t idx = ((struct set*)(id_of_set))->hash_function(element->data) % new_size;

                    element->next = set_bucket_aux[idx];
                    set_bucket_aux[idx] = element;
                    element = next;
                }
        }



        free(((struct set*)(id_of_set))->set_data_buckets);
        ((struct set*)(id_of_set))->set_data_buckets = set_bucket_aux;
        ((struct set*)(id_of_set))->set_size_allocated = new_size;


        return ;
}












