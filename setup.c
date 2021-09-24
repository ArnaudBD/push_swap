#include "push_swap.h"

t_list *targeter(t_list *stack)
{
    int i;
    int tmp;
    int max;
    int last_assigned;
    t_list  *current;

    i = 1;
    current = stack;
    last_assigned = current->value;
    max = count_int(stack);
    while (current->next != NULL)
    {
        if (current->value < last_assigned)
            last_assigned = current->value;
        current = current->next;
    }    

    while (i <= max)
    {
        tmp = last_assigned;
        current = stack;
        while (current->next != NULL)
        {
            if(current->value > last_assigned && current->value < tmp)
                tmp = current->value;
            current = current->next;
        }
        last_assigned = tmp;
        current = stack;
        while (current->next != NULL)
        {
            if (current->value > last_assigned)
                current->target = i;
            current = current->next;
        }
        i++;
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
