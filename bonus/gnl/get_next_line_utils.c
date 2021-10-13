/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 08:26:58 by abiju-du          #+#    #+#             */
/*   Updated: 2021/10/13 12:02:01 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../../push_swap.h"

int	n_search(char *str)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i] != '\n' && str[i] != 0)
			i++;
	if (str[i] == '\n')
		return (i);
	else
		return (-1);
}

int	mv_first_line(char *str, char **dest)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		dest[0] = malloc(1);
		dest[0][0] = 0;
		return (0);
	}
	while (str[i] != '\n' && str[i] != 0 && str[i] != EOF)
		i++;
	dest[0] = malloc(sizeof(char) * i + 1);
	if (!dest[0])
		return (-1);
	dest[0][i--] = 0;
	while (i >= 0)
	{
		dest[0][i] = str[i];
		i--;
	}
	return (1);
}

char	*sup_first_line(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*new_str;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	new_str = NULL;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if ((len - i - 1) >= 0)
	{
		new_str = malloc(sizeof(*new_str) * len + 1);
		if (!new_str)
			return (0);
		i++;
		while (j < len)
			new_str[j++] = str[i++];
		new_str[j] = 0;
	}
	free(str);
	return (new_str);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_cpy;
	char		*src_cpy;

	dst_cpy = (char *)dst;
	src_cpy = (char *)src;
	if (dst == src)
		return (dst);
	if (src_cpy < dst_cpy)
	{
		while (len--)
			*(dst_cpy + len) = *(src_cpy + len);
		return (dst);
	}
	else
	{
		while (len--)
			*dst_cpy++ = *src_cpy++;
	}
	return (dst);
}

