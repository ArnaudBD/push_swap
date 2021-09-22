#include "push_swap.h"

t_list *insert_on_top(t_list *stack, int number)
{
	t_list	*new;
	new = malloc(sizeof(*new));
	if (new == NULL)
		exit(2);

	new->value = number;
	new->next = stack;
	stack = new;

	return (stack);
}


t_list	*create_stack(t_list *stack, int argc, const char **argv)
{
	int i;

	i = 0;

	if(argc > 2)
	{
		i = argc - 1;

		while(i > 0)
		{
			stack = insert_on_top(stack, ft_atoi(argv[i]));
			stack->pos = i;
			i--;
		}
	}
	else if (argc == 2)
	{
		char	**tab;
		tab = ft_split(argv[1], ' ');
		while(tab[i] != NULL)
			i++;
		i--;
		while (i >= 0)
		{
			stack = insert_on_top(stack, ft_atoi(tab[i]));
			stack->pos = i + 1;
			i--;
		}
	}
	return (stack);
}

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

    stack = restore_pos(stack);

    return (stack);
}

void    push(t_list **stack, char dest)
{

    t_list  *tmp;
    if (dest == 'a' && stack[1] != NULL)
    {
        tmp = stack[1]->next;
        printf("OK\n");
        stack[1]->next = stack[0];
        stack[0] = stack[1];
        stack[1] = tmp;
    }
    else if (dest == 'b' && stack[0] != NULL)
    {
        tmp = stack[0]->next;
        stack[0]->next = stack[1];
        stack[1] = stack[0];
        stack[0] = tmp;
    }
}