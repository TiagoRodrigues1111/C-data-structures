

/*******************************************************************************************************************
* FILE NAME: general_all_test.c
*                                                                                                               
* PURPOSE: This file   
*                                                                                                               
*                                                                                                      
*                                                                                                             
*                                                                                                               
* NOTES:                                                                                                        
*                                 
*                                                                                             
*
*                                                                                                               
* DEVELOPMENT HISTORY:                                                                                          
*                                                                                                               
* Date          Author                  Change Id       Release         Description Of Change                   
* ----------    ---------------         ---------       -------         ---------------------   
* 24-01-2026    Tiago Rodrigues                               1         File creation
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

/* 1.2 C system headers */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
// #include <errno.h>

/* 1.3 C++ standard library headers*/

/* 1.4 other libraries' headers*/



/* 1.5 project's headers */
#include "types.h"

#include "stack.h"
#include "queue.h"
#include "priority_queue.h"
#include "set.h"
#include "hash_map.h"

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

void test_stack_functions();
void test_queue_functions();
void test_priority_queue_functions();
void test_set_functions();
void test_hash_map_functions();

/*****************************************************/



/* 7 function declarations */
/*****************************************************/

int main()
{
        test_stack_functions();
        printf("\n");
        test_queue_functions();
        printf("\n");
        test_priority_queue_functions();
        printf("\n");
        test_set_functions();
        printf("\n");
        test_hash_map_functions();

        return 0;
}


void test_stack_functions()
{
        stack_t* my_stack = NULL;
        my_stack = create_stack(sizeof(uint32_t), 200);
        if(NULL == my_stack)
        {
                fprintf(stderr, "Stack creation failed\n");
                return ;
        }
        printf("Stack created successfully\n");

        uint16_t data_to_push = 1234;
        if(false == stack_push(my_stack, &data_to_push))
        {
                fprintf(stderr, "Stack push failed\n");
                free_stack(my_stack);
                return ;
        }
        printf("Data pushed successfully onto the stack\n");


        uint16_t data_at_top = 0;
        if(false == stack_top(my_stack, &data_at_top))
        {
                fprintf(stderr, "Stack top failed\n");
                free_stack(my_stack);
                return ;
        }
        printf("Data at the top of the stack: %u\n", data_at_top);

        data_to_push = 3456;
        if(false == stack_push(my_stack, &data_to_push))
        {
                fprintf(stderr, "Stack push failed\n");
                free_stack(my_stack);
                return ;
        }
        printf("Data pushed successfully onto the stack\n");


        data_at_top = 0;
        if(false == stack_top(my_stack, &data_at_top))
        {
                fprintf(stderr, "Stack top failed\n");
                free_stack(my_stack);
                return ;
        }
        printf("Data at the top of the stack: %u\n", data_at_top);
        
        if(false == stack_is_empty(my_stack))
        {
                printf("Stack is not empty\n");
        }
        else
        {
                printf("Stack is empty\n");
        }
        
        size_t current_size = stack_size(my_stack);
        printf("Current stack size: %zu\n", current_size);


        stack_pop(my_stack);

        free_stack(my_stack);
        return ;
}

/*****************************************************/

void test_queue_functions()
{
        queue_t* my_queue = NULL;
        my_queue = create_queue(sizeof(uint32_t), 200);
        if(NULL == my_queue)
        {
                fprintf(stderr, "Queue creation failed\n");
                return ;
        }
        printf("Queue created successfully\n");

        uint16_t data_to_push = 5678;
        if(false == queue_push(my_queue, &data_to_push))
        {
                fprintf(stderr, "Queue push failed\n");
                free_queue(my_queue);
                return ;
        }
        printf("Data pushed successfully onto the queue\n");



        uint16_t data_at_front = 0;
        if(false == queue_front(my_queue, &data_at_front))
        {
                fprintf(stderr, "Queue front failed\n");
                free_queue(my_queue);
                return ;
        }
        printf("Data at the front of the queue: %u\n", data_at_front);

        data_to_push = 2345;
        if(false == queue_push(my_queue, &data_to_push))
        {
                fprintf(stderr, "Queue push failed\n");
                free_queue(my_queue);
                return ;
        }
        printf("Data pushed successfully onto the queue\n");


        data_at_front = 0;
        if(false == queue_front(my_queue, &data_at_front))
        {
                fprintf(stderr, "Queue front failed\n");
                free_queue(my_queue);
                return ;
        }
        printf("Data at the front of the queue: %u\n", data_at_front);

        if(false == queue_is_empty(my_queue))
        {
                printf("Queue is not empty\n");
        }
        else
        {
                printf("Queue is empty\n");
        }

        size_t current_size = queue_size(my_queue);
        printf("Current queue size: %zu\n", current_size);
        queue_pop(my_queue);
        
        free_queue(my_queue);
        return ;
}

/*****************************************************/

bool priority_queue_compare_uint16_t_func(void* val1, void* val2)
{
        uint16_t val1_int = *((uint16_t*)val1);
        uint16_t val2_int = *((uint16_t*)val2);

        if(val1_int < val2_int)
                return false;
        else
                return true;
}


void test_priority_queue_functions()
{
        priority_queue_t* my_pq = NULL;

        my_pq = create_priority_queue(sizeof(uint16_t), 100,priority_queue_compare_uint16_t_func);
        if(NULL == my_pq)
        {
                fprintf(stderr, "Priority Queue creation failed\n");
                return ;
        }
        printf("Priority Queue created successfully\n");
        uint16_t data_to_push = 50;
        if(false == priority_queue_push(my_pq, &data_to_push))
        {
                fprintf(stderr, "Priority Queue push failed\n");
                free_priority_queue(my_pq);
                return ;
        }
        printf("Data pushed successfully onto the priority queue\n");
        data_to_push = 20;
        if(false == priority_queue_push(my_pq, &data_to_push))
        {
                fprintf(stderr, "Priority Queue push failed\n");
                free_priority_queue(my_pq);
                return ;
        }
        printf("Data pushed successfully onto the priority queue\n");
        data_to_push = 80;
        if(false == priority_queue_push(my_pq, &data_to_push))
        {
                fprintf(stderr, "Priority Queue push failed\n");
                free_priority_queue(my_pq);
                return ;
        }
        printf("Data pushed successfully onto the priority queue\n");

        uint16_t data_at_top = 0;
        if(false == priority_queue_top(my_pq, &data_at_top))
        {
                fprintf(stderr, "Priority Queue top failed\n");
                free_priority_queue(my_pq);
                return ;
        }
        printf("Data at the top of the priority queue: %u\n", data_at_top);
        priority_queue_pop(my_pq);

        if(false == priority_queue_top(my_pq, &data_at_top))
        {
                fprintf(stderr, "Priority Queue top failed\n");
                free_priority_queue(my_pq);
                return ;
        }
        printf("Data at the top of the priority queue: %u\n", data_at_top);
        priority_queue_pop(my_pq);
        if(false == priority_queue_top(my_pq, &data_at_top))
        {
                fprintf(stderr, "Priority Queue top failed\n");
                free_priority_queue(my_pq);
                return ;
        }
        printf("Data at the top of the priority queue: %u\n", data_at_top);
        priority_queue_pop(my_pq);


        if(true == priority_queue_is_empty(my_pq))
        {
                printf("Priority Queue is empty\n");
        }
        else
        {
                printf("Priority Queue is not empty\n");
        }

        size_t current_size = priority_queue_size(my_pq);
        printf("Current priority queue size: %zu\n", current_size);


        free_priority_queue(my_pq);
        return ;
}

/*****************************************************/

bool set_compare_uint16_t_func(const void* val1, const void* val2)
{
        uint16_t val1_int = *((uint16_t*)val1);
        uint16_t val2_int = *((uint16_t*)val2);

        if(val1_int == val2_int)
                return true;
        else
                return false;

}

// not really a good hash function, using uint16_t as the hash, means the uint64_t max size of buckets will not be used
size_t hash_function(const void* val)                       
{
        uint16_t val1_int = *((uint16_t*)val);
        return val1_int;
}


void test_set_functions()
{
        set_t* my_set = NULL;

        my_set = create_set(sizeof(uint16_t), 100, set_compare_uint16_t_func, hash_function);
        if(NULL == my_set)
        {
                fprintf(stderr, "Set creation failed\n");
                return ;
        }
        printf("Set created successfully\n");

        uint16_t value1 = 10;
        if(false == set_insert(my_set, &value1))
        {
                fprintf(stderr, "Set add failed\n");
                free_set(my_set);
                return ;
        }
        printf("Value %u added to the set successfully\n", value1);

        value1 = 20;
        if(false == set_insert(my_set, &value1))
        {
                fprintf(stderr, "Set add failed\n");
                free_set(my_set);
                return ;
        }
        printf("Value %u added to the set successfully\n", value1);

        value1 = 10;
        if(false == set_insert(my_set, &value1))
        {
                printf("Value %u already exists in the set, not added again\n", value1);
        }

        value1 = 20;
        if(true == set_contains(my_set, &value1))
        {
                printf("Value %u exists in the set\n", value1);
        }
        else
        {
                printf("Value %u does not exist in the set\n", value1);
        }
        value1 = 30;
        if(true == set_contains(my_set, &value1))
        {
                printf("Value %u exists in the set\n", value1);
        }
        else
        {
                printf("Value %u does not exist in the set\n", value1);
        }

        value1 = 10;
        if(false == set_erase(my_set, &value1)) // trying to erase a non existing value
        {
                printf("Value %u does not exist in the set, not erased\n", value1);
        }


        size_t current_size = set_size(my_set);
        printf("Current set size: %zu\n", current_size);

        if(true == set_is_empty(my_set))
        {
                printf("Set is empty\n");
        }
        else
        {
                printf("Set is not empty\n");
        }



        free_set(my_set);
        return ;
}


/*****************************************************/

void test_hash_map_functions()
{
        hash_map_t* hash_map = NULL;
        hash_map = create_hash_map(sizeof(uint16_t), sizeof(uint16_t), 100, set_compare_uint16_t_func, hash_function);
        if(NULL == hash_map)
        {
                fprintf(stderr, "Hash Map creation failed\n");
                return ;
        }
        printf("Hash Map created successfully\n");

        uint16_t key1 = 10;
        uint16_t value1 = 100;
        if(false == hash_map_insert(hash_map, (void*)&key1, (void*)&value1))
        {
                fprintf(stderr, "Hash Map insertion failed\n");
                free_hash_map(hash_map);
                return ;
        }
        printf("Key %u with value %u inserted successfully into the hash map\n", key1, value1);
        key1 = 20;
        value1 = 200;
        if(false == hash_map_insert(hash_map, (void*)&key1, (void*)&value1))
        {
                fprintf(stderr, "Hash Map insertion failed\n");
                free_hash_map(hash_map);
                return ;
        }
        printf("Key %u with value %u inserted successfully into the hash map\n", key1, value1);
        key1 = 10;
        if(true == hash_map_contains(hash_map, (void*)&key1))
        {
                printf("Key %u exists in the hash map\n", key1);
        }
        else
        {
                printf("Key %u does not exist in the hash map\n", key1);
        }
        key1 = 30;
        if(true == hash_map_contains(hash_map, (void*)&key1))
        {
                printf("Key %u exists in the hash map\n", key1);
        }
        else
        {
                printf("Key %u does not exist in the hash map\n", key1);
        }

        key1 = 10;
        if(false == hash_map_erase(hash_map, (void*)&key1))
        {
                printf("Key %u does not exist in the hash map, not erased\n", key1);
        }

        key1 = 20;
        uint16_t retrieved_value = 0;
        if(hash_map_get_value(hash_map, (void*)&key1, (void*)&retrieved_value) == false)
        {
                printf("Key %u does not exist in the hash map, cannot retrieve value\n", key1);
        }
        else
        {
                printf("Key %u has value %u in the hash map\n", key1, retrieved_value);
        }
        

        size_t current_size = hash_map_size(hash_map);
        printf("Current hash map size: %zu\n", current_size);
        if(true == hash_map_is_empty(hash_map))
        {
                printf("Hash map is empty\n");
        }
        else
        {
                printf("Hash map is not empty\n");
        }


        free_hash_map(hash_map);
        return ;
}

