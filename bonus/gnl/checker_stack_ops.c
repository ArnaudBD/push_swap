/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:09:40 by abiju-du          #+#    #+#             */
/*   Updated: 2021/10/11 18:13:32 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*c_swap(t_list *stack)
{
	t_list	*temp;

	if (stack == NULL || stack->next == NULL)
		return (NULL);
	temp = stack->next;
	stack->next = stack->next->next;
	temp->next = stack;
	stack = temp;
	stack = restore_pos(stack);
	return (stack);
}

t_list	*c_rotate(t_list *stack)
{
	t_list	*last;
	t_list	*tmp;

	last = stack;
	tmp = stack;
	if (stack->next == NULL)
		return (stack);
	stack = stack->next;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	stack = restore_pos(stack);
	return (stack);
}

t_list	*c_reverse_rotate(t_list *stack)
{
	t_list	*last;
	t_list	*tmp;

	last = stack;
	if (stack->next == NULL)
		return (stack);
	while (last->next != NULL)
	{
		if (last->next->next == NULL)
			tmp = last;
		last = last->next;
	}
	last->next = stack;
	tmp->next = NULL;
	last = restore_pos(last);
	return (last);
}

void	c_push(t_list **stack, char dest)
{
	t_list	*tmp;

	if (dest == 'a' && stack[1] != NULL)
	{
		tmp = stack[1]->next;
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
	stack[0] = restore_pos(stack[0]);
	stack[1] = restore_pos(stack[1]);
	return ;
}
