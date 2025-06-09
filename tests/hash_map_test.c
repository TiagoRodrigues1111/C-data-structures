

#include "hash_map.h"
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

// not really a good hash function, using uint16_t as the hash, means the uint64_t max size of buckets will not be used
uint64_t hash_function(void* val)                       
{
        uint16_t val1_int = *((uint16_t*)val);
        return val1_int;
}



void single_hash_map_simple_test()
{
        void *hash_map = NULL;

        create_hash_map(&hash_map, sizeof(uint16_t),sizeof(uint16_t),20, compare_uint16_t_func,hash_function);

        printf("%u\n",check_hash_map_is_empty(hash_map));
        printf("%u\n",check_hash_map_size(hash_map));


        uint16_t key1 = 30;
        uint16_t value1 = 30;
        hash_map_insert(hash_map, (void*)&key1,(void*)&value1);
        value1 = 10;
        hash_map_insert(hash_map, (void*)&key1,(void*)&value1);
        key1 = 25;
        value1 = 20;
        hash_map_insert(hash_map, (void*)&key1,(void*)&value1);
        key1 = 60;
        value1 = 20000;
        hash_map_insert(hash_map, (void*)&key1,(void*)&value1);
        key1 = 5444;
        value1 = 2220;
        hash_map_insert(hash_map, (void*)&key1,(void*)&value1);

        printf("%u\n",check_hash_map_is_empty(hash_map));
        printf("%u\n",check_hash_map_size(hash_map));


        key1 = 25;
        printf("%u\n",hash_map_contains(hash_map,(void*)&key1));
        hash_map_erase(hash_map, (void*)&key1);
        printf("%u\n",hash_map_contains(hash_map,(void*)&key1));
        hash_map_erase(hash_map, (void*)&key1);


        key1 = 60;
        printf("%u\n",hash_map_contains(hash_map,(void*)&key1));
        hash_map_erase(hash_map, (void*)&key1);
        printf("%u\n",hash_map_contains(hash_map,(void*)&key1));

        key1 = 5444;
        printf("%u\n",hash_map_contains(hash_map,(void*)&key1));
        hash_map_erase(hash_map, (void*)&key1);
        printf("%u\n",hash_map_contains(hash_map,(void*)&key1));

        key1 = 30;
        printf("%u\n", *((uint16_t*)hash_map_get_value(hash_map,(void*)&key1)));



        free_hash_map(hash_map);

        return;
}



int main()
{

        single_hash_map_simple_test();

        return 0;  
}