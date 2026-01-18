

#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <errno.h>
#include "types.h"


bool compare_uint16_t_func(void* val1, void* val2)
{
        uint16_t val1_int = *((uint16_t*)val1);
        uint16_t val2_int = *((uint16_t*)val2);

        if(val1_int < val2_int)
                return false;
        else
                return true;
}



void single_priority_queue_simple_test()
{
        priority_queue_t *priority_queue = NULL;

        priority_queue = create_priority_queue(sizeof(uint16_t),20, compare_uint16_t_func);


        printf("%u\n",priority_queue_is_empty(priority_queue));
        printf("%u\n",priority_queue_size(priority_queue));


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


        uint16_t value_top = 0;

        if(priority_queue_top(priority_queue, (void *)&value_top))
        {
                printf("Value at top: %u\n", value_top);
        }
        priority_queue_pop(priority_queue);

        if(priority_queue_top(priority_queue, (void *)&value_top))
        {
                printf("Value at top: %u\n", value_top);
        }
        priority_queue_pop(priority_queue);

        if(priority_queue_top(priority_queue, (void *)&value_top))
        {
                printf("Value at top: %u\n", value_top);
        }
        priority_queue_pop(priority_queue);

        if(priority_queue_top(priority_queue, (void *)&value_top))
        {
                printf("Value at top: %u\n", value_top);
        }
        priority_queue_pop(priority_queue);

        if(priority_queue_top(priority_queue, (void *)&value_top))
        {
                printf("Value at top: %u\n", value_top);
        }
        priority_queue_pop(priority_queue);        

        

        printf("%u\n",priority_queue_is_empty(priority_queue));
        printf("%u\n",priority_queue_size(priority_queue));

        priority_queue_pop(priority_queue);
       

        free_priority_queue(priority_queue);

        return;
}



int main()
{

        single_priority_queue_simple_test();

        return 0;  
}