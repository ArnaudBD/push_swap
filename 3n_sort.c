#include "push_swap.h"

void    three_numbers_sort(t_list *stack)
{
    while((stack->target =! 1) && (stack->next->target != 2))
    {
        if((stack->target == 1 && stack->next->target == 3)\
        || (stack->target == 2 && stack->next->target == 1)\
        || (stack->target == 3 && stack->next->target == 2))
        {
            swap(stack);
            write(1, "pa\n", 3);
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
