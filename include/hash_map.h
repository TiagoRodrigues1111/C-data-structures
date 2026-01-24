/*******************************************************************************************************
* NAME: hash_map.h                                                              
*                                                                                                       
* PURPOSE: This file defines the function prototypes for a hash map implementation                                                                      
*                                                                                                       
* GLOBAL VARIABLES: None                                                                                
*                                                                                                       
*                                                                                                       
* DEVELOPMENT HISTORY:                                                                                  
*                                                                                                       
* Date          Author          Change Id       Release         Description Of Change                   
* ----------    --------------- ---------       -------         -----------------------------------     
* 09-06-2025    Tiago Rodrigues                       1         File preparation   
* 18-01-2026    Tiago Rodrigues                       2         Changed functions for opaqueness  
*
*                                                                                                      
*******************************************************************************************************/

#ifndef HASH_MAP_H
#define HASH_MAP_H


/* 0 copyright/licensing */
/**********************************************************************
*
* 2025 Tiago Filipe Rodrigues tiagorodrigues1590@hotmail.com
*
***********************************************************************/

#ifdef __cplusplus
extern "C" {
#endif



/* 1 includes */
/*****************************************************/
#include <stdint.h>
#include <stddef.h>
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
typedef struct hash_map hash_map_t;

/*****************************************************/

/* 5 global variable declarations */
/*****************************************************/


/*****************************************************/


/* 6 function prototypes */
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
hash_map_t* create_hash_map(size_t size_of_key_datatype, size_t size_of_value_datatype, size_t elements_to_allocate, bool (*compare_func)(const void* val1, const void* val2), size_t (*hash_function)(const void* val));

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
bool hash_map_insert(hash_map_t* id_of_hash_map, const void* key_to_insert, const void* value_to_insert);

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
bool hash_map_erase(hash_map_t* id_of_hash_map, const void* key_to_erase);

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
bool hash_map_contains(const hash_map_t* id_of_hash_map, const void* key_to_check);

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
bool hash_map_get_value(const hash_map_t* id_of_hash_map, const void* key, void* value_out);

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
bool hash_map_is_empty(const hash_map_t* id_of_hash_map);

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
size_t hash_map_size(const hash_map_t* id_of_hash_map);

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
void free_hash_map(hash_map_t* id_of_hash_map);





#ifdef __cplusplus
}
#endif


#endif












