#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


typedef struct s_list t_list;
struct s_list
{
    int	value;
    int	pos;
    int	target;
    // int	winer;
    // t_list	*prev;
    t_list	*next;
};
// stack_ops.c
t_list *insert_on_top(t_list *stack, int number);
int count_int(t_list *stack);
t_list  *restore_pos(t_list *stack);
t_list  *swap(t_list *stack);
t_list  *rotate(t_list *stack);
t_list *reverse_rotate(t_list *stack);
void    push(t_list **stack, char dest);

// split.c
char	**ft_split(char const *s, char c);

//utils.c
int	ft_strlen(const char *s);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);

//3n_sort.c
t_list  *three_numbers_sort(t_list *stack);

//setup.c
t_list *targeter(t_list *stack);
t_list	*create_stack(t_list *stack, int argc, const char **argv);
int stack_size(t_list *stack);

//big_sort.c
void    move_to_b(t_list **stack);

#endif