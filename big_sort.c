#include "push_swap.h"

// void    big_sort(t_list **stack, t_list *stackA, t_list *stackB)
// {
//     int i;
//     t_list *current;

//     i = 1;
//     move_to_b(stack);
//     stack = upset(stack);
//     distance_calculator(stack);

// }

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
    printf("------------------------pos == %d-------------size == %d\n", pos, size);
    if((size / 2) > pos)
        return (1);
    else
        return (0);
    
}

void    distance_calculator(t_list **stack)
{
    while(stack[1] != NULL)
    {

    }
}
