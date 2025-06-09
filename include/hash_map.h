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
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------              ----            ---     ------------
* id_of_hash_map        void**	        I/O	pointer to the memory position of the hash map to implement
* size_of_datatype      uint64_t        I       byte size of datatype to place in the hash map
* elements_to_allocate  uint64_t        I       number of elements to allocate for the hash map
* compare_func          function        I       function to compare presence of element in the hash map
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void create_hash_map(void** id_of_hash_map, uint64_t size_of_datatype, uint64_t elements_to_allocate,int8_t (*compare_func)(void* val1, void* val2),uint64_t (*hash_function)(void* val));

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
* id_of_hash_map        void*	        I	pointer to the memory position of the hash map to insert into
* data_to_insert        void*	        I	pointer to the memory position of the key to insert into the hash map
* value_to_insert       void*           I       pointer to the memory position of the value to insert into the hash map
*
* RETURNS: void
*
*
*
*****************************************************************/
void hash_map_insert(void* id_of_hash_map, void* key_to_insert,void* value_to_insert);

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
* id_of_hash_map        void*	        I	pointer to the memory position of the hash map to erase from
* key_to_erase          void*	        I	pointer to the memory position of the key to erase from the hash map
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void hash_map_erase(void* id_of_hash_map, void* key_to_erase);

/******************************************************************
*
* FUNCTION NAME: hash_map_contains        
*
* PURPOSE: Checks if a hash map contains an element
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------	        -------------	---	--------------------------
* id_of_hash_map        void*	        I	pointer to the memory position of the hash map
* key_to_check          void*	        I	pointer to the memory position of the key to check if exists
*
*
* RETURNS: uint8_t
*
*
*
*****************************************************************/
uint8_t hash_map_contains(void* id_of_hash_map, void* key_to_check);


/******************************************************************
*
* FUNCTION NAME: hash_map_get_value       
*
* PURPOSE: Returns the memory position of the value that corresponds to a key
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------              ----            ---     ------------
* id_of_hash_map        void*	        I	pointer to the memory position of the stack to check
* key                   void*	        I	pointer to the memory position of the key
*
* RETURNS: void* (pointer to the memory position of the value that corresponds to a key)
*
*
*
*****************************************************************/
void* hash_map_get_value(void* id_of_hash_map, void* key);



/******************************************************************
*
* FUNCTION NAME: check_hash_map_is_empty
*
* PURPOSE: Checks if the hash map is empty or not
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------	        -------------	---	--------------------------
* id_of_hash_map        void*	        I	pointer to the memory position of the hash map to check
*
*
* RETURNS: uint8_t
*
*
*
*****************************************************************/
uint8_t check_hash_map_is_empty(void* id_of_hash_map);

/******************************************************************
*
* FUNCTION NAME: check_hash_map_size
*
* PURPOSE: Will return the current element count in the hash map
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------	        -------------	---	--------------------------
* id_of_hash_map        void*	        I	pointer to the memory position of the hash map to check
*
*
* RETURNS: uint64_t (size of the hash map)
*
*
*
*****************************************************************/
uint64_t check_hash_map_size(void* id_of_hash_map);


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
* id_of_hash_map        void*	        I	pointer to the memory position of the hash map to free
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_hash_map(void* id_of_hash_map);





#ifdef __cplusplus
}
#endif


#endif












