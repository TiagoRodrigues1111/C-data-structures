/*******************************************************************************************************************
* FILE NAME: doublelinkedlist.c
*                                                                                                               
* PURPOSE: This file implements all the functions needed for the creation and modification of a doubly linked list
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
*
*                                                                    
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
* 27-01-2025    Tiago Rodrigues                               1         Creation of the repository as well 
*                                                                        as implementation of functions and
*                                                                        update of functions from singly linked list
* 03-02-2025    Tiago Rodrigues                               1         Added fix to data being NULL bug   
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

#include "doublelinkedlist.h"
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
        // uint64_t size_of_datatype;                   not needed, unless trying to make a multi value linked list
        void* data;
        struct node* next;
        struct node* previous;
};



/*****************************************************/


/* 6 function prototypes */
/*****************************************************/

/*****************************************************/



/* 7 function declarations */
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
void create_node_dll(void** node)
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
        (*(struct node **)(node))->next = NULL;
        (*(struct node **)(node))->previous = NULL;
        (*(struct node **)(node))->data = NULL;
        return ;
}


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
void give_node_value_dll(void* node, void *value1, uint64_t size_of_datatype)
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
        if(NULL == value1)
        {
                fprintf(stderr, "Data pointer is null\n");
                return ;
        }

        ((struct node*)node)->data =(void*) malloc(1*size_of_datatype);

        if(NULL == ((struct node*)node)->data)
        {
                perror("Memory allocation failed");
                return ;
        }

        memcpy(((struct node*)node)->data, value1, size_of_datatype);

        return ;
}


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
void add_node_to_head_dll(void** linked_list_node, void* node)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct node*    auxiliary node to walk through the list      
        */
        if(NULL == linked_list_node)
        {
                fprintf(stderr, "linked_list_node pointer is null\n");
                return ;
        }
        if(NULL == (*linked_list_node))
        {
                (*linked_list_node) = node;
                return;
        }
        else if(NULL == node)
        {
                return;
        }
        else if(NULL == get_previous_node_dll((*linked_list_node)))               // given linked_list_node is head
        {
                ((struct node*)node)->next= ((struct node*)(*linked_list_node));
                ((struct node*)node)->previous= NULL;
                ((struct node*)(*linked_list_node))->previous = ((struct node*)node);
                (*linked_list_node) = node;
                return ;
        }

        struct node* aux_ptr = (*(struct node**)(linked_list_node));
        while(NULL != get_previous_node_dll((void *)aux_ptr))
                previous_node_dll((void**) &aux_ptr);


        ((struct node*)node)->next= aux_ptr;
        ((struct node*)node)->previous= NULL;
        aux_ptr->previous = ((struct node*)node);


}

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
void add_node_to_tail_dll(void** linked_list_node, void* node)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct node*    auxiliary node to walk through the list         
        */
        if(NULL == linked_list_node)
        {
                fprintf(stderr, "linked_list_node pointer is null\n");
                return ;
        }   
        if(NULL == (*linked_list_node))
        {
                (*linked_list_node) = node;
                return;
        }
        if(NULL == node)
        {
                return;
        }

        struct node* aux_ptr = (*(struct node**)(linked_list_node));
        while(NULL != get_next_node_dll((void *)aux_ptr))
                next_node_dll((void**) &aux_ptr);


        aux_ptr->next = node;
        ((struct node*)node)->previous = aux_ptr;

        return;

}

/******************************************************************
*
* FUNCTION NAME: add_node_in_index_n_dll       
*
* PURPOSE: Adds a node to index n compared to given node of a linked list
*
* ARGUMENTS:
*
* ARGUMENT 	        TYPE	        I/O	DESCRIPTION
* linked_list_node	void**	        I/O	pointer to the memory position a node in the linked list
* node                  void*	        I	pointer to the memory position of the node to add to the list
* position              int64_t         I       position to add node to the linked list
*
* RETURNS: void
*
*
*
*****************************************************************/
void add_node_in_index_n_dll(void** linked_list_node, void* node, int64_t position)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct node*    auxiliary node to walk through the list         
        */        
        if(NULL == linked_list_node)
        {
                fprintf(stderr, "linked_list_node pointer is null\n");
                return ;
        }   
        if(NULL == (*linked_list_node))
        {
                (*linked_list_node) = node;
                return;
        }
        if(NULL == node)
        {
                return;
        }
        else if((NULL == get_previous_node_dll((*linked_list_node))) && (0 >= position))               // given node is head
        {
                add_node_to_head_dll(linked_list_node, node);
                return ;
        }

        struct node* aux_ptr = (*(struct node**)(linked_list_node));
        if(position > 0)
        {
                while(NULL != get_next_node_dll((void *)aux_ptr) && position>0)                     //has to be 1
                {
                        next_node_dll((void**) &aux_ptr);
                        position--;
                }

        }
        else if(position < 0)
        {
                while(NULL != get_previous_node_dll((void *)aux_ptr) && position<0)                     //has to be 1
                {
                        previous_node_dll((void**) &aux_ptr);
                        position++;
                }
        }


        if(NULL != aux_ptr->previous )
                aux_ptr->previous->next = ((struct node*)node);
        ((struct node*)node)->previous = aux_ptr->previous;
        aux_ptr->previous = ((struct node*)node);
        ((struct node*)node)->next= aux_ptr;
        


        if((*linked_list_node) == aux_ptr)
                (*linked_list_node) = node;                                                     // depending on wanted implementation, this should be commented                                                      
        

        return;
}

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
void remove_head_node_dll(void** linked_list_node)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct node*    auxiliary pointer to node to free         
        */        
        if(NULL == linked_list_node)
        {
                fprintf(stderr, "linked_list_node pointer is null\n");
                return ;
        }     
        if(NULL == (*linked_list_node))
        {
                return;
        }
        if((NULL == get_previous_node_dll((*linked_list_node))) && (NULL == get_next_node_dll((*linked_list_node))))
        {
                (*(struct node**)(linked_list_node))->next = NULL;
                (*(struct node**)(linked_list_node))->previous = NULL;

                free((*(struct node**)(linked_list_node))->data);
                free((*linked_list_node));
                (*linked_list_node) = NULL;
                return;
        }

        struct node* aux_ptr = (*(struct node**)(linked_list_node));
        if(NULL == get_previous_node_dll((*linked_list_node)))  
        {
                next_node_dll(linked_list_node);
                (*(struct node**)(linked_list_node))->previous = NULL;
                free(aux_ptr->data);
                free(aux_ptr);
                return;
        }

        while(NULL != get_previous_node_dll(aux_ptr))
                previous_node_dll((void**) &aux_ptr);    


        if(NULL != get_next_node_dll(aux_ptr))
                aux_ptr->next->previous = NULL;
        


        free(aux_ptr->data);
        free(aux_ptr);

        return;

}

/******************************************************************
*
* FUNCTION NAME: remove_tail_node_dll       
*
* PURPOSE: removes the tail of a linked list
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
void remove_tail_node_dll(void** linked_list_node)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct node*    auxiliary pointer to node to free and for walking through the list         
        */
        if(NULL == linked_list_node)
        {
                fprintf(stderr, "linked_list_node pointer is null\n");
                return ;
        }   
        if(NULL == (*linked_list_node))
        {
                return;
        }

        if((NULL == get_previous_node_dll((*linked_list_node))) && (NULL == get_next_node_dll((*linked_list_node))))
        {
                (*(struct node**)(linked_list_node))->next = NULL;
                (*(struct node**)(linked_list_node))->previous = NULL;

                free((*(struct node**)(linked_list_node))->data);
                free((*linked_list_node));
                (*linked_list_node) = NULL;
                return;
        }

        struct node* aux_ptr = (*(struct node**)(linked_list_node));

        if(NULL == (*(struct node**)(linked_list_node))->next)
        {
                (*(struct node**)(linked_list_node))->previous->next = NULL;
                
                previous_node_dll(linked_list_node);
                free(aux_ptr->data);
                free(aux_ptr);
                // (*linked_list_node) = NULL;
                return;
        }

        aux_ptr = (*(struct node**)(linked_list_node));
        while(NULL != get_next_node_dll((void *)aux_ptr))
        {
                next_node_dll((void**) &aux_ptr);
        }


        //free(get_value(get_next_node((void *)aux_ptr)));
        aux_ptr->previous->next = NULL;
        free(aux_ptr->data);
        free(aux_ptr);

        return;


}


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
void remove_node_in_index_n_dll(void** linked_list_node, int64_t position)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct node*    auxiliary pointer to node to free and for walking through the list         
        */
        if(NULL == linked_list_node)
        {
                fprintf(stderr, "linked_list_node pointer is null\n");
                return ;
        }    
        if(NULL == (*linked_list_node))
        {
                return;
        }

        else if((NULL == get_previous_node_dll((*linked_list_node))) && (0 >= position))               // given node is head
        {
                remove_head_node_dll(linked_list_node);
                return ;
        }
        

        struct node* aux_ptr = (*(struct node**)(linked_list_node));
        if(position > 0)
        {
                while(NULL != get_next_node_dll((void *)aux_ptr) && position>0)                     //has to be 1
                {
                        next_node_dll((void**) &aux_ptr);
                        position--;
                }

        }
        else if(position < 0)
        {
                while(NULL != get_previous_node_dll((void *)aux_ptr) && position<0)                     //has to be 1
                {
                        previous_node_dll((void**) &aux_ptr);
                        position++;
                }
        }
        if(position == 0)
        {
                if(aux_ptr->previous != NULL)
                        aux_ptr->previous->next = aux_ptr->next;
                if(aux_ptr->next != NULL)
                        aux_ptr->next->previous = aux_ptr->previous;
                
                if(aux_ptr == (*(struct node**)(linked_list_node)))
                {
                        next_node_dll(linked_list_node);
                }
                
                aux_ptr->next = NULL;
                aux_ptr->previous = NULL;               

                free(aux_ptr->data);
                aux_ptr->data = NULL;
                free(aux_ptr);
                
                        
        }
        return ;
}


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
void next_node_dll(void** node)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == node)
        {
                return;
        }
        if(NULL == (*node))
        {
                return;
        }
        (*(struct node**)(node)) = get_next_node_dll((*(struct node**)(node)));
        return;
}


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
void* get_next_node_dll(void* node)
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
void previous_node_dll(void** node)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == node)
        {
                return;
        }
        if(NULL == (*node))
        {
                return;
        }
        (*(struct node**)(node)) = get_previous_node_dll((*(struct node**)(node)));
        return;
}


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
* RETURNS: void* (memory position of the previous node to the given node )
*
*
*
*****************************************************************/
void* get_previous_node_dll(void* node)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */        
        if(NULL == node)
                return NULL;

        return ((void *)((struct node*)node)->previous);              
}


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
void* get_value_dll(void* node)
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
* FUNCTION NAME: get_value_in_index_n_dll       
*
* PURPOSE: Returns the memory position of the value that is currently in the node in index n
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
void* get_value_in_index_n_dll(void* linked_list_node, int64_t n)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct node*    auxiliary pointer to node for walking through the list         
        */
        if(NULL == linked_list_node)
        {
                return NULL;
        }

        struct node* aux_ptr = ((struct node*)(linked_list_node));

        while(NULL != get_previous_node_dll((void *)aux_ptr) && 0 > n)                  
        {
                previous_node_dll((void**) &aux_ptr);
                n++;
        }       

        while(NULL != get_next_node_dll((void *)aux_ptr) && 0 < n)                  
        {
                next_node_dll((void**) &aux_ptr);
                n--;
        }

        if(0 != n)
                return NULL;

        return aux_ptr->data;
}

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
void  free_linked_list_dll(void** linked_list_node)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct node*    auxiliary pointer to a node to free         
        */  
        if(NULL == linked_list_node)
        {
                return;
        }  

        while(NULL != get_previous_node_dll((*linked_list_node)))
        {
                (*linked_list_node) = get_previous_node_dll((*linked_list_node));
        }
        while(NULL != (*linked_list_node))
        {
                struct node* aux_ptr = (*linked_list_node);
                (*linked_list_node) = get_next_node_dll((*linked_list_node));
                free(aux_ptr->data);
                free(aux_ptr);
        }
        linked_list_node = NULL;

        return ;
}



/*****************************************************/





