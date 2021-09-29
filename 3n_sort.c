#include "push_swap.h"

void    three_numbers_sort(t_list *stack)
{
    while((stack->target != 1) && (stack->next->target != 2))
    {
    printf("OK\n");
        if((stack->target == 1 && stack->next->target == 3)\
        || (stack->target == 2 && stack->next->target == 1)\
        || (stack->target == 3 && stack->next->target == 2))
        {
            swap(stack);
            write(1, "sa\n", 3);
        }

        t_list *current;
        current = stack;
        while (current != NULL)
        {
            printf("number   == %d\n", current->value);
            printf("position == %d\n", current->pos);
            printf("target == %d\n\n", current->target);
            current = current->next;
        }

        if((stack->target == 3) && (stack->next->target == 1))
        {
            reverse_rotate(stack);
            write(1, "rra\n", 4);
        }

        if((stack->target == 2) && (stack->next->target == 3))
        {
            rotate(stack);
            write(1,"ra\n", 3);
        }
        
    }
    
    return ;
}
