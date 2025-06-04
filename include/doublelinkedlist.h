
/*******************************************************************************************************
* NAME: doublelinkedlist.h                                                               
*                                                                                                       
* PURPOSE: Defines a general template for double linked lists, including                                
*           the different needed functions                                                                        
*                                                                                                       
* GLOBAL VARIABLES: None                                                                                
*                                                                                                       
*                                                                                                       
* DEVELOPMENT HISTORY:                                                                                  
*                                                                                                       
* Date          Author          Change Id       Release         Description Of Change                   
* ----------    --------------- ---------       -------         -----------------------------------      
* 27-01-2025    Tiago Rodrigues                       1         Creation of the repository and changes to prototypes
*                                                                                                       
*
*
*******************************************************************************************************/
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

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
* FUNCTION NAME: create_node_dll       
*
* PURPOSE: Allocates the needed memory for a node of the doubly linked list
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
void create_node_dll(void** node);


/******************************************************************
*
* FUNCTION NAME: give_node_value_dll       
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
void give_node_value_dll(void* node, void *value1, uint64_t size_of_datatype);


/******************************************************************
*
* FUNCTION NAME: add_node_to_head_dll       
*
* PURPOSE: Adds a node to the head of a linked list
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* linked_list_node      void**	        I/O	pointer to the memory position of a node in the list
* node                  void*	        I	pointer to the memory position of the node to add to the list
*
* RETURNS: void
*
*
*
*****************************************************************/
void add_node_to_head_dll(void** linked_list_node, void* node);



/******************************************************************
*
* FUNCTION NAME: add_node_to_tail_dll       
*
* PURPOSE: Adds a node to the tail of a linked list
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* linked_list_node      void**	        I/O	pointer to the memory position of a node in the list
* node                  void*	        I	pointer to the memory position of the node to add to the list
*
* RETURNS: void
*
*
*
*****************************************************************/
void add_node_to_tail_dll(void** linked_list_node, void* node);                  // ** needed in case head in null


/******************************************************************
*
* FUNCTION NAME: add_node_in_index_n_dll       
*
* PURPOSE: Adds a node to index n compared to given node of a linked list
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* linked_list_node      void**	        I/O	pointer to the memory position of a node in the list
* node                  void*	        I	pointer to the memory position of the node to add to the list
* position              int64_t         I       position to add node to the linked list
*
* RETURNS: void
*
*
*
*****************************************************************/
void add_node_in_index_n_dll(void** linked_list_node, void* node, int64_t position);


/******************************************************************
*
* FUNCTION NAME: remove_head_node_dll       
*
* PURPOSE: removes the head of a linked list
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* linked_list_node	void**	        I/O	pointer to the memory position a node in the linked list
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void remove_head_node_dll(void** linked_list_node);

/******************************************************************
*
* FUNCTION NAME: remove_tail_node_dll       
*
* PURPOSE: removes the tail of a linked list
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* linked_list_node	void**	        I/O	pointer to the memory position a node in the linked listt
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void remove_tail_node_dll(void** linked_list_node);

/******************************************************************
*
* FUNCTION NAME: remove_node_in_index_n_dll       
*
* PURPOSE: removes node at index n compared to given node of a linked list
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* linked_list_node	void**	        I/O	pointer to the memory position a node in the linked list
* position              int64_t         I       position to remove node in the linked list
*
* RETURNS: void
*
*
*
*****************************************************************/
void remove_node_in_index_n_dll(void** linked_list_node, int64_t position);

/******************************************************************
*
* FUNCTION NAME: next_node_dll       
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
void next_node_dll(void** node);

/******************************************************************
*
* FUNCTION NAME: get_next_node_dll       
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
void* get_next_node_dll(void* node);


/******************************************************************
*
* FUNCTION NAME: previous_node_dll       
*
* PURPOSE: changes pointer to the previous node of that pointer
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
void previous_node_dll(void** node);

/******************************************************************
*
* FUNCTION NAME: get_previous_node_dll       
*
* PURPOSE: returns a pointer to the previous node of a node
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
void* get_previous_node_dll(void* node);


/******************************************************************
*
* FUNCTION NAME: get_value_dll       
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
void* get_value_dll(void* node);

/******************************************************************
*
* FUNCTION NAME: get_value_in_index_n_dll       
*
* PURPOSE: Returns the memory position of the value that is currently in the node in index n compared to given node
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* linked_list_node	void**	        I/O	pointer to the memory position a node in the linked list
* position              int64_t         I       position of the node to return value
*
* RETURNS: void* (pointer to the memory position of the value in the node at index n)
*
*
*
*****************************************************************/
void* get_value_in_index_n_dll(void* linked_list_node, int64_t n);

// void print_list(void* head);


/******************************************************************
*
* FUNCTION NAME: free_linked_list_dll       
*
* PURPOSE: frees a linked list
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* linked_list_node	void**	        I/O	pointer to the memory position a node in the linked list
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_linked_list_dll(void** linked_list_node);


/*****************************************************/



/* 7 function declarations */
/*****************************************************/

/*****************************************************/


#ifdef __cplusplus
}
#endif


#endif

























