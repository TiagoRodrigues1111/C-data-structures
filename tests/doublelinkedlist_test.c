

#include "doublelinkedlist.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void simple_double_linked_list_test()
{


        void *head1 = NULL;
        void *node1 = NULL;
        uint32_t data1 = 2;

        create_node_dll(&head1);


        give_node_value_dll(head1,(void*) &data1,sizeof(uint32_t));
        printf("%u\n", *((uint32_t*)get_value_dll(head1)));

   

        create_node_dll(&node1);
        data1 = 3;
        give_node_value_dll(node1,(void*) &data1,sizeof(uint32_t));

        add_node_to_head_dll(&head1,node1);


        printf("%u\n", *((uint32_t*)get_value_dll(head1)));
     
        remove_head_node_dll(&head1);

        printf("%u\n", *((uint32_t*)get_value_dll(head1)));

        remove_head_node_dll(&head1);
        remove_head_node_dll(&head1);
        remove_head_node_dll(&head1);

        return ;
}




/* High memory usage test */
void double_linked_list_stress_test1()
{
        void *head1 = NULL;
        void *node1 = NULL;
        uint16_t data1 = 2;

        create_node_dll(&head1);
        give_node_value_dll(head1,(void*) &data1,sizeof(uint16_t));    


        // uint64_t n = 400000000;
        uint64_t n = 400000;
        
        while(0 < n)
        {
                

                
                if(NULL != get_value_dll(head1))
                {
                        // printf("%lu",*((uint16_t*)get_value(head1)));
                }
                
                create_node_dll(&node1);

                data1++;
                give_node_value_dll(node1,(void*) &data1,sizeof(uint16_t));
                add_node_to_head_dll(&head1,node1);
                n--;



        }
        while(NULL != head1)
        {
                remove_head_node_dll(&head1);


        }

        free_linked_list_dll(&head1);

}

/* High CPU usage test */

void double_linked_list_stress_test2()
{
        void *head1 = NULL;
        void *head2 = NULL;
        void *node1 = NULL;
        uint16_t data1 =0;
        uint16_t data2 =0; 

        create_node_dll(&head1);
        give_node_value_dll(head1,(void*) &data1,sizeof(uint16_t));    

        create_node_dll(&head2);
        give_node_value_dll(head2,(void*) &data2,sizeof(uint16_t));    



        uint64_t n = 4000000;
        // uint64_t n = 4000000;
        
        while(0 < n)
        {
                remove_head_node_dll(&head1);
                remove_head_node_dll(&head2);
                data1++;
                data2++;


                create_node_dll(&node1);
                give_node_value_dll(node1,(void*) &data1,sizeof(uint16_t));
                add_node_to_head_dll(&head1,node1);


                create_node_dll(&node1);
                give_node_value_dll(node1,(void*) &data2,sizeof(uint16_t));
                add_node_to_head_dll(&head2,node1);

                n--;        
        }
        while(NULL != head1)
        {
                remove_head_node_dll(&head1);


        }

        free_linked_list_dll(&head1);
        free_linked_list_dll(&head2);

}


/* Array of linked lists test */

void double_linked_list_stress_test3()
{
        void **heads=NULL;
        
        uint64_t num_of_heads = 20000;
        heads = (void **) malloc(num_of_heads* sizeof(void *));
        if(heads == NULL)
        {
                perror("");
                return ;
        }
        uint16_t data1=20;

        for(uint64_t i=0;i<num_of_heads;i++)
        {
                create_node_dll(&heads[i]);
                give_node_value_dll(heads[i],(void*) &data1,sizeof(uint16_t));    
        }

        for(uint64_t i=0;i<num_of_heads;i++)
        {
                while(NULL != heads[i])
                {
                        if(NULL != get_value_dll(heads[i]))
                        {
                                printf("%u ",*((uint16_t*)get_value_dll(heads[i])));
                        }
                        remove_head_node_dll(&heads[i]);
                }
        }

        for(uint64_t i=0;i<num_of_heads;i++)
        {
                free_linked_list_dll(&heads[i]);
        }        
        free(heads);
        
}

/* Random Operations test*/

void double_linked_list_stress_test4()
{

        void *head1 = NULL;
        void *node1 = NULL;
        uint16_t data1 = 2;
        void* value_aux = NULL;
        srand(time(NULL));   

        create_node_dll(&head1);
        give_node_value_dll(head1,(void*) &data1,sizeof(uint16_t));    

        // uint64_t n = 400000000;
        uint64_t operations = 400000;

        
        while(0 < operations)
        {
                uint8_t op_to_do = rand() % 8;          
                switch (op_to_do)
                {
                case 0:                                         // add_node_to_head
                        create_node_dll(&node1);
                        give_node_value_dll(node1,(void*) &data1,sizeof(uint16_t));      
                        add_node_to_head_dll(&head1,node1);
                        break;
                case 1:                                         // add_node_to_tail
                        create_node_dll(&node1);
                        give_node_value_dll(node1,(void*) &data1,sizeof(uint16_t));      
                        add_node_to_tail_dll(&head1,node1);
                        break; 
                case 2:                                         // add_node_in_index_n
                        create_node_dll(&node1);
                        give_node_value_dll(node1,(void*) &data1,sizeof(uint16_t));      
                        add_node_in_index_n_dll(&head1,node1, (rand() % 4000)-2000);
                        break; 
                case 3:                                         // remove_head_node
                        remove_head_node_dll(&head1);
                        break; 
                case 4:                                         // remove_tail_node
                        remove_tail_node_dll(&head1);
                        break; 
                case 5:                                         // remove_tail_node
                        remove_node_in_index_n_dll(&head1,(rand() % 400)-200);
                        break; 
                case 6:                                         // get_value  
                        value_aux = get_value_dll(head1);                               
                        if(NULL != value_aux)
                        {
                                printf("%u\n",*((uint16_t*)value_aux));
                        }
                        break; 
                case 7:
                        value_aux = get_value_in_index_n_dll(head1, (rand() % 400)-200);     
                        if(NULL != value_aux)
                        {
                                printf("%u\n",*((uint16_t*)value_aux));
                        }
                        break; 

                default:
                        break;
                }



                data1++;
                operations--;
        }

        free_linked_list_dll(&head1);    


}


/* Exclusive double linked list test */

void double_linked_list_stress_test5()
{

        void *head1 = NULL;
        void *node1 = NULL;
        void *node_in_list = NULL;
        uint16_t data1 = 0;

        create_node_dll(&head1);
        give_node_value_dll(head1,(void*) &data1,sizeof(uint16_t));    


        // uint64_t n = 400000000;
        uint64_t n = 100;
        
        while(0 < n)
        {

                if(NULL != get_value_dll(head1))
                {
                        printf("%lu\n",*((uint16_t*)get_value_dll(head1)));
                }
                
                create_node_dll(&node1);

                data1++;
                give_node_value_dll(node1,(void*) &data1,sizeof(uint16_t));
                add_node_to_head_dll(&head1,node1);
                n--;


        }

        n = 10;
        node_in_list = head1;
        while(0 < n)
        {
                next_node_dll(&node_in_list);
                n--;
        }

        void* aux_val = NULL;   
        aux_val = get_value_dll(node_in_list);
        if(NULL != aux_val)
        {
                printf("Node in list val: %lu\n",*((uint16_t*)aux_val));
        }             
        
        aux_val = get_value_in_index_n_dll(node_in_list,50);   
        if(NULL != aux_val)
        {
                printf("Node in list val: %lu\n",*((uint16_t*)aux_val));
        }  

        

        create_node_dll(&node1);
        data1 = 10000;
        give_node_value_dll(node1,(void*) &data1,sizeof(uint16_t));

        // add_node_in_index_n(&node_in_list,node1,-100);
        // remove_node_in_index_n(&node_in_list,-10);                                   // error because node removed is the same as head1;
        
        remove_tail_node_dll(&node_in_list);
        
        //remove_head_node(&node_in_list);                                                // error because node removed is the same as head1;

        aux_val = get_value_in_index_n_dll(node_in_list,50);   
        if(NULL != aux_val)
        {
                printf("Node in list val: %lu\n",*((uint16_t*)aux_val));
        } 


        while(NULL != head1)
        {
                //remove_tail_node(&head1);
                //remove_head_node(&node_in_list);
                remove_head_node_dll(&head1);


        }
        free_linked_list_dll(&head1);
        
        return;
}



void tutorial()
{
        void *head1 = NULL;
        void *node1 = NULL;
        uint16_t data1 = 0;
        void *value_aux = NULL;
         
        
        create_node_dll(&head1);                                                    // create a node

        data1 = 3;
        give_node_value_dll(head1,(void*) &data1,sizeof(uint16_t));                 // give a value to a node
        

        create_node_dll(&node1);
        data1 = 20;
        give_node_value_dll(node1,(void*) &data1,sizeof(uint16_t));        
        add_node_to_head_dll(&head1,node1);                                         // add new node to the head

        create_node_dll(&node1);
        data1 = 30;
        give_node_value_dll(node1,(void*) &data1,sizeof(uint16_t));        
        add_node_to_tail_dll(&head1,node1);                                         // add node to tail of head            

        create_node_dll(&node1);
        data1 = 40;
        give_node_value_dll(node1,(void*) &data1,sizeof(uint16_t));      
        add_node_in_index_n_dll(&head1,node1, 1);                                   // add node at index 1 of list


        value_aux = get_value_dll(head1);                                           // get value at the head of list
        if(NULL != value_aux)
        {
                printf("%u\n",*((uint16_t*)value_aux));
        } 

        value_aux = get_value_in_index_n_dll(head1, 1);                             // get value at index 1 of list
        if(NULL != value_aux)
        {
                printf("%u\n",*((uint16_t*)value_aux));
        }


        remove_head_node_dll(&head1);                                               // remove head node

        remove_tail_node_dll(&head1);                                               // remove tail node

        remove_node_in_index_n_dll(&head1,1);                                       // remove node at index 1 of list


        free_linked_list_dll(&head1);                                               // free linked list

        return ;



}




int main()
{

//        double_linked_list_stress_test1();
//        double_linked_list_stress_test2();
//        double_linked_list_stress_test3();
//        double_linked_list_stress_test4();
        double_linked_list_stress_test5();

//        tutorial();


        return 0;  
}