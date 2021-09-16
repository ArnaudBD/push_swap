#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>


typedef struct s_list t_list;

struct s_list
{
    int	value;
    int	pos;
    // int	target;
    // int	winer;
    // t_list	*prev;
    t_list	*next;
};

void    swap(t_list *stack);

#endif