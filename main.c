/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:03:58 by abiju-du          #+#    #+#             */
/*   Updated: 2021/10/08 16:18:29 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stacks(t_list *stacka, t_list *stackb)
{
	int		diff;
	t_list	*current[2];

	current[0] = stacka;
	current[1] = stackb;
	diff = stack_size(stacka) - stack_size(stackb);
	while (diff > 0 && current[0] != NULL)
	{
		printf("%2d\n", current[0]->value);
		current[0] = current[0]->next;
		diff--;
	}
	while (diff < 0 && current[1] != NULL)
	{
		printf("   %2d\n", current[1]->value);
		current[1] = current[1]->next;
		diff++;
	}
	while (current[0] != NULL && current[1] != NULL)
	{
		printf("%2d %2d\n", current[0]->value, current[1]->value);
		current[0] = current[0]->next;
		current[1] = current[1]->next;
	}
	printf("-- --\n");
	printf("a   b\n\n\n");
	return ;
}

int	main(int argc, char const *argv[])
{
	t_list	*stack[2];

	stack[0] = NULL;
	stack[1] = NULL;
	stack[0] = create_stack(stack[0], argc, argv);
	if (count_int(stack[0]) == 3)
		stack[0] = three_numbers_sort(stack[0]);
	else if (count_int(stack[0]) == 5)
	{
		five_numbers_sort(stack);
		stack[0] = upset(stack[0]);
		stack[1] = upset(stack[1]);
		movers_move(stack);
		stack[0] = upset(stack[0]);
		stack[1] = upset(stack[1]);
		movers_move(stack);
		stack[0] = upset(stack[0]);
		stack[1] = upset(stack[1]);
		movers_move(stack);
	}
	else
		big_sort(stack);
	return (0);
}
