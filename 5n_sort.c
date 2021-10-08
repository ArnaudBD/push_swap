/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5n_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:34:54 by abiju-du          #+#    #+#             */
/*   Updated: 2021/10/08 16:46:46 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_numbers_sort(t_list **stack)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (stack[0]->target < 4)
			stack[0] = rotate(stack[0], 0);
		else
		{
			push(stack, 'b');
			i++;
		}
	}
	stack[0] = three_numbers_sort(stack[0]);
}
