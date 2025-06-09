/*******************************************************************************************************
* NAME: set.h                                                              
*                                                                                                       
* PURPOSE: This file defines the function prototypes for a set implementation                                                                      
*                                                                                                       
* GLOBAL VARIABLES: None                                                                                
*                                                                                                       
*                                                                                                       
* DEVELOPMENT HISTORY:                                                                                  
*                                                                                                       
* Date          Author          Change Id       Release         Description Of Change                   
* ----------    --------------- ---------       -------         -----------------------------------     
* 03-06-2025    Tiago Rodrigues                       1         File preparation     
*
*                                                                                                      
*******************************************************************************************************/

#ifndef SET_H
#define SET_H


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
void create_set(void** id_of_set, uint64_t size_of_datatype, uint64_t elements_to_allocate,int8_t (*compare_func)(void* val1, void* val2),uint64_t (*hash_function)(void* val));

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
void set_insert(void* id_of_set, void* data_to_insert);

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
void set_erase(void* id_of_set, void* element_to_erase);

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
uint8_t set_contains(void* id_of_set, void* element_to_check);

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
uint8_t check_set_is_empty(void* id_of_set);

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
uint64_t check_set_size(void* id_of_set);


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
void free_set(void* id_of_set);





#ifdef __cplusplus
}
#endif


#endif












