#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>


typedef struct s_elem
{
    int	value;
    int	pos;
    int	target;
    int	winer;
    t_elem	*prev;
    t_elem	*next;
} t_elem;

typedef struct s_stack
{
	t_elem *first;
	int	size;
}	t_stack;

#endif