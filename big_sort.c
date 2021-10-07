#include "push_swap.h"

void    big_sort(t_list **stack)
{  
    move_to_b(stack);
    while(stack[1] != NULL)
    {
        stack[0] = upset(stack[0]);
        stack[1] = upset(stack[1]);
        distance_set(stack);
        movers_move(stack);
        // show_stacks(stack[0], stack[1]);
    }
    stack[0] = upset(stack[0]);
    movers_move(stack);
    // show_stacks(stack[0], stack[1]);
}

void    move_to_b(t_list **stack)
{
    t_list *current;
    t_list  *last;
    int i;

    while(stack_size(stack[0]) > 1)
    {
        i = 1;
        current = stack[0];
         while(current->next != NULL)
        {
            if(current->target < current->next->target)
                i++;
            current = current->next;
        }
        if (i == stack_size(stack[0]))
            break;
        last = current;
        if(stack[0]->target > last->target)
        {
            stack[0] = rotate(stack[0], 0);
        }
        else
        {
            push(stack, 'b');
        }
    }
    return ;
}

t_list  *upset(t_list *stack)
{
    t_list *current;
    int size;

    size = stack_size(stack);
    current = stack;
    while(current != NULL)
    {
        current->up = isup(current->pos, size);
        current = current->next;
    }
    return (stack);
}

int isup(int pos, int size)
{
    if((size / 2) >= pos)
        return (1);
    else
        return (0);
    
}

void    distance_set(t_list **stack)
{
    t_list *current[2];

    current[0] = stack[0];
    current[1] = stack[1];
    while(current[1] != NULL)
    {
        current[1]->dist = distance_calculator(current, stack_size(stack[0]), stack_size(stack[1]));
        current[1] = current[1]->next;
    }
    return ;
}

t_list *choose_base(t_list **stack)
{
    t_list *current[2];
    int i;

    current[0] = stack[0];
    i = 1;
    if(stack[1] == NULL)
    {
        while(current[0]->target != 1)
            current[0] = current[0]->next;
        return (current[0]);
    }
    else
    {
        while(current[0]->target != (stack[1]->target + i))
        {
            current[0] = current[0]->next;
            if(current[0] == NULL)
            {
                i++;
                current[0] = stack[0];
            }
        }
    }
    return (current[0]);
}

int distance_calculator(t_list **stack, int sizeA, int sizeB)
{
    t_list *base;
    int d;

    base = choose_base(stack);
    if(stack[1]->up == 1)
    {
        if(base->up == 1)
        {
            d = stack[1]->pos -1 + base->pos;
        }
        else
        {
            d = stack[1]->pos - 1 + sizeA - base->pos + 1;
        }
    }
    else
    {
        if(base->up == 1)
        {
            d = sizeB - stack[1]->pos + 1 + base->pos - 1;
        }
        else
        {
            d = sizeB - stack[1]->pos + 1 + sizeA - base->pos + 1;
        }
    }
    return (d);
}

t_list *choose_mover(t_list *stack)
{
    t_list *current;
    t_list *mover;

    current = stack;
    mover = stack;
    while(current != NULL)
    {
        if(current->dist < mover->dist)
            mover = current;
        current = current->next;
    }
    return (mover);
}

void movers_move(t_list **stack)
{
    t_list *mover;
    t_list *base;
    t_list *current[2];
    int i;
    mover = NULL;
    if(stack[1] != NULL)
        mover = choose_mover(stack[1]);
    current[0] = stack[0];
    current[1] = mover;
    base = choose_base(current);
    if(base->up == 1)
    {
        i = base->pos;
        while(i != 1)
        {
            stack[0] = rotate(stack[0], 0);
            i--;
        }
    }
    else
    {
        i = base->pos - stack_size(stack[0]);
        while(i != 1)
        {
            stack[0] = reverse_rotate(stack[0], 0);
            i++;
        }
    }
    
    if(stack[1] != NULL && mover->up == 1)
    {
        i = mover->pos;
        while(i != 1)
        {
            stack[1] = rotate(stack[1], 1);
            i--;
        }
    }
    else if(stack[1] != NULL)
    {
        i = mover->pos - stack_size(stack[1]);
        while(i != 1)
        {
            stack[1] = reverse_rotate(stack[1], 1);
            i++;
        }
    }
    push(stack, 'a');
    return ;
}