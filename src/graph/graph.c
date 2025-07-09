/*******************************************************************************************************************
* FILE NAME: graph.c
*                                                                                                               
* PURPOSE: This file implements the functions defined in graph.h, with an array 
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
* malloc                        allocates memory space                                                          https://man7.org/linux/man-pages/man3/free.3.html
* realloc                       reallocates memory space                                                        https://man7.org/linux/man-pages/man3/realloc.3p.html
* memcpy                        copies x number of bytes from one memory position to another memory position    https://man7.org/linux/man-pages/man3/memcpy.3.html
* fprintf                       writes formatted data to a stream                                               https://man7.org/linux/man-pages/man3/fprintf.3p.html
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
* 08-07-2025    Tiago Rodrigues                               1         File preparation   
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

/* 1.1 Related header */
#include "graph.h"

/* 1.2 C system headers */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* 1.3 C++ standard library headers*/

/* 1.4 other libraries' headers*/

/* 1.5 project's headers */






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
struct node
{
        uint64_t vertex;
        void *weight;        
        void *data;
        struct node* next;
};



struct graph 
{
        uint64_t datatype_size;                         // num_of_bytes
        uint64_t weight_size;                           // num_of_bytes
        int num_of_vertices;
        struct node** adjacency_list;
};


/*****************************************************/


/* 6 function prototypes */
/*****************************************************/
void create_node(void** node, uint64_t vertex, void * weight,uint64_t size_of_weight);


/*****************************************************/



/* 7 function declarations */
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
void create_graph(void** id_of_graph, uint64_t size_of_datatype, uint64_t size_of_weight, uint64_t num_of_vertices)           // send the size of values;
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == id_of_graph)
        {
                fprintf(stderr, "Graph pointer location is null\n");
                return ;
        }
                

        // Allocation of a graph struct
        (*id_of_graph) = malloc(1*sizeof(struct graph));                       
        if(NULL == *id_of_graph)
        {
                perror("Memory allocation failed");
                return ;
        }
        ((struct graph*)(*id_of_graph))->datatype_size= size_of_datatype;
        ((struct graph*)(*id_of_graph))->weight_size = size_of_weight;
        ((struct graph*)(*id_of_graph))->num_of_vertices = num_of_vertices;
        ((struct graph*)(*id_of_graph))->adjacency_list = malloc(num_of_vertices * sizeof(struct node));
        for(uint64_t i=0; i<num_of_vertices;i++)
        {
                ((struct graph*)(*id_of_graph))->adjacency_list[i] = NULL;
        }
        return ;   
}






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
void add_edge_graph(void* id_of_graph, void *weight, void* source, void* destination, uint8_t undirected)
{
        // For now, simple example
        uint64_t src = *(uint64_t*)source;
        uint64_t dest = *(uint64_t*)destination;
        struct node *new_node = NULL;

        create_node((void **)&new_node, dest, weight,((struct graph*)id_of_graph)->weight_size);
        new_node->next = ((struct graph*)id_of_graph)->adjacency_list[src];
        ((struct graph*)id_of_graph)->adjacency_list[src] = new_node;


        if(undirected)
        {
                create_node((void **)&new_node, src, weight,((struct graph*)id_of_graph)->weight_size);
                new_node->next = ((struct graph*)id_of_graph)->adjacency_list[dest];
                ((struct graph*)id_of_graph)->adjacency_list[dest] = new_node;
        }
        return;
}


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
void remove_edge_graph(void* id_of_graph, void* source, void* destination, uint8_t undirected)
{
        uint64_t src = *(uint64_t*)source;
        uint64_t dest = *(uint64_t*)destination;

        struct node *aux_pointer = NULL;
        
        aux_pointer = ((struct graph*)id_of_graph)->adjacency_list[src];

        if ((aux_pointer)->vertex == dest)
        {
                ((struct graph*)id_of_graph)->adjacency_list[src] = aux_pointer->next;
                free(aux_pointer);
        }
        else
        {
                while (NULL != aux_pointer->next) 
                {
                        if ((aux_pointer)->next->vertex == dest) 
                        {
                                struct node* temp = aux_pointer->next;
                                aux_pointer->next = aux_pointer->next->next;
                                free(temp);
                                break;
                        }
                        aux_pointer = aux_pointer->next;
                }
        }

        if(undirected)
        {
                aux_pointer = ((struct graph*)id_of_graph)->adjacency_list[dest];

                if ((aux_pointer)->vertex == src)
                {
                        ((struct graph*)id_of_graph)->adjacency_list[dest] = aux_pointer->next;
                        free(aux_pointer);
                }
                else
                {
                        while (NULL != aux_pointer->next) 
                        {
                                if ((aux_pointer)->next->vertex == src) 
                                {
                                        struct node* temp = aux_pointer->next;
                                        aux_pointer->next = aux_pointer->next->next;
                                        free(temp);
                                        break;
                                }
                                aux_pointer = aux_pointer->next;
                        }
                }






        }
}


void print_graph(void* id_of_graph) 
{
    for (uint64_t i = 0; i <  ((struct graph*)id_of_graph)->num_of_vertices; i++) 
    {
        struct node *aux_pointer = ((struct graph*)id_of_graph)->adjacency_list[i];
        printf("Vertex %d:", i);
        while (NULL != aux_pointer) 
        {
            printf(" -> %d(w=%d)", aux_pointer->vertex, *((int64_t*)aux_pointer->weight));
            aux_pointer = aux_pointer->next;
        }
        printf("\n");
    }
}

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
void free_graph(void* id_of_graph)
{
        /* LOCAL VARIABLES:
        *  Variable        Type         Description
        *  --------        ------------ -----------
        *  aux_data_ptr    struct data* auxiliary pointer to data node to deallocate
        */
        if(NULL == id_of_graph)
                return;

        for (uint64_t i = 0; i < ((struct graph*)id_of_graph)->num_of_vertices; i++) 
        {
                struct node *aux_pointer = ((struct graph*)id_of_graph)->adjacency_list[i];
                while (aux_pointer) 
                {
                        struct node *free_node_pointer;
                        free_node_pointer = aux_pointer;
                        aux_pointer = aux_pointer->next;
                        free(free_node_pointer);
                }
        }
        free(((struct graph*)id_of_graph)->adjacency_list);
        free(((struct graph*)id_of_graph));        
        return ;




}



void create_node(void** node, uint64_t vertex, void * weight,uint64_t size_of_weight)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == node)
        {
                fprintf(stderr, "node pointer is null\n");
                return ;
        }

        (*node) = malloc(1*sizeof(struct node));
        if(NULL == (*node))
        {
                perror("Memory allocation failed");
                return ;
        }

        (*(struct node **)(node))->vertex = vertex;


        (*(struct node **)(node))->weight = (void*) malloc(1*size_of_weight);
        if(NULL == (*(struct node **)(node))->weight)
        {
                perror("Memory allocation failed");
                return ;
        }

        memcpy((*(struct node **)(node))->weight, weight, size_of_weight);

        (*(struct node **)(node))->next = NULL;
        (*(struct node **)(node))->data = NULL;
        return ;
}




/*****************************************************/


