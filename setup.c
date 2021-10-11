/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:16:48 by abiju-du          #+#    #+#             */
/*   Updated: 2021/10/11 18:20:25 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*insert_on_top(t_list *stack, int number)
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

t_list	*create_with_string_args(t_list *stack, const char **argv, int i)
{
	char	**tab;

	tab = ft_split(argv[1], ' ');
	while (tab[i + 1] != NULL)
		i++;
	while (i >= 0)
	{
		stack = insert_on_top(stack, ft_atoi(tab[i]));
		stack->pos = i-- + 1;
	}
	return (stack);
}

t_list	*create_stack(t_list *stack, int argc, const char **argv)
{
	int		i;

	i = 0;
	if (argc > 2)
	{
		i = argc - 1;
		while (i > 0)
		{
			stack = insert_on_top(stack, ft_atoi(argv[i]));
			stack->pos = i--;
		}
	}
	else if (argc == 2)
		stack = create_with_string_args(stack, argv, i);
	stack = targeter(stack);
	return (stack);
}

int	stack_size(t_list *stack)
{
	int		i;
	t_list	*current;

	i = 0;
	current = stack;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	freelist(t_list **stack)
{
	t_list	*current[2];

	current[0] = stack[0];
	current[1] = stack[1];
	while (current[0] != NULL)
	{
		current[0] = current[0]->next;
		free(stack[0]);
		stack[0] = current[0];
	}
	free(current[0]);
	while (current[1] != NULL)
	{
		current[1] = current[1]->next;
		free(stack[0]);
		stack[1] = current[1];
	}
	free(current[1]);
	return ;
}
