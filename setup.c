#include "push_swap.h"

t_list *targeter(t_list *stack)
{
    int tmp;
    int i;
    int max;
    int nb;
    int last_assigned;
    t_list  *current;

    i = 1;
    current = stack;
    current->target = i;
    last_assigned = current->value;
    max = current->value;
    nb = count_int(stack);
    while (current != NULL)
    {
        if (current->value < last_assigned)
        {
            last_assigned = current->value;
            current->target = i;
        }
        current = current->next;
    }
    current = stack;
    while (current != NULL)
    {
        if(current->value > max)
            max = current->value;
        current = current->next;
    }
    while (i++ <= nb)
    {

        current = stack;
        while(current != NULL)
        {
            if(current->value > last_assigned && current->value <= max)
                current->target = i;
            current = current->next;
        }
        current = stack;
        tmp = max;
        while(current != NULL)
        {
            if(current->value > last_assigned && current->value < tmp)
                tmp = current->value;
            current = current->next;
        }
        last_assigned = tmp;
    }
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
    stack = targeter(stack);
	return (stack);
}

int stack_size(t_list *stack)
{
    int i;
    t_list  *current;

    i = 0;
    current = stack;
    while (current != NULL)
    {
        current = current->next;
        i++;
    }
    return (i);
}
