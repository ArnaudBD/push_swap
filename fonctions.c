#include <unistd.h>
#include "push_swap.h"

// void    swap(t_list *stack)
// {
//     int tmp;
//     if(stack == NULL || stack->next == NULL)
//         return ;
//     tmp = stack->next->value;
//     stack->next->value = stack->value;
//     stack->value = tmp;
//     return ;
// }

t_list  *restore_pos(t_list *stack)
{
    int     i;
    t_list  *current;

    i = 1;
    current = stack;
    while(current != NULL)
    {
        current->pos = i;
        i++;
        current = current->next;
    }
    return (stack);
}

t_list  *swap(t_list *stack)
{
    t_list *temp;

    if(stack == NULL || stack->next == NULL)
        return (NULL);
    temp = stack->next;
    stack->next = stack->next->next;
    temp->next = stack;
    stack = temp;
    stack = restore_pos(stack);
    return (stack);
}

t_list  *rotate(t_list *stack)
{
    t_list *last;
    t_list *tmp;
    
    last = stack;
    tmp = stack;
    stack = stack->next;
    while (last->next != NULL)
        last = last->next;

    last->next = insert_on_top(last->next, tmp->value);

    printf("last->next == %p\n", last->next);
    printf("last->value == %d\n\n\n", last->value);
    //last->next->next = NULL;

    stack = insert_on_top(tmp, last->value);

    // free(tmp);
    
    return (stack);
}