
/*******************************************************************************************************
* NAME: circularsinglelinkedlist.h                                                                        
*                                                                                                       
* PURPOSE: Defines a general template for circular single linked lists, including                                
* the different needed functions                                                                        
*                                                                                                       
* GLOBAL VARIABLES: None                                                                                
*                                                                                                       
*                                                                                                       
* DEVELOPMENT HISTORY:                                                                                  
*                                                                                                       
* Date          Author          Change Id       Release         Description Of Change                   
* ----------    --------------- ---------       -------         -----------------------------------     
* 02-06-2025    Tiago Rodrigues                       1         Initial commit 
*                                                                                                       
*******************************************************************************************************/
#ifndef CIRCULARSINGLELINKEDLIST_H
#define CIRCULARSINGLELINKEDLIST_H

/* 0 copyright/licensing */
/**********************************************************************
*
* 2024 Tiago Filipe Rodrigues tiagorodrigues1590@hotmail.com
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
* FUNCTION NAME: create_node_csll       
*
* PURPOSE: Allocates the needed memory for a node of the singly linked list
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* node	        void**	        I/O	pointer to the memory position of the node to allocate
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void create_node_csll(void** node);


/******************************************************************
*
* FUNCTION NAME: give_node_value_csll       
*
* PURPOSE: Allocates and gives a value to a node already allocated
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* node	                void*	        I/O	pointer to the memory position of the node
* value1                void*	        I	pointer to the memory position of the data to push into the node
* size_of_datatype      uint64_t        I       byte size of datatype to place in the node
*
* RETURNS: void
*
*
*
*****************************************************************/
void give_node_value_csll(void* node, void *value1, uint64_t size_of_datatype);


/******************************************************************
*
* FUNCTION NAME: add_node_to_head_csll       
*
* PURPOSE: Adds a node to the head of a linked list
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* head	                void**	        I/O	pointer to the memory position of the head of the list
* node                  void*	        I	pointer to the memory position of the node to add to the list
*
* RETURNS: void
*
*
*
*****************************************************************/
void add_node_to_head_csll(void** head, void* node);



/******************************************************************
*
* FUNCTION NAME: add_node_to_tail_csll       
*
* PURPOSE: Adds a node to the tail of a linked list
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* head	                void**	        I/O	pointer to the memory position of the head of the list
* node                  void*	        I	pointer to the memory position of the node to add to the list
*
* RETURNS: void
*
*
*
*****************************************************************/
void add_node_to_tail_csll(void** head, void* node);                  // ** needed in case head in null


/******************************************************************
*
* FUNCTION NAME: add_node_in_index_n_csll       
*
* PURPOSE: Adds a node to index n of a linked list
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* head	                void**	        I/O	pointer to the memory position of the head of the list
* node                  void*	        I	pointer to the memory position of the node to add to the list
* position              uint64_t        I       position to add node to the linked list
*
* RETURNS: void
*
*
*
*****************************************************************/
void add_node_in_index_n_csll(void** head, void* node, uint64_t position);


/******************************************************************
*
* FUNCTION NAME: remove_head_node_csll       
*
* PURPOSE: removes the head of a linked list
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* head	                void**	        I/O	pointer to the memory position of the head of the list
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void remove_head_node_csll(void** head);

/******************************************************************
*
* FUNCTION NAME: remove_tail_node_csll       
*
* PURPOSE: removes the tail of a linked list
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* head	                void**	        I/O	pointer to the memory position of the head of the list
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void remove_tail_node_csll(void** head);

/******************************************************************
*
* FUNCTION NAME: remove_node_in_index_n_csll       
*
* PURPOSE: removes node at index n of a linked list
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* head	                void**	        I/O	pointer to the memory position of the head of the list
* position              uint64_t        I       position to remove node in the linked list
*
* RETURNS: void
*
*
*
*****************************************************************/
void remove_node_in_index_n_csll(void** head, uint64_t position);

/******************************************************************
*
* FUNCTION NAME: next_node_csll       
*
* PURPOSE: changes pointer to the next node of that pointer
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* node	                void**	        I/O	pointer to the memory position of the node
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void next_node_csll(void** node);

/******************************************************************
*
* FUNCTION NAME: get_next_node_csll       
*
* PURPOSE: returns a pointer to the next node of a node
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* node	                void*	        I	pointer to the memory position of the node
*
*
* RETURNS: void* (memory position of the next node to the given node )
*
*
*
*****************************************************************/
void* get_next_node_csll(void* node);

/******************************************************************
*
* FUNCTION NAME: get_value_csll       
*
* PURPOSE: Returns the memory position of the value that is currently in the given node
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* node	                void*	        I	pointer to the memory position of the node
*
*
* RETURNS: void* (pointer to the memory position of the value in the node)
*
*
*
*****************************************************************/
void* get_value_csll(void* node);

/******************************************************************
*
* FUNCTION NAME: get_value_in_index_n_csll       
*
* PURPOSE: Returns the memory position of the value that is currently in the node in index n
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* head	                void*	        I	pointer to the memory position of the head of the list
* position              uint64_t        I       position of the node to return value
*
* RETURNS: void* (pointer to the memory position of the value in the node at index n)
*
*
*
*****************************************************************/
void* get_value_in_index_n_csll(void* head, uint64_t n);


// get_head_value;

// get_tail_value;


// void print_list(void* head);


/******************************************************************
*
* FUNCTION NAME: free_linked_list_csll       
*
* PURPOSE: frees a linked list
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* head	                void**	        I/O	pointer to the memory position of the head of the list
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_linked_list_csll(void** head);


/*****************************************************/



/* 7 function declarations */
/*****************************************************/

/*****************************************************/


#ifdef __cplusplus
}
#endif


#endif

























