

#include <cdatastructures/stack.h>
#include <stdio.h>



int main()
{
        stack_t* stack = create_stack(sizeof(int), 0);
        for(int i = 0; i < 10; i++)
        {
                stack_push(stack, &i);
        }
        while(!stack_is_empty(stack))
        {
                int value = 0;
                stack_top(stack, &value);
                printf("%d\n", value);
                stack_pop(stack);
        }

        free_stack(stack);
        return 0;
}