/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:22:14 by abiju-du          #+#    #+#             */
/*   Updated: 2021/10/11 18:23:11 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**freedom(char **tab, int j)
{
	while (j >= 0)
	{
		free(tab[j]);
		j--;
	}
	free(tab);
	return (NULL);
}

static int	nb_words(char const *s, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (s[i] != c)
		nb++;
	while (s[i] != 0)
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			nb++;
		i++;
	}
	return (nb);
}

static char	**filling_good(char const *s, char **tab, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == 0)
			break ;
		while (s[i] != c && s[i] != 0)
		{
			tab[j][k] = s[i];
			k++;
			i++;
		}
		tab[j][k] = 0;
		k = 0;
		j++;
	}
	tab[j] = 0;
	return (tab);
}

static char	**ft_malloc_split(char const *s, char c, char **tab, int i)
{
	int		j;
	int		first_letter;

	j = 0;
	while (s[i] != 0)
	{
		if (s[i] == c || i == 0)
		{
			while (s[i] == c)
				i++;
			if (s[i] == 0)
				break ;
			first_letter = i;
			while (s[i] != 0 && s[i] != c)
				i++;
			tab[j] = malloc(sizeof(char) * (i - first_letter) + 1);
			if (!tab)
			{
				tab = freedom(tab, j);
				return (NULL);
			}
			j++;
		}
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (s == 0)
		return (0);
	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (nb_words(s, c) + 1));
	if (!tab)
		return (NULL);
	tab = ft_malloc_split(s, c, tab, i);
	if (tab == NULL)
		return (tab);
	else
	{
		tab[nb_words(s, c)] = malloc(sizeof(char));
		if (!tab)
		{
			tab = freedom(tab, j);
			return (NULL);
		}
		tab = filling_good(s, tab, c);
	}
	return (tab);
}
