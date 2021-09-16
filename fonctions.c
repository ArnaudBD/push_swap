#include "push_swap.h"

void    swap(t_list *stack)
{
    int tmp;
    if(stack == NULL || stack->next == NULL)
        return ;
    tmp = stack->next->value;
    stack->next->value = stack->value;
    stack->value = tmp;
}

void    rotate(t_list *stack)
{
    t_list last;
    
    last = stack;
    stack = stack->next;
    while (last->next != NULL)
    {
        last = last->next;
    }
}