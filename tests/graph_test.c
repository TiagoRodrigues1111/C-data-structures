

#include "graph.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void graph_simple_test()
{
        void *graph = NULL;


        create_graph(&graph,sizeof(uint16_t),sizeof(int64_t),10);

        int64_t weight = 10;
        uint64_t source = 0;
        uint64_t destination = 2;

  
        add_edge_graph(graph,(void *)&weight,(void*)&source,(void*)&destination,1);
        
        add_edge_graph(graph,(void *)&weight,(void*)&source,(void*)&destination,1);

        remove_edge_graph(graph,(void*)&source,(void*)&destination,0);

        print_graph(graph);
        
        free_graph(graph);

        return;
}



int main()
{

        graph_simple_test();

        return 0;  
}