
/*******************************************************************************************************
* NAME: binary_tree.h                                                                        
*                                                                                                       
* PURPOSE: Defines a general template for binary trees, including                                
* the different needed functions                                                                        
*                                                                                                       
* GLOBAL VARIABLES: None                                                                                
*                                                                                                       
*                                                                                                       
* DEVELOPMENT HISTORY:                                                                                  
*                                                                                                       
* Date          Author          Change Id       Release         Description Of Change                   
* ----------    --------------- ---------       -------         -----------------------------------     
* 11-06-2025    Tiago Rodrigues                       1         Prolog and definition of operations     
*                                                                                                       
*******************************************************************************************************/
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

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
* FUNCTION NAME: create_node_bt       
*
* PURPOSE: Allocates the needed memory for a node of the binary tree
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
void create_node_bt(void** node);


/******************************************************************
*
* FUNCTION NAME: give_node_value_bt       
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
void give_node_value_bt(void* node, void *value1, uint64_t size_of_datatype);


/******************************************************************
*
* FUNCTION NAME: add_node_to_left_bt       
*
* PURPOSE: Adds a node to the left of another node
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* parent	        void*	        I/O	pointer to the memory position of the parent node
* child                 void*	        I	pointer to the memory position of the child node
*
* RETURNS: void
*
*
*
*****************************************************************/
void add_node_to_left_bt(void* parent, void* child);



/******************************************************************
*
* FUNCTION NAME: add_node_to_right_bt       
*
* PURPOSE: Adds a node to the right of another node
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* parent	        void*	        I/O	pointer to the memory position of the parent node
* child                 void*	        I	pointer to the memory position of the child node
*
* RETURNS: void
*
*
*
*****************************************************************/
void add_node_to_right_bt(void* parent, void* child);

/******************************************************************
*
* FUNCTION NAME: remove_node_to_left_bt       
*
* PURPOSE: removes the child to the left of a node
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* node	                void*           I/O	pointer to the memory position of the node to remove the its left node
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void remove_node_to_left_bt(void* node);

/******************************************************************
*
* FUNCTION NAME: remove_node_to_right_bt       
*
* PURPOSE: removes the child to the right of a node
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* node	                void*           I/O	pointer to the memory position of the node to remove the its right node
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void remove_node_to_right_bt(void* node);


/******************************************************************
*
* FUNCTION NAME: remove_node_bt       
*
* PURPOSE: removes the current node from a tree
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* node	                void*           I/O	pointer to the memory position of the node to remove
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void remove_node_bt(void* node);


/******************************************************************
*
* FUNCTION NAME: next_left_node_bt       
*
* PURPOSE: changes pointer to the left node of that pointer
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
void next_left_node_bt(void** node);

/******************************************************************
*
* FUNCTION NAME: get_next_left_node_bt       
*
* PURPOSE: returns a pointer to the left node of a node
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* node	                void*	        I	pointer to the memory position of the node
*
*
* RETURNS: void* (memory position of the left node to the given node )
*
*
*
*****************************************************************/
void* get_next_left_node_bt(void* node);

/******************************************************************
*
* FUNCTION NAME: next_right_node_bt       
*
* PURPOSE: changes pointer to the right node of that pointer
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
void next_right_node_bt(void** node);

/******************************************************************
*
* FUNCTION NAME: get_next_right_node_bt       
*
* PURPOSE: returns a pointer to the right node of a node
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* node	                void*	        I	pointer to the memory position of the node
*
*
* RETURNS: void* (memory position of the right node to the given node )
*
*
*
*****************************************************************/
void* get_next_right_node_bt(void* node);

/******************************************************************
*
* FUNCTION NAME: get_value_bt       
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
void* get_value_bt(void* node);



// void print_list(void* head);


/******************************************************************
*
* FUNCTION NAME: free_binary_tree       
*
* PURPOSE: frees a binary tree
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* root	                void**	        I/O	pointer to the memory position of the root of the list
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_binary_tree(void** root);


/*****************************************************/



/* 7 function declarations */
/*****************************************************/

/*****************************************************/


#ifdef __cplusplus
}
#endif


#endif

























