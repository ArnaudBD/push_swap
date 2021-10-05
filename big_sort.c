#include "push_swap.h"

void    big_sort(t_list **stack)
{
    move_to_b(stack);
    show_stacks(stack[0], stack[1]);
    stack[0] = upset(stack[0]);
    stack[1] = upset(stack[1]);
    distance_set(stack);
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
            stack[0] = rotate(stack[0]);
            write(1,"ra\n",3);
        }
        else
        {
            push(stack, 'b');
            write(1,"pb\n", 3);
        }
    }
    return ;
}



// int distance_calculator(t_list **stack)
// {
//     t_list  *currentA;
//     t_list  *currentB;
//     int i;
//     int d;

//     currentA = stackA;
//     currentB = satckB;
//     while (currentB != NULL)
//     {
//         while(currentA != NULL)
//         {
//             if(currentA->target == (currentB->target + 1))
//             {
//                 if(currentB->pos > (stack_size(satckB) / 2)
//                     d = (stack_size(stackB) - currentB->pos) + (distance dans la stackA)
//                 else
//                     d = 
//             }
//         }
        
//         if(currentB->target == (stack_size(stackA) + stack_size(satckB)))
            

//         currentB = currentB->next;
//     }}




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

int distance_calculator(t_list **stack, int sizeA, int sizeB)
{
    t_list *current[2];
    int d;
    int i;

    current[0] = stack[0];
    current[1] = stack[1];
    i = 1;
    while(current[0]->target != (stack[1]->target + i))
    {
        current[0] = current[0]->next;
        if(current[0] == NULL)
        {
            i++;
            current[0] = stack[0];
        }
    }
    if(stack[1]->up == 1)
    {
        if(current[0]->up == 1)
        {
            d = stack[1]->pos + current[0]->pos;
        }
        else
        {
            d = stack[1]->pos + sizeA - current[0]->pos;
        }
    }
    else
    {
        if(current[0]->up == 1)
        {
            d = sizeB - stack[1]->pos + current[0]->pos;
        }
        else
        {
            d = sizeB - stack[1]->pos + sizeA - current[0]->pos;
        }
    }
    return (d);
}
