/*******************************************************************************************************************
* FILE NAME: circularsinglelinkedlist.c
*                                                                                                               
* PURPOSE: This file implements all the functions needed for the creation and modification of a circular single linked list
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
* calloc                        allocates memory, and initiates with zeros     
* printf                        function to print formatted output     
*    
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:                                                  
*             
*                                                                                                  
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:                                                                       
* It is assumed that the list is less than 2^64 elements, for input at                                          
*  a especific position operations          
* It is assumed for list insertion that it starts at index 0, and if n is larger than the list,
*  it is added to the end  
                                                                                                                
* NOTES:                                                                                                        
* If more that 2^64 is needed, use arbitrary-precision arithmetic libs                                  
*                                       
* REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:                                                            
*
*                                                                                                               
* DEVELOPMENT HISTORY:                                                                                          
*                                                                                                               
* Date          Author                  Change Id       Release         Description Of Change                   
* ----------    ---------------         ---------       -------         ---------------------   
* 02-06-2025    Tiago Rodrigues                         1               Initial commit
*                                                                                                              
* ALGORITHM (PDL)
*    
*
*                                                                                                           
****************************************************************************************************************/


/* 0 copyright/licensing */
/***************************************************************************************************************/
/*
*       2024 Tiago Filipe Rodrigues tiagorodrigues1590@hotmail.com
*/
/***************************************************************************************************************/


/* 1 includes */
/*****************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "circularsinglelinkedlist.h"
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
struct node
{
        struct node* tail;                                              // TODO: create sentinel nodes, this is way too much allocation
        // uint64_t size_of_datatype;                   not needed, unless trying to make a multi value linked list
        void* data;
        struct node* next;
};





/*****************************************************/


/* 6 function prototypes */
/*****************************************************/

/*****************************************************/



/* 7 function declarations */
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
void create_node_csll(void** node)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        (*node) = malloc(1*sizeof(struct node));
        if(NULL == (*node))
        {
                fprintf(stderr, "Memory allocation failed\n");
                return ;
        }
        (*(struct node **)(node))->next = NULL;
        
        (*(struct node **)(node))->tail = NULL;
        
        return ;
}


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
void give_node_value_csll(void* node, void *value1, uint64_t size_of_datatype)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == node)
        {
                fprintf(stderr, "Node mem location is null\n");
                return ;
        }

        ((struct node*)node)->data =(void*) malloc(1*size_of_datatype);

        if(NULL == ((struct node*)node)->data)
        {
                fprintf(stderr, "Memory allocation failed\n");
        }

        memcpy(((struct node*)node)->data, value1, size_of_datatype);

        return ;
}


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
void add_node_to_head_csll(void** head, void* node)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == (*head))
        {
                (*head) = node;
                ((struct node*)node)->tail = node;
                return;
        }
        if(NULL == node)
        {
                return;
        }

        ((struct node*)node)->next= ((struct node*)(*head));

        
        if(NULL != ((struct node*)(*head))->tail)
        {
                ((struct node*)node)->tail = ((struct node*)(*head))->tail;
                ((struct node*)(*head))->tail = NULL;
                
        }
        else                            // first insertion
        {

                ((struct node*)node)->tail = ((struct node*)(*head));
        }

        ((struct node*)node)->tail->next = ((struct node*)node);

        (*head) = node;

}

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
void add_node_to_tail_csll(void** head, void* node)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  None      
        */
        if(NULL == (*head))
        {
                (*head) = node;
                ((struct node*)node)->tail = node;
                return;
        }
        if(NULL == node)
        {
                return;
        }
        
        if (NULL != ((struct node*)(*head))->tail)
        {
                 ((struct node*)(*head))->tail->next = node;
        }
        

        ((struct node*)(*head))->tail = node;
        ((struct node*)node)->next = (*head);

        return;

}

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
void add_node_in_index_n_csll(void** head, void* node, uint64_t position)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct node*    auxiliary node to walk through the list         
        */        
        if(NULL == (*head))
        {
                (*head) = node;
                ((struct node*)node)->tail = node;
                return;
        }
        if(NULL == node)
        {
                return;
        }
        if(0 == position)
        {
                add_node_to_head_csll(head, node);
                return ;
        }

        struct node* aux_ptr = (*(struct node**)(head));
        while((*head) != get_next_node_csll((void *)aux_ptr) && position>1)                     //has to be 1
        {
                next_node_csll((void**) &aux_ptr);
                position--;
        }

        if((*head) == get_next_node_csll((void *)aux_ptr))
        {
                add_node_to_tail_csll(head,node);
        }
        else
        {
                ((struct node*)node)->next= aux_ptr->next;
                aux_ptr->next =((struct node*)node);
        }

        return;
}

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
void remove_head_node_csll(void** head)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct node*    auxiliary pointer to node to free         
        */        
        if(NULL == (*head))
        {
                return;
        }

        struct node* aux_ptr = (*(struct node**)(head));

        //if(NULL == ((struct node*)(*head))->next)
        //{

        //}

        ((struct node*)(*head))->next->tail = ((struct node*)(*head))->tail;
        ((struct node*)(*head))->tail->next = ((struct node*)(*head))->next;

        next_node_csll(head);

        free(aux_ptr->data);
        free(aux_ptr);

        return;

}

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
void remove_tail_node_csll(void** head)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct node*    auxiliary pointer to node to free and for walking through the list         
        */
        if(NULL == (*head))
        {
                return;
        }
        if(NULL == (*(struct node**)(head))->next)
        {
                free((*(struct node**)(head))->data);
                free((*head));
                (*head) = NULL;
                return;
        }

        struct node* aux_ptr = (*(struct node**)(head));
        while(((struct node*)(*head))->tail != get_next_node_csll((void *)aux_ptr))
        {
                
                next_node_csll((void**) &aux_ptr);


        }
        ((struct node*)(*head))->tail = aux_ptr;

        aux_ptr = aux_ptr->next;
        //free(get_value(get_next_node_csll((void *)aux_ptr)));
        free(aux_ptr->data);
        //free(get_next_node_csll((void *)aux_ptr));
        free(aux_ptr);

        ((struct node*)(*head))->tail->next = ((struct node*)(*head));

        

        return;


}


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
void remove_node_in_index_n_csll(void** head, uint64_t position)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct node*    auxiliary pointer to node to free and for walking through the list         
        */
        if(NULL == (*head))
        {
                return;
        }
        if(0 == position)
        {
                remove_head_node_csll(head);
                return ;
        }

        struct node* aux_ptr = (*(struct node**)(head));
        while(((struct node*)(*head)) != get_next_node_csll((void *)aux_ptr) && position>1)                     //has to be 1
        {
                next_node_csll((void**) &aux_ptr);
                position--;
        }

        if(((struct node*)(*head)) == get_next_node_csll((void *)aux_ptr))
                return ;

        if(((struct node*)(*head))->tail != get_next_node_csll((void *)aux_ptr))
        {
                remove_tail_node_csll(head);
        }

        if(1 == position)
        {
                struct node* node_to_free = NULL;
                node_to_free = get_next_node_csll((void *)aux_ptr);
                aux_ptr->next = node_to_free->next;
        
                free(node_to_free->data);
                free(node_to_free);
        }

        return ;
}


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
void next_node_csll(void** node)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        (*(struct node**)(node)) = get_next_node_csll((*(struct node**)(node)));
        return;
}


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
void* get_next_node_csll(void* node)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */        
        if(NULL == node)
                return NULL;

        return ((void *)((struct node*)node)->next);              
}

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
void* get_value_csll(void* node)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == node)
                return NULL;
        return ((struct node*)node)->data;
}



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
void* get_value_in_index_n_csll(void* head, uint64_t n)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct node*    auxiliary pointer to node for walking through the list         
        */
        if(NULL == (head))
        {
                return NULL;
        }

        struct node* aux_ptr = ((struct node*)(head));
        

        while(NULL != get_next_node_csll((void *)aux_ptr) && n>0)                  
        {
                next_node_csll((void**) &aux_ptr);
                n--;
        }

        if(0 != n)
                return NULL;
        
        return aux_ptr->data;
}

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
void  free_linked_list_csll(void** head)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct node*    auxiliary pointer to a node to free         
        */  
        ((struct node*)(*head))->tail->next = NULL;
        while(NULL != (*head))
        {
                struct node* aux_ptr = (*head);
                (*head) = get_next_node_csll((*head));
                free(aux_ptr->data);
                free(aux_ptr);
        }
        head = NULL;
        return ;
}



/*****************************************************/





