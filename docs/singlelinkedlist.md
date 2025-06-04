


# Singly Linked List Implementation in C

This file contains documentation for the simple implementation of the singly linked list data structure in the C programming language. A singly linked list is a linear data structure where each element is a separate object, known as a node. Each node contains two items: the data and a reference (or link) to the next node in the sequence. This implementation supports common singly linked list operations such as add to head/tail, remove from head/tail,and get value of a node. It also has two functions for getting the next node. Additionally, it also allows for nodes to be added/removed at a specific position n, and to get the nth value from a node.

## Features

- Singly Linked List implementation.
- Basic operations:
  - `Create`: Creates a node of the singly linked list datastructure.  - `create_node`
  - `Add value`: Gives a value to a node. - `give_node_value`
  - `Add at head`: Adds a node at the head of a linked list. - `add_node_to_head`
  - `Add at tail`: Adds a node at the tail of a linked list. - `add_node_to_tail`
  - `Add at n`: Adds a node at index n of a linked list. - `add_node_in_index_n`
  - `remove head`: Removes head node of a linked list. - `remove_head_node`
  - `remove tail`: Removes tail node of a linked list. - `remove_tail_node      `
  - `remove n`:  Removes the nth node of a linked list. - `remove_node_in_index_n`
  - `next node`: gives the pointer the value of its next node. - `next_node`
  - `get next node`: returns the next node. - `get_next_node` 
  - `get value`: returns value of a node. - `get_value` 
  - `get value at n`: returns value of the nth node. - `get_value_in_index_n` 
  - `Free`: frees a linked. - `free_linked_list` 


## Prerequisites

To compile and run the program, you need:
- A C compiler (e.g., GCC, Clang, or MSVC).
- Basic knowledge of working with C files.


## Operations Breakdown

### `Create`
- **Description**: Creates a node
- **Input**: The pointer to the memory position of the node
- **Example**:
  ```c
  void *head1= NULL;
  create_node(&head1);
  ```

### `Add value`
- **Description**: Gives a value to a node.
- **Input**: The pointer to the node, as well as a void* to the input data, and the size of the datatype.
- **Example**:
  ```c
  uint8_t data=10;
  give_node_value(head1,(void*)&data,sizeof(uint8_t));
  ```

### `Add at head`
- **Description**: Adds a node at the head of a linked list
- **Input**: The pointer to the head, And the node to add.
- **Example**:
  ```c
        
  add_node_to_head(&head1,node1);
  ```
### `Add at tail`
- **Description**: Adds a node at the tail of a linked list
- **Input**: The pointer to the head, And the node to add.
- **Example**:
  ```c
        
  add_node_to_tail(&head1,node1);
  ```

### `Add at n`
- **Description**: Adds a node at index n of a linked list
- **Input**: The pointer to the head, the node to add, and the position to add.
- **Example**:
  ```c
  uint64_t n = 100;
  add_node_in_index_n(&head1,node1,n);
  ```

### `Remove head`
- **Description**: Remove node at the head of a linked list
- **Input**: The pointer to the head
- **Example**:
  ```c
        
  remove_head_node(&head1);
  ```
### `Remove tail`
- **Description**: Remove node at the tail of a linked list
- **Input**: The pointer to the head.
- **Example**:
  ```c
        
  remove_tail_node(&head1,node1);
  ```

### `Remove at n`
- **Description**: Remove node at index n of a linked list
- **Input**: The pointer to the head, and the position to remove.
- **Example**:
  ```c
  uint64_t n = 100;
  remove_node_in_index_n(&head1,n);
  ```

### `next node`
- **Description**: gives the pointer the value of its next node
- **Input**: The pointer to the node.
- **Example**:
  ```c
  next_node(&node);

### `get next node`
- **Description**: returns the next node
- **Input**: The pointer to the node.
- **Example**:
  ```c
  void *nextnode = NULL;
  nextnode = get_next_node(node);

### `get value`
- **Description**: returns value of a node
- **Input**: The node to get value.
- **Example**:
  ```c
  void *value = NULL;
  value = get_value(node);

### `get value at n`
- **Description**: returns value of the nth node
- **Input**: The head node of the list, and the position of the node.
- **Example**:
  ```c
  void *value = NULL;
  uint64_t n = 100;
  value = get_value_in_index_n(node,n);


### `Free`
- **Description**: Frees the linked list.
- **Output**: None.
- **Example**:
  ```c
  free_linked_list(&head1);
  ```



## Example Usage

Here is a simple example of how the linked list can be used:

```c
#include <stdio.h>
#include "singlelinkedlist.h"

int main() 
{
        void *head1 = NULL;
        void *node1 = NULL;
        uint16_t data1 = 0;
        void *value_aux = NULL;
         
        
        create_node(&head1);                                                    // create a node

        data1 = 3;
        give_node_value(head1,(void*) &data1,sizeof(uint16_t));                 // give a value to a node
        

        create_node(&node1);
        data1 = 20;
        give_node_value(node1,(void*) &data1,sizeof(uint16_t));        
        add_node_to_head(&head1,node1);                                         // add new node to the head

        create_node(&node1);
        data1 = 30;
        give_node_value(node1,(void*) &data1,sizeof(uint16_t));        
        add_node_to_tail(&head1,node1);                                         // add node to tail of head            

        create_node(&node1);
        data1 = 40;
        give_node_value(node1,(void*) &data1,sizeof(uint16_t));      
        add_node_in_index_n(&head1,node1, 1);                                   // add node at index 1 of list


        value_aux = get_value(head1);                                           // get value at the head of list
        if(NULL != value_aux)
        {
                printf("%u\n",*((uint16_t*)value_aux));
        } 

        value_aux = get_value_in_index_n(head1, 1);                             // get value at index 1 of list
        if(NULL != value_aux)
        {
                printf("%u\n",*((uint16_t*)value_aux));
        }


        remove_head_node(&head1);                                               // remove head node

        remove_tail_node(&head1);                                               // remove tail node

        remove_node_in_index_n(&head1,1);                                       // remove node at index 1 of list


        free_linked_list(&head1);                                               // free linked list

        return 0;
}
```
## Notes


