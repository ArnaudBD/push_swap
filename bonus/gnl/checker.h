#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

t_list	*c_swap(t_list *stack);
t_list	*c_rotate(t_list *stack);
t_list	*c_reverse_rotate(t_list *stack);
void	c_push(t_list **stack, char dest);


#endif