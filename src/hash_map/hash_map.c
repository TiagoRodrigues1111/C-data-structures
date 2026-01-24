
/*******************************************************************************************************************
* FILE NAME: hash_map.c  
*                                                                                                               
* PURPOSE: This file defines the function prototypes for a hash map implementation     
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
*  It is assumed that the hash map will never have more than 2^64 elements.                               
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
* 09-06-2025    Tiago Rodrigues                         1               File preparation
* 24-01-2026    Tiago Rodrigues                         2               Changed functions for opaqueness    
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
#include "hash_map.h"

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
        void *key;
        void *value;
        struct bucket *next;
};



struct hash_map
{
        size_t hash_map_size;
        size_t hash_map_size_allocated;                    // num_of_elements
        size_t key_datatype_size;                         // num_of_bytes
        size_t value_datatype_size;                         // num_of_bytes
        size_t k_aux;                                 // auxiliary 4 bytes for reallocation      
        // uint64_t load_factor;                        // could give the user the ability to choose his load factor                                       
        struct bucket **hash_map_data_buckets;
        bool (*compare_func)(const void* val1,const  void* val2);
        size_t (*hash_function)(const void* val);
};


/*****************************************************/


/* 6 function prototypes */
/*****************************************************/

// uint64_t hash_function(void* data);

void resize_hash_map(hash_map_t* id_of_hash_map);
void* hash_map_contains_location(hash_map_t* id_of_hash_map,const void* key_to_check);

/*****************************************************/



/* 7 function declarations */
/*****************************************************/




/******************************************************************
*
* FUNCTION NAME: create_hash_map
*
* PURPOSE: Allocates the needed memory for the hash map wanted
*
* ARGUMENTS:
*
* ARGUMENT 	                TYPE	        I/O	DESCRIPTION
* --------                      ----            ---     ------------
* size_of_key_datatype          size_t          I       byte size of key datatype to place in the hash map
* size_of_value_datatype        size_t          I       byte size of value datatype to place in the hash map
* elements_to_allocate          size_t          I       number of elements to allocate for the hash map
* compare_func                  function        I       function to compare presence of element in the hash map
* hash_function                 function        I       function to hash the key to place in the hash map
*
* RETURNS: hash_map_t*
*
*
*
*****************************************************************/
hash_map_t* create_hash_map(size_t size_of_key_datatype, size_t size_of_value_datatype, size_t elements_to_allocate, bool (*compare_func)(const void* val1, const void* val2), size_t (*hash_function)(const void* val))
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  i            uint64_t        Simple increment variable
        * 
        */
        hash_map_t* id_of_hash_map = NULL;

        // Allocation of a priority_queue struct
        id_of_hash_map = malloc(1*sizeof(struct hash_map));                       
        if(NULL == id_of_hash_map)
        {
                perror("Memory allocation failed");
                return NULL;
        }

        if(0 == elements_to_allocate)
                id_of_hash_map->hash_map_size_allocated = INITIAL_ALLOC;      // assumed that the number of elements to allocate initially is INITIAL_ALLOC (3 by default)
        else
                id_of_hash_map->hash_map_size_allocated = elements_to_allocate;

        id_of_hash_map->hash_map_size = 0;
        id_of_hash_map->key_datatype_size = size_of_key_datatype;
        id_of_hash_map->value_datatype_size = size_of_value_datatype;
        id_of_hash_map->k_aux = 1;
        id_of_hash_map->compare_func = compare_func;
        id_of_hash_map->hash_function = hash_function;
        // Allocate space in the priority_queue for the array of values
        id_of_hash_map->hash_map_data_buckets = (struct bucket**) malloc(id_of_hash_map->hash_map_size_allocated*sizeof(struct bucket*));     
        if(NULL == id_of_hash_map->hash_map_data_buckets)
        {
                perror("Memory allocation failed");
                return NULL;
        }
        for(uint64_t i = 0; i < id_of_hash_map->hash_map_size_allocated; i++)
        {
                id_of_hash_map->hash_map_data_buckets[i] = NULL;
        }


        
        return id_of_hash_map;        
}

/******************************************************************
*
* FUNCTION NAME: hash_map_insert        
*
* PURPOSE: Inserts an element into the hash map
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------	        -------------	---	--------------------------
* id_of_hash_map        hash_map_t*	I	pointer to the memory position of the hash map to insert into
* key_to_insert         const void*	I	pointer to the memory position of the key to insert into the hash map
* value_to_insert       const void*	I	pointer to the memory position of the value to insert into the hash map
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool hash_map_insert(hash_map_t* id_of_hash_map, const void* key_to_insert, const void* value_to_insert)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  idx          uint64_t        index of the bucket to add the new element
        *  new_entry    struct bucket*  helps allocate the memory to the new data to insert   
        */
        if(NULL == id_of_hash_map)
        {
                fprintf(stderr, "Hash map pointer location is null\n");
                return false;
        }
        if(UINT64_MAX == hash_map_size(id_of_hash_map))
        {
                fprintf(stderr, "Hash map full, can't add more elements\n");
                return false;
        }
        if(NULL == key_to_insert)
        {
                fprintf(stderr, "Key pointer is null\n");
                return false;
        }
        if(NULL == value_to_insert)
        {
                fprintf(stderr, "Value pointer is null\n");
                return false;
        }


        struct bucket *new_entry = NULL;

        new_entry = hash_map_contains_location(id_of_hash_map, key_to_insert);
        if (NULL != new_entry) 
        {
                memcpy(new_entry->value, value_to_insert, id_of_hash_map->value_datatype_size);       
                return true; 
        }
        
        uint64_t idx = id_of_hash_map->hash_function(key_to_insert) % id_of_hash_map->hash_map_size_allocated;
        
        

        new_entry = malloc(1* sizeof(struct bucket));
        if(NULL == new_entry)
        {
                perror("Memory allocation failed");
                return false;
        }


        new_entry->key = malloc(1*(id_of_hash_map->key_datatype_size));
        if(NULL == new_entry->key)
        {
                perror("Memory allocation failed");
                return false;
        }
        memcpy(new_entry->key, key_to_insert, id_of_hash_map->key_datatype_size);       
        new_entry->next = id_of_hash_map->hash_map_data_buckets[idx];
   

        new_entry->value = malloc(1*(id_of_hash_map->value_datatype_size));
        if(NULL == new_entry->value)
        {
                perror("Memory allocation failed");
                return false;
        }
        memcpy(new_entry->value, value_to_insert, id_of_hash_map->value_datatype_size);       
        new_entry->next = id_of_hash_map->hash_map_data_buckets[idx];
   

        id_of_hash_map->hash_map_data_buckets[idx] = new_entry;
        id_of_hash_map->hash_map_size++;

        resize_hash_map(id_of_hash_map);

        return true;        
}

/******************************************************************
*
* FUNCTION NAME: hash_map_erase        
*
* PURPOSE: Erases an element from the hash map
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------	        -------------	---	--------------------------
* id_of_hash_map        hash_map_t*	I	pointer to the memory position of the hash map to erase from
* key_to_erase          const void*	I	pointer to the memory position of the key to erase from the hash map
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool hash_map_erase(hash_map_t* id_of_hash_map, const void* key_to_erase)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  idx          uint64_t        index of the bucket to add the new element
        *  element      struct bucket*  pointer to the bucket
        *  prev         struct bucket*  auxiliary pointer to the previous bucket in the bucket linked list
        */
        if(NULL == id_of_hash_map)
        {
                fprintf(stderr, "Hash map pointer location is null\n");
                return false;
        }
        if(NULL == key_to_erase)
        {
                fprintf(stderr, "Key pointer is null\n");
                return false;
        }


        uint64_t idx = id_of_hash_map->hash_function(key_to_erase) % id_of_hash_map->hash_map_size_allocated;

        struct bucket *element = id_of_hash_map->hash_map_data_buckets[idx];
        struct bucket *prev = NULL;

        while (element) 
        {
            if (true == id_of_hash_map->compare_func(element->key, key_to_erase)) 
            {
                if (NULL != prev) 
                        prev->next = element->next;
                else 
                        id_of_hash_map->hash_map_data_buckets[idx] = element->next;
                
                free(element->key);
                free(element->value);
                free(element);
                id_of_hash_map->hash_map_size--;
                return true;
            }
            prev = element;
            element = element->next;
        }

        return false;
}

/******************************************************************
*
* FUNCTION NAME: hash_map_contains        
*
* PURPOSE: Checks if a hash map contains an element
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	                I/O	DESCRIPTION
* --------	        -------------	        ---	--------------------------
* id_of_hash_map        const hash_map_t*	I	pointer to the memory position of the hash map
* key_to_check          const void*	        I	pointer to the memory position of the key to check if exists
*
*
* RETURNS: bool
*
*
*****************************************************************/
bool hash_map_contains(const hash_map_t* id_of_hash_map, const void* key_to_check)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  idx          uint64_t        index of the bucket to add the new element
        *  bucket_aux   struct bucket*  pointer to the bucket
        *
        */
        if(NULL == id_of_hash_map)
        {
                fprintf(stderr, "Hash map pointer location is null\n");
                return false;
        }
        if(NULL == key_to_check)
        {
                fprintf(stderr, "Key pointer is null\n");
                return false;
        }

        uint64_t idx = id_of_hash_map->hash_function(key_to_check) % id_of_hash_map->hash_map_size_allocated;
        struct bucket *bucket_aux = (id_of_hash_map->hash_map_data_buckets[idx]);
        while (NULL != bucket_aux) {
            if (true == id_of_hash_map->compare_func(bucket_aux->key, key_to_check)) 
                return true;
            bucket_aux = bucket_aux->next;
        }
        return false;
}

/******************************************************************
*
* FUNCTION NAME: hash_map_get_value       
*
* PURPOSE: Returns the memory position of the value that corresponds to a key
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	                I/O	DESCRIPTION
* --------              ----                    ---     ------------
* id_of_hash_map        const hash_map_t*	I	pointer to the memory position of the hash map
* key                   const void*	        I	pointer to the memory position of the key
* value_out             void*	                O	pointer to the memory position where the value will be copied
*
* RETURNS: bool (true if the key exists, false otherwise)
*
*
*****************************************************************/
bool hash_map_get_value(const hash_map_t* id_of_hash_map, const void* key, void* value_out)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  idx          uint64_t        index of the bucket to add the new element
        *  bucket_aux   struct bucket*  pointer to the bucket
        *
        */
        if(NULL == id_of_hash_map)
        {
                fprintf(stderr, "Hash map pointer location is null\n");
                return false;
        }
        if(NULL == key)
        {
                fprintf(stderr, "Key pointer is null\n");
                return false;
        }

        uint64_t idx = id_of_hash_map->hash_function(key) % id_of_hash_map->hash_map_size_allocated;
        struct bucket *bucket_aux = (id_of_hash_map->hash_map_data_buckets[idx]);
        
        while (NULL != bucket_aux) 
        {
                if (true == id_of_hash_map->compare_func(bucket_aux->key, key)) 
                {
                        memcpy(value_out, bucket_aux->value, id_of_hash_map->value_datatype_size);
                        return true;
                }
            bucket_aux = bucket_aux->next;
        }
        return false;
}

/******************************************************************
*
* FUNCTION NAME: hash_map_is_empty
*
* PURPOSE: Checks if the hash map is empty or not
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	                I/O	DESCRIPTION
* --------	        -------------	---	--------------------------
* id_of_hash_map        const hash_map_t*	I	pointer to the memory position of the hash map to check
*
*
* RETURNS: bool
*
*
*
*****************************************************************/
bool hash_map_is_empty(const hash_map_t* id_of_hash_map)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_hash_map)
        {
                fprintf(stderr, "set pointer location is null\n");
                return false;
        }

        if(0 == id_of_hash_map->hash_map_size)
                return true;
        else
                return false;
}

/******************************************************************
*
* FUNCTION NAME: hash_map_size
*
* PURPOSE: Will return the current element count in the hash map
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	                I/O	DESCRIPTION
* --------	        -------------	        ---	--------------------------
* id_of_hash_map        const hash_map_t*	I	pointer to the memory position of the hash map to check
*
*
* RETURNS: size_t (size of the hash map)
*
*
*
*****************************************************************/
size_t hash_map_size(const hash_map_t* id_of_hash_map)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_hash_map)
        {
                fprintf(stderr, "Hash map pointer location is null\n");
                return 0;
        }

        return id_of_hash_map->hash_map_size;
}

/******************************************************************
*
* FUNCTION NAME: free_hash_map
*
* PURPOSE: Frees the memory allocated for the hash map
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------              ----            ---     ------------
* id_of_hash_map        hash_map_t*	I	pointer to the memory position of the hash map to free
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_hash_map(hash_map_t* id_of_hash_map)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  i            uint64_t        Simple increment variable
        *  aux          struct bucket*  auxiliary pointer to current bucket being freed
        *  aux_next     struct bucket*  auxiliary pointer to next bucket
        */
        if(NULL == id_of_hash_map)
                return;

        for(size_t i=0;i<id_of_hash_map->hash_map_size_allocated;i++)
        {
                struct bucket *aux = id_of_hash_map->hash_map_data_buckets[i];
                while(NULL != aux)
                {
                        struct bucket *aux_next = aux->next;
                        
                        free(aux->key);
                        free(aux->value);
                        free(aux);
                        
                        aux = aux_next;

                }
        }
        free(id_of_hash_map);
        return ;
}



/******************************************************************
*
* FUNCTION NAME: resize_hash_map
*
* PURPOSE: Resizes a hash map, whenever it gets too full
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------              ----            ---     ------------
* id_of_hash_map        hash_map_t*	I	pointer to the memory position of the hash map to resize
*
* RETURNS: void
*
*
*
*****************************************************************/
void resize_hash_map(hash_map_t* id_of_hash_map)
{
        /* LOCAL VARIABLES:
        *  Variable             Type            Description
        *  --------             ----            -----------
        *  hash_map_bucket_aux       struct bucket** auxiliary pointer to new memory position to place the hash map 
        *  new_size             uint64_t        holds the new value allocated for the size of the array of buckets 
        *  i                    uint64_t        increment variable
        *  element              struct bucket*  pointer to the current element being sent to the new memory position
        *  next                 struct bucket*  pointer to the next bucket to element
        *  idx                  uint64_t        index of the bucket in the new memory position to place the bucket
        */
        if ((float)(id_of_hash_map->hash_map_size)/(id_of_hash_map->hash_map_size_allocated) < LOAD_FACTOR) 
                return ;



        struct bucket **hash_map_bucket_aux = NULL;
        
        uint64_t new_size = 0;

        // tries to allocate double the size of the current stack;
        if(1 == id_of_hash_map->k_aux)
        {
                hash_map_bucket_aux = (struct bucket**) malloc((id_of_hash_map->hash_map_size_allocated + id_of_hash_map->hash_map_size_allocated)*(sizeof(struct bucket*)));                 
                if(NULL != hash_map_bucket_aux)                   // this is not needed, and could be placed after the while, however the shift left is a bit faster than the addition
                {
                        new_size = id_of_hash_map->hash_map_size_allocated << 1;                        
                }
        }
        else
        {
                while (NULL == hash_map_bucket_aux)
                {
                        perror("Memory reallocation failed");
                        printf("Attempting smaller reallocation\n");
                        id_of_hash_map->k_aux<<=1;                              // always times 2 (TODO: might be faster to shift at the end again, and add 1 (check the lim->))
                         
                        if(0 == (id_of_hash_map->hash_map_size_allocated/id_of_hash_map->k_aux))
                        {
                                fprintf(stderr, "Impossible to reallocate stack\n");
                                //perror("Impossible to reallocate stack");
                                return ;
                        }

                        hash_map_bucket_aux = (struct bucket**) malloc((id_of_hash_map->hash_map_size_allocated + (id_of_hash_map->hash_map_size_allocated / id_of_hash_map->k_aux))*(sizeof(struct bucket*)));
                }

                new_size = id_of_hash_map->hash_map_size_allocated + (id_of_hash_map->hash_map_size_allocated/id_of_hash_map->k_aux);          
        }
        for(uint64_t i = 0; i < new_size; i++)
        {       
                hash_map_bucket_aux[i] = NULL;
        }



        for (uint64_t i = 0; i < id_of_hash_map->hash_map_size_allocated; i++) 
        {

                struct bucket *element = id_of_hash_map->hash_map_data_buckets[i];

                while (NULL != element) 
                {
                    struct bucket *next = element->next;
                    
                    uint64_t idx = id_of_hash_map->hash_function(element->key) % new_size;

                    element->next = hash_map_bucket_aux[idx];
                    hash_map_bucket_aux[idx] = element;
                    element = next;
                }
        }



        free(id_of_hash_map->hash_map_data_buckets);
        id_of_hash_map->hash_map_data_buckets = hash_map_bucket_aux;
        id_of_hash_map->hash_map_size_allocated = new_size;


        return ;
}

/******************************************************************
*
* FUNCTION NAME: hash_map_contains_location        
*
* PURPOSE: Checks if a hash map contains an element, and returns the memory position of the bucket node
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------	        -------------	---	--------------------------
* id_of_hash_map        hash_map_t*	I	pointer to the memory position of the hash map
* key_to_check          const void*	I	pointer to the memory position of the key to check if exists
*
*
* RETURNS: void* (pointer to node bucket)
*
*
*
*****************************************************************/
void* hash_map_contains_location(hash_map_t* id_of_hash_map,const void* key_to_check)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  idx          uint64_t        index of the bucket to add the new element
        *  bucket_aux   struct bucket*  pointer to the bucket
        *
        */
        uint64_t idx = id_of_hash_map->hash_function(key_to_check) % id_of_hash_map->hash_map_size_allocated;
        struct bucket *bucket_aux = id_of_hash_map->hash_map_data_buckets[idx];

        while (NULL != bucket_aux) {
            if (true == id_of_hash_map->compare_func(bucket_aux->key, key_to_check)) 
                return bucket_aux;
            bucket_aux = bucket_aux->next;
        }
        return NULL;
}




/*****************************************************/







