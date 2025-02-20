

#include "singlelinkedlist.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simple_single_linked_list_test()
{

        void *head1 = NULL;
        void *node1 = NULL;
        uint32_t data1 = 2;

        create_node(&head1);


        give_node_value(head1,(void*) &data1,sizeof(uint32_t));
        printf("%u\n", *((uint32_t*)get_value(head1)));

   

        create_node(&node1);
        data1 = 3;
        give_node_value(node1,(void*) &data1,sizeof(uint32_t));

        add_node_to_head(&head1,node1);


        printf("%u\n", *((uint32_t*)get_value(head1)));
     
        remove_head_node(&head1);

        printf("%u\n", *((uint32_t*)get_value(head1)));

        remove_head_node(&head1);
        remove_head_node(&head1);
        remove_head_node(&head1);

        return ;
}


void simple_single_linked_list_test2()
{

        void *head1 = NULL;
        void *node1 = NULL;
        uint32_t data1 = 22;

        create_node(&head1);

        give_node_value(head1,(void*) &data1,sizeof(uint32_t));
        // printf("%u\n", *((uint32_t*)get_value(head1)));

   
        for(int i=0;i<10;i++)
        {
                create_node(&node1);
                data1 = i;
                give_node_value(node1,(void*) &data1,sizeof(uint32_t));

                add_node_to_tail(&head1,node1);

        }

        create_node(&node1);
        data1 = 730;
        give_node_value(node1,(void*) &data1,sizeof(uint32_t));
        add_node_in_index_n(&head1,node1,1);

        for(int i=0;i<10;i++)
        {
                printf("%u\n", *((uint32_t*)get_value(head1)));
                // remove_head_node(&head1);
                //remove_tail_node(&head1);
                remove_node_in_index_n(&head1,12);
        }       

        for(int i=0;i<11;i++)
        {
                printf("%u\n", *((uint32_t*)get_value(head1)));
                remove_head_node(&head1);
        }       

        printf("%u\n", *((uint32_t*)get_value(head1)));

        remove_head_node(&head1);
        remove_head_node(&head1);
        remove_head_node(&head1);

        free_linked_list(&head1);

        return ;
}


void single_ops_test()
{
        void *head1 = NULL;
        uint32_t data1 = 2;

        create_node(&head1);
        give_node_value(head1,(void*) &data1,sizeof(uint32_t));
        
        printf("%u\n", *((uint32_t*)get_value(head1)));

        printf("%p\n", get_next_node(head1));

        printf("%p\n", head1);

        printf("%u\n", *((uint32_t*)get_value_in_index_n(head1,0)));

        remove_head_node(&head1);
        remove_head_node(&head1);
        remove_head_node(&head1);

        free_linked_list(&head1);

        return ;


}


void free_linked_list_test()
{

        void *head1 = NULL;
        void *node1 = NULL;
        uint32_t data1 = 22;

        create_node(&head1);

        give_node_value(head1,(void*) &data1,sizeof(uint32_t));
        // printf("%u\n", *((uint32_t*)get_value(head1)));

   
        for(int i=0;i<10;i++)
        {
                create_node(&node1);
                data1 = i;
                give_node_value(node1,(void*) &data1,sizeof(uint32_t));

                add_node_to_tail(&head1,node1);
        }


        free_linked_list(&head1);


        return ;
}

void simple_single_linked_list_test3()
{

        void *head1 = NULL;
        void *node1 = NULL;
        uint32_t data1 = 2;

        create_node(&head1);
        give_node_value(head1,(void*) &data1,sizeof(uint32_t));

        printf("%u\n", *((uint32_t*)get_value(head1)));

        create_node(&node1);
        data1 = 3;
        give_node_value(node1,(void*) &data1,sizeof(uint32_t));
        add_node_to_head(&head1,node1);

        printf("%u\n", *((uint32_t*)get_value(head1)));
     
        // remove_node_in_index_n(&head1,1);
        printf("%u\n", *((uint32_t*)get_value(head1)));
        remove_head_node(&head1);
        printf("%u\n", *((uint32_t*)get_value(head1)));

        free_linked_list(&head1);

        return ;


}


/* High memory usage test */
void single_linked_list_stress_test1()
{
        void *head1 = NULL;
        void *node1 = NULL;
        uint16_t data1 = 2;

        create_node(&head1);
        give_node_value(head1,(void*) &data1,sizeof(uint16_t));    


        // uint64_t n = 400000000;
        uint64_t n = 400000;
        
        while(0 < n)
        {
                

                
                if(NULL != get_value(head1))
                {
                        // printf("%lu",*((uint16_t*)get_value(head1)));
                }
                
                create_node(&node1);

                data1++;
                give_node_value(node1,(void*) &data1,sizeof(uint16_t));
                add_node_to_head(&head1,node1);
                n--;



        }
        while(NULL != head1)
        {
                remove_head_node(&head1);


        }

        free_linked_list(&head1);

}

/* High CPU usage test */

void single_linked_list_stress_test2()
{
        void *head1 = NULL;
        void *head2 = NULL;
        void *node1 = NULL;
        uint16_t data1 =0;
        uint16_t data2 =0; 

        create_node(&head1);
        give_node_value(head1,(void*) &data1,sizeof(uint16_t));    

        create_node(&head2);
        give_node_value(head2,(void*) &data2,sizeof(uint16_t));    



        uint64_t n = 4000000;
        // uint64_t n = 4000000;
        
        while(0 < n)
        {
                remove_head_node(&head1);
                remove_head_node(&head2);
                data1++;
                data2++;


                create_node(&node1);
                give_node_value(node1,(void*) &data1,sizeof(uint16_t));
                add_node_to_head(&head1,node1);


                create_node(&node1);
                give_node_value(node1,(void*) &data2,sizeof(uint16_t));
                add_node_to_head(&head2,node1);

                n--;        
        }
        while(NULL != head1)
        {
                remove_head_node(&head1);


        }

        free_linked_list(&head1);
        free_linked_list(&head2);

}


/* Array of linked lists test */

void single_linked_list_stress_test3()
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
                create_node(&heads[i]);
                give_node_value(heads[i],(void*) &data1,sizeof(uint16_t));    
        }

        for(uint64_t i=0;i<num_of_heads;i++)
        {
                while(NULL != heads[i])
                {
                        if(NULL != get_value(heads[i]))
                        {
                                printf("%u ",*((uint16_t*)get_value(heads[i])));
                        }
                        remove_head_node(&heads[i]);
                }
        }

        for(uint64_t i=0;i<num_of_heads;i++)
        {
                free_linked_list(&heads[i]);
        }        
        free(heads);
        
}

/* Random Operations test*/

void single_linked_list_stress_test4()
{

        void *head1 = NULL;
        void *node1 = NULL;
        uint16_t data1 = 2;
        void* value_aux = NULL;
        srand(time(NULL));   

        create_node(&head1);
        give_node_value(head1,(void*) &data1,sizeof(uint16_t));    

        // uint64_t n = 400000000;
        uint64_t operations = 400000;

        
        while(0 < operations)
        {
                uint8_t op_to_do = rand() % 8;          
                switch (op_to_do)
                {
                case 0:                                         // add_node_to_head
                        create_node(&node1);
                        give_node_value(node1,(void*) &data1,sizeof(uint16_t));      
                        add_node_to_head(&head1,node1);
                        break;
                case 1:                                         // add_node_to_tail
                        create_node(&node1);
                        give_node_value(node1,(void*) &data1,sizeof(uint16_t));      
                        add_node_to_tail(&head1,node1);
                        break; 
                case 2:                                         // add_node_in_index_n
                        create_node(&node1);
                        give_node_value(node1,(void*) &data1,sizeof(uint16_t));      
                        add_node_in_index_n(&head1,node1, rand() % 4000);
                        break; 
                case 3:                                         // remove_head_node
                        remove_head_node(&head1);
                        break; 
                case 4:                                         // remove_tail_node
                        remove_tail_node(&head1);
                        break; 
                case 5:                                         // remove_tail_node
                        remove_node_in_index_n(&head1,rand() % 400);
                        break; 
                case 6:                                         // get_value  
                        value_aux = get_value(head1);                               
                        if(NULL != value_aux)
                        {
                                printf("%u\n",*((uint16_t*)value_aux));
                        }
                        break; 
                case 7:
                        value_aux = get_value_in_index_n(head1, rand() % 400);     
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

        free_linked_list(&head1);    


}

void tutorial()
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

        return ;



}




int main()
{
        // single_linked_list_stress_test1();
        // single_linked_list_stress_test2();
        // single_linked_list_stress_test3();
        // single_linked_list_stress_test4();

        tutorial();


        return 0;  
}