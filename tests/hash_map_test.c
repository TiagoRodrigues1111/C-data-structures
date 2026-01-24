

#include "hash_map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"
// #include <errno.h>



bool compare_uint16_t_func(const void* val1, const void* val2)
{
        uint16_t val1_int = *((uint16_t*)val1);
        uint16_t val2_int = *((uint16_t*)val2);

        if(val1_int == val2_int)
                return true;
        else
                return false;

}




// not really a good hash function, using uint16_t as the hash, means the uint64_t max size of buckets will not be used
size_t hash_function(const void* val)                       
{
        uint16_t val1_int = *((uint16_t*)val);
        return val1_int;
}



void single_hash_map_simple_test()
{
        hash_map_t* hash_map = NULL;

        hash_map = create_hash_map(sizeof(uint16_t),sizeof(uint16_t),20, compare_uint16_t_func,hash_function);

        printf("%u\n",hash_map_is_empty(hash_map));
        printf("%u\n",hash_map_size(hash_map));


        uint16_t key1 = 30;
        uint16_t value1 = 30;
        if(hash_map_insert(hash_map, (void*)&key1,(void*)&value1) == false)
        {
                printf("Insertion failed for key %u value %u\n",key1,value1);
        }
        value1 = 10;
        if(hash_map_insert(hash_map, (void*)&key1,(void*)&value1) == false)
        {
                printf("Insertion failed for key %u value %u\n",key1,value1);
        }
        key1 = 25;
        value1 = 20;
        if(hash_map_insert(hash_map, (void*)&key1,(void*)&value1) == false)
        {
                printf("Insertion failed for key %u value %u\n",key1,value1);
        }
        key1 = 60;
        value1 = 20000;
        if(hash_map_insert(hash_map, (void*)&key1,(void*)&value1) == false)
        {
                printf("Insertion failed for key %u value %u\n",key1,value1);
        }
        key1 = 5444;
        value1 = 2220;
        if(hash_map_insert(hash_map, (void*)&key1,(void*)&value1) == false)
        {
                printf("Insertion failed for key %u value %u\n",key1,value1);
        }

        printf("%u\n",hash_map_is_empty(hash_map));
        printf("%u\n",hash_map_size(hash_map));


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

        uint16_t out_value = 0;
        if(true == hash_map_get_value(hash_map,(void*)&key1,(void*)&out_value))
        {
                printf("Value for key %u is %u\n",key1,out_value);
        }
        else
        {
                printf("Key %u not found\n",key1);
        }


        printf("%u\n",hash_map_is_empty(hash_map));
        printf("%u\n",hash_map_size(hash_map));

        free_hash_map(hash_map);

        return;
}



int main()
{

        single_hash_map_simple_test();

        return 0;  
}