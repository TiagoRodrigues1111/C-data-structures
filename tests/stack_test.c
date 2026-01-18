

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"
/* #include <errno.h> */

void single_stack_simple_test()
{

        stack_t *stack1 = NULL;

        stack1 = create_stack(sizeof(uint16_t),0);
        
        printf("%d\n",stack_is_empty(stack1));


        uint16_t data_test = 3;
        stack_push(stack1,(void*) &data_test);

        data_test = 20;
        stack_push(stack1,(void*) &data_test);
        
        data_test = 30;
        stack_push(stack1,(void*) &data_test);
        

        uint16_t top_value = 0;
        if(true == stack_top(stack1, (void *)(&top_value)))
                printf("%u\n", top_value);

        stack_pop(stack1);
        
        if(true == stack_top(stack1, (void *)(&top_value)))
                printf("%u\n", top_value);

        stack_pop(stack1);

        if(true == stack_top(stack1, (void *)(&top_value)))
                printf("%u\n", top_value);



        printf("%lu\n",stack_size(stack1));


        free_stack(stack1);

        return ;
}

void single_stack_simple_test_2()
{

        stack_t *stack1 = NULL;

        stack1 = create_stack(sizeof(uint16_t),0);


        uint16_t data_test = 3;
        stack_push(stack1,(void*) &data_test);

        free_stack(stack1);

        return ;
}

void two_stacks_simple_test()
{

        stack_t *stack1 = NULL;
        stack_t *stack2 = NULL;


        stack1 = create_stack(sizeof(uint16_t),0);
        stack2 = create_stack(sizeof(uint16_t),0);


        printf("%d\n",stack_is_empty(stack1));


        uint16_t data_test = 3;
        stack_push(stack1,(void*) &data_test);

        data_test = 20;
        stack_push(stack1,(void*) &data_test);
        
        data_test = 30;
        stack_push(stack2,(void*) &data_test);
        

        uint16_t top_value = 0;
        if(true == stack_top(stack1, (void *)(&top_value)))
                printf("%u\n", top_value);
        stack_pop(stack1);

        if(true == stack_top(stack1, (void *)(&top_value)))
                printf("%u\n", top_value);
        stack_pop(stack1);

        if(true == stack_top(stack1, (void *)(&top_value)))
                printf("%u\n", top_value);


        printf("%lu\n",stack_size(stack1));

        free_stack(stack1);

        free_stack(stack2);

        return;
}

/* High memory usage test */
void stack_stress_test1()
{
        stack_t *stack1=NULL;
        uint16_t data1=0; 

        stack1 = create_stack(sizeof(uint16_t),100);

        /*uint64_t n = 400000000;*/

        uint64_t n = 4000000;
        
        while(0 < n)
        {
                uint16_t top_value = 0;
                if(true == stack_top(stack1, (void *)(&top_value)))
                {
                        /*printf("%lu",top_value);*/
                }

                data1++;
                stack_push(stack1, (void*) &data1);
                n--;


        }
        while(!stack_is_empty(stack1))
        {
                stack_pop(stack1);
                /*printf("%lu",check_stack_size(stack1));*/


        }

        free_stack(stack1);

}

/* High CPU usage test */
void stack_stress_test2()
{
        stack_t *stack1=NULL;
        stack_t *stack2=NULL;
        uint16_t data1 =0;
        uint16_t data2 =0; 

        stack1 = create_stack(sizeof(uint16_t),5);
        stack2 = create_stack(sizeof(uint16_t),5);

        uint64_t n = 4000000000;
        /*uint64_t n = 4000000; */
        
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
        while(!stack_is_empty(stack1))
        {
                stack_pop(stack1);
                /*printf("%lu",check_stack_size(stack1));*/
        }

        free_stack(stack1);
        free_stack(stack2);

}

/* Array of stacks test */
void stack_stress_test3()
{
        stack_t **stacks=NULL;
        
        uint64_t num_of_stacks = 20000;
        stacks = (stack_t **) malloc(num_of_stacks* sizeof(stack_t *));
        if(stacks == NULL)
        {
                perror("");
                return ;
        }
        uint16_t data1=20;

        for(uint64_t i=0;i<num_of_stacks;i++)
        {
                stacks[i] = create_stack(sizeof(uint16_t),2);
                
                stack_push(stacks[i], (void*) &data1);
                stack_push(stacks[i], (void*) &data1);
        }

        for(uint64_t i=0;i<num_of_stacks;i++)
        {

                while(!stack_is_empty(stacks[i]))
                {
                        uint16_t top_value = 0;
                        if(true == stack_top(stacks[i], (void *)(&top_value)))
                        {
                                printf("%u ", top_value);
                        }

                        stack_pop(stacks[i]);
                
                        /*printf("%lu",check_stack_size(stack1));*/
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
        stack_t *stack1=NULL;
        uint16_t data1=0; 
        srand(time(NULL));                      
       
        stack1 = create_stack(sizeof(uint16_t),100);
        
        /*uint64_t n = 400000000;*/
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
                {
                        uint16_t top_value = 0;
                        if(true == stack_top(stack1, (void *)(&top_value)))
                        {
                                printf("stack top: %u\n", top_value);
                        }
                        break; 
                }
                case 3:                                         // check_stack_is_empty
                        printf("stack empty?: %d\n",stack_is_empty(stack1));
                        break; 
                case 4:                                         // check_stack_size
                        printf("stack size: %lu\n",stack_size(stack1));
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
        stack_t *stack1 = NULL;
        stack1 = create_stack(sizeof(uint16_t),5);                              // create a stack of 5 elements of uint16_t size

        uint16_t data1 = 3;
        stack_push(stack1,(void*) &data1);                                      // Push a value onto the stack
        
        data1 = 20;
        stack_push(stack1,(void*) &data1);                                  // Push another value onto the stack

        if(!stack_is_empty(stack1))                                       // Checks if stack is not empty 
        {
                uint16_t top_value = 0;
                if(true == stack_top(stack1, (void *)(&top_value)))
                {
                        printf("%u\n", top_value);
                }
        }

        stack_pop(stack1);                                                      // Pops a value from the stack

        printf("%lu\n",stack_size(stack1));                               // prints size of the stack

        free_stack(stack1);                                                     // frees the stack

        return ;



}

int main()
{

        /*
        printf("Stack Data Structure Tutorial:\n");
        tutorial();
        */

        /*
        printf("\nSingle Stack Simple Test:\n");
        single_stack_simple_test();
        */

        /*
        printf("\nsingle_stack_simple_test_2:\n");
        single_stack_simple_test_2();
        */

        /*
        printf("\nTwo Stacks Simple Test:\n");
        two_stacks_simple_test();
        */

        /*
        printf("\nstack_stress_test1:\n");
        stack_stress_test1();
        */

        /*
        printf("\nstack_stress_test2:\n");
        stack_stress_test2();
        */


        /*
        printf("\nstack_stress_test3:\n");
        stack_stress_test3();
        */

        /*
        printf("\nstack_stress_test4:\n");
        stack_stress_test4();
        */

        return 0;  
}