/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:45:39 by abiju-du          #+#    #+#             */
/*   Updated: 2021/10/08 16:03:06 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				pos;
	int				target;
	int				dist;
	int				up;
	struct s_list	*next;
}	t_list;
// main.c
void	show_stacks(t_list *stacka, t_list *stackb);

// stack_ops.c
t_list	*insert_on_top(t_list *stack, int number);
int		count_int(t_list *stack);
t_list	*restore_pos(t_list *stack);
t_list	*swap(t_list *stack);
t_list	*rotate(t_list *stack, int ab);
t_list	*reverse_rotate(t_list *stack, int ab);
void	push(t_list **stack, char dest);

// split.c
char	**ft_split(char const *s, char c);

//utils.c
int		ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

//3n_sort.c
t_list	*three_numbers_sort(t_list *stack);

//setup.c
t_list	*targeter(t_list *stack);
t_list	*create_stack(t_list *stack, int argc, const char **argv);
int		stack_size(t_list *stack);

//big_sort.c
void	big_sort(t_list **stack);
void	move_to_b(t_list **stack);
t_list	*upset(t_list *stack);
int		isup(int pos, int size);
void	distance_set(t_list **stack);
int		distance_calculator(t_list **stack, int sizeA, int sizeB);
t_list	*choose_mover(t_list *stack);
void	movers_move(t_list **stack);

// 5n_sort.c
void	five_numbers_sort(t_list **stack);

#endif
