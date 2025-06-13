
/*******************************************************************************************************
* NAME: graph.h                                                                    
*                                                                                                       
* PURPOSE: This file defines the function prototypes for a graph implementation                                                                       
*                                                                                                       
* GLOBAL VARIABLES: None                                                                                
*                                                                                                       
*                                                                                                       
* DEVELOPMENT HISTORY:                                                                                  
*                                                                                                       
* Date          Author          Change Id       Release         Description Of Change                   
* ----------    --------------- ---------       -------         -----------------------------------     
* 13-06-2025    Tiago Rodrigues                       1         File preparation     
*                                                                                                      
*******************************************************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

/* 0 copyright/licensing */
/*******************************************************************************************************
*
* 2025 Tiago Filipe Rodrigues tiagorodrigues1590@hotmail.com
*
********************************************************************************************************/

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
* FUNCTION NAME: create_graph 
*
* PURPOSE: Allocates the needed memory for the graph wanted
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* --------              ----            ---     ------------
* id_of_graph	        void**	        I/O	pointer to the memory position of the graph to implement
* size_of_datatype      uint64_t        I       byte size of datatype to place in the graph
* nodes_to_allocate     uint64_t        I       number of elements to initially allocate for the graph
*
* RETURNS: void
*
*
*
*****************************************************************/
void create_graph(void** id_of_graph, uint64_t size_of_datatype, uint64_t nodes_to_allocate);           // send the size of values;


/******************************************************************
*
* FUNCTION NAME: add_edge_graph       
*
* PURPOSE: Adds an edge to the graph
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* id_of_graph	        void*	        I/O	pointer to the memory position of the graph
* weight                void*	        I	pointer to the memory position of the weight to add to the graph
* size_of_datatype      uint64_t        I       byte size of weight to place in the graph
* source	        void*	        I	pointer to the memory position of the source node
* destination	        void*	        I	pointer to the memory position of the destination node
* undirected            uint8_t         I       defines if the edge is or isn't undirected
*
* RETURNS: void
*
*
*
*****************************************************************/
void add_edge_graph(void* id_of_graph, void *weight, uint64_t size_of_weight, void* source, void* destination, uint8_t undirected);

/******************************************************************
*
* FUNCTION NAME: remove_edge_graph       
*
* PURPOSE: Removes an edge to the graph
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* id_of_graph	        void*	        I/O	pointer to the memory position of the graph
* source	        void*	        I	pointer to the memory position of the source node
* destination	        void*	        I	pointer to the memory position of the destination node
* undirected            uint8_t         I       defines if both directions should be removed
*
* RETURNS: void
*
*
*
*****************************************************************/
void remove_edge_graph(void* id_of_graph, void* source, void* destination, uint8_t undirected);




/******************************************************************
*
* FUNCTION NAME: free_graph
*
* PURPOSE: Frees the memory allocated for the graph
*
* ARGUMENTS:
*
* ARGUMENT 	TYPE	        I/O	DESCRIPTION
* --------	-------------	---	--------------------------
* id_of_graph   void*	        I	pointer to the memory position of the graph to free
*
*
* RETURNS: void
*
*
*
*****************************************************************/
void free_graph(void* id_of_graph);



#ifdef __cplusplus
}
#endif


#endif

