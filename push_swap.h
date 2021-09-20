#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>


typedef struct s_list t_list;

struct s_list
{
    int	value;
    int	pos;
    // int	target;
    // int	winer;
    // t_list	*prev;
    t_list	*next;
};

t_list  *swap(t_list *stack);
t_list  *rotate(t_list *stack);
t_list *insert_on_top(t_list *stack, int number);
char	**ft_split(char const *s, char c);
int	ft_strlen(const char *s);
t_list  *restore_pos(t_list *stack);



#endif