

#include "binary_tree.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simple_binary_tree_test()
{

        void *root = NULL;
        void *node1 = NULL;
        void *aux_node = NULL;
        uint32_t data1 = 2;

        create_node_bt(&root);
        give_node_value_bt(root,(void*) &data1,sizeof(uint32_t));

        printf("%u\n", *((uint32_t*)get_value_bt(root)));

   

        create_node_bt(&node1);
        data1 = 3;
        give_node_value_bt(node1,(void*) &data1,sizeof(uint32_t));
        add_node_to_left_bt(root,node1);
        printf("%u\n", *((uint32_t*)get_value_bt(root)));
     

        create_node_bt(&node1);
        data1 = 20;
        give_node_value_bt(node1,(void*) &data1,sizeof(uint32_t));
        add_node_to_right_bt(root,node1);
        printf("%u\n", *((uint32_t*)get_value_bt(root)));


        aux_node = get_next_left_node_bt(root);
        printf("%u\n", *((uint32_t*)get_value_bt(aux_node)));

        aux_node = get_next_right_node_bt(root);
        printf("%u\n", *((uint32_t*)get_value_bt(aux_node)));


        free_binary_tree(root);

        return ;
}




int main()
{

        simple_binary_tree_test();



        return 0;  
}