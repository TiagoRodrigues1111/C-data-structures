/*******************************************************************************************************************
* FILE NAME: binary_tree.c
*                                                                                                               
* PURPOSE: This file implements all the functions needed for the creation and modification of a binary tree
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
* 11-06-2025    Tiago Rodrigues                         0               Prolog start and coding of functions             
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

#include "binary_tree.h"
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
        struct node* left;
        struct node* right;
};



/*****************************************************/


/* 6 function prototypes */
/*****************************************************/

/*****************************************************/



/* 7 function declarations */
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
void create_node_bt(void** node)
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
        (*(struct node **)(node))->left = NULL;
        (*(struct node **)(node))->right = NULL;
        (*(struct node **)(node))->data = NULL;
        return ;
}

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
void give_node_value_bt(void* node, void *value1, uint64_t size_of_datatype)
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
void add_node_to_left_bt(void* parent, void* child)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == parent)
        {
                fprintf(stderr, "Parent pointer is null\n");
                return ;
        }
        if(NULL == child)
        {
                fprintf(stderr, "child is null\n");
                return;
        }

        ((struct node*)parent)->left= ((struct node*)(child));

        return;
}

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
void add_node_to_right_bt(void* parent, void* child)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */
        if(NULL == parent)
        {
                fprintf(stderr, "Parent pointer is null\n");
                return ;
        }
        if(NULL == child)
        {
                fprintf(stderr, "child is null\n");
                return;
        }

        ((struct node*)parent)->right= ((struct node*)(child));

        return;
}

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
void remove_node_to_left_bt(void* node)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct node*    auxiliary pointer to node to free         
        */  
        if(NULL == node)
        {
                fprintf(stderr, "node pointer is null\n");
                return ;
        }               

        // TODO: give the option to the user to either free or not the left node

        free(((struct node*)node)->left->data);
        free(((struct node*)node)->left);



        ((struct node*)node)->left = NULL;

        return;

}

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
void remove_node_to_right_bt(void* node)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct node*    auxiliary pointer to node to free         
        */  
        if(NULL == node)
        {
                fprintf(stderr, "node pointer is null\n");
                return ;
        }               

        // TODO: give the option to the user to either free or not the right node

        free(((struct node*)node)->right->data);
        free(((struct node*)node)->right);



        ((struct node*)node)->right = NULL;

        return;

}

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
void remove_node_bt(void* node)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct node*    auxiliary pointer to node to free         
        */  
        if(NULL == node)
        {
                fprintf(stderr, "node pointer is null\n");
                return ;
        }               


        free(((struct node*)node)->data);
        free(((struct node*)node));


        return;

}

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
void next_left_node_bt(void** node)
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
        (*(struct node**)(node)) = get_left_node_bt((*(struct node**)(node)));
        return;
}

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
void* get_next_left_node_bt(void* node)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */        
        if(NULL == node)
                return NULL;

        return ((void *)((struct node*)node)->left);              
}

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
void next_right_node_bt(void** node)
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
        (*(struct node**)(node)) = get_right_node_bt((*(struct node**)(node)));
        return;
}

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
void* get_next_right_node_bt(void* node)
{
        /* LOCAL VARIABLES:
        *  Variable        Type    Description
        *  --------        ----    -----------
        *  None
        */        
        if(NULL == node)
                return NULL;

        return ((void *)((struct node*)node)->right);              
}


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
void* get_value_bt(void* node)
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
void free_binary_tree(void** root)
{
        /* LOCAL VARIABLES:
        *  Variable     Type            Description
        *  --------     ----            -----------
        *  aux_ptr      struct node*    auxiliary pointer to a node to free         
        */  
        if(NULL == root)
        {
                return;
        }

        free_left_and_right_node((*(struct node**)(root)));

        return ;
}



/*****************************************************/


void free_left_and_right_node(struct node *parent)
{
        if(NULL == parent->left && NULL == parent->right)
        {
                free(parent);
                return;
        }
        if(NULL != parent->left)
                free_left_and_right_node(parent->left);
        if(NULL != parent->right)
                free_left_and_right_node(parent->right);


        parent->left = NULL;
        parent->right = NULL;
        free(parent);
        return;
}




