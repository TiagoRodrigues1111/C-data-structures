

#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <errno.h>


int8_t compare_uint16_t_func(void* val1, void* val2)
{
        uint16_t val1_int = *((uint16_t*)val1);
        uint16_t val2_int = *((uint16_t*)val2);

        if(val1_int<val2_int)
                return -1;
        else if(val1_int == val2_int)
                return 0;
        else
                return 1;
}


void single_priority_queue_simple_test()
{
        void *priority_queue = NULL;

        create_priority_queue(&priority_queue, sizeof(uint16_t),20, 0, compare_uint16_t_func);

        printf("%u\n",check_priority_queue_is_empty(priority_queue));
        printf("%u\n",check_priority_queue_size(priority_queue));


        uint16_t value1 = 30;
        priority_queue_push(priority_queue, (void *)&value1);
        value1 = 10;
        priority_queue_push(priority_queue, (void *)&value1);
        value1 = 20;
        priority_queue_push(priority_queue, (void *)&value1);
        value1 = 20000;
        priority_queue_push(priority_queue, (void *)&value1);
        value1 = 8;
        priority_queue_push(priority_queue, (void *)&value1);

        printf("%u\n",check_priority_queue_is_empty(priority_queue));
        printf("%u\n",check_priority_queue_size(priority_queue));

        printf("%u\n", *((uint16_t*)check_priority_queue_top(priority_queue)));
        priority_queue_pop(priority_queue);
        printf("%u\n", *((uint16_t*)check_priority_queue_top(priority_queue)));
        priority_queue_pop(priority_queue);
        printf("%u\n", *((uint16_t*)check_priority_queue_top(priority_queue)));
        priority_queue_pop(priority_queue);

        free_priority_queue(priority_queue);

        return;
}



int main()
{

        single_priority_queue_simple_test();

        return 0;  
}