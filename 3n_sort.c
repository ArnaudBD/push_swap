#include "push_swap.h"

t_list  *three_numbers_sort(t_list *stack)
{
    printf("stack->target == %d\n\n\n", stack->target);
    printf("stack->next->target == %d\n\n\n", stack->next->target);
    int i = 0;
    while((stack->target != 1) || (stack->next->target != 2))
    {
        if((stack->target == 1 && stack->next->target == 3)\
        || (stack->target == 2 && stack->next->target == 1)\
        || (stack->target == 3 && stack->next->target == 2))
        {
            stack = swap(stack);
            write(1, "sa\n", 3);
        }

        if((stack->target == 3) && (stack->next->target == 1))
        {
            stack = rotate(stack);
            write(1, "ra\n", 3);
        }

        if((stack->target == 2) && (stack->next->target == 3))
        {
            stack = reverse_rotate(stack);
            write(1,"rra\n", 4);
        }
    
    printf("-------------------------%d---------------------------------\n\n", i++);
    t_list  *current;
    current = stack;
	while(current != NULL)
	{
		printf("number   == %d\n", current->value);
		printf("position == %d\n", current->pos);
		printf("target == %d\n\n", current->target);
		current = current->next;
	}

    }
    
    return (stack);
}
