/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:13:42 by abiju-du          #+#    #+#             */
/*   Updated: 2021/10/13 11:14:46 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(char const *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strncmp(argv[i], argv[j], 20) == 0)
			{
				write(1, "Error\n", 6);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_errors(int argc, char const *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argv[1] == 0)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	i = 1;
	if (check_double(argv) == -1)
		return (-1);
	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (1);
}
