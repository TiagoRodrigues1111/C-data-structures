

#include "set.h"
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



void single_set_simple_test()
{
        void *set = NULL;

        create_set(&set, sizeof(uint16_t),20, compare_uint16_t_func,hash_function);

        printf("%u\n",check_set_is_empty(set));
        printf("%u\n",check_set_size(set));


        uint16_t value1 = 30;
        set_insert(set, (void *)&value1);
        value1 = 10;
        set_insert(set, (void *)&value1);
        value1 = 20;
        set_insert(set, (void *)&value1);
        value1 = 20000;
        set_insert(set, (void *)&value1);
        value1 = 8;
        set_insert(set, (void *)&value1);

        printf("%u\n",check_set_is_empty(set));
        printf("%u\n",check_set_size(set));


        value1 = 10;
        printf("%u\n",set_contains(set,&value1));
        set_erase(set, (void *)&value1);
        printf("%u\n",set_contains(set, &value1));
        set_erase(set, (void *)&value1);

        value1 = 20000;
        printf("%u\n",set_contains(set, &value1));
        set_erase(set, (void *)&value1);
        printf("%u\n",set_contains(set, &value1));

        value1 = 30;
        printf("%u\n",set_contains(set, &value1));
        set_erase(set, (void *)&value1);
        printf("%u\n",set_contains(set, &value1));

        free_set(set);

        return;
}



int main()
{

        single_set_simple_test();

        return 0;  
}