

#include "set.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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



void single_set_simple_test()
{
        set_t *set = NULL;

        set = create_set(sizeof(uint16_t),20, compare_uint16_t_func,hash_function);

        printf("%u\n",set_is_empty(set));
        printf("%u\n",set_size(set));


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

        printf("%u\n",set_is_empty(set));
        printf("%u\n",set_size(set));


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