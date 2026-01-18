

#include "queue.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void single_queue_simple_test()
{

        queue_t *queue1 = NULL;
        uint16_t data_test = 0;

        queue1 = create_queue(sizeof(uint16_t), 0);

        printf("%u\n",queue_is_empty(queue1));
        

        data_test = 1;
        queue_push(queue1,(void*) &data_test);

        data_test = 2;
        queue_push(queue1,(void*) &data_test);
        
        data_test = 3;
        queue_push(queue1,(void*) &data_test);
        
        uint16_t queue_top = 0;

        if(queue_front(queue1, (void*) &queue_top))
        {
                printf("%u\n", queue_top);
        }
        queue_pop(queue1);


        if(queue_front(queue1, (void*) &queue_top))
        {
                printf("%u\n", queue_top);
        }
        queue_pop(queue1);

        if(queue_front(queue1, (void*) &queue_top))
        {
                printf("%u\n", queue_top);
        }


        printf("%lu\n",queue_size(queue1));

        free_queue(queue1);

        return ;
}


/* High memory usage test */
void queue_stress_test1()
{
        queue_t *queue1=NULL;
        uint16_t data1=0; 

        queue1 = create_queue(sizeof(uint16_t), 100);

        // uint64_t n = 400000000;
        uint64_t n = 400000;
        
        while(0 < n)
        {
                
                uint16_t check_value = 0;

                if(true == queue_front(queue1, (void*) &check_value))
                {
                        // printf("%u",check_value);
                }

                data1++;
                queue_push(queue1, (void*) &data1);
                n--;



        }
        while(!queue_is_empty(queue1))
        {
                queue_pop(queue1);
                // printf("%lu",queue_size(queue1));
        }

        free_queue(queue1);

}

void queue_stress_test2()
{
        queue_t *queue1=NULL;
        queue_t *queue2=NULL;
        uint16_t data1 =0;
        uint16_t data2 =0; 

        queue1 = create_queue(sizeof(uint16_t), 5);
        queue2 = create_queue(sizeof(uint16_t), 5);

        uint64_t n = 4000000;
        // uint64_t n = 4000000;
        
        while(0 < n)
        {
                queue_pop(queue1);
                queue_pop(queue2);
                data1++;
                data2++;
                queue_push(queue1, (void*) &data1);
                queue_push(queue2, (void*) &data2);
                n--;        
        }
        while(!queue_is_empty(queue1))
        {
                queue_pop(queue1);
                // printf("%lu",queue_size(queue1));
        }

        free_queue(queue1);
        free_queue(queue2);

}

/* Array of queues test */
void queue_stress_test3()
{
        queue_t **queues=NULL;
        
        uint64_t num_of_queues = 20000;
        queues = (queue_t **) malloc(num_of_queues* sizeof(queue_t *));
        if(queues == NULL)
        {
                perror("");
                return ;
        }
        uint16_t data1=20;

        for(uint64_t i=0;i<num_of_queues;i++)
        {
                queues[i] = create_queue(sizeof(uint16_t), 2);
                
                queue_push(queues[i], (void*) &data1);
                queue_push(queues[i], (void*) &data1);
        }

        for(uint64_t i=0;i<num_of_queues;i++)
        {

                while(!queue_is_empty(queues[i]))
                {
                        uint16_t data1=0;
                        if(queue_front(queues[i], (void*) &data1))
                        {
                                printf("%u ",data1);
                        }

                        queue_pop(queues[i]);
                
                        // printf("%lu",check_queue_size(queue1));
                }
        }

        for(uint64_t i=0;i<num_of_queues;i++)
        {
                free_queue(queues[i]);
        }        
        free(queues);
        
}

/* Random Operations test*/
void queue_stress_test4()
{
        queue_t *queue1=NULL;
        uint16_t data1=0; 
        srand(time(NULL));                      
       
        queue1 = create_queue(sizeof(uint16_t), 100);

        // uint64_t n = 400000000;
        uint64_t operations = 400000;

        
        while(0 < operations)
        {
                uint8_t op_to_do = rand() % 6;          
                switch (op_to_do)
                {
                case 0:                                         // queue_push
                        queue_push(queue1, (void*) &data1);
                        break;
                case 1:                                         // queue_pop
                        queue_pop(queue1);
                        break; 
                case 2:                                         // check_queue_front
                {
                        uint16_t front_value = 0;
                        if(queue_front(queue1, (void*) &front_value))
                        {
                                printf("queue front: %u\n",front_value);
                        }
                }
                        break; 
                case 3:                                        // check_queue_back
                {
                        uint16_t back_value = 0;
                        if(queue_back(queue1, (void*) &back_value))
                        {
                                printf("queue back: %u\n",back_value);
                        }
                }
                        break; 
                case 4:                                         // check_queue_is_empty
                        printf("queue empty?: %u\n",queue_is_empty(queue1));
                        break; 
                case 5:                                         // check_queue_size
                        printf("queue size: %lu\n",queue_size(queue1));
                        break; 
                default:
                        break;
                }



                data1++;
                operations--;
        }

        free_queue(queue1);    


}


void tutorial()
{
        queue_t *queue1 = NULL;
        
        queue1 = create_queue(sizeof(uint16_t),5);                              // create a queue of 5 elements of uint16_t size

        uint16_t data1 = 3;
        queue_push(queue1,(void*) &data1);                                      // Push a value onto the queue
        
        data1 = 20;
        queue_push(queue1,(void*) &data1);                                  // Push another value onto the queue

        if(!queue_is_empty(queue1))                                       // Checks if queue is not empty 
        {
                uint16_t front_value = 0;
                if(queue_front(queue1, (void*) &front_value))          // gets the value at the front of the queue
                {
                        printf("%u\n", front_value);                           // prints the value at the front of the queue
                }
        }

        if(!queue_is_empty(queue1))                                       // Checks if queue is not empty 
        {
                uint16_t back_value = 0;
                if(queue_back(queue1, (void*) &back_value))         // gets the value at the back of the queue
                {
                        printf("%u\n", back_value);                           // prints the value at the back of the queue
                }
        }

        queue_pop(queue1);                                                      // Pops a value from the queue

        printf("%lu\n",queue_size(queue1));                               // prints size of the queue
        free_queue(queue1);                                                     // frees the queue

        return ;



}


int main()
{
        tutorial();

        //single_queue_simple_test();

        // queue_stress_test1();
        // queue_stress_test2();
        // queue_stress_test3();
        // queue_stress_test4();
       
        
        return 0;  
}