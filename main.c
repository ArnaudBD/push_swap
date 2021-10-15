/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:03:58 by abiju-du          #+#    #+#             */
/*   Updated: 2021/10/13 11:12:23 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	t_list	*stack[2];
	int		i;

	i = 0;
	if (check_errors(argv) < 0)
		return (0);
	stack[0] = NULL;
	stack[1] = NULL;
	stack[0] = create_stack(stack[0], argc, argv);
	if (count_int(stack[0]) == 3)
		stack[0] = three_numbers_sort(stack[0]);
	else if (count_int(stack[0]) == 5)
	{
		five_numbers_sort(stack);
		while (i++ < 3)
		{
			stack[0] = upset(stack[0]);
			stack[1] = upset(stack[1]);
			movers_move(stack);
		}
	}
	else
		big_sort(stack);
	freelist(stack);
	return (0);
}
