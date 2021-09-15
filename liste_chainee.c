#include "push_swap.h"

t_stack	*init(void)
{
	t_stack *a = malloc(sizeof(*a));
	t_elem	*first = malloc(sizeof(*first));

	if (a == NULL || first == NULL)
		exit(2);

	first->value = 0;
	first->pos = 0;
	first->target = 0;
	first->winer = 0;
	first->prev = NULL;
	first->next = NULL;

	return (a);
}

void insert_on_top(t_stack *stack, int number)
{
	t_elem	*new = malloc(sizeof(*new));
	if (new == NULL || stack == NULL)
		exit(2);

	new->number = number;
	new->next = stack->first;
	stack->first = new;
}