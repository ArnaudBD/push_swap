#include "push_swap.h"

t_list *insert_on_top(t_list *stack, int number)
{
	t_list	*new = malloc(sizeof(*new));
	if (new == NULL)
		exit(2);

	new->value = number;
	new->next = stack;
	stack = new;

	return (stack);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	resultat;

	i = 0;
	n = 1;
	resultat = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		resultat = 10 * resultat + str[i] - '0';
		i++;
	}
	return (resultat * n);
}

int main(int argc, char const *argv[])
{
	int i;

	t_list *stack;
	stack = NULL;
	i = 0;

	if(argc > 2)
	{
		i = argc - 1;

		while(i > 0)
		{
			stack = insert_on_top(stack, ft_atoi(argv[i]));
			stack->pos = i;
			i--;
		}
	}
	else if (argc == 2)
	{
		char	**tab;
		tab = ft_split(argv[1], ' ');
		while(tab[i] != NULL)
			i++;
		i--;
		while (i >= 0)
		{
			stack = insert_on_top(stack, ft_atoi(tab[i]));
			stack->pos = i + 1;
			i--;
		}
	}
	t_list *current = stack;

	while(current != NULL)
	{
		printf("number   == %d\n", current->value);
		printf("position == %d\n\n", current->pos);
		current = current->next;
	}

	stack = swap(stack);
	
	current = stack;

		while(current != NULL)
	{
		printf("swap_number   == %d\n", current->value);
		printf("swap_position == %d\n\n", current->pos);
		current = current->next;
	}

	stack = rotate(stack);

	current = stack;


	while(current != NULL)
	{
		printf("rotate_number   == %d\n", current->value);
		printf("rotate_position == %d\n\n", current->pos);
		current = current->next;
	}


	return 0;
}