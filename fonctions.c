#include <unistd.h>
#include "push_swap.h"

void    swap(t_list *stack)
{
    int tmp;
    if(stack == NULL || stack->next == NULL)
        return ;
    tmp = stack->next->value;
    stack->next->value = stack->value;
    stack->value = tmp;
    return ;
}

// void    swap(t_list *stack)
// {
//     t_list *temp;

//     if(stack == NULL || stack->next == NULL)
//         return ;
//     temp = stack->next;
//     stack->next = stack;
//     stack = temp;
//     return ;
// }

void    rotate(t_list *stack)
{
    t_list *last;
    t_list *tmp;
    
    last = stack;
    tmp = stack;
    stack = stack->next;
    while (last->next != NULL)
    {
        last = last->next;
    }

    insert_on_top(last->next, tmp->value);

    // free(tmp);
    
    return ;
}