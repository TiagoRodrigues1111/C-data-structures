

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <errno.h>

void single_stack_simple_test()
{

        void *stack1 = NULL;

        create_stack(&stack1, sizeof(uint16_t),0);
        printf("%u\n",check_stack_is_empty(stack1));


        uint16_t data_test = 3;
        stack_push(stack1,(void*) &data_test);

        data_test = 20;
        stack_push(stack1,(void*) &data_test);
        
        data_test = 30;
        stack_push(stack1,(void*) &data_test);
        

        printf("%u\n", *((uint16_t*)check_stack_top(stack1)));
        stack_pop(stack1);

        printf("%u\n", *((uint16_t*)check_stack_top(stack1)));
        stack_pop(stack1);

        printf("%u\n", *((uint16_t*)check_stack_top(stack1)));


        printf("%lu\n",check_stack_size(stack1));

        free_stack(stack1);

        return ;
}


void single_stack_simple_test_2()
{

        void *stack1 = NULL;

        create_stack(&stack1, sizeof(uint16_t),0);


        uint16_t data_test = 3;
        stack_push(stack1,(void*) &data_test);

        free_stack(stack1);

        return ;
}






void two_stacks_simple_test()
{

        void *stack1 = NULL;
        void *stack2 = NULL;


        create_stack(&stack1, sizeof(uint16_t),0);
        create_stack(&stack2, sizeof(uint16_t),0);


        printf("%u\n",check_stack_is_empty(stack1));


        uint16_t data_test = 3;
        stack_push(stack1,(void*) &data_test);

        data_test = 20;
        stack_push(stack1,(void*) &data_test);
        
        data_test = 30;
        stack_push(stack2,(void*) &data_test);
        

        printf("%u\n", *((uint16_t*)check_stack_top(stack1)));
        stack_pop(stack1);

        printf("%u\n", *((uint16_t*)check_stack_top(stack1)));
        stack_pop(stack1);

        printf("%u\n", *((uint16_t*)check_stack_top(stack2)));


        printf("%lu\n",check_stack_size(stack1));

        free_stack(stack1);

        free_stack(stack2);

        return;
}


/* High memory usage test */
void stack_stress_test1()
{
        void *stack1=NULL;
        uint16_t data1=0; 

        create_stack(&stack1,sizeof(uint16_t),100);

        // uint64_t n = 400000000;
        uint64_t n = 4000000;
        
        while(0 < n)
        {
                
                if(NULL != check_stack_top(stack1))
                {
                        // printf("%lu",*((uint16_t*)check_stack_top(stack1)));
                }

                data1++;
                stack_push(stack1, (void*) &data1);
                n--;



        }
        while(!check_stack_is_empty(stack1))
        {
                stack_pop(stack1);
                // printf("%lu",check_stack_size(stack1));


        }

        free_stack(stack1);

}

/* High CPU usage test */
void stack_stress_test2()
{
        void *stack1=NULL;
        void *stack2=NULL;
        uint16_t data1 =0;
        uint16_t data2 =0; 

        create_stack(&stack1,sizeof(uint16_t),5);
        create_stack(&stack2,sizeof(uint16_t),5);

        uint64_t n = 4000000000;
        // uint64_t n = 4000000;
        
        while(0 < n)
        {
                stack_pop(stack1);
                stack_pop(stack2);
                data1++;
                data2++;
                stack_push(stack1, (void*) &data1);
                stack_push(stack2, (void*) &data2);
                n--;        
        }
        while(!check_stack_is_empty(stack1))
        {
                stack_pop(stack1);
                // printf("%lu",check_stack_size(stack1));
        }

        free_stack(stack1);
        free_stack(stack2);

}

/* Array of stacks test */
void stack_stress_test3()
{
        void **stacks=NULL;
        
        uint64_t num_of_stacks = 20000;
        stacks = (void **) malloc(num_of_stacks* sizeof(void *));
        if(stacks == NULL)
        {
                perror("");
                return ;
        }
        uint16_t data1=20;

        for(uint64_t i=0;i<num_of_stacks;i++)
        {
                create_stack(&(stacks[i]),sizeof(uint16_t),2);
                
                stack_push(stacks[i], (void*) &data1);
                stack_push(stacks[i], (void*) &data1);
        }

        for(uint64_t i=0;i<num_of_stacks;i++)
        {

                while(!check_stack_is_empty(stacks[i]))
                {
                if(NULL != check_stack_top(stacks[i]))
                {
                        printf("%u ",*((uint16_t*)check_stack_top(stacks[i])));
                }

                stack_pop(stacks[i]);
                
                // printf("%lu",check_stack_size(stack1));
                }
        }

        for(uint64_t i=0;i<num_of_stacks;i++)
        {
                free_stack(stacks[i]);
        }        
        free(stacks);
        
}

/* Random Operations test*/
void stack_stress_test4()
{
        void *stack1=NULL;
        uint16_t data1=0; 
        srand(time(NULL));                      
       
        create_stack(&stack1,sizeof(uint16_t),100);

        // uint64_t n = 400000000;
        uint64_t operations = 400000;

        
        while(0 < operations)
        {
                uint8_t op_to_do = rand() % 5;          
                switch (op_to_do)
                {
                case 0:                                         // stack_push
                        stack_push(stack1, (void*) &data1);
                        break;
                case 1:                                         // stack_pop
                        stack_pop(stack1);
                        break; 
                case 2:                                         // check_stack_top
                       if(NULL != check_stack_top(stack1))
                        {
                                printf("stack top: %u\n",*((uint16_t*)check_stack_top(stack1)));
                        }
                        break; 
                case 3:                                         // check_stack_is_empty
                        printf("stack empty?: %u\n",check_stack_is_empty(stack1));
                        break; 
                case 4:                                         // check_stack_size
                        printf("stack size: %lu\n",check_stack_size(stack1));
                        break; 
                default:
                        break;
                }



                data1++;
                operations--;
        }

        free_stack(stack1);    


}


void tutorial()
{
        void *stack1 = NULL;
        create_stack(&stack1, sizeof(uint16_t),5);                              // create a stack of 5 elements of uint16_t size

        uint16_t data1 = 3;
        stack_push(stack1,(void*) &data1);                                      // Push a value onto the stack
        
        data1 = 20;
        stack_push(stack1,(void*) &data1);                                  // Push another value onto the stack

        if(!check_stack_is_empty(stack1))                                       // Checks if stack is not empty 
        {
                printf("%u\n",*((uint16_t*)check_stack_top(stack1)));         // prints top of stack
        }

        stack_pop(stack1);                                                      // Pops a value from the stack

        printf("%lu\n",check_stack_size(stack1));                               // prints size of the stack

        free_stack(stack1);                                                     // frees the stack

        return ;



}


int main()
{
        tutorial();

        // single_stack_simple_test();
        
        //single_stack_simple_test_2();

        // stack_stress_test1();
        
        // stack_stress_test2();

        // stack_stress_test3();

        //stack_stress_test4();

        return 0;  
}